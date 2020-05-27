#include "receserial_msg.h"

extern Settings currentSettings;

extern int read_pixel_flag;    //读取pixel的标识  0:4300  1：casset_package_1  2:casset_package_2
receSerial_msg::receSerial_msg(QObject *parent) : QObject(parent)
{

    qDebug()<<" the thread begin "<<endl;
    isTranslateFlag = true;
    serial = NULL;
    clearFlag = false;
    is_pileUp_flag = true;

    historgramVec_2048.resize(2048);    //2048个数据
    historgramVec_4096.resize(4096);   //4096个数据


}

void receSerial_msg::openOrCloseSerial_slot(bool flag)
{
    if(NULL == serial)
    {
        serial = new QSerialPort(this);
        connect(serial, SIGNAL(readyRead()), this, SLOT(readDataSlot()),Qt::DirectConnection);

    }

    if(true == flag)   //打开串口
    {
        serial->setPortName(currentSettings.name);
        serial->setBaudRate(currentSettings.baudRate);
        serial->setDataBits(currentSettings.dataBits);
        serial->setParity(currentSettings.parity);
        serial->setStopBits(currentSettings.stopBits);
        serial->setFlowControl(currentSettings.flowControl);
        if(serial->open(QIODevice::ReadWrite))
        {
            qDebug()<<"serial open success!!";
            emit returnLinkInfo_signal("open",true);
        }else{
            qDebug()<<"serial open error";
            emit returnLinkInfo_signal("open",false);
        }
    }else              //关闭串口
    {
        serial->close();
        emit returnLinkInfo_signal("close",true);
        m_buffer.clear();
    }

}


