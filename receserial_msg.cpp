#include "receserial_msg.h"

extern Settings currentSettings;
receSerial_msg::receSerial_msg(QObject *parent) : QObject(parent)
{

    qDebug()<<" the thread begin "<<endl;
    isTranslateFlag = true;
    serial = NULL;
    clearFlag = false;

    historgramVec.resize(2048);    //2048个数据


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
        int totallen = m_buffer.size();

        if(isTranslateFlag)    //转换成十进制的tof和peak进行显示解析
        {
            while(totallen)
            {
                if(totallen <12)   //单个命令最少要有6个字节 所以长度为12       5A 03 00 01 3A XX
                    return;

               int indexOf5A = m_buffer.indexOf("5A",0);
               if(indexOf5A < 0)  //没有找到5A
               {
                   qDebug()<<QString::fromUtf8("接收数据有误，不存在5A")<<"index ="<<indexOf5A<<"buffer"<<m_buffer<<endl;
                   return;
               }else if(indexOf5A>0)  //第一次的时候前面会有冗余数据，删掉
               {
                   m_buffer = m_buffer.right(totallen-indexOf5A);
                   totallen = m_buffer.size();
                   if(totallen <12)
                       return;
               }

               //以下数据为5A打头数据
               //首先根据长度字段 来提取出整条数据，数据长度不足的话返回
               QString lenStr= m_buffer.mid(6,2) + m_buffer.mid(4,2);
               int dataLen = lenStr.toInt(NULL,16) * 2;       //数据区的长度  这个长度包含一个字节的 地址
               int len = dataLen + 5 * 2;                     //5A 03（命令） 04 00（长度）  + 检验位共5个字节   这个len是单个包的总长度
               if(totallen < len)                            //本次接收不够一个包,返回 等待下次接收
                   return;

               dataLen = dataLen - 2;                         //减去一个字节的 地址   2019-12-10

               //进行和校验
               QString single_Data = m_buffer.left(len);       //single_Data就是单个命令
               if(!msgCheck(single_Data))
               {
                   qDebug()<<QStringLiteral("和校验失败,singleData =")<<single_Data;
                   m_buffer = m_buffer.right(totallen - len);                                                  //一帧处理完毕 减去该帧的长度
                   totallen = m_buffer.size();
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
               //读取  距离offset 2 校准应答命令 5A 80 0B 00 04 DD DD DD DD DD DD XX
               if("80" == returnCmdStr)
               {
                   QString secCmd = single_Data.mid(8,2);
                   if("04" == secCmd)
                   {
                       QString thirdCmd = single_Data.mid(4,2);   //根据长度判断是哪一种校准
                       if("07" == thirdCmd)
                       {
                           QString firstCmd = "8004";
                           QString dataStr = single_Data.mid(10,dataLen);
                           emit AckCmdMain_signal(firstCmd,dataStr);

                       }else if("0B" == thirdCmd )
                       {
                           QString firstCmd = "8004";
                           QString dataStr = single_Data.mid(10,dataLen);
                           emit AckCmdMain_signal(firstCmd,dataStr);
                       }

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
                       if("07" == thirdCmd)   //根据长度来判断是第一次校准的返回命令
                       {
                           QString firstCmd = "8104";
                           QString dataStr= "07";
                           emit AckCmdMain_signal(firstCmd,dataStr);
                       }else if("0B" == thirdCmd)
                       {
                           QString firstCmd = "8104";
                           QString dataStr= "0B";
                           emit AckCmdMain_signal(firstCmd,dataStr);
                       }

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
                       showResultMsg_signal(DistanceStr);
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

                       for(int i=0; i<dataLen; i+=16)
                       {
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
                       showResultMsg_signal(DistanceStr);
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
                       int tmpTof = 0;

                       for(int i=0; i<dataLen; i+=8)
                       {
                           //16进制数据转化为10进制 然后再转化成字符串
                           QString strTmp = dataStr.mid(i+2,2) + dataStr.mid(i+0,2);
                           tmpTof = strTmp.toInt(NULL,16);
                           currentSingleData = QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '));
                           currentSingleData.append("   ");


                           strTmp = dataStr.mid(i+6,2) + dataStr.mid(i+4,2);
                           currentSingleData.append(QString("%1").arg(strTmp.toInt(NULL,16),5,10,QLatin1Char(' '))).append("   ");

                           DistanceStr.append(currentSingleData);          //存放入链表中,供数据区显示，一行数据存储在一个QStringList文件当中，方便主界面的显示



                           //StatisticData_vector 对1000帧tof数据进行循环存储
//                           int tmpTof = dataStr.mid(i+0,2).toInt(NULL,16);

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
                       showResultMsg_signal(DistanceStr);
                       DistanceStr.clear();                            //发送完数据清空链表

                       int tof_int = tmpTof;  //转换为10进制显示 实时TOF的值   显示的第一个峰
                       QString currentTof = QString::number(tof_int);
                       emit dealedData_signal(currentTof,PlotData_vector,StatisticData_vector);    //发送至主程序，用于显示当前TOf 均值  方差
                   }
               }



               //读取Historgram的 应答命令 5A 80 01 08 09 DD.DD XX
               //直方图数据解析 横坐标：依次为1536，1024，512，0；1537，1025，513，1；  ......；2047,1535,1023,511
               //每个字节代表一个数,需要解析到相应的vector中
               if("80" == returnCmdStr)
               {
                   QString secCmd = single_Data.mid(8,2);
                   if("09" == secCmd)
                   {
                       if(dataLen != 2048*2)     //  0800 = 2048
                       {
                           qDebug()<<QStringLiteral("解析直方图数据，长度出错,  dataLen = ")<<dataLen;
                       }
                       QString dataStr = single_Data.mid(10,dataLen);
                       int index = 0;
                       int tmpValue = 0;
                       int maxValue = 0;
                       for(int i=0; i<dataLen; i+=8)    //4个字节为一组
                       {
                           tmpValue = dataStr.mid(i,2).toInt(NULL,16);
                           historgramVec[1536 + index] = tmpValue;
                           maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                           tmpValue = dataStr.mid(i+2,2).toInt(NULL,16);
                           historgramVec[1024 + index] = tmpValue;
                           maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                           tmpValue = dataStr.mid(i+4,2).toInt(NULL,16);
                           historgramVec[512 + index] = tmpValue;
                           maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                           tmpValue = dataStr.mid(i+6,2).toInt(NULL,16);
                           historgramVec[0 + index] = tmpValue;
                           maxValue = tmpValue>maxValue ? tmpValue:maxValue;

                           index++;
                       }

                       //发送给主线程进行显示直方图
                       emit toShowHistogram_signal(historgramVec,maxValue);

                       //发送给主线程 在数据区显示原始数据
                       DistanceStr.append(dataStr);   //原始数据存放入链表中,供数据区显示
                       showResultMsg_signal(DistanceStr);
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
                       showResultMsg_signal(DistanceStr);
                       DistanceStr.clear();
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
                emit showResultMsg_signal(DistanceStr);                                                   //发送用于界面显示的数据  显示TOF或者PEAK 或者16进制数据
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




