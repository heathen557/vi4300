#ifndef AUTOSERIAL_MSG_H
#define AUTOSERIAL_MSG_H

#include <QObject>
#include"globaldata.h"
#include<Windows.h>
#include<QTimer>


class autoSerial_msg : public QObject
{
    Q_OBJECT
public:
    explicit autoSerial_msg(QObject *parent = 0);

    QSerialPort *serial;
    QByteArray m_buffer;
    int totallen;
    bool isTranslateFlag;
    QStringList   DistanceStr;               //显示tof peak相关

    int receFlagInt;      // 1:读取是否已经到位置   2：是否已经复位完成
    bool isArrived_flag;
    bool isFuwei;
    QTimer *mArrive_Timer;
    QTimer *mfuwei_Timer;

    int arrival_diatance;
    QString arrival_color;
    bool delay_flag;

    /*************/

    QTimer *sendthrPoint_timer;
    bool isSenddelay_flag;


signals:

    void returnLinkInfoAuto_signal(QString, bool);

    //发送给主线程  告知滑轨已经到位
    void thePointArrived_signal(int ,QString );   //距离 颜色

    void fuwei_over_signal();

public slots:

    void sendSerialAutoSlot(QString sendCmdStr);

    void openOrCloseSerialAuto_slot(bool);

    QByteArray StringToByte(QString str);      //将QString 转换为 Byte的槽函数

    void readDataSlot();




    /********Auto Test *****************/
    //!
    //! \brief sendAdjustDistanceColor_slot
    //! 1、接收命令后(距离 颜色) 发送给滑轨
    //! 2、等待滑轨到位后，
    //! 3、发送给主线程
     void sendAdjustDistanceColor_slot(int ,QString);   //距离 颜色

     QString add_CRC16_KC_check(QString msg);

     bool CRC_check(QString msg);

//     QString add_CRC16_KC_check_table(QString msg);

     void send_fuwei_slot();

     void mArrive_Timer_slot();

     void mfuwei_Timer_slot();


     /***********************/

     void sendthePoint_slot(int );
     void sendthrPoint_timer_slot();


};

#endif // AUTOSERIAL_MSG_H