//!
//! \brief receSerial_msg::readDataSlot  串口接收数据，并对命令进行解析 （暂时约定传输数据为小端模式）
//!   1、首先接收到字符串 以后把它转换成16进制的字符串类型，本次处理时去掉空格；
//!   2、将接收到的数据添加到成员变量m_buffer中；
//!   3、根据长度字段将单个命令提取出来
//!   4、对单个命令进行解析
//!   5、命令解析完毕后，从m_buffer中剔除到这个命令，并更新totallen
void receSerial_msg::readDataSlot()
{
    QByteArray temp = serial->readAll();
    QString strHex;//16进制数据

    if (!temp.isEmpty())
    {
        QDataStream out(&temp,QIODevice::ReadWrite);
        while (!out.atEnd())
        {
            qint8 outChar=0;
            out>>outChar;
            QString str=QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));

            if (str.length()>1)
            {
                //strHex+=str+" ";
                strHex+=str;
            }
            else
            {
                //strHex+="0"+str+" ";
                strHex+="0"+str;
            }
        }
        strHex = strHex.toUpper();
        //        qDebug()<<" strHex = "<<strHex;
        //        return;

        m_buffer.append(strHex);
        totallen = m_buffer.size();

        if(isTranslateFlag)    //转换成十进制的tof和peak进行显示解析
        {
            while(totallen)
            {
                if(totallen <12)   //单个命令最少要有6个字节 所以长度为12       5A 03 00 01 3A XX
                    return;



                //                /***********其他公司的协议************************/
                //                int indexOf_A55A = m_buffer.indexOf("A55A",0);
                //                if(indexOf_A55A>0)
                //                {
                //                    m_buffer = m_buffer.right(totallen-indexOf_A55A);    //去除多余的头部
                //                    totallen = m_buffer.size();
                //                    if(totallen<12)
                //                        return;
                //                   QByteArray tmpArray  = m_buffer.mid(0,12);
                //                   if(true==CRC16_KC_check(tmpArray))
                //                   {
                //                       int tmpTof_other = tmpArray.mid(4,4).toInt(NULL,16);
                //                       DistanceStr.append(QString::number(tmpTof_other));
                //                       emit showResultMsg_signal(DistanceStr,1);
                //                       DistanceStr.clear();                            //发送完数据清空链表


                //                       m_buffer = m_buffer.right(totallen - 12);
                //                       totallen = m_buffer.size();
                //                   }else
                //                   {
                ////                       qDebug()<<QStringLiteral("其他版本协议校验失败！")<<m_buffer;
                //                       m_buffer = m_buffer.right(totallen-4);    //去除多余的头部
                //                       totallen = m_buffer.size();
                //                   }
                //                }
                //                /*********************************/



                /***********其他公司的协议 科沃斯协议************************/
                //                while(totallen>=8)
                //                {
                //                    int indexOf_5AA5 = m_buffer.indexOf("5AA5",0);
                //                    if(indexOf_5AA5>0) //说明找到了5AA5
                //                    {
                //                        m_buffer = m_buffer.right(totallen - indexOf_5AA5);
                //                        totallen = m_buffer.size();
                //                        if(totallen<8)
                //                        {
                //                           return;
                //                        }else
                //                        {
                //                            m_buffer = m_buffer.right(totallen - 8);
                //                            totallen = m_buffer.size();

                //                        }

                //                    }else
                //                    {
                //                        break;
                //                    }
                //                }
                /*********************************/

                int indexOf5A = m_buffer.indexOf("5A",0);
                if(indexOf5A < 0)  //没有找到5A
                {
                    //                   qDebug()<<QStringLiteral("接收数据有误，不存在5A")<<"index ="<<indexOf5A<<"buffer"<<m_buffer<<endl;
                    m_buffer.clear();
                    totallen = 0;
                    return;
                }else if(indexOf5A>0)  //第一次的时候前面会有冗余数据，删掉
                {
                    m_buffer = m_buffer.right(totallen-indexOf5A);
                    totallen = m_buffer.size();
                    if(totallen <12)
                        return;
                }

//                qDebug()<<"m_buffer = "<<m_buffer;
                //以下数据为5A打头数据
                int pointNum = 0;
                while(totallen>=8)
                {
                    int indexOf_5AA5 = m_buffer.indexOf("5AA5",0);
                    if(indexOf_5AA5==0)   //说明找到了5AA5
                    {
                        pointNum++;
                        QByteArray tmpBuffer = m_buffer.left(8);
                        QByteArray tmpNumArray = m_buffer.mid(4,4);
                        int tmpTof = tmpNumArray.toInt(NULL,16);
                        m_buffer = m_buffer.right(totallen - 8);
                        totallen = m_buffer.size();

                        //显示信息
                        QString single_Data  = QString::number(tmpTof);
                        DistanceStr.append(single_Data);

                        //StatisticData_vector 对1000帧tof数据进行循环存储
                        int statistic_offset = StatisticData_vector.size() -1000;
                        if(statistic_offset >= 0)
                        {
                            StatisticData_vector.erase(StatisticData_vector.begin(),StatisticData_vector.begin() + statistic_offset + 1);
                        }
                        StatisticData_vector.push_back(tmpTof);

                        if(clearFlag)
                        {
                            PlotData_vector.clear();
                            clearFlag = false;
                        }

                        //PlotData_vector 对20000帧tof数据进行循环存储  这个是用来显示tof图
                        int Plot_offset = PlotData_vector.size() - 20000;
                        if(Plot_offset >= 0)
                        {
                            PlotData_vector.erase(PlotData_vector.begin(),PlotData_vector.begin()+Plot_offset + 1);
                        }
                        PlotData_vector.push_back(tmpTof);



                        //50个点后 向主线程发送一次数据
                        if(DistanceStr.length()>50)
                        {
                            showResultMsg_signal(DistanceStr,pointNum);
                            DistanceStr.clear();                            //发送完数据清空链表

                            QString currentTof = QString::number(tmpTof);
                            emit dealedData_signal(currentTof,PlotData_vector,StatisticData_vector);    //发送至主程序，用于显示当前TOf 均值  方差
                        }
                    }else
                    {
                        break;
                    }
                }


                //首先根据长度字段 来提取出整条数据，数据长度不足的话返回
                QString lenStr= m_buffer.mid(6,2) + m_buffer.mid(4,2);
                int dataLen = lenStr.toInt(NULL,16) * 2;       //数据区的长度  这个长度包含一个字节的 地址
                int len = dataLen + 5 * 2;                     //5A 03（命令） 04 00（长度）  + 检验位共5个字节   这个len是单个包的总长度
                if(totallen < len)                            //本次接收不够一个包,返回 等待下次接收
                    return;

                dataLen = dataLen - 2;                         //减去一个字节的 地址   2019-12-10

                //进行和校验
                QString single_Data = m_buffer.left(len);       //single_Data就是单个命令

//                qDebug()<<" single_Data = "<<single_Data;

                if(!msgCheck(single_Data))
                {
                    //                   qDebug()<<QStringLiteral("和校验失败,singleData =")<<single_Data;
                    //                   m_buffer = m_buffer.right(totallen - len);                                                  //一帧处理完毕 减去该帧的长度
                    //                   totallen = m_buffer.size();

                    m_buffer.clear();
                    totallen = 0;
                    return;
                }


                //             qDebug()<<" receive single_Data = "<<single_Data;

                QString returnCmdStr = single_Data.mid(2,2);   //命令标识
                ////////////////////////////////////////////////////////单个命令处理代码块//////////////////////////////////////////////////////////////////////////////////////////
                // 5A 86 01 00 01 xx  MCU开始升级成功
                // 5A 86 01 00 81 XX  MCU开始升级失败
                // 5A 86 01 00 00 xx  MCU开始升级成功
                // 5A 86 01 00 88 XX  MCU开始升级失败
                if("86" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(4,2);     //这个实际是长度
                    if("01" == secCmd)
                    {
                        QString cmdAck = single_Data.mid(8,2);
                        emit AckCmdUpgrade_signal(returnCmdStr,cmdAck);
                    }
                }

                // 5A 87 84 00 AA AA AA AA DD...DD XX    MCU升级过程中的命令
                if("87" == returnCmdStr)
                {
                    int singleLen = single_Data.size();
                    QString dataStr = single_Data.right(singleLen - 4*2 );  //减去前面的4个字节之后 为数据区内容
                    //发送到界面进行显示
                    emit AckCmdUpgrade_signal(returnCmdStr,dataStr);
                }

                //写寄存器的应答命令 5A 81 NN NN 01 DD..DD XX
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("01" == secCmd)
                    {
                        QString cmdAck = "00";  //没有意义
                        emit AckCmdRegister_signal(returnCmdStr,cmdAck);
                    }
                }

                //读寄存器应答命令 5A 80 NN nn 01 DD...DD XX
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("01" == secCmd)
                    {
                        QString cmdAck = single_Data.mid(10,dataLen);
                        emit AckCmdRegister_signal(returnCmdStr,cmdAck);
                    }
                }

                //写入出厂设置 应答命令 5A 81 22 00 02 DD.DD XX   接收到说明配置成功
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("02" == secCmd)
                    {
                        QString firstCmd = "8102";
                        QString dataStr= "00";//没有意义
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                //读取出厂设置 应答命令 5A 80 22 00 02 DD.DD  XX
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("02" == secCmd)
                    {
                        QString firstCmd = "8002";
                        QString dataStr = single_Data.mid(10,dataLen);
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                //读取  距离offset 1 校准应答命令 5A 80 07 00 04 DD DD DD DD DD DD XX
                //读取  距离offset 2 校准应答命令 5A 80 0C 00 04 DD DD DD DD DD DD XX   现在只有这一个
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("04" == secCmd)
                    {
                        QString thirdCmd = single_Data.mid(4,2);   //根据长度判断是哪一种校准,此种校准取消
                        QString firstCmd = "8004";
                        QString dataStr = single_Data.mid(10,dataLen);
                        emit AckCmdMain_signal(firstCmd,dataStr);

                        //                       if("07" == thirdCmd)
                        //                       {
                        //                           QString firstCmd = "8004";
                        //                           QString dataStr = single_Data.mid(10,dataLen);
                        //                           emit AckCmdMain_signal(firstCmd,dataStr);

                        //                       }else if("0C" == thirdCmd )
                        //                       {
                        //                           QString firstCmd = "8004";
                        //                           QString dataStr = single_Data.mid(10,dataLen);
                        //                           emit AckCmdMain_signal(firstCmd,dataStr);
                        //                       }

                    }
                }



                //读取恢复出厂设置的应答命令 5A 81 01 00 03 00 XX
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("03" == secCmd)
                    {
                        QString firstCmd = "8103";
                        QString dataStr= "00";//没有意义
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                //读取距离offset校准 1 的应答命令 5A 81 07 00 04 DD DD DD DD DD DD XX
                //读取距离offset校准 2 的应答命令 5A 81 0B 00 04 DD DD DD DD DD DD XX
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("04" == secCmd)
                    {
                        QString thirdCmd = single_Data.mid(4,2);
                        QString firstCmd = "8104";
                        QString dataStr= "07";
                        emit AckCmdMain_signal(firstCmd,dataStr);
                        //                       if("07" == thirdCmd)   //根据长度来判断是第一次校准的返回命令
                        //                       {
                        //                           QString firstCmd = "8104";
                        //                           QString dataStr= "07";
                        //                           emit AckCmdMain_signal(firstCmd,dataStr);
                        //                       }else if("0B" == thirdCmd)
                        //                       {
                        //                           QString firstCmd = "8104";
                        //                           QString dataStr= "0B";
                        //                           emit AckCmdMain_signal(firstCmd,dataStr);
                        //                       }

                    }
                }

                //读取高反应答命令  5A 81 3C 00 05 DD..DD XX
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("05" == secCmd)
                    {
                        QString firstCmd = "8105";
                        QString dataStr = "00";   //没有意义
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }



                //读取设置输出数据的 应答命令 5A 81 01 00 06 DD XX
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("06" == secCmd)
                    {
                        QString firstCmd = "8106";
                        QString dataStr = single_Data.mid(10,2);   //00真实距离 01：LSB
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                //读取单次采集的 应答命令 5A 80 08 00 07 DD.DD XX
                //解析数据  并将数据存入QStringList 当中，发送给主线程以供显示
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    int tmpTof = 0;
                    if("07" == secCmd )
                    {
                        if(dataLen != 8*2)
                        {
                            qDebug()<<QStringLiteral("解析单次采集数据，长度出错, dataLen = ")<<dataLen;
                        }

                        QString dataStr = single_Data.mid(10,dataLen);
                        QString currentSingleData;

                        //16进制数据转化为10进制 然后再转化成字符串
                        QString strTmp = dataStr.mid(2,2) + dataStr.mid(0,2);
                        tmpTof = strTmp.toInt(NULL,16);
                        currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");

                        strTmp = dataStr.mid(6,2) + dataStr.mid(4,2);
                        currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");

                        strTmp = dataStr.mid(10,2) + dataStr.mid(8,2);
                        currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");

                        strTmp = dataStr.mid(14,2) + dataStr.mid(12,2);
                        currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");


                        DistanceStr.append(currentSingleData);          //存放入链表中,供数据区显示
                        showResultMsg_signal(DistanceStr,1);
                        DistanceStr.clear();                            //发送完数据清空链表

                        int tof_int = tmpTof;  //转换为10进制显示 实时TOF的值   显示的第一个峰
                        QString currentTof = QString::number(tof_int);
                        emit dealedData_signal(currentTof,PlotData_vector,StatisticData_vector);    //发送至主程序，用于显示当前TOf 均值  方差
                    }
                }


                //读取 （开启/停止） 连续采集 的应答命令 5A 81 01 00 08 DD..DD XX
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("08" ==secCmd)    //这个暂时不需进行处理
                    {
                        qDebug()<<QStringLiteral("已经接收到连续采集开始/停止返回命令！");

                    }
                }


                //读取连续采集时 模组主动上传的数据 （双峰数据）  5A 03 LL LL 0B DD...DD XX
                if("03" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0B" == secCmd)
                    {
                        QString dataStr = single_Data.mid(10,dataLen);
                        QString currentSingleData;
                        int tmpTof_1,tmpTof_2;

                        int pointNum = 0;

                        for(int i=0; i<dataLen; i+=16)
                        {
                            pointNum += 2;     //每次循坏会有两个点的数据  （因为是双峰）

                            //16进制数据转化为10进制 然后再转化成字符串
                            QString strTmp = dataStr.mid(i+2,2) + dataStr.mid(i+0,2);
                            tmpTof_1 = strTmp.toInt(NULL,16);
                            currentSingleData = QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '));
                            currentSingleData.append("   ");

                            strTmp = dataStr.mid(i+6,2) + dataStr.mid(i+4,2);
                            currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");

                            strTmp = dataStr.mid(i+10,2) + dataStr.mid(i+8,2);
                            tmpTof_2 = strTmp.toInt(NULL,16);
                            currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");

                            strTmp = dataStr.mid(i+14,2) + dataStr.mid(i+12,2);
                            currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");




                            DistanceStr.append(currentSingleData);          //存放入链表中,供数据区显示，一行数据存储在一个QStringList文件当中，方便主界面的显示


                            //StatisticData_vector 对1000帧tof数据进行循环存储
                            //                           int tmpTof_1 = dataStr.mid(i+0,2).toInt(NULL,16);
                            //                           int tmpTof_2 = dataStr.mid(i+4,2).toInt(NULL,16);

                            int statistic_offset = StatisticData_vector.size() -1000;
                            if(statistic_offset >= 0)
                            {
                                StatisticData_vector.erase(StatisticData_vector.begin(),StatisticData_vector.begin() + statistic_offset + 2);
                            }
                            StatisticData_vector.push_back(tmpTof_1);
                            StatisticData_vector.push_back(tmpTof_2);


                            if(clearFlag)
                            {
                                PlotData_vector.clear();
                                clearFlag = false;
                            }

                            //PlotData_vector 对20000帧tof数据进行循环存储
                            int Plot_offset = PlotData_vector.size() - 20000;
                            if(Plot_offset >= 0)
                            {
                                PlotData_vector.erase(PlotData_vector.begin(),PlotData_vector.begin()+Plot_offset + 2);
                            }
                            PlotData_vector.push_back(tmpTof_1);
                            PlotData_vector.push_back(tmpTof_2);




                        }
                        emit showResultMsg_signal(DistanceStr,pointNum);
                        DistanceStr.clear();                            //发送完数据清空链表


                        int tof_int = tmpTof_1;  //转换为10进制显示 实时TOF的值   显示的第一个峰
                        QString currentTof = QString::number(tof_int);
                        emit dealedData_signal(currentTof,PlotData_vector,StatisticData_vector);    //发送至主程序，用于显示当前TOf 均值  方差

                    }
                }

                //读取连续采集时 模组主动上传的数据 （单峰数据）  5A 03 LL LL 0C DD...DD XX
                if("03" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0C" == secCmd)
                    {
                        QString dataStr = single_Data.mid(10,dataLen);
                        QString currentSingleData;
                        float tmpTof = 0;
                        float tmpPeak = 0;
                        int pointNum = 0;   //该包数据点的个数

                        for(int i=0; i<dataLen; i+=8)
                        {
                            pointNum++;

                            //16进制数据转化为10进制 然后再转化成字符串  没有pileUp
                            QString strTmp = dataStr.mid(i+2,2) + dataStr.mid(i+0,2);
                            tmpTof = strTmp.toInt(NULL,16);
                            strTmp = dataStr.mid(i+6,2) + dataStr.mid(i+4,2);
                            tmpPeak = strTmp.toInt(NULL,16);

                            if(least_index>0)    //开始least
                            {
                                leastTofMean_vector.push_back(tmpTof);
                                leastPeakMean_vector.push_back(tmpPeak);
                                int len = leastTofMean_vector.size();
                                if(2000 == len)
                                {
                                    float resTof=0;
                                    float resPeak = 0;
                                    resTof = std::accumulate(std::begin(leastTofMean_vector),std::end(leastTofMean_vector),0.0)/len;
                                    resPeak = std::accumulate(std::begin(leastPeakMean_vector),std::end(leastPeakMean_vector),0.0)/len;
                                    emit sendLeastRes_signal(least_index,resTof,resPeak);
                                    least_index = -1;
                                    leastTofMean_vector.clear();
                                    leastPeakMean_vector.clear();

                                }
                            }






                            currentSingleData = QString::number(tmpTof,'f',2);
                            currentSingleData.append("   ");
                            currentSingleData.append(QString::number(tmpPeak,'f',1)).append("   ");


                            DistanceStr.append(currentSingleData);          //存放入链表中,供数据区显示，一行数据存储在一个QStringList文件当中，方便主界面的显示



                            //StatisticData_vector 对1000帧tof数据进行循环存储
                            int statistic_offset = StatisticData_vector.size() -1000;
                            if(statistic_offset >= 0)
                            {
                                StatisticData_vector.erase(StatisticData_vector.begin(),StatisticData_vector.begin() + statistic_offset + 1);
                            }
                            StatisticData_vector.push_back(tmpTof);

                            if(clearFlag)
                            {
                                PlotData_vector.clear();
                                clearFlag = false;
                            }

                            //PlotData_vector 对20000帧tof数据进行循环存储
                            int Plot_offset = PlotData_vector.size() - 20000;
                            if(Plot_offset >= 0)
                            {
                                PlotData_vector.erase(PlotData_vector.begin(),PlotData_vector.begin()+Plot_offset + 1);
                            }
                            PlotData_vector.push_back(tmpTof);


                        }
                        showResultMsg_signal(DistanceStr,pointNum);
                        DistanceStr.clear();                            //发送完数据清空链表

                        int tof_int = tmpTof;  //转换为10进制显示 实时TOF的值   显示的第一个峰
                        QString currentTof = QString::number(tof_int);
                        emit dealedData_signal(currentTof,PlotData_vector,StatisticData_vector);    //发送至主程序，用于显示当前TOf 均值  方差
                    }
                }



                //读取Historgram的 应答命令 5A 80 01 08 09 DD.DD XX
                //直方图数据解析 横坐标：依次为1536，1024，512，0； 1537，1025，513，1；  ......； 2047,1535,1023,511
                //                     更改 3072,2048,1024,0； 3073，2049，1025，1； .......；4095，3071，2047，1023        --2020:03：23

                //每个字节代表一个数,需要解析到相应的vector中
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("09" == secCmd)
                    {
                        if(dataLen != 2048*2)     //  0800 = 2048
                        {
                            qDebug()<<QStringLiteral("解析4300直方图数据，长度出错, 这里的 dataLen = ")<<dataLen;
                        }
                        QString dataStr = single_Data.mid(10,dataLen);
                        int index = 0;
                        int tmpValue = 0;
                        int maxValue = 0;
                        for(int i=0; i<dataLen; i+=8)    //4个字节为一组
                        {
                            tmpValue = dataStr.mid(i,2).toInt(NULL,16);
                            historgramVec_2048[1536 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            tmpValue = dataStr.mid(i+2,2).toInt(NULL,16);
                            historgramVec_2048[1024 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            tmpValue = dataStr.mid(i+4,2).toInt(NULL,16);
                            historgramVec_2048[512 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            tmpValue = dataStr.mid(i+6,2).toInt(NULL,16);
                            historgramVec_2048[0 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            index++;
                        }

                        //发送给主线程进行显示直方图
                        emit toShowHistogram_signal(historgramVec_2048,maxValue);

                        //发送给主线程 在数据区显示原始数据
                        DistanceStr.append(dataStr);   //原始数据存放入链表中,供数据区显示
                        showResultMsg_signal(DistanceStr,2048);
                        DistanceStr.clear();
                    }
                }


                //读取RowData的应答命令 5A 80 00 10 0A DD.DD XX
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0A" == secCmd)
                    {
                        if(dataLen != 4096*2)
                        {
                            qDebug()<<QStringLiteral("解析RowData数据，长度出错, dataLen = ")<<dataLen;
                        }
                        QString dataStr = single_Data.mid(10,dataLen);
                        //发送给主线程 在数据区显示原始数据
                        DistanceStr.append(dataStr);   //原始数据存放入链表中,供数据区显示
                        showResultMsg_signal(DistanceStr,4096);
                        DistanceStr.clear();
                    }
                }


                //4300读取 单Pixel模式peak值数据
                //               1号     4号     7号   	10号  	13号	    16号
                //               2号     5号     8号	    11号	    14号	    17号
                //               3号     6号  	9号	    12号	    15号 	18号


                //cassset_package_1
                //               0    4     8      12     4  0  12  8
                //               1    5     9      13     5  1  13  9
                //               2    6     10     14     6  2  14  10
                //               3    7     11     15     7  3  15  11


                //CASSET__PACKAGE_2
                //               3    7     11     15
                //               2    6     10     14
                //               1    5     9      13
                //               0    4     8      12


                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0F" == secCmd)
                    {
                        if(0 == read_pixel_flag)      //4300的协议解析
                        {
//                            qDebug()<<" read_pixel_flag = 4300";
                            if(dataLen != 36*2)
                            {
                                qDebug()<<QStringLiteral("解析4300单Pixel模式peak值数据，长度出错, dataLen = ")<<dataLen;
                            }

                            vector<vector<double> > trainX(18,vector<double>(1,0));    //聚类相关

                            int redArray[3][6];   //存储 0 1
                            memset(redArray,0,sizeof(redArray));


                            int srcArray[3][6];   // 存储原始数据
                            memset(redArray,0,sizeof(redArray));



                            // 1  把数据存储到 peak_vec 容器当中， 并将数据存储到k-means算法输入
                            vector<int> peak_vec;
                            QString dataStr = single_Data.mid(10,dataLen);      //36个字节的数据
                            for(int i=0; i<dataStr.length();i+=4)     //获取18个像素的值
                            {
                                QString data_str = dataStr.mid(i+2,2)+dataStr.mid(i,2);
                                int peak_value = data_str.toInt(NULL,16);
                                peak_vec.push_back(peak_value);

                                //k-means 输入
                                int pixelIndex = i/4;
                                trainX[pixelIndex][0] = peak_value;
                            }


                            // 2 做k-means 聚类算法 ，并可以将分类得到的结果 存储到  redResult_vec当中
                            vector<Cluster> clusters_out = k_means(trainX, 2, 100);
                            qDebug()<<"clusters_out.size = "<<clusters_out.size()<<" ";
                            qDebug()<<"center1 = "<<clusters_out[0].centroid[0];
                            qDebug()<<"center2 = "<<clusters_out[1].centroid[0];
                            float centor_1 = clusters_out[0].centroid[0];
                            float centor_2 = clusters_out[1].centroid[0];
                            vector<int> redResult_vec;
                            if(centor_1>centor_2)
                            {
                                for(int i=0; i<clusters_out[0].samples.size(); i++)
                                {
                                    uint c = clusters_out[0].samples[i];

                                    redResult_vec.push_back(trainX[c][0]);
                                }
                            }else
                            {
                                for(int i=0; i<clusters_out[1].samples.size(); i++)
                                {
                                    uint c = clusters_out[1].samples[i];
                                    redResult_vec.push_back(trainX[c][0]);
                                }
                            }

//                            for(int i=0; i<redResult_vec.size(); i++)
//                            {
//                                qDebug()<<"i="<<i<<"   res="<<redResult_vec[i];
//                            }





                            // 3 显示数据  将光斑的值 标记成为红色，显示到界面上面  ； 存储原始数据到 srcArray
                            QString currentSingleData;
                            //三行数据  分别写入到列表当中
                            currentSingleData.clear();
                            for(int i=0; i<18; i+=3)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));

                                for(int k=0; k<redResult_vec.size();k++)
                                {
                                    if(redResult_vec[k] == tmp_int)
                                    {
                                         tmp = "<font size=\"3\" color=red> " +tmp  + "</font> ";
                                         redArray[0][i/3] = 1;
                                    }
                                }


                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                                srcArray[0][i/3] = tmp_int;
                            }


                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();
                            for(int i=1; i<18; i+=3)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));

                                for(int k=0; k<redResult_vec.size();k++)
                                {
                                    if(redResult_vec[k] == tmp_int)
                                    {
                                         tmp = "<font size=\"3\" color=red>" +tmp  + "</font> ";
                                         redArray[1][i/3] = 1;
                                    }
                                }
                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                                srcArray[1][i/3] = tmp_int;

                            }
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();
                            for(int i=2; i<18; i+=3)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                for(int k=0; k<redResult_vec.size();k++)
                                {
                                    if(redResult_vec[k] == tmp_int)
                                    {
                                         tmp = "<font size=\"3\" color=red> " +tmp  + "</font> ";
                                         redArray[2][i/3] = 1;
                                    }
                                }
                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                                srcArray[2][i/3] = tmp_int;

                            }
                            DistanceStr.append(currentSingleData);
                            DistanceStr.append("  ");
                            showResultMsg_signal(DistanceStr,0);   //发送到主线程以供界面显示
                            DistanceStr.clear();                   //发送完毕后清空字符队列

                            //以下为判断是否为有效数据的方法
                            std::cout<<"here is the array!"<<std::endl;
                            for(int i=0;i<3;i++)
                            {
                                for(int j=0;j<6;j++)
                                {
                                  std::cout<<srcArray[i][j]<<"  ";
                                }
                                std::cout<<endl;
                            }


                            bool isRight_flag = false;   //默认未摆正到正中心

                            //一 、 以下为符合要求的六种情况
                            //1 第一种情况
                            if((1==redArray[0][1]) && (1==redArray[0][2]) && (1==redArray[1][1]) && (1==redArray[1][2]))
                            {
                                isRight_flag = true;
                            }
                            //2 第二种情况
                            if((1==redArray[1][1]) && (1==redArray[1][2]) && (1==redArray[2][1]) && (1==redArray[2][2]))
                            {
                                isRight_flag = true;
                            }
                            //3 第三种情况
                            if((1==redArray[0][2]) && (1==redArray[0][3]) && (1==redArray[1][2]) && (1==redArray[1][3]))
                            {
                                isRight_flag = true;
                            }
                            //4 第四种情况
                            if((1==redArray[1][2]) && (1==redArray[1][3]) && (1==redArray[2][2]) && (1==redArray[2][3]))
                            {
                                isRight_flag = true;
                            }
                            //5 第二种情况
                            if((1==redArray[0][3]) && (1==redArray[0][4]) && (1==redArray[1][3]) && (1==redArray[1][4]))
                            {
                                isRight_flag = true;
                            }
                            //6 第二种情况
                            if((1==redArray[1][3]) && (1==redArray[1][4]) && (1==redArray[2][3]) && (1==redArray[2][4]))
                            {
                                isRight_flag = true;
                            }

                            qDebug()<<" isRight_flag = "<<isRight_flag;
                            QString warnMsg;
                            if(!isRight_flag)    //二、 如果光斑不符合要求，则对光斑的位置进行判断
                            {
                                warnMsg = QStringLiteral("光斑偏离中心位置！");


                                // add
                                // A、 如果都小于15  说明没有光斑
                                bool haveGuangban_flag = false;
                                for(int i=0;i<3;i++)
                                {
                                    for(int j=0;j<6;j++)
                                    {
                                       if(srcArray[i][j]>15)
                                       {
                                           haveGuangban_flag = true;
                                       }
                                    }
                                }


                                if(false == haveGuangban_flag)   //像素上根本就没有光斑
                                {
                                    warnMsg = QStringLiteral("未发现光斑！");

                                }else   // 有光斑， 根据最大像素的位置来确定光斑的偏移的位置
                                {
                                    int max =-100;
                                    int row = 0;
                                    int col = 0;
                                    for(int i=0;i<3;i++)
                                    {
                                        for(int j=0;j<6;j++)
                                        {
                                           if(srcArray[i][j]>max)
                                           {
                                               max = srcArray[i][j];
                                               row = i;
                                               col = j;
                                           }
                                        }
                                    }

                                    qDebug()<<" pixel offset row="<<row<<"  col="<<col;
                                    if(row<1) //光斑上上面
                                    {
                                        warnMsg = QStringLiteral("光斑在上方！");
                                    }
                                    if(row>1)  //光斑在下面
                                    {
                                        warnMsg = QStringLiteral("光斑在下方！");
                                    }
                                    if(col<2)  //光斑在左边
                                    {
                                        warnMsg = QStringLiteral("光斑在左侧！");
                                    }
                                    if(col>3)  //光斑在右边
                                    {
                                        warnMsg = QStringLiteral("光斑在右侧！");
                                    }


                                }





                            }

