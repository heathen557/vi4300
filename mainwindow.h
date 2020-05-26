#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<receserial_msg.h>
#include<QThread>
#include<QTimer>
#include<QFileDialog>
#include<QDateTime>
#include<qcustomplot.h>
#include<calhistogram_obj.h>
#include<regisitersetdialog.h>
#include<mcuupgradedialog.h>
#include<highreact_dialog.h>
#include<QMenu>
#include<QAction>
#include<historytof_dialog.h>
#include<devmanagement_dialog.h>
#include"aboutdialog.h"
#include"leastsquare_method.h"
#include"autoserial_msg.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTranslator translator;

    void changeEvent(QEvent *e);

    void initUILanguage();

    void initSerial();

    void initConnect();

    void initStatisticUI();

    void initUINum();

    void SerialSetting_Enable_false();

    void SerialSetting_Enable_true();


    receSerial_msg  *receSerial_Obj;      //串口接收数据线程

    QThread *receSerialThread;

    calHistogram_obj  *calHis_obg;        //计算统计直方图的线程

    QThread *calHisThread;

    leastSquare_method *leastSquare_obj;

    QThread *leastSquareThread;


    bool isLinked;

    QTimer showTimer;                  //暂定为30ms

    QTimer oneSecondTimer;            //1秒钟的定时器

    QString DistanceStrCurrent;        //当前距离

    float DistanceMean;

    float DistanceStd;

    QStringList DistanceStr;               //要显示的tof/peak的字符串，或者显示16进制数据

    vector<double> PlotData_vector;           //plot相关

    vector<double> StatisticData_vector;      //统计相关

    bool isTranslateFlag;     //解析数据 还是直接显示16进制的 切换标识 true：则对数据进行解析

    int Count_num;            //每秒显示记录的条数

    int allCountNum;

    int Count_num_lastSec;    //上一秒钟收到记录的条数

    bool isTimelySaveFlag;

    int tumlySaveCnt;

    int generateCnt;

    bool plot_Mode;           //是否显示统计图的标识，默认为false，也就是不显示，

    QTimer plotShowTimer;     //plot显示的 定时器  20ms

    int plot_type;            //0：显示TOF   1：显示直方图His

    QCPBars *regen;          //直方图用   *****标签相关

    QCPBars *regen_4096;

    int index;


    RegisiterSetDialog registerDia;

    McuUpgradeDialog  McuUpgradeDia;


    QVector<double> HistorgramTicks_2048;      //4300
    QVector<QString> HistorgramLabels_2048;    //4300

    QVector<double> HistorgramTicks_4096;      //4300
    QVector<QString> HistorgramLabels_4096;    //4300



    HighReact_Dialog highReactDia;

    QMenu *m_menu;
    QAction *m_English;
    QAction *m_China;


    //保存直方图数据
    int saveHist_index;
    bool isSaveHistData_flag;
    QString saveHistDataFilePath;

    //显示历史数据TOF 图
    HistoryTof_Dialog hisTof_dia;
    devManagement_Dialog devManagement_dia;



    //读取pixel 定时器
    QTimer readPixel_timer;


    QString deviceType_str;   //设备类型

    aboutDialog about_dia;




    /******least square********/
    vector<float> vecDistacne_10;
    vector<float> vecPeak_10;

    vector<float> vecDistacne_3;
    vector<float> vecPeak_3;


    /*********** autoTest *********************/
    void initSerial_2();

    autoSerial_msg *autoSerial_obj;
    QThread *autoSerial_thread;

    bool isAutoTest_flag;    //若是自动校准，复位成功后直接 开启校准   ；否则只是单纯的复位

