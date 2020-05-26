#include "autoserial_msg.h"

extern Settings currentSettings_auto;

autoSerial_msg::autoSerial_msg(QObject *parent) : QObject(parent)
{
    qDebug()<<"autoSerial_msg::autoSerial_msg(QObject *parent) start";
    serial = NULL;
    mArrive_Timer = NULL;
    mfuwei_Timer = NULL;
    isTranslateFlag = true;
    totallen = 0;

    receFlagInt = 0;
    m_buffer.clear();

    isArrived_flag = false;
    isFuwei = false;

}


void autoSerial_msg::openOrCloseSerialAuto_slot(bool flag)
{
    if(NULL == serial)
    {
        serial = new QSerialPort(this);
        connect(serial, SIGNAL(readyRead()), this, SLOT(readDataSlot()),Qt::DirectConnection);
        mArrive_Timer = new QTimer;
        mfuwei_Timer = new QTimer;
        sendthrPoint_timer = new QTimer;
        connect(mArrive_Timer,SIGNAL(timeout()),this,SLOT(mArrive_Timer_slot()));
        connect(mfuwei_Timer,SIGNAL(timeout()),this,SLOT(mfuwei_Timer_slot()));
        connect(sendthrPoint_timer,SIGNAL(timeout()),this,SLOT(sendthrPoint_timer_slot()));


    }

    if(true == flag)   //打开串口
    {
        serial->setPortName(currentSettings_auto.name);
        serial->setBaudRate(currentSettings_auto.baudRate);
        serial->setDataBits(currentSettings_auto.dataBits);
        serial->setParity(currentSettings_auto.parity);
        serial->setStopBits(currentSettings_auto.stopBits);
        serial->setFlowControl(currentSettings_auto.flowControl);
        if(serial->open(QIODevice::ReadWrite))
        {
            qDebug()<<"serial open success!!";
            emit returnLinkInfoAuto_signal("open",true);
        }else{
            qDebug()<<"serial open error";
            emit returnLinkInfoAuto_signal("open",false);
        }
    }else              //关闭串口
    {
        serial->close();
        emit returnLinkInfoAuto_signal("close",true);
        m_buffer.clear();
    }
}

/**
*@date 2020-04-30
*@brief:
*/
void autoSerial_msg::readDataSlot()
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
                strHex+=str;
            }
            else
            {
                strHex+="0"+str;
            }
        }
        strHex = strHex.toUpper();
        qDebug()<<" strHex = "<<strHex;
        //        return;

        m_buffer.append(strHex);
        totallen = m_buffer.size();

        if(isTranslateFlag)    //转换成十进制的tof和peak进行显示解析
        {
            while(totallen)
            {
                if(totallen <14)   //单个命令最少要有6个字节 所以长度为12       5A 03 00 01 3A XX
                    return;



                int indexOf5A = m_buffer.indexOf("01",0);
                if(indexOf5A < 0)  //没有找到01
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

                //               qDebug()<<"m_buffer = "<<m_buffer;
                //以下数据为01打头数据

                //进行和校验
                QString single_Data = m_buffer;       //single_Data就是单个命令
                if(!CRC_check(single_Data))
                {
                    qDebug()<<QStringLiteral("CRC校验失败,singleData =")<<single_Data;
                    m_buffer.clear();
                    totallen = 0;
                    return;
                }
                ////////////////////////////////////////////////////////单个命令处理代码块//////////////////////////////////////////////////////////////////////////////////////

                qDebug()<<"single_data = "<<single_Data;
                if(1 == receFlagInt)   // shifou yijing daowei
                {
                    QString cmd = single_Data.mid(8,2);
                    if(1 == cmd.toInt(NULL,16))
                    {
                        isArrived_flag = true;
                    }
                }

                if(2 == receFlagInt)   //shifou yijing fuwei
                {
                    QString cmd = single_Data.mid(8,2);
                    if(1 == cmd.toInt(NULL,16))
                    {
                        isFuwei = true;
                    }

                }


                ////////////////////////////////////////////////////////单个命令处理代码块//////////////////////////////////////////////////////////////////////////////////////////
                //               m_buffer = m_buffer.right(totallen);                                                  //一帧处理完毕 减去该帧的长度
                //               totallen = m_buffer.size();

                m_buffer.clear();
                totallen = 0;
                //         qDebug()<<"total ="<<totallen<<endl;
            }
        }
        else   //直接打印16进制的数据
        {
            DistanceStr.append(m_buffer);
            DistanceStr.clear();                                                                      //清空
            m_buffer.clear();
            totallen = m_buffer.size();
        }

    }
}


bool autoSerial_msg::CRC_check(QString msg)
{
    int len = msg.length();
    if(len<4)
    {
        qDebug()<<QStringLiteral("CRC 校验失败！");
        return false;
    }

    QString srcStr = msg.left(len-4);
    QString check_str = add_CRC16_KC_check(srcStr);
    if(msg == check_str)
    {
        return true;
    }
    else
    {
        qDebug()<<QStringLiteral("CRC 校验失败！")<<"msg="<<msg<<"   , check_str="<<check_str;
        return false;
    }

}