//                            emit AckSinglePixelPosition_signal(isRight_flag,warnMsg);



                        }else if(1 == read_pixel_flag)      //casset_package_1的封装协议解析
                        {
                            if(dataLen != 30*2)
                            {
                                qDebug()<<QStringLiteral("解析casset_apckage_1单Pixel模式peak值数据，长度出错, dataLen = ")<<dataLen;
                            }

                            vector<int> peak_vec;
                            QString dataStr = single_Data.mid(10,dataLen);      //30个字节的数据
                            for(int i=0; i<dataStr.length();i+=4)             //获取16个像素的值
                            {
                                QString data_str = dataStr.mid(i+2,2)+dataStr.mid(i,2);
                                int peak_value = data_str.toInt(NULL,16);
                                peak_vec.push_back(peak_value);

                            }

                            QString currentSingleData;

                            //三行数据  分别写入到列表当中
                            currentSingleData.clear();

                            QString strTmp[4];
                            int tmpIndex = 0;
                            for(int i=0; i<15; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                strTmp[tmpIndex] = tmp+"   ";
                                tmpIndex++;
                                //                               currentSingleData.append(tmp);
                                //                               currentSingleData.append("   ");

                            }
                            currentSingleData.append(strTmp[1]).append(strTmp[0]).append(strTmp[3]).append(strTmp[2]);
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();
                            tmpIndex = 0;
                            for(int i=1; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                strTmp[tmpIndex] = tmp+"   ";
                                tmpIndex++;
                                //                               currentSingleData.append(tmp);
                                //                               currentSingleData.append("   ");

                            }
                            currentSingleData.append(strTmp[1]).append(strTmp[0]).append(strTmp[3]).append(strTmp[2]);
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();

                            tmpIndex = 0;
                            for(int i=2; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                strTmp[tmpIndex] = tmp+"   ";
                                tmpIndex++;
                                //                               currentSingleData.append(tmp);
                                //                               currentSingleData.append("   ");

                            }
                            currentSingleData.append(strTmp[1]).append(strTmp[0]).append(strTmp[3]).append(strTmp[2]);
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();

                            tmpIndex = 0;
                            for(int i=3; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                strTmp[tmpIndex] = tmp+"   ";
                                tmpIndex++;
                                //                               currentSingleData.append(tmp);
                                //                               currentSingleData.append("   ");

                            }
                            currentSingleData.append(strTmp[1]).append(strTmp[0]).append(strTmp[3]).append(strTmp[2]);
                            DistanceStr.append(currentSingleData);
                            DistanceStr.append("  ");
                            showResultMsg_signal(DistanceStr,0);   //发送到主线程以供界面显示
                            DistanceStr.clear();                   //发送完毕后清空字符队列
                        }else if(2 == read_pixel_flag)      //casset_package_2的封装协议解析
                        {
                            if(dataLen != 30*2)
                            {
                                qDebug()<<QStringLiteral("解析casset_apckage_1单Pixel模式peak值数据，长度出错, dataLen = ")<<dataLen;
                            }

                            vector<int> peak_vec;
                            QString dataStr = single_Data.mid(10,dataLen);      //30个字节的数据
                            for(int i=0; i<dataStr.length();i+=4)             //获取16个像素的值
                            {
                                QString data_str = dataStr.mid(i+2,2)+dataStr.mid(i,2);
                                int peak_value = data_str.toInt(NULL,16);
                                peak_vec.push_back(peak_value);

                            }

                            QString currentSingleData;

                            //三行数据  分别写入到列表当中
                            currentSingleData.clear();
                            for(int i=3; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                            }
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();
                            for(int i=2; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                            }
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();
                            for(int i=1; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                            }
                            DistanceStr.append(currentSingleData);
                            currentSingleData.clear();
                            for(int i=0; i<16; i+=4)
                            {
                                int tmp_int = peak_vec[i];
                                QString tmp = QString("%1").arg(tmp_int,5,10,QLatin1Char(' '));
                                currentSingleData.append(tmp);
                                currentSingleData.append("   ");

                            }
                            DistanceStr.append(currentSingleData);
                            DistanceStr.append("  ");
                            showResultMsg_signal(DistanceStr,0);   //发送到主线程以供界面显示
                            DistanceStr.clear();                   //发送完毕后清空字符队列
                        }

                    }
                }


                //直接读寄存器相关
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0D"== secCmd)
                    {
                        QString firstCmd = "800D";
                        QString dataStr = single_Data.mid(10,2);   //00真实距离 01：LSB
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                //直接写寄存器
                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0D" == secCmd)
                    {
                        QString firstCmd= "810D";
                        QString dataStr = "00";   //此参数暂时无意义
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                //读取Historgram的 应答命令 5A 80 01 08 09 DD.DD XX
                //直方图数据解析 横坐标：依次为1536，1024，512，0； 1537，1025，513，1；  ......； 2047,1535,1023,511
                //                     更改 3072,2048,1024,0； 3073，2049，1025，1； .......；4095，3071，2047，1023        --2020:03：23

                //每个字节代表一个数,需要解析到相应的vector中
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("0E" == secCmd)
                    {
                        if(dataLen != 4096*2)     //  0800 = 2048
                        {
                            qDebug()<<QStringLiteral("解析CASSET直方图数据, 这里的 dataLen = ")<<dataLen;
                        }
                        QString dataStr = single_Data.mid(10,dataLen);
                        int index = 0;
                        int tmpValue = 0;
                        int maxValue = 0;
                        for(int i=0; i<dataLen; i+=8)    //4个字节为一组
                        {
                            tmpValue = dataStr.mid(i,2).toInt(NULL,16);
                            historgramVec_4096[3072 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            tmpValue = dataStr.mid(i+2,2).toInt(NULL,16);
                            historgramVec_4096[2048 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            tmpValue = dataStr.mid(i+4,2).toInt(NULL,16);
                            historgramVec_4096[1024 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            tmpValue = dataStr.mid(i+6,2).toInt(NULL,16);
                            historgramVec_4096[0 + index] = tmpValue;
                            maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                            index++;
                        }

                        //发送给主线程进行显示直方图
                        emit toShowHistogram_4096_signal(historgramVec_4096,maxValue);

                        //发送给主线程 在数据区显示原始数据
                        DistanceStr.append(dataStr);   //原始数据存放入链表中,供数据区显示
                        showResultMsg_signal(DistanceStr,4096);
                        DistanceStr.clear();
                    }

                }


                //读取Delay LINE信息
                //5A 80 19 00 DDDD(24 BYTE)
                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("11" == secCmd)
                    {
                        if(dataLen != 50*2)
                        {
                            qDebug()<<QStringLiteral("解析Delay Line数据出错, 这里的 dataLen = ")<<dataLen;
                        }
                        //  reg_int  :  testResult
                        QString dataStr = single_Data.mid(10,dataLen);
                        QString reg_int = dataStr.mid(0,2);
                        QString str1 = QStringLiteral("寄存器(0x):") + reg_int;
                        QString reg_val = dataStr.mid(2,2);
                        QString str2 = QStringLiteral("   测试结果(0x)：")+ reg_val;
                        str1.append(str2);
                        DistanceStr.append(str1);

                        // 测试结果值
                        QString currentSingleData_tof;
                        QString currentSingleData_peak;
                        QString tmpStr_tof,resStr_tof,tmpStr_peak,resStr_peak;
                        int tmpValue_tof,tmpValue_peak;
                        for(int i=0; i<8*8; i+=8 )
                        {
                            tmpStr_tof = dataStr.mid(4+i,4);
                            resStr_tof = tmpStr_tof.mid(2,2) + tmpStr_tof.mid(0,2);
                            tmpValue_tof = resStr_tof.toInt(NULL,16);

                            tmpStr_peak = dataStr.mid(4+i+4,4);
                            resStr_peak = tmpStr_peak.mid(2,2)+ tmpStr_peak.mid(0,2);
                            tmpValue_peak = resStr_peak.toInt(NULL,16);

                            currentSingleData_tof.append(QString("%1").arg(tmpValue_tof,5,10,QChar(' '))).append("  ");
                            currentSingleData_peak.append(QString("%1").arg(tmpValue_peak,5,10,QChar(' '))).append("  ");

                            //                           currentSingleData_tof.append(QString::number(tmpValue_tof)).append("  ");
                            //                           currentSingleData_peak.append(QString::number(tmpValue_peak)).append("  ");

                        }
                        DistanceStr.append(currentSingleData_tof);
                        DistanceStr.append(currentSingleData_peak);
                        DistanceStr.append("  ");
                        showResultMsg_signal(DistanceStr,0);   //发送到主线程以供界面显示
                        DistanceStr.clear();
                    }
                }



                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("12" == secCmd)
                    {
                        QString firstCmd= "8112";
                        QString dataStr = "00";   //此参数暂时无意义
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                if("80" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("12" == secCmd)
                    {
                        QString firstCmd = "8012";
                        QString dataStr = single_Data.mid(10,dataLen);
                        emit AckCmdMain_signal(firstCmd,dataStr);

                    }
                }

                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("13" == secCmd)
                    {

                        qDebug()<<" return command ";
                        QString firstCmd= "8113";
                        QString dataStr = single_Data.mid(10,dataLen);
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }
                }

                if("81" == returnCmdStr)
                {
                    QString secCmd = single_Data.mid(8,2);
                    if("14" == secCmd)
                    {
                        QString firstCmd = "8114";
                        QString dataStr = single_Data.mid(10,2);
                        emit AckCmdMain_signal(firstCmd,dataStr);
                    }

                }




                ////////////////////////////////////////////////////////单个命令处理代码块//////////////////////////////////////////////////////////////////////////////////////////
                m_buffer = m_buffer.right(totallen - len);                                                  //一帧处理完毕 减去该帧的长度
                totallen = m_buffer.size();
                //         qDebug()<<"total ="<<totallen<<endl;
            }
        }
        else   //直接打印16进制的数据
        {
            DistanceStr.append(m_buffer);
            emit showResultMsg_signal(DistanceStr,0);                                                   //发送用于界面显示的数据  显示TOF或者PEAK 或者16进制数据
            DistanceStr.clear();                                                                      //清空
            m_buffer.clear();
            totallen = m_buffer.size();
        }

    }
}