private slots:
    void on_save_pushButton_clicked();

    void on_plotSet_on_radioButton_clicked();

    void on_plotSet_off_radioButton_clicked();

    void on_openPort_pushButton_clicked();

    void on_Transform_checkBox_clicked();

    void dealedData_slot(QString,vector<double>,vector<double>);   //接收处理数据线程数据的槽函数

    void showTimerSlot();

    void beginTimer();

    void stopTimer();

    void oneSecondTimer_slot();

    void on_TimingSave_checkBox_clicked();

    void on_clear_pushButton_clicked();

    void on_timeInnterval_lineEdit_returnPressed();

    void on_portScan_pushButton_clicked();


    void showResultMsg_slot(QStringList,int);    //接收界面的要显示的tof和peak信息,每一秒钟显示一次，然后清空暂存变量 ;该包数据中点的个数。接收到点个数增加即可

    void plotShowTimer_slot();

    void returnLinkInfo_slot(QString, bool);

    void toShowHistogram_slot(QVector<double>,int);          //显示统计直方图   VI4300   2048

    void toShowHistogram_4096_slot(QVector<double>,int);   //显示统计直方图   CASSET   4096



    void on_savePicture_pushButton_clicked();

    void on_actionMCU_triggered();

    void on_Register_action_triggered();

    void on_singleMeasure_pushButton_clicked();

    void on_delayMeasure_pushButton_clicked();

    void on_stopMeasure_pushButton_clicked();

    void on_calibration_pushButton_clicked();

    void on_read_outFactory_pushButton_clicked();

    void on_send_outFactory_pushButton_clicked();


    //!
    //! \brief AckCmdMain_signal
    //!主界面配置的相关信息返回信号    参数1：“8102”：写入出厂设置成功，参数2暂无
    void AckCmdMain_slot(QString returnCmdStr,QString cmdAck);

    void on_reStoreFactory_pushButton_clicked();

    void on_rowData_pushButton_clicked();

    void on_gaofan_pushButton_clicked();

    void on_actionEnglish_triggered();

    void on_action_china_triggered();

    void on_HistogramData_pushButton_clicked();

    void on_calibration_read_pushButton_clicked();


    //将float数据 转换为16进制数据 并存储在QString 当中
    QString floatToQString(float);

    //QString中存储的16进制数据，解析为float型的数据
    float QStringToFloat(QString );

    QByteArray StringToByte(QString str);

    void on_plot_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_showTOF_action_TOF_triggered();

    void on_manageMent_action_triggered();    //设备数据库管理

    void on_savePicture_his_pushButton_clicked();

    void on_pixel_read_pushButton_clicked();

    void AckSinglePixelPosition_slot(bool,QString);

    void on_singleReg_read_pushButton_clicked();

    void on_singleReg_write_pushButton_clicked();

    void on_casset_imageSave_pushButton_clicked();

    void on_casset_historgram_pushButton_clicked();

    void on_pixel_time_pushButton_clicked();

    void pixel_time_slot();

    void on_about_action_triggered();

    void on_delayLine_pushButton_clicked();

    void on_CAS_pix1_pushButton_clicked();

    void on_CAS_pix2_pushButton_clicked();


    void on_checkBox_clicked();

    void on_pileUp_checkBox_clicked();

    void on_black_01_pushButton_clicked();

    void on_white_01_pushButton_clicked();

    void on_black_02_pushButton_clicked();

    void on_white_02_pushButton_clicked();

    void on_black_03_pushButton_clicked();

    void on_white_03_pushButton_clicked();

    void on_black_04_pushButton_clicked();

    void on_white_04_pushButton_clicked();

    void on_black_05_pushButton_clicked();

    void on_white_05_pushButton_clicked();

    void on_black_1_pushButton_clicked();

    void on_white_1_pushButton_clicked();

    void on_black_3_pushButton_clicked();

    void on_white_3_pushButton_clicked();

    void on_black_8_pushButton_clicked();

    void on_white_8_pushButton_clicked();




    /*******least square******/
    void  sendLeastRes_slot(int index,float resTof,float resPeak);

    void on_least_start_pushButton_clicked();

    void send_leastResult_slot(float,float,float,float,float,float,float,float);

    float calculate_offset(float a,float b,float c,float bias,float peak);  //用来计算正向的大小


    void on_writeMCU_pushButton_clicked();

    void on_newJiaohun_start_pushButton_clicked();

    void on_newjiaozhun_end_pushButton_clicked();

    void on_portScan_pushButton_2_clicked();

    void on_openPort_pushButton_2_clicked();


    /*********auto Test****************/
    void returnLinkInfoAuto_slot(QString, bool);

    void on_startAutoAdjust_pushButton_clicked();

    void thePointArrived_slot(int ,QString );   //距离 颜色

    void on_startlds_pushButton_clicked();

    void on_fuwei_pushButton_clicked();

    void fuwei_over_slot();

    void on_readMCU_pushButton_clicked();

    void on_startMove_pushButton_clicked();

    void on_openOrClose_laser_pushButton_clicked();

signals:
    void openOrCloseSerial_signal(bool);        //true:open   false：close

    void calHistogram_signal(vector<double>);   //begin histogram signal()

    void sendSerialSignal(QString);             //串口发送信号


    /**************************/
    void deal_receLeast_signal(vector<float>,vector<float>,vector<float>,vector<float>);

    /**********auto test 相关************/
    void openOrCloseSerialAuto_signal(bool);
    void sendSerialAuto_Signal(QString);

    void sendAdjustDistanceColor_signal(int ,QString);   //距离 颜色

    void send_fuwei_signal();


    /********/
    void sendthePoint_signal(int );

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
