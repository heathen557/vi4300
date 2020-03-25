#ifndef RECESERIAL_MSG_H
#define RECESERIAL_MSG_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>
#include<QDataStream>
#include<vector>
#include<QTimer>
#include<QList>

using namespace std;


struct Settings {
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;
};


class receSerial_msg : public QObject
{
    Q_OBJECT
public:
    explicit receSerial_msg(QObject *parent = 0);

    QSerialPort *serial;

    QByteArray m_buffer;

    vector<int> tofPeak_vector;

    bool isTranslateFlag;     //解析数据 还是直接显示16进制的 切换标识 true：则对数据进行解析

    vector<double> StatisticData_vector;     //统计相关  均值方差

    QStringList   DistanceStr;               //显示tof peak相关

    vector<double> PlotData_vector;          //plot相关 画图

    QVector<double> historgramVec_2048;

    QVector<double> historgramVec_4096;

    bool clearFlag;

signals:
    void dealedData_signal(QString,vector<double>,vector<double>);     //当前的tof值 ; plotData ; statisticData

    void showResultMsg_signal(QStringList,int);  //显示tof peak相关  主界面显示;  主线程中设定一个暂存变量，每秒钟在result窗口中显示append(),然后清空result  ,该包数据点的个数

    void returnLinkInfo_signal(QString, bool);

    //!
    //! \brief AckCmdUpgrade_signal
    //!//升级相关的信号，参数为两个，1：“86”：开始升级命令应答    参数2： “01”：成功
    //!                                                            “00” ：失败
    //!                                                            其他：命令有误
    //!                              “87”：升级过程中的命令应答 参数2： 应答的数据
    void AckCmdUpgrade_signal(QString,QString);


    //!
    //! \brief AckCmdRegister_signal
    //!寄存器返回命令的相关信号   参数1：“81”：写寄存器应答  参数2 暂无
    //!                              “80”：读寄存器应答  参数2 寄存器的数据区
    void AckCmdRegister_signal(QString,QString);

    //!
    //! \brief AckCmdMain_signal
    //!主界面配置的相关信号    参数1：“8102”：写入出厂设置，参数2暂无
    void AckCmdMain_signal(QString,QString);



    //!
    //! \brief toShowHistogram_signal
    //!将脂肪乳数据解析以后发送给主界面进行直方图显示  参数1：1-2048 个数  参数2 Y轴的最大值
    void toShowHistogram_signal(QVector<double> ,int );

    //!
    //! \brief toShowHistogram_signal
    //!将脂肪乳数据解析以后发送给主界面进行直方图显示  参数1：1-4096 个数  参数2 Y轴的最大值
    void toShowHistogram_4096_signal(QVector<double> ,int );

public slots:
    void readDataSlot();

    bool msgCheck(QString msg);

    void openOrCloseSerial_slot(bool);

    void sendSerialSlot(QString);              //串口发送数据的槽函数

    QString addCheck(QString);

    QByteArray StringToByte(QString str);      //将QString 转换为 Byte的槽函数


};

#endif // RECESERIAL_MSG_H