//字节校验 从第二个字节开始，到倒数第二个字节 求和并取反 判断是否与最后一个字节相等
bool receSerial_msg::msgCheck(QString msg)
{
    int len = msg.length();
    int i=2;
    int num = 0;
    for(;i<len-2;i+=2)
    {
        num += msg.mid(i,2).toInt(NULL,16);
    }

    int checkNum = msg.mid(i,2).toInt(NULL,16);
    if(quint8(~num) == checkNum)
    {
        return true;
    }else
    {
        return false;
    }
}


//!
//! \brief receSerial_msg::sendSerialSlot
//! \param sendCmdStr: 不带校验位的 QString 类型的字符串  QString cmdStr = "5A 03 04 00 0A 00 88 13 ";
//! 1、添加校验位
//! 2、转换为字节数,存储在QByteArray
//! 3、向串口发送数据
//! 4、清空缓存区
void receSerial_msg::sendSerialSlot(QString sendCmdStr)
{

    QByteArray sendArray;
    QString wholeStr;
    wholeStr = addCheck(sendCmdStr);     //添加校验
    sendArray = StringToByte(wholeStr);  //转换成字节数据
    if(serial!=NULL && serial->isWritable())
    {
        totallen = 0;
        m_buffer.clear();
        serial->write(sendArray);            //串口发送字节数据
        serial->flush();                     //清空缓冲区
    }
    else
    {
        qDebug()<<"can not write right now ";
    }

}