void autoSerial_msg::sendSerialAutoSlot(QString sendCmdStr)
{
    //clear the buffer;
    m_buffer.clear();

    QByteArray sendArray;
    QString wholeStr;
    wholeStr = add_CRC16_KC_check(sendCmdStr);     //添加校验
    sendArray = StringToByte(wholeStr);            //转换成字节数据
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


QString autoSerial_msg::add_CRC16_KC_check(QString msg)
{
    msg = msg.replace(" ","");    //去掉空格键
    int length = msg.length()/2;
    uint8_t data[100];
    for(int i=0; i<length; i++)
    {
        data[i] = msg.mid(i*2,2).toInt(NULL,16);
    }
    uint8_t *Pushdata = data;
    uint16_t Reg_CRC=0xffff;
    uint8_t Temp_reg=0x00;
    uint8_t i,j;
    for( i = 0; i<length; i ++)
    {
        Reg_CRC^= *Pushdata++;
        for (j = 0; j<8; j++)
        {
            if (Reg_CRC & 0x0001)

                Reg_CRC=Reg_CRC>>1^0xA001;
            else
                Reg_CRC >>=1;
        }
    }
    Temp_reg=Reg_CRC>>8;
    uint16_t res= (Reg_CRC<<8|Temp_reg);
    QString resStr = QString("%1").arg(res,4,16,QChar('0')).toUpper();
    QString allCmdStr = msg + resStr;
    return allCmdStr;
}



QByteArray autoSerial_msg::StringToByte(QString str)
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



//! 1、接收命令后 发送给滑轨
//! 2、等待滑轨到位后，
//! 3、发送给主线程
void autoSerial_msg::sendAdjustDistanceColor_slot(int distance ,QString colorStr)   //距离(mm)  颜色(black or white)
{
    arrival_diatance = distance;
    arrival_color = colorStr;

    qDebug()<<QStringLiteral("接收到移动滑轨的命令，distance=")<<distance<<"  colorStr="<<colorStr<<endl;


    //         QString cmdStr;
    // 1、  移动到指定位置  reg:02 写实际距离
    QString distanceStr = QString("%1").arg(distance,4,16,QChar('0'));
    QString cmdStr = "01 06 00 02 ";
    cmdStr.append(distanceStr);
    sendSerialAutoSlot(cmdStr);


    //读线圈寄存器 sendSerialAutoSlot   reg:70
    isArrived_flag = false;   //  0512
//            isArrived_flag = true;

    delay_flag = true;
    if(mArrive_Timer!=NULL)
    {
        mArrive_Timer->start(500);
    }




    //    if(8000==distance && "white"==colorStr)
    //    {
    //        emit thePointArrived_signal(distance,colorStr);
    //    }else
    //    {
    //        //         QString cmdStr;
    //        // 1、  移动到指定位置  reg:02 写实际距离
    //        QString distanceStr = QString("%1").arg(distance,4,16,QChar('0'));
    //        QString cmdStr = "01 06 00 02 ";
    //        cmdStr.append(distanceStr);
    //        sendSerialAutoSlot(cmdStr);


    //        //读线圈寄存器 sendSerialAutoSlot   reg:70
    //        isArrived_flag = false;   //  0512
    ////        isArrived_flag = true;

    //        delay_flag = true;
    //        if(mArrive_Timer!=NULL)
    //        {
    //            mArrive_Timer->start(500);
    //        }
    //    }



}

// 发送复位的命令
void autoSerial_msg::send_fuwei_slot()
{
    // 1
    QString cmdStr = "01 06 00 04 00 01 ";
    sendSerialAutoSlot(cmdStr);
    // 2
    isFuwei = false;
//    isFuwei = true;

    if(mfuwei_Timer!=NULL)
    {
        mfuwei_Timer->start(500);    //lun xun
    }


}


//检查是否到位置的槽函数
void autoSerial_msg::mArrive_Timer_slot()
{
    if(delay_flag)
    {
        QString cmdStr1 = "01 05 00 07 FF 00 ";
        sendSerialAutoSlot(cmdStr1);
        delay_flag = false;
        return;
    }



    if(isArrived_flag)
    {
        mArrive_Timer->stop();
        receFlagInt = -1;
        isArrived_flag = false;
        emit thePointArrived_signal(arrival_diatance,arrival_color);
        return;
    }

    QString cmdStr = "01 03 00 46 00 01";
    receFlagInt = 1;
    sendSerialAutoSlot(cmdStr);
}


//检查是否复位的槽函数
void autoSerial_msg::mfuwei_Timer_slot()
{
    if(isFuwei)
    {
        mfuwei_Timer->stop();
        receFlagInt = -1;
        isFuwei =false;
        emit fuwei_over_signal();
        return;
    }

    QString cmdStr = "01 03 00 50 00 01";
    receFlagInt = 2;
    sendSerialAutoSlot(cmdStr);

}



/***************************************************/
void autoSerial_msg::sendthePoint_slot(int distance)
{

    qDebug()<<QStringLiteral("接收到移动滑轨的命令，distance=")<<distance;

    //         QString cmdStr;
    // 1、  移动到指定位置  reg:02 写实际距离
    QString distanceStr = QString("%1").arg(distance,4,16,QChar('0'));
    QString cmdStr = "01 06 00 02 ";
    cmdStr.append(distanceStr);
    sendSerialAutoSlot(cmdStr);



    //读线圈寄存器 sendSerialAutoSlot   reg:70
    isArrived_flag = false;   //arrive


    isSenddelay_flag = true;
    if(sendthrPoint_timer!=NULL)
    {
        sendthrPoint_timer->start(1000);
    }

}


void autoSerial_msg:: sendthrPoint_timer_slot()
{
    qDebug()<<"sendthrPoint_timer_slot";
    if(isSenddelay_flag)
    {
        QString cmdStr1 = "01 05 00 07 FF 00 ";
        sendSerialAutoSlot(cmdStr1);
        isSenddelay_flag = false;
        sendthrPoint_timer->stop();
        return;
    }

}