//为命令添加校验位
QString receSerial_msg::addCheck(QString str)
{
    "5A 06 00 01 01 ";
    //    str = "5A 07 14 00 0800a180 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00";

    QString tmpStr = str;
    tmpStr.replace(" ","");
    int len = tmpStr.length();
    int sum = 0;
    for(int i = 2; i<len; i+=2)
    {
        sum += tmpStr.mid(i,2).toInt(NULL,16);
    }
    quint8 checkValue = (quint8)(~sum);
    QString resStr = str.append(QString("%1").arg(checkValue,2,16,QLatin1Char('0')));

    //    qDebug()<<"addCheck = "<<resStr;
    return resStr;
}


//!
//! \brief receSerial_msg::StringToByte
//! \return
//! 将QString QByteArray
QByteArray receSerial_msg::StringToByte(QString str)
{
    QByteArray byte_arr;
    bool ok;
    //如果str的长度 不是2的倍数  那么直接返回空
    //    if(str.size()%2!=0){
    //        qDebug()<<"is not twice "<<endl;
    //        return QByteArray::fromHex("字符串不符合标准");
    //    }

    str = str.replace(" ","");    //去掉空格键
    int len=str.size();
    for(int i=0;i<len;i+=2){
        byte_arr.append(char(str.mid(i,2).toUShort(&ok,16)));
    }
    //    qDebug()<<" byte_arr's len = "<<byte_arr.size()<<"    "<<byte_arr;

    //下面这段程序是将Byte 转化为QString的类型，将结果输出 对比发出的数据是否正确
    QDataStream out(&byte_arr,QIODevice::ReadWrite);
    QString strHex;
    while (!out.atEnd())
    {
        qint8 outChar=0;
        out>>outChar;
        QString str=QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));

        if (str.length()>1)
        {
            strHex+=str+" ";
        }
        else
        {
            strHex+="0"+str+" ";
        }
    }
    strHex = strHex.toUpper();
    qDebug()<<QStringLiteral("发送的原始数据为：")<<strHex<<"   len="<< strHex.length()/3<<endl;
    return byte_arr;
}









//!
//! \brief DealUsb_msg::pileUp_calibration
//! \param srcTof
//! \param peak
//! \return
//!利用Peak值线性外插法可得对应校正量ΔTOF (Unit: mm)
float receSerial_msg::pileUp_calibration(int srcTof,float peak)
{
    //casset pileUp参数更新
    float cal[] = {0,18.1575422735644,21.9516416845111,26.5250123823675,33.2185699762792,43.2514600367095,58.7828400399069,88.8759515570934,92.8966119455117,96.4577679782904,101.705719237435,105.876097560976,110.808458120783,117.097666666667,123.648721855426,130.332472896231,138.397357723577,145.641474935243,155.035546938116,162.867552929591,171.384641012827,181.655995934959,191.951244286440,202.692046556741,217.299101847145,230.800833333333,250.601909307876,266.857119422572,287.539699195523,305.126563281641,328.258676146944,348.650862068966,368.383249581240,390.898653314917,415.542261611686,446.582666666667,489.524078431373,535.656653746770,600};
    float val[] = {74,73.9233116524325,72.5295511777099,76.1650343239396,74.4531666722966,63.5330820290539,54.1551179913535,46.8833833563948,44.4630970834773,41.8329498812762,37.0950704332808,32.3011780975711,30.8561473589072,28.1126593500135,27.0352663788883,28.4278951987796,29.9944213414847,32.0993373762231,33.9005754726289,33.8478441162089,34.3842059970061,29.6169806402442,23.2917252412352,14.6047011639151,1.76783899339505,-4.82199899999103,-8.71394272075049,-6.93507012793973,-4.61974102832141,-1.79615447723391,-2.72094961909891,-2.72225031499276,-3.41978160804357,-13.4944476346688,-33.3391450024642,-56.4176570000019,-67.6015647058833,-77.6965628875963,-78};
    float begin_tof,end_tof,offset_start,offset_end;
    float resTof = 0;
    float bias_tof = 0;

    int len = sizeof(cal)/sizeof(cal[0]);

    for(int i=0; i<len-1; i++)
    {
        if(peak>=cal[i] && peak<cal[i+1])
        {
            begin_tof = cal[i];
            end_tof = cal[1+i];
            offset_start = val[i];
            offset_end = val[1+i];
            bias_tof = (peak-begin_tof)*(offset_end-offset_start)/(end_tof-begin_tof) + offset_start;
            resTof = srcTof - bias_tof;
            return  resTof;
        }
    }
    return srcTof - val[len-1];

}




//!
//! \brief receSerial_msg::start_num_leastSlot
//! \param index
//! 开始哪个距离颜色的矫正
void receSerial_msg::start_num_leastSlot(int index)
{
    leastTofMean_vector.clear();
    leastPeakMean_vector.clear();
    least_index = index;
}

/******** 单pixel 聚类相关 ******************/

double receSerial_msg::cal_distance(vector<double> a, vector<double> b)
{
    uint da = a.size();
    uint db = b.size();
    if (da != db) cerr << "Dimensions of two vectors must be same!!\n";
    double val = 0.0;
    for (uint i = 0; i < da; i++)
    {
        val += pow((a[i] - b[i]), 2);
    }
    return pow(val, 0.5);
}

vector<Cluster> receSerial_msg::k_means(vector<vector<double> > trainX, uint k, uint maxepoches)
{
    const uint row_num = trainX.size();
    const uint col_num = trainX[0].size();

    /*初始化聚类中心*/
    vector<Cluster> clusters(k);
    uint seed = (uint)time(NULL);
    for (uint i = 0; i < k; i++)
    {
        srand(seed);
        int c = rand() % row_num;
        clusters[i].centroid = trainX[c];
        seed = rand();
    }

    /*多次迭代直至收敛，本次试验迭代100次*/
    for (uint it = 0; it < maxepoches; it++)
    {
        /*每一次重新计算样本点所属类别之前，清空原来样本点信息*/
        for (uint i = 0; i < k; i++)
        {
            clusters[i].samples.clear();
        }
        /*求出每个样本点距应该属于哪一个聚类*/
        for (uint j = 0; j < row_num; j++)
        {
            /*都初始化属于第0个聚类*/
            uint c = 0;
            double min_distance = cal_distance(trainX[j],clusters[c].centroid);
            for (uint i = 1; i < k; i++)
            {
                double distance = cal_distance(trainX[j], clusters[i].centroid);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    c = i;
                }
            }
            clusters[c].samples.push_back(j);
        }

        /*更新聚类中心*/
        for (uint i = 0; i < k; i++)
        {
            vector<double> val(col_num, 0.0);
            for (uint j = 0; j < clusters[i].samples.size(); j++)
            {
                uint sample = clusters[i].samples[j];
                for (uint d = 0; d < col_num; d++)
                {
                    val[d] += trainX[sample][d];
                    if (j == clusters[i].samples.size() - 1)
                        clusters[i].centroid[d] = val[d] / clusters[i].samples.size();
                }
            }
        }
    }
    return clusters;
}


