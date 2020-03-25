#include "mainwindow.h"
#include "ui_mainwindow.h"


#define historgram_label_num_2048 2048
#define historgram_label_num_4096 4096

//设备类型 0x01 芯视界内部测试用，不对外开放  所以获取设备类型时是根据名称来获取，而不是根据其序号
#define VisionICS_USE


Settings currentSettings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->groupBox_11->setVisible(false);

    initUILanguage();
    allCountNum = 0;

    m_menu  =  new  QMenu;
    m_English  =  new  QAction(tr("English"),this);
    m_China  =  new  QAction(tr("中文"),this);
    m_menu->addAction(m_China);
    m_menu->addAction(m_English);
//    m_pTitleBar->m_pBtnMenu->setMenu(m_menu);





//    ui->groupBox_5->setEnabled(false);
    ui->ResultHistory_textEdit->document()->setMaximumBlockCount(200000);    //最多显示10000行，滑动存储  10w

    qRegisterMetaType<vector<double>>("vector<double>");   //注册函数
    qRegisterMetaType<vector<int>>("vector<int>");       //注册函数
    qRegisterMetaType<QVector<double>>("QVector<double>");   //注册函数
    qRegisterMetaType<QVector<QString>>("QVector<QString>");   //注册函数

    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,2);
    ui->splitter->setStretchFactor(2,5);
    ui->groupBox_2->setVisible(true);

    ui->timeInnterval_label->setEnabled(false);
    ui->timeInnterval_lineEdit->setEnabled(false);

    receSerial_Obj = new receSerial_msg;;
    receSerialThread = new QThread;
    receSerial_Obj->moveToThread(receSerialThread);
    receSerialThread->start();


    calHis_obg = new calHistogram_obj;
    calHisThread = new QThread;
    calHis_obg->moveToThread(calHisThread);
    calHisThread->start();

    isLinked = false;
    isTranslateFlag = true;
    Count_num = 0;
    Count_num_lastSec = 0;
    isTimelySaveFlag = false;
    plot_Mode = false;      //默认不显示统计图
    plot_type = 0;     //默认显示TOF
    initSerial();
    initStatisticUI();
    initConnect();
    initUINum();
    SerialSetting_Enable_false();

    ui->toolBox->setCurrentIndex(0);

    saveHist_index = 1;
    isSaveHistData_flag = false;

}

//关闭所有串口相关的按键
void MainWindow::SerialSetting_Enable_false()
{
//    ui->groupBox_5->setEnabled(false);

    ui->groupBox_8->setEnabled(false);
    ui->actionMCU->setEnabled(false);
    ui->Register_action->setEnabled(false);
    ui->send_outFactory_pushButton->setEnabled(false);
    ui->read_outFactory_pushButton->setEnabled(false);
    ui->calibration_read_pushButton->setEnabled(false);
    ui->calibration_pushButton->setEnabled(false);
    ui->gaofan_pushButton->setEnabled(false);
    ui->groupBox_10->setEnabled(false);
    ui->singleMeasure_pushButton->setEnabled(false);
    ui->delayMeasure_pushButton->setEnabled(false);
    ui->stopMeasure_pushButton->setEnabled(false);
    ui->reStoreFactory_pushButton->setEnabled(false);
    ui->rowData_pushButton->setEnabled(false);
    ui->pixel_read_pushButton->setEnabled(false);
    ui->singleReg_read_pushButton->setEnabled(false);
    ui->singleReg_write_pushButton->setEnabled(false);

}

//打开所有串口相关的按键
void MainWindow::SerialSetting_Enable_true()
{
//    ui->groupBox_5->setEnabled(true);
    ui->groupBox_8->setEnabled(true);
    ui->actionMCU->setEnabled(true);
    ui->Register_action->setEnabled(true);
    ui->send_outFactory_pushButton->setEnabled(true);
    ui->read_outFactory_pushButton->setEnabled(true);
    ui->calibration_pushButton->setEnabled(true);
    ui->calibration_read_pushButton->setEnabled(true);
    ui->gaofan_pushButton->setEnabled(true);
    ui->groupBox_10->setEnabled(true);
    ui->singleMeasure_pushButton->setEnabled(true);
    ui->delayMeasure_pushButton->setEnabled(true);
    ui->stopMeasure_pushButton->setEnabled(true);
    ui->reStoreFactory_pushButton->setEnabled(true);
    ui->rowData_pushButton->setEnabled(true);
    ui->pixel_read_pushButton->setEnabled(true);
    ui->singleReg_read_pushButton->setEnabled(true);
    ui->singleReg_write_pushButton->setEnabled(true);
}

void MainWindow::initUINum()
{
//    ui->botelv_comboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
//    ui->botelv_comboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
//    ui->botelv_comboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
//    ui->botelv_comboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
//    ui->botelv_comboBox->addItem(QStringLiteral("256000"), QSerialPort::Baud256000);

    HistorgramTicks_2048.resize(historgram_label_num_2048);
    HistorgramLabels_2048.resize(historgram_label_num_2048);

    for(int i=0; i<historgram_label_num_2048; i++)
    {
        HistorgramTicks_2048[i] = i;
        HistorgramLabels_2048[i] = "";
        if(0 == i%100)         //相隔100个数据打一个标签
        {
            HistorgramLabels_2048[i] = QString::number(i);
        }
    }

}



//语言的初始化
void MainWindow::initUILanguage()
{
//    ui->groupBox_3->setTitle(QStringLiteral("串口设置"));

    ui->deviceType_comboBox->addItem("VI4300_Master");
#ifdef VisionICS_USE
    ui->deviceType_comboBox->addItem("VI4300_Slave");
#endif
    ui->deviceType_comboBox->addItem("LDS");

}



void MainWindow::initConnect()
{
    //接收数据线程 接收并处理数据后，将处理结果发送给主线程的信号与槽
    connect(receSerial_Obj,SIGNAL(dealedData_signal(QString,vector<double>,vector<double>)),this,SLOT(dealedData_slot(QString,vector<double>,vector<double>)));
    connect(receSerial_Obj,SIGNAL(showResultMsg_signal(QStringList,int)),SLOT(showResultMsg_slot(QStringList,int)));
    //link info slot
    connect(this,SIGNAL(openOrCloseSerial_signal(bool)),receSerial_Obj,SLOT(openOrCloseSerial_slot(bool)));
    connect(receSerial_Obj,SIGNAL(returnLinkInfo_signal(QString, bool)),this,SLOT(returnLinkInfo_slot(QString, bool)));

    // calculate histogram connect
    connect(this,SIGNAL(calHistogram_signal(vector<double>)),calHis_obg,SLOT(calHistogram_slot(vector<double>)));


    //刷新定时器 信号与槽的连接
    connect(&showTimer,SIGNAL(timeout()),this,SLOT(showTimerSlot()));
    connect(&oneSecondTimer,SIGNAL(timeout()),this,SLOT(oneSecondTimer_slot()));
    connect(&plotShowTimer,SIGNAL(timeout()),this,SLOT(plotShowTimer_slot()));

    //主界面串口发送数据相关
    connect(this,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));
    connect(receSerial_Obj,SIGNAL(AckCmdMain_signal(QString,QString)),this,SLOT(AckCmdMain_slot(QString,QString)));

    //MCU 升级相关
    connect(&McuUpgradeDia,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));
    connect(receSerial_Obj,SIGNAL(AckCmdUpgrade_signal(QString,QString)),&McuUpgradeDia,SLOT(AckCmdUpgrade_signal(QString,QString)));

    //寄存器读写相关
    connect(&registerDia,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));
    connect(receSerial_Obj,SIGNAL(AckCmdRegister_signal(QString,QString)),&registerDia,SLOT(AckCmdRegister_slot(QString,QString)));

    //画统计直方图
    connect(receSerial_Obj,SIGNAL(toShowHistogram_signal(QVector<double>,int)),this,SLOT(toShowHistogram_slot(QVector<double>,int)));
    connect(receSerial_Obj,SIGNAL(toShowHistogram_4096_signal(QVector<double>,int)),this,SLOT(toShowHistogram_4096_slot(QVector<double>,int)));

    //高反设置的串口数据
    connect(&highReactDia,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));

}

//统计显示相关窗口的初始化
void MainWindow::initStatisticUI()
{
    QString demoName = "Histogram";//实例名称
    // set dark background gradient: 设置暗背景渐变
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));//开始颜色为黑色
    gradient.setColorAt(0.38, QColor(200, 105, 105));//红色
    gradient.setColorAt(1, QColor(70, 70, 70));//黑色
    //tof统计相关
//    ui->TOF_widget->setBackground(QBrush(gradient));//设置图表背景（用画刷设置）
    ui->TOF_widget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);

    ui->TOF_widget->legend->setVisible(true);
    ui->TOF_widget->legend->setFont(QFont("Helvetica", 9));
    ui->TOF_widget->yAxis->setRange(0,500);
    ui->TOF_widget->xAxis->setRange(0,256);
    ui->TOF_widget->addGraph();
    ui->TOF_widget->graph(0)->setName(QStringLiteral("TOF"));

//Histgram统计相关
    regen = new QCPBars(ui->Histogram_widget->xAxis, ui->Histogram_widget->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(2);
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));

    ui->Histogram_widget->xAxis->setTickLabelRotation(60);//设置标签角度旋转
    ui->Histogram_widget->xAxis->setSubTicks(false);//设置是否显示子标签
    ui->Histogram_widget->xAxis->setTickLength(0, 4);
    ui->Histogram_widget->xAxis->setRange(0, 500);     //设置x轴区间
    ui->Histogram_widget->xAxis->setBasePen(QPen(Qt::black));
    ui->Histogram_widget->xAxis->setTickPen(QPen(Qt::black));
    ui->Histogram_widget->xAxis->grid()->setVisible(true);//设置网格是否显示
    ui->Histogram_widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->Histogram_widget->xAxis->setTickLabelColor(Qt::black);//设置标记标签颜色
    ui->Histogram_widget->xAxis->setLabelColor(Qt::black);

    // prepare y axis: //设置y轴
    ui->Histogram_widget->yAxis->setRange(0, 800);
    ui->Histogram_widget->yAxis->setPadding(5); // a bit more space to the left border 设置左边留空间
//    ui->Histogram_widget->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->Histogram_widget->yAxis->setBasePen(QPen(Qt::black));
    ui->Histogram_widget->yAxis->setTickPen(QPen(Qt::black));
    ui->Histogram_widget->yAxis->setSubTickPen(QPen(Qt::black));//设置SubTick颜色，SubTick指的是轴上的
//刻度线
    ui->Histogram_widget->yAxis->grid()->setSubGridVisible(true);
    ui->Histogram_widget->yAxis->setTickLabelColor(Qt::black);//设置标记标签颜色（y轴标记标签）
    ui->Histogram_widget->yAxis->setLabelColor(Qt::black);//设置标签颜色（y轴右边标签）
    ui->Histogram_widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->Histogram_widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    // setup legend: 设置标签
//    ui->Histogram_widget->legend->setVisible(true);
    ui->Histogram_widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->Histogram_widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->Histogram_widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->Histogram_widget->legend->setFont(legendFont);
    ui->Histogram_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);//设置 可拖动，可放大缩


    //cassset  4096 直方图相关设置

    regen_4096 = new QCPBars(ui->casset_historgrm_widget->xAxis, ui->casset_historgrm_widget->yAxis);
    regen_4096->setAntialiased(false);
    regen_4096->setStackingGap(2);
    regen_4096->setName("Regenerative");
    regen_4096->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen_4096->setBrush(QColor(0, 168, 140));

    ui->casset_historgrm_widget->xAxis->setTickLabelRotation(60);//设置标签角度旋转
    ui->casset_historgrm_widget->xAxis->setSubTicks(false);//设置是否显示子标签
    ui->casset_historgrm_widget->xAxis->setTickLength(0, 4);
    ui->casset_historgrm_widget->xAxis->setRange(0, 500);     //设置x轴区间
    ui->casset_historgrm_widget->xAxis->setBasePen(QPen(Qt::black));
    ui->casset_historgrm_widget->xAxis->setTickPen(QPen(Qt::black));
    ui->casset_historgrm_widget->xAxis->grid()->setVisible(true);//设置网格是否显示
    ui->casset_historgrm_widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->casset_historgrm_widget->xAxis->setTickLabelColor(Qt::black);//设置标记标签颜色
    ui->casset_historgrm_widget->xAxis->setLabelColor(Qt::black);

    // prepare y axis: //设置y轴
    ui->casset_historgrm_widget->yAxis->setRange(0, 800);
    ui->casset_historgrm_widget->yAxis->setPadding(5); // a bit more space to the left border 设置左边留空间
//    ui->Histogram_widget->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->casset_historgrm_widget->yAxis->setBasePen(QPen(Qt::black));
    ui->casset_historgrm_widget->yAxis->setTickPen(QPen(Qt::black));
    ui->casset_historgrm_widget->yAxis->setSubTickPen(QPen(Qt::black));//设置SubTick颜色，SubTick指的是轴上的
//刻度线
    ui->casset_historgrm_widget->yAxis->grid()->setSubGridVisible(true);
    ui->casset_historgrm_widget->yAxis->setTickLabelColor(Qt::black);//设置标记标签颜色（y轴标记标签）
    ui->casset_historgrm_widget->yAxis->setLabelColor(Qt::black);//设置标签颜色（y轴右边标签）
    ui->casset_historgrm_widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->casset_historgrm_widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    // setup legend: 设置标签
//    ui->Histogram_widget->legend->setVisible(true);
    ui->casset_historgrm_widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->casset_historgrm_widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->casset_historgrm_widget->legend->setBorderPen(Qt::NoPen);

    ui->casset_historgrm_widget->legend->setFont(legendFont);
    ui->casset_historgrm_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);//设置 可拖动，可放大缩

}

void MainWindow::beginTimer()
{
    showTimer.start(90);
    oneSecondTimer.start(1000);
}

void MainWindow::stopTimer()
{
    showTimer.stop();
    oneSecondTimer.stop();
}


//查找可用的端口
void MainWindow::on_portScan_pushButton_clicked()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    ui->serialPortInfoListBox->clear();
    ui->serialPortInfoListBox->addItems(m_serialPortName);
    QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("可用端口检测完毕！"));
}


//串口初始化
void MainWindow::initSerial()
{
    QFile file("setting.ini");
    QByteArray temp("\r\n");
    QString line[20];

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd())
        {
            line[i] = in.readLine();
            i++;
        }
        file.close();
    }
    int numSeri_ = line[0].toInt();       //串口号
    int baudRateBox_ = line[1].toInt();   //波特率


//    QStringList comList;//串口号
//    comList.clear();
//    comList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"
//          <<"COM7"<<"COM8"<<"COM9"<<"COM10"<<"COM11"<<"COM12"
//         <<"COM13"<<"COM14"<<"COM15"<<"COM16"<<"COM17"<<"COM18"
//        <<"COM19"<<"COM20"<<"COM21"<<"COM22"<<"COM23"<<"COM24"
//       <<"COM25"<<"COM26"<<"COM27"<<"COM28"<<"COM28"<<"COM29"<<"COM30";

//    ui->serialPortInfoListBox->setCurrentIndex(numSeri_);

    int num = 0;
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        num++;
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    ui->serialPortInfoListBox->clear();
    ui->serialPortInfoListBox->addItems(m_serialPortName);
    if(numSeri_>num)
        ui->serialPortInfoListBox->setCurrentIndex(0);
    else
        ui->serialPortInfoListBox->setCurrentIndex(numSeri_);



    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->addItem(QStringLiteral("230400"), QSerialPort::Baud230400);
    ui->baudRateBox->addItem(QStringLiteral("256000"), QSerialPort::Baud256000);
    ui->baudRateBox->addItem(QStringLiteral("460800"), QSerialPort::Baud460800);

    ui->baudRateBox->addItem(tr("Custom"));
    ui->baudRateBox->setCurrentIndex(baudRateBox_);

    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
}

//打开串口
void MainWindow::on_openPort_pushButton_clicked()
{
    if(ui->openPort_pushButton->text() == "Open")
    {
        currentSettings.name = ui->serialPortInfoListBox->currentText();

        if (ui->baudRateBox->currentIndex() == 4) {
            currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
        } else {
            currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                        ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
        }


        qDebug()<<" currentIndex ="<<ui->baudRateBox->currentIndex() <<" currentSettings.baudRate = "<<currentSettings.baudRate;
        currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);

        currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                    ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
        currentSettings.stringDataBits = ui->dataBitsBox->currentText();

        currentSettings.parity = static_cast<QSerialPort::Parity>(
                    ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
        currentSettings.stringParity = ui->parityBox->currentText();

        currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                    ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
        currentSettings.stringStopBits = ui->stopBitsBox->currentText();

//         qDebug()<<"name="<<currentSettings.name<<" baudRate ="<<currentSettings.baudRate<<" dataBits="<<currentSettings.dataBits<<" parity="<<currentSettings.parity<<" stopBits="<<currentSettings.stopBits<<" flowCon"<<currentSettings.flowControl;


        emit openOrCloseSerial_signal(true);

        qDebug()<<"name="<<currentSettings.name<<" baudRate ="<<currentSettings.baudRate<<" dataBits="<<currentSettings.dataBits<<" parity="<<currentSettings.parity<<" stopBits="<<currentSettings.stopBits<<" flowCon"<<currentSettings.flowControl;


        QFile file("setting.ini");
        QByteArray temp("\r\n");
        QString line[20];

        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            int i = 0;
            while (!in.atEnd())
            {
                line[i] = in.readLine();
                i++;
            }
            file.close();
        }

        int seriNum = ui->serialPortInfoListBox->currentIndex();
        int baudBox = ui->baudRateBox->currentIndex();


        if(file.open(QIODevice::WriteOnly))
        {
            QByteArray writeData;
            writeData = QString::number(seriNum).toLatin1()+ temp + QString::number(baudBox).toLatin1()+temp+\
                    line[2].toLatin1()+ temp +line[3].toLatin1()+ temp+ line[4].toLatin1()+ temp +line[5].toLatin1();
            if (-1 == file.write(writeData))
            {
                qDebug()<<"ERROR";
            }
            file.close();
        }

    }
    else
    {
        emit openOrCloseSerial_signal(false);

    }


}

void MainWindow::returnLinkInfo_slot(QString str, bool flag)
{
    if("open" == str)
    {
        if(true == flag)
        {
             isLinked = true;
             ui->serialPortInfoListBox->setEnabled(false);
             ui->baudRateBox->setEnabled(false);
             ui->dataBitsBox->setEnabled(false);
             ui->parityBox->setEnabled(false);
             ui->stopBitsBox->setEnabled(false);
             ui->openPort_pushButton->setText("Close");
             beginTimer();
             SerialSetting_Enable_true();
        }else
        {
            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("打开串口失败！"));
        }
    }else
    {
        if(true == flag)
        {
            isLinked = false;
            stopTimer();
            ui->openPort_pushButton->setText("Open");
            ui->serialPortInfoListBox->setEnabled(true);
            ui->baudRateBox->setEnabled(true);
            ui->dataBitsBox->setEnabled(true);
            ui->parityBox->setEnabled(true);
            ui->stopBitsBox->setEnabled(true);
            SerialSetting_Enable_false();
        }else
        {
            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("关闭串口失败！"));
        }
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}


//是否进行进制转换的槽函数
void MainWindow::on_Transform_checkBox_clicked()
{
    if( ui->Transform_checkBox->isChecked())
    {
        qDebug()<<" checked is true";
        receSerial_Obj->isTranslateFlag = true;
    }else{
        qDebug()<<" checked is false";
        receSerial_Obj->isTranslateFlag = false;
    }
}





//接收处理数据线程数据的槽函数
void MainWindow::dealedData_slot(QString currTof,vector<double> plotData, vector<double> StatisticData)
{

    DistanceStrCurrent = currTof;

    PlotData_vector = plotData;           //plot相关

    StatisticData_vector = StatisticData;      //统计相关
}

//50ms定时器的槽函数
void MainWindow::showTimerSlot()
{
    //text_BOX上面的数据显示   分为显示解析后的TOF数据 或者16进制的数据  ;看是否需要判断 isTranslateFlag
    for(int i=0 ;i<DistanceStr.length();i++ )
    {
        ui->ResultHistory_textEdit->appendPlainText(DistanceStr[i]);
    }
    DistanceStr.clear();    //清空暂存的变量
    ui->HistoryData_label->setText(QString::number(allCountNum));   //显示记录条数



    //显示当前的距离
    ui->currentDistance11_label->setText(DistanceStrCurrent);
//    ui->currentDistance11_label->setText("12.369");

    //计算tof的均值
    int len = StatisticData_vector.size();
    if(len<1)
        return;
    DistanceMean = std::accumulate(std::begin(StatisticData_vector),std::end(StatisticData_vector),0.0)/len;
    ui->mean_label->setText(QString::number(DistanceMean));

    //计算tof的方差
    float tofAccum = 0.0;
    std::for_each (std::begin(StatisticData_vector), std::end(StatisticData_vector), [&](const double d) {
            tofAccum  += (d-DistanceMean)*(d-DistanceMean);
        });
    DistanceStd = sqrt(tofAccum/(len-1));
    ui->std_label->setText(QString::number(DistanceStd));




}


//选中文件保存功能
void MainWindow::on_save_pushButton_clicked()
{
    QString sFilePath = ui->savePath_lineEdit->text() ;
    if(sFilePath.isEmpty())
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("请先设置文件保存路径"));
        return;
    }

    QString text = ui->ResultHistory_textEdit->toPlainText();


    if("txt" != sFilePath.right(3))
    {
        sFilePath.append(".txt");
    }



    QFile file(sFilePath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream out(&file);
        out<<text.toLocal8Bit()<<endl;
        file.close();
        ui->savePath_lineEdit->setText(sFilePath);
    }else
    {
        QString strMsg = QStringLiteral("文件保存失败，请检查路径");
        QMessageBox::information(NULL,QStringLiteral("提示"),strMsg);
    }


}


//接收串口处理线程发送来的用于界面上显示的字符串连接
void MainWindow::showResultMsg_slot(QStringList DisStr, int pointNum)
{
    Count_num += pointNum;

    allCountNum++;

    DistanceStr.append(DisStr);

    //判断是否需要保存直方图数据,每条直方图数据保存成一个文本文件
    if(isSaveHistData_flag)
    {
        QString sFilePath = saveHistDataFilePath + QString::number(saveHist_index)+".txt";
        QFile file(sFilePath);
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream out(&file);
        QString text ;

        for(int i=0; i<DisStr[0].length();i+=2)
        {
            text.append(DisStr[0].mid(i,2)).append(" ");
        }

        out<<text.toLocal8Bit()<<endl;
        file.close();
        saveHist_index++;
    }


}

//每秒钟刷新的槽函数
void MainWindow::oneSecondTimer_slot()
{
//    int dps = Count_num - Count_num_lastSec;
    int dps = Count_num;
    if(dps > 0)
    {
        ui->DPS_label->setText(QString::number(dps));
    }else
    {
        ui->DPS_label->setText("0");
    }
//    Count_num_lastSec = Count_num;
    Count_num = 0;


    if(isTimelySaveFlag)     //60s存一帧数据
    {
        tumlySaveCnt--;
        if(0 == tumlySaveCnt)
        {
            tumlySaveCnt = ui->timeInnterval_lineEdit->text().toInt();
            QString textBox_Data = ui->ResultHistory_textEdit->toPlainText();
            if(!textBox_Data.isEmpty())
            {
                QString filePathName = ui->savePath_lineEdit->text() +"AutoSave" +QString::number(generateCnt)+".txt";  //文件名
                QFile file(filePathName);
                if(file.open(QIODevice::WriteOnly|QIODevice::Text))
                {
                    QTextStream out(&file);
                    out<<textBox_Data.toLocal8Bit()<<endl;
                    file.close();
                }else
                {
                    QString strWarn = QStringLiteral("定时保存时路径存在问题，请检查路径！");
                    QMessageBox::warning(NULL,QStringLiteral("提示"),strWarn);
                }



                generateCnt++;
                ui->ResultHistory_textEdit->clear(); //清空控件上的数据
            }

        }

    }
}


//TimeingSave_checkBox的点击的槽函数
void MainWindow::on_TimingSave_checkBox_clicked()
{
    QString sFilePath = ui->savePath_lineEdit->text();
    if(sFilePath.isEmpty())
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("请先设置文件保存路径"));
        ui->TimingSave_checkBox->setChecked(false);
        return;
    }
    //设置文件的保存路径
    if(sFilePath.right(3)=="txt")
    {
        sFilePath = sFilePath.left(sFilePath.length() - 4);
    }


    if(sFilePath.right(1) != "\\")
    {
        sFilePath.append("\\");
    }

    ui->savePath_lineEdit->setText(sFilePath);



    if(ui->TimingSave_checkBox->isChecked())
    {
        isTimelySaveFlag = true;
        ui->timeInnterval_label->setEnabled(true);
        ui->timeInnterval_lineEdit->setEnabled(true);
        tumlySaveCnt = ui->timeInnterval_lineEdit->text().toInt();
        generateCnt = 0;
        ui->save_pushButton->setEnabled(false);
    }
    else
    {
        isTimelySaveFlag = false;
        ui->timeInnterval_label->setEnabled(false);
        ui->timeInnterval_lineEdit->setEnabled(false);
        ui->save_pushButton->setEnabled(true);
    }

}

//改变tumlySaveCnt的槽函数
void MainWindow::on_timeInnterval_lineEdit_returnPressed()
{
    tumlySaveCnt = ui->timeInnterval_lineEdit->text().toInt();
}

//clear清空函数
void MainWindow::on_clear_pushButton_clicked()
{

    receSerial_Obj->clearFlag = true;
    PlotData_vector.clear();
    ui->ResultHistory_textEdit->clear();
    allCountNum = 0;

}


//画图的选项  currentIndex=1:画TOF 图  currentIndex=2:画直方图
void MainWindow::on_plot_comboBox_currentIndexChanged(int index)
{
    if(1 == index)
    {
        if(plotShowTimer.isActive())
            plotShowTimer.stop();
        plotShowTimer.start(70);

        plot_Mode = true;
        plot_type = 0;
        ui->stackedWidget->setCurrentIndex(0);
    }else if(2 == index)
    {
        plot_Mode = true;
        if(plotShowTimer.isActive())
            plotShowTimer.stop();
        plotShowTimer.start(500);      //定时器改为100ms进行一次刷新

        plot_type = 1;
        ui->stackedWidget->setCurrentIndex(1);
    }else if(3 == index)
    {
        plot_Mode = true;
        if(plotShowTimer.isActive())
            plotShowTimer.stop();
        plotShowTimer.start(500);      //定时器改为100ms进行一次刷新

        plot_type = 2;
        ui->stackedWidget->setCurrentIndex(2);

    }
    else if(0 == index)
    {
        if(plotShowTimer.isActive())
            plotShowTimer.stop();

    }

}


//!
//! \brief MainWindow::on_rowData_pushButton_clicked
//!  请求RowData的数据 5A 00 01 10 0A DD..DD
void MainWindow::on_rowData_pushButton_clicked()
{
//    QString strData = QString("%1").arg(2,4096*2,16,QLatin1Char('0'));
    QString cmdStr = "5A 00 01 00 0A ";
//    cmdStr.append(strData);
    emit sendSerialSignal(cmdStr);
}


//show plot
void MainWindow::on_plotSet_on_radioButton_clicked()
{
    plotShowTimer.start(20);
    plot_Mode = true;
    ui->groupBox_2->setVisible(true);

}
//hide plot
void MainWindow::on_plotSet_off_radioButton_clicked()
{
    plotShowTimer.stop();
    plot_Mode = false;
    ui->groupBox_2->setVisible(false);

}


//显示统计信息的槽函数 20ms刷新一次
void MainWindow::plotShowTimer_slot()
{
    QVector<double> label_x(20000);
    QVector<double> tofValue(20000);

    float labelMax = 0;
    float valueMax = 0;
    float valueMin = 100000;
    if(plot_Mode)   //用户选中了显示统计信息的模式
    {
        if(0 == plot_type)          //显示tof的统计信息      暂时不考虑之
        {
            int len = PlotData_vector.size();

            for(int i=0; i< len; i++)
            {
                label_x[i] = i;
                tofValue[i] = PlotData_vector[i];

                valueMin = valueMin>tofValue[i] ? tofValue[i]:valueMin;
                valueMax = valueMax>tofValue[i] ? valueMax:tofValue[i];    //统计tof的最大值，方便显示
            }
            labelMax = PlotData_vector.size();

//            qDebug()<<"valueMin = "<<valueMin<<"   valueMax="<<valueMax;

            ui->TOF_widget->xAxis->setRange(0,labelMax);
            ui->TOF_widget->yAxis->setRange(valueMin-1,valueMax+1);
            ui->TOF_widget->graph(0)->setData(label_x,tofValue);
            ui->TOF_widget->replot();


        }

        //  5A 00 01 08 09 DD..DDDDD  XX
        else if(1 == plot_type)    //  VI4300显示直方图的信息      将这里改成发送请求 直方图的数据
        {
//            QString strData = QString("%1").arg(2,2048*2,16,QLatin1Char('0'));
            QString cmdStr = "5A 00 02 00 09 00";
//            cmdStr.append(strData);
            emit sendSerialSignal(cmdStr);
        }
        else if(2 == plot_type)    //CASSSET 显示直方图信息  请求直方图的数据
        {
            QString cmdStr = "5A 00 02 00 0E 00";
            emit sendSerialSignal(cmdStr);
        }


    }
}


// 4300 显示统计直方图放的槽函数
void MainWindow::toShowHistogram_slot(QVector<double> numData,int yMax)
{
//    qDebug()<<" xTicks = "<<xTicks;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->setTicks(HistorgramTicks_2048, HistorgramLabels_2048);
    ui->Histogram_widget->xAxis->setTicker(textTicker);

    ui->Histogram_widget->xAxis->setRange(0,historgram_label_num_2048);
    ui->Histogram_widget->yAxis->setRange(0,yMax);

    regen->setData(HistorgramTicks_2048, numData);        //只不过第一个向量xTicks的每个元素表示“第几个柱子”，然后后面对应的values表示对应“柱子的值”
    ui->Histogram_widget->replot();

}


//!
//! \brief MainWindow::toShowHistogram_4096_signal
//!   cassset   4096个点的
void MainWindow::toShowHistogram_4096_slot(QVector<double> numData,int yMax)
{
//    qDebug()<<" xTicks = "<<xTicks;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->setTicks(HistorgramTicks_4096, HistorgramLabels_4096);
    ui->casset_historgrm_widget->xAxis->setTicker(textTicker);

    ui->casset_historgrm_widget->xAxis->setRange(0,historgram_label_num_4096);
    ui->casset_historgrm_widget->yAxis->setRange(0,yMax);

    regen_4096->setData(HistorgramTicks_4096,numData);
    ui->casset_historgrm_widget->replot();

}



//保存统计图像
void MainWindow::on_savePicture_pushButton_clicked()
{
    QString filePath;

    QFileDialog *fileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
    fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
    fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
    fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
    fileDialog->setGeometry(10,30,300,200);//设置文件对话框的显示位置
    fileDialog->setDirectory(".");//设置文件对话框打开时初始打开的位置
    QStringList mimeTypeFilters;
//    mimeTypeFilters <<"(*.bmp)|*.bmp|JPEG(*.jpg)|*.jpg;|Png(*.png)|*.png" ;
    mimeTypeFilters<<"bmp(*.bmp)|*.bmp"<<"JPEG(*.jpg)|*.jpg"<<"Png(*.png)|*.png"<<"PDF(*.pdf)|*.pdf";
    fileDialog->setNameFilters(mimeTypeFilters);


    if(fileDialog->exec() == QDialog::Accepted)
    {
        filePath = fileDialog->selectedFiles()[0];//得到用户选择的文件名
        qDebug()<<" filePath = "<<filePath<<endl;
        QString formatStr = filePath.right(3);
        if(0 == plot_type)   //保存统计图
        {
            if("bmp" == formatStr)
            {
                ui->TOF_widget->saveBmp(filePath.toLatin1().data());
            }else if("jpg" == formatStr)
            {
                ui->TOF_widget->saveJpg(filePath.toLatin1().data());
            }else if("png" == formatStr)
            {
                ui->TOF_widget->savePng(filePath.toLatin1().data());
            }else if("pdf" == formatStr)
            {
                ui->TOF_widget->savePdf(filePath.toLatin1().data());
            }

        }else                //保存直方图
        {
            if("bmp" == formatStr)
            {
                ui->Histogram_widget->saveBmp(filePath.toLatin1().data());
            }else if("jpg" == formatStr)
            {
                ui->Histogram_widget->saveJpg(filePath.toLatin1().data());
            }else if("png" == formatStr)
            {
                ui->Histogram_widget->savePng(filePath.toLatin1().data());
            }else if("pdf" == formatStr)
            {
                ui->Histogram_widget->savePdf(filePath.toLatin1().data());
            }
        }
    }else
    {
        return ;
    }

}

//打开寄存器界面
void MainWindow::on_Register_action_triggered()
{
    registerDia.setModal(true);
    registerDia.show();
}

//MCU升级界面打开
void MainWindow::on_actionMCU_triggered()
{
    McuUpgradeDia.setModal(true);
    McuUpgradeDia.show();
}


//!
//! \brief MainWindow::on_singleMeasure_pushButton_clicked
//!
//!单次测量的槽函数   5A 00 09 00 07 DD.DD XX
void MainWindow::on_singleMeasure_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A 00 09 00 07 00 00 00 00 00 00 00 00 ";
    emit sendSerialSignal(cmdStr);
}

//!
//! \brief MainWindow::on_delayMeasure_pushButton_clicked
//!
//!连续测量的槽函数
//! 1、开启连续测量以后 其他串口相关的操作都关闭 防止程序崩溃 ，除了停止按键以外
//! 开启命令 5A 01 02 00 08 00
void MainWindow::on_delayMeasure_pushButton_clicked()
{

    SerialSetting_Enable_false();
    ui->stopMeasure_pushButton->setEnabled(true);

    //命令组帧
    QString cmdStr = "5A 01 02 00 08 00";
    emit sendSerialSignal(cmdStr);
}


//!
//! \brief MainWindow::on_stopMeasure_pushButton_clicked
//! 停止  测量的槽函数
//! 停止命令 5A 01 02 00 08 FF
void MainWindow::on_stopMeasure_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A 01 02 00 08 FF";
    emit sendSerialSignal(cmdStr);

    SerialSetting_Enable_true();
}


//!
//! \brief MainWindow::on_read_outFactory_pushButton_clicked
//! 读取出厂设置 槽函数  5A 00 23 00 02 DDD..D XX
void MainWindow::on_read_outFactory_pushButton_clicked()
{

    //命令组帧 0X22 34
    QString data = QString("%1").arg(0,68,16,QLatin1Char('0'));

    QString cmdStr = "5A 00 23 00 02 ";
    cmdStr.append(data);
    emit sendSerialSignal(cmdStr);
}


//!
//! \brief MainWindow::on_outFactory_pushButton_clicked
//!  出厂设置 点击发送的槽函数  （SN 、 波特率）  5A 01 23 00 02 DD..DD XX
//! SN :      4
//! UUID :    12
//! BAUDRATE: 1
//! CAIJI:    1
//! DeviceId :1
//! Ranges :  2
//! YULIU:    13
//! 界面上输入十六进制数据
void MainWindow::on_send_outFactory_pushButton_clicked()
{

    QString SN_number = ui->SN_lineEdit->text();
    QString SN_numberStr = SN_number.replace(" ","");
    if(SN_numberStr.length() > 8)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("SN号过长，请重新输入！"));
        return;
    }
    QString str = "00000000" + SN_numberStr;
    SN_numberStr = str.right(8);
    qDebug()<<" SN_numberStr = "<<SN_numberStr   <<" len="<<SN_numberStr.length();


    QString UUID_num = ui->UUID_lineEdit->text();
    QString UUID_str = UUID_num.replace(" ","");
    if(UUID_str.length()>24)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("UUID号过长，请重新输入！"));
        return;
    }
    str = "000000000000000000000000" + UUID_str;
    UUID_str = str.right(24);
    qDebug()<<" UUID_str = "<<UUID_str<<" len="<<UUID_str.size();

//    //波特率
    QString banuRateStr = QString("%1").arg(ui->botelv_comboBox->currentIndex(),2,16,QLatin1Char('0'));
    qDebug()<<" baudRateStr = "<<banuRateStr<<" len="<<banuRateStr.size();

//    //采集频率
//    QString caiji_str = QString("%1").arg(ui->CAIJI_frequency_comboBox->currentIndex(),2,16,QLatin1Char('0'));
//    qDebug()<<" caiji_str = "<<caiji_str<<" len="<<caiji_str.length();

    //设备类型
    //  VI4300_Master =0x00;
    //  VI4300_Slave = 0x01;
    //  LDS = 0x02
    QString deviceType_str = ui->deviceType_comboBox->currentText();
    int TypeIndex = 0;
    if("VI4300_Master" == deviceType_str)
    {
        TypeIndex = 0;
    }else if("VI4300_Slave" == deviceType_str)
    {
        TypeIndex = 1;
    }else if("LDS" == deviceType_str)
    {
        TypeIndex = 2;
    }

    QString deviceType = QString("%1").arg(TypeIndex,2,16,QLatin1Char('0'));
    qDebug()<<" deviceType = "<<deviceType<<" len="<<deviceType.length();


    QString version_str = "0000";


//    //最大量程(单位 ：mm)
//    int measurement_range = ui->Range_lineEdit->text().toInt();
//    QString measurement_range_str_tmp = QString("%1").arg(measurement_range,4,16,QLatin1Char('0'));
//    QString measurement_range_str = measurement_range_str_tmp.mid(2,2) + measurement_range_str_tmp.mid(0,2);
//    qDebug()<<"measurement_range_str = "<<measurement_range_str;


    //预留数据
    QString YuLiu_str = QString("%1").arg(0,28,16,QLatin1Char('0'));
//    QString YuLiu_num = ui->YULIU_lineEdit->text();
//    QString YuLiu_str = YuLiu_num.replace(" ","");
//    if(YuLiu_str.length()>26)
//    {
//        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("预留数据过长，请重新输入！"));
//        return;
//    }
//    str = "00000000000000000000000000000000" + YuLiu_str;
//    YuLiu_str = str.right(26);
//    qDebug()<<" YuLiu_str = "<<YuLiu_str<<" len="<<YuLiu_str.length();


    //命令组帧
    QString cmdStr = "5A 01 23 00 02 ";
    cmdStr.append(SN_numberStr).append(UUID_str).append(banuRateStr).append(deviceType).append(version_str).append(YuLiu_str);

    emit sendSerialSignal(cmdStr);



    //清空lineEdit
    ui->SN_lineEdit->clear();
    ui->UUID_lineEdit->clear();


}

//!
//! \brief MainWindow::on_reStoreFactory_pushButton_clicked
//! 恢复出厂设置 5A 01 02 00 03 00
void MainWindow::on_reStoreFactory_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A 01 02 00 03 00 ";
    emit sendSerialSignal(cmdStr);
}

QByteArray MainWindow::StringToByte(QString str)
{
    QByteArray byte_arr;
    bool ok;
    str = str.replace(" ","");    //去掉空格键
    int len=str.size();
    for(int i=0;i<len;i+=2){
         byte_arr.append(char(str.mid(i,2).toUShort(&ok,16)));
    }

    return byte_arr;
}


//QString中存储的16进制数据，解析为float型的数据   现在已经是小端模式了
float MainWindow::QStringToFloat(QString str)
{
    QByteArray betaArray =StringToByte(str);
    unsigned char* hexStr1 =  (unsigned char*)betaArray.data();
    float x;
    unsigned char c[4];
    c[0] = hexStr1[0];
    c[1] = hexStr1[1];
    c[2] = hexStr1[2];
    c[3] = hexStr1[3];
    memcpy(&x,c,4);
    qDebug()<<"x = "<<x;
    return x;
}


//将float数据 转换为16进制数据 并存储在QString 当中  现在已经是小端模式了
QString MainWindow::floatToQString(float fVal)
{
    float x_pid_p = fVal;
    unsigned char * bValue = (unsigned char *)& x_pid_p;
    printf("%x\t%x\t%x\t%x\n", bValue[0], bValue[1], bValue[2], bValue[3]);

    char *str1 = (char *)bValue;
    QByteArray betaArray1 = QByteArray(str1,4);
    QDataStream out(&betaArray1,QIODevice::ReadWrite);
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
//    qDebug()<<QStringLiteral("把float型数据解析为QString 为：")<<strHex<<"   len="<< strHex.length()/3<<endl;
    return strHex;
}

//!
//! \brief MainWindow::on_calibration_read_pushButton_clicked
//!  出厂校准1 读取 点击槽函数  （真实距离）  5A 00 07 00 04 DD DD DD DD DD DD
//!  出厂校准1 读取 点击槽函数  （真实距离）  5A 00 02 00 04 00
//!
void MainWindow::on_calibration_read_pushButton_clicked()
{
    //命令组帧
//    QString cmdStr = "5A 00 0B 00 04 ";
    QString cmdStr = "5A 00 01 00 04";
    emit sendSerialSignal(cmdStr);
}


//!
//! \brief MainWindow::on_calibration_pushButton_clicked
//! 出厂校准1 点击设置的槽函数 （真实距离）  5A 01 07 00 04 DD DD DD DD DD DD
//!     增加了一个字节，协议更改为          5A 01 08 00 04 DD DD DD DD DD DD DD
//!     增加了抗阳光一个字节，协议改为      5A 01 09 00 04 DD DD DD DD DD DD DD DD
//! 2020-03-24  协议更改
//!   5A 01 19 00  04  DDDDDDD(24 BYTE)
void MainWindow::on_calibration_pushButton_clicked()
{
    int realDis = ui->realDisFactory_lineEdit->text().toInt();
    QString realDisStrTmp = QString("%1").arg(realDis,4,16,QLatin1Char('0'));   //真实距离
    QString realDisStr = realDisStrTmp.mid(2,2) + realDisStrTmp.mid(0,2);
    qDebug()<<"realDis = "<<realDisStr;

    float K1 = ui->K1_lineEdit->text().toFloat() ;      //十进制的float数字
    int k1_num = int (K1 *1000);                        //转化为10进制,扩大1000以后的数值
    QString k1Tmp = QString("%1").arg(k1_num,8,16,QLatin1Char('0'));
    QString K1Str = k1Tmp.mid(6,2) +k1Tmp.mid(4,2) +k1Tmp.mid(2,2) +k1Tmp.mid(0,2);  //K1
    qDebug()<<"K1Str="<<K1Str;


    int tempture_coefficient = ui->tempture_k_lineEdit->text().toInt();
    QString tempture_coeff_str = QString("%1").arg(tempture_coefficient,2,16,QLatin1Char('0'));  //温度校正系数
    qDebug()<<"tempture_coeff_str="<<tempture_coeff_str;

    int sunPower_index = ui->sunPower_set_comboBox->currentIndex();
    QString sunPower_str = QString("%1").arg(sunPower_index,2,16,QLatin1Char('0'));   //抗阳光强度
    qDebug()<<"sunPower_str="<<sunPower_str;

    int maxValue = ui->offset_maxValue_lineEdit->text().toInt();
    QString maxValueTmp = QString("%1").arg(maxValue,8,16,QLatin1Char('0'));
    QString maxValueStr = maxValueTmp.mid(6,2) +maxValueTmp.mid(4,2) +maxValueTmp.mid(2,2) +maxValueTmp.mid(0,2);  //最大量程
    qDebug()<<"maxValueStr="<<maxValueStr;

    int filter_select = ui->filter_comboBox->currentIndex();
    QString filter_str = QString("%1").arg(filter_select,2,16,QLatin1Char('0'));   //滤波方式
    qDebug()<<"filter_str="<<filter_str;


    int caiji_int = ui->offset_caiji_comboBox->currentIndex();
    QString caiji_str =  QString("%1").arg(caiji_int,2,16,QLatin1Char('0'));   //采集频率
    qDebug()<<"caiji_str="<<caiji_str;

    int peak_offset = ui->peakOffset_lineEdit->text().toInt();
    QString peakOffset_str = QString("%1").arg(peak_offset,2,16,QLatin1Char('0'));   //peak阈值
    qDebug()<<"peakOffset_str="<<peakOffset_str;

    QString yuliu_str = QString("%1").arg(0,18,16,QLatin1Char('0'));   //peak阈值


    //命令组帧
    QString cmdStr = "5A 01 19 00 04 ";
    cmdStr.append(realDisStr);
    cmdStr.append(K1Str);
    cmdStr.append(tempture_coeff_str);
    cmdStr.append(sunPower_str);
    cmdStr.append(maxValueStr);
    cmdStr.append(filter_str);
    cmdStr.append(caiji_str);
    cmdStr.append(peakOffset_str);
    cmdStr.append(yuliu_str);
    emit sendSerialSignal(cmdStr);

    ui->realDisFactory_lineEdit->clear();
    ui->K1_lineEdit->clear();
    ui->tempture_k_lineEdit->clear();
    ui->offset_maxValue_lineEdit->clear();
    ui->peakOffset_lineEdit->clear();

}


//!
//! \brief MainWindow::on_gaofan_pushButton_clicked
//! 高反校准 的弹出窗口
void MainWindow::on_gaofan_pushButton_clicked()
{
    highReactDia.setModal(true);
    highReactDia.show();
}





//输出真实距离 与 原始LSB 的选项
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(1 == index)    //输出真实距离  5A 01 02 00 06 00
    {
        //命令组帧
        QString cmdStr = "5A 01 02 00 06 00";
        emit sendSerialSignal(cmdStr);

    }else if(2 == index)  //输出设置为LSB 5A 01 02 00 06 01
    {
        //命令组帧
        QString cmdStr = "5A 01 02 00 06 01";
        emit sendSerialSignal(cmdStr);
    }
}


//!
//! \brief AckCmdMain_signal
//!主界面配置的相关信息返回信号    参数1：“8102”：写入出厂设置成功，   参数2暂无
//!                             参数1：“8002”：读取出厂设置 ，     参数2 数据
//!                             参数1：“8103”：恢复出厂设置成功     参数2暂无
//!                             参数1：“8104”：设置 距离offset校准成功  参数2 "04":第一种校准  “0B”：第二种校准
//!                             参数1：“8105”：高反校准成功，      参数2暂无
//!                             参数1：“8106”：输出数据设置成功     参数2 00：原始距离 01：LSB
//!                             参数1：“8004”：读取 距离offset校准信息  参数2 6个字节第一种校准，10个字节第二种校准
//!                             参数1：“800D”：读取单个寄存器      参数2:4个字节 前两个字节为地址，后两个字节为值
//!                             参数1："810D":写入单个寄存器成功   参数2：暂无
void MainWindow::AckCmdMain_slot(QString returnCmdStr,QString cmdAck)
{
    if("8102" ==returnCmdStr )
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("出厂设置成功！"));
        return;
    }
    else if("8002" == returnCmdStr)   //SN:4  UUID:12  baudRate:1   caiji:1   deviceType:1  range:2  yuliu:13
    {
        QString SN_str = cmdAck.mid(0,8);
        QString UUID_str = cmdAck.mid(8,24);
        int baudRateIndex = cmdAck.mid(32,2).toInt(NULL,16);
        int deviceTypeIndex = cmdAck.mid(34,2).toInt(NULL,16);
        QString version_str = cmdAck.mid(36,4);

//        QString range_str = cmdAck.mid(38,4);
//        QString range_tmp = range_str.mid(2,2)+ range_str.mid(0,2);
//        int range_int = range_tmp.toInt(NULL,16);
//        QString YuLiuStr = cmdAck.mid(42,26);

        ui->SN_lineEdit->setText(SN_str);
        ui->UUID_lineEdit->setText(UUID_str);
        ui->botelv_comboBox->setCurrentIndex(baudRateIndex);
//        ui->CAIJI_frequency_comboBox->setCurrentIndex(caijiIndex);
        ui->deviceType_comboBox->setCurrentIndex(deviceTypeIndex);  //VI4300_Slave（芯视界测试用，不对外开放）  0x01
        ui->versionNum_lineEdit->setText(version_str);

        return;
    }
    else if("8103" == returnCmdStr)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("恢复出厂设置成功！"));
        return;
    }
    else if("8104" == returnCmdStr)
    {
        if("07" == cmdAck)
        {
            QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("距离offset_1校准设置成功！"));
        }else if("0B" == cmdAck)
        {
            QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("距离offset_2校准设置成功！"));
        }

        return;
    }else if("8105" == returnCmdStr)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("高反offset校准设置成功！"));
        return;
    }
    else if("8106" == returnCmdStr)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("数据输出设置成功！"));
        return;
    }
    else if("8004" == returnCmdStr)
    {
        int ackCmdLen = cmdAck.length();  //  D1 D1 D2 D2 D2 D2
        qDebug()<<"ackCmdLen = "<<ackCmdLen;

        if(12 == ackCmdLen)   //第一次校准  读取返回指令 信息
        {
            QString strDis = cmdAck.mid(2,2) + cmdAck.mid(0,2);
            int disTance = strDis.toInt(NULL,16);
            QString k1_str = cmdAck.mid(4,8) ;
            QString tmpStr = k1_str.mid(6,2) +k1_str.mid(4,2)+k1_str.mid(2,2)+k1_str.mid(0,2);

            float K1 = tmpStr.toInt(NULL,16)/1000.0;

            ui->realDisFactory_lineEdit->setText(QString::number(disTance));
            ui->K1_lineEdit->setText(QString::number(K1));

        }else if(22 == ackCmdLen)    //第二次校准  读取返回指令 信息    新增了抗阳光强度信息的读取（1个字节）
        {
            //  D1 D1 D2 D2 D3 D3 D4 D4 D4 D4 D5
            QString strDis = cmdAck.mid(2,2) + cmdAck.mid(0,2);
            int disTance = strDis.toInt(NULL,16);
            QString temptureStr = cmdAck.mid(6,2) + cmdAck.mid(4,2);
            int tempture = temptureStr.toInt(NULL,16);          //这里是校准时温度 扩大100倍的值
            QString offsetStr = cmdAck.mid(10,2) + cmdAck.mid(8,2);
            int offset = offsetStr.toInt(NULL,16);              //这里是offset值，扩大10倍后的值

            QString k2_str = cmdAck.mid(12,8) ;                 //K2的系数  这里是扩大1000倍以后的数值
            QString k2_str_tmp = k2_str.mid(6,2)+k2_str.mid(4,2)+k2_str.mid(2,2)+k2_str.mid(0,2);
            float K2 = k2_str_tmp.toInt(NULL,16)/1000.0;

            QString sunPower_str = cmdAck.mid(20,2);
            int sunPower_int = sunPower_str.toInt(NULL,16);

            ui->realDisFactory_2_lineEdit->setText(QString::number(disTance));
            ui->temperature_lineEdit->setText(QString::number(tempture));
            ui->offset_jiaozhun_lineEdit->setText(QString::number(offset));
            ui->K2_lineEdit->setText(QString::number(K2));
            ui->sunPower_read_lineEdit->setText(QString::number(sunPower_int));

        }else if(48 == ackCmdLen)   //新增协议 03.24
        {
//            int realDis = ui->realDisFactory_lineEdit->text().toInt();

//            float K1 = ui->K1_lineEdit->text().toFloat() ;      //十进制的float数字
//            int k1_num = int (K1 *1000);      //转化为10进制,扩大1000以后的数值

//        //    QString K1Str = floatToQString(K1);

//            QString realDisStrTmp = QString("%1").arg(realDis,4,16,QLatin1Char('0'));   //真实距离
//            QString realDisStr = realDisStrTmp.mid(2,2) + realDisStrTmp.mid(0,2);

//            QString k1Tmp = QString("%1").arg(k1_num,8,16,QLatin1Char('0'));
//            QString K1Str = k1Tmp.mid(6,2) +k1Tmp.mid(4,2) +k1Tmp.mid(2,2) +k1Tmp.mid(0,2);  //K1
//        //    qDebug()<<"ki_num="<<k1_num<<"  k1Tmp="<<k1Tmp;


//            int tempture_coefficient = ui->tempture_k_lineEdit->text().toInt();
//            QString tempture_coeff_str = QString("%1").arg(tempture_coefficient,2,16,QLatin1Char('0'));  //温度校正系数

//            int sunPower_index = ui->sunPower_set_comboBox->currentIndex();
//            QString sunPower_str = QString("%1").arg(sunPower_index,2,16,QLatin1Char('0'));   //抗阳光强度

//            int maxValue = ui->offset_maxValue_lineEdit->text().toInt();
//            QString maxValueTmp = QString("%1").arg(maxValue,8,16,QLatin1Char('0'));
//            QString maxValueStr = maxValueTmp.mid(6,2) +maxValueTmp.mid(4,2) +maxValueTmp.mid(2,2) +maxValueTmp.mid(0,2);  //最大量程

//            int filter_select = ui->filter_comboBox->currentIndex();
//            QString filter_str = QString("%1").arg(filter_select,2,16,QLatin1Char('0'));   //滤波方式

//            int caiji_int = ui->offset_caiji_comboBox->currentIndex();
//            QString caiji_str =  QString("%1").arg(caiji_int,2,16,QLatin1Char('0'));   //采集频率

//            int peak_offset = ui->peakOffset_lineEdit->text().toInt();
//            QString peakOffset_str = QString("%1").arg(peak_offset,2,16,QLatin1Char('0'));   //peak阈值

//            QString yuliu_str = QString("%1").arg(0,18,16,QLatin1Char('0'));   //peak阈值

            //距离
            QString strDis = cmdAck.mid(2,2) + cmdAck.mid(0,2);
            int disTance = strDis.toInt(NULL,16);
            ui->realDisFactory_lineEdit->setText(QString::number(disTance));
            //系数 K
            QString k2_str = cmdAck.mid(4,8) ;                 //K2的系数  这里是扩大1000倍以后的数值
            QString k2_str_tmp = k2_str.mid(6,2)+k2_str.mid(4,2)+k2_str.mid(2,2)+k2_str.mid(0,2);
            float K2 = k2_str_tmp.toInt(NULL,16)/1000.0;
            ui->K1_lineEdit->setText(QString::number(K2));
            //温度校正系数
            QString tempture_str = cmdAck.mid(12,2);
            int tempture_int = tempture_str.toInt(NULL,16);
            ui->tempture_k_lineEdit->setText(QString::number(tempture_int));
            //抗阳光强度
            int sunPower_index = cmdAck.mid(14,2).toInt(NULL,16);
            ui->sunPower_set_comboBox->setCurrentIndex(sunPower_index);
            //最大量程设置
            QString maxValue_str = cmdAck.mid(16,8);
            QString maxValueTmp = maxValue_str.mid(6,2)+maxValue_str.mid(4,2)+maxValue_str.mid(2,2)+maxValue_str.mid(0,2);;
            int maxValue_int =  maxValueTmp.toInt(NULL,16);
            ui->offset_maxValue_lineEdit->setText(QString::number(maxValue_int));
            //滤波方式
            int filter_int = cmdAck.mid(24,2).toInt(NULL,16);
            ui->filter_comboBox->setCurrentIndex(filter_int);
            //采集频率
            int caiji_int = cmdAck.mid(26,2).toInt(NULL,16);
            ui->offset_caiji_comboBox->setCurrentIndex(caiji_int);
            //过滤阈值
            int peakOffset = cmdAck.mid(28,2).toInt(NULL,16);
            ui->peakOffset_lineEdit->setText(QString::number(peakOffset));

        }



    }
    else if("800D" == returnCmdStr)   //cmdAck ：四个字节 前两个字节为地址 后两个字节为值
    {
        QString addr_reg = cmdAck.mid(0,2);
        QString value_reg = cmdAck.mid(2,2);
        if(addr_reg == ui->singleReg_addr_lineEdit->text())
        {
            ui->singleReg_value_lineEdit->setText(value_reg);
        }
    }
    else if("810D" == returnCmdStr)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("寄存器写入成功！"));
        return;
    }

}



//!
//! \brief MainWindow::on_actionEnglish_triggered
//! 语言切换：英文
void MainWindow::on_actionEnglish_triggered()
{
//    if(translator.load("translate/myApp_EN.qm"))
//    {
//        qApp->installTranslator(&translator);
//        qDebug()<<"translator  load success";
//    }


    if(translator.load(":/language/translate/myApp_EN.qm"))
    {
        qApp->installTranslator(&translator);
        qDebug()<<"translator  load success";
    }else
    {
        qDebug()<<"translate load error";
    }

}

//!
//! \brief MainWindow::on_action_china_triggered
//!语言切换：中文
void MainWindow::on_action_china_triggered()
{
    if(translator.load("resources/tr_zh_nouse.qm"))
    qApp->installTranslator(&translator);
}

//!
//! \brief MainWindow::changeEvent
//! \param e
//!语言切换以后 界面刷新的槽函数
void MainWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}







//显示历史TOF图的窗口
void MainWindow::on_showTOF_action_TOF_triggered()
{
    hisTof_dia.setModal(true);
    hisTof_dia.show();
}


//!
//! \brief MainWindow::on_manageMent_action_triggered
//!设备数据库管理界面
void MainWindow::on_manageMent_action_triggered()
{
    devManagement_dia.initSelect();
    devManagement_dia.setModal(true);
    devManagement_dia.show();
}


//!
//! \brief MainWindow::on_savePicture_his_pushButton_clicked
//!存储直方图 图片
void MainWindow::on_savePicture_his_pushButton_clicked()
{
    QString filePath;

    QFileDialog *fileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
    fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
    fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
    fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
    fileDialog->setGeometry(10,30,300,200);//设置文件对话框的显示位置
    fileDialog->setDirectory(".");//设置文件对话框打开时初始打开的位置
    QStringList mimeTypeFilters;
//    mimeTypeFilters <<"(*.bmp)|*.bmp|JPEG(*.jpg)|*.jpg;|Png(*.png)|*.png" ;
    mimeTypeFilters<<"bmp(*.bmp)|*.bmp"<<"JPEG(*.jpg)|*.jpg"<<"Png(*.png)|*.png"<<"PDF(*.pdf)|*.pdf";
    fileDialog->setNameFilters(mimeTypeFilters);


    if(fileDialog->exec() == QDialog::Accepted)
    {
        filePath = fileDialog->selectedFiles()[0];//得到用户选择的文件名
        qDebug()<<" filePath = "<<filePath<<endl;
        QString formatStr = filePath.right(3);
        //保存直方图
        if("bmp" == formatStr)
        {
            ui->Histogram_widget->saveBmp(filePath.toLatin1().data());
        }else if("jpg" == formatStr)
        {
            ui->Histogram_widget->saveJpg(filePath.toLatin1().data());
        }else if("png" == formatStr)
        {
            ui->Histogram_widget->savePng(filePath.toLatin1().data());
        }else if("pdf" == formatStr)
        {
            ui->Histogram_widget->savePdf(filePath.toLatin1().data());
        }

    }else
    {
        return ;
    }
}

//!
//! \brief MainWindow::on_HistogramData_pushButton_clicked
//!//选择是否保存 直方图数据
//! 文件标识：saveHist_index;
//! 是否保存文件标识: isSaveHistData_flag
void MainWindow::on_HistogramData_pushButton_clicked()
{
    if("HistData_save" == ui->HistogramData_pushButton->text())
    {
        QString file_path = QFileDialog::getExistingDirectory(this,QStringLiteral("请选择文件保存路径..."),"./");
        if(file_path.isEmpty())
        {
           qDebug()<<QStringLiteral("没有选择路径")<<endl;
           QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("保存路径不能为空"));
            return;
        }
        else
        {
            file_path.append("/");
            qDebug() << file_path << endl;
            saveHistDataFilePath = file_path;

            saveHist_index = 1;  //文件标号
            isSaveHistData_flag = true;//开始保存
            ui->HistogramData_pushButton->setText("Stop");
        }


    }else
    {
        isSaveHistData_flag = false;
        ui->HistogramData_pushButton->setText("HistData_save");
    }
}





//!
//! \brief MainWindow::on_casset_imageSave_pushButton_clicked
//!  CASSET 直方图  图片保存
void MainWindow::on_casset_imageSave_pushButton_clicked()
{
    QString filePath;

    QFileDialog *fileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
    fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
    fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
    fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
    fileDialog->setGeometry(10,30,300,200);//设置文件对话框的显示位置
    fileDialog->setDirectory(".");//设置文件对话框打开时初始打开的位置
    QStringList mimeTypeFilters;
//    mimeTypeFilters <<"(*.bmp)|*.bmp|JPEG(*.jpg)|*.jpg;|Png(*.png)|*.png" ;
    mimeTypeFilters<<"bmp(*.bmp)|*.bmp"<<"JPEG(*.jpg)|*.jpg"<<"Png(*.png)|*.png"<<"PDF(*.pdf)|*.pdf";
    fileDialog->setNameFilters(mimeTypeFilters);


    if(fileDialog->exec() == QDialog::Accepted)
    {
        filePath = fileDialog->selectedFiles()[0];//得到用户选择的文件名
        qDebug()<<" filePath = "<<filePath<<endl;
        QString formatStr = filePath.right(3);
        //保存直方图
        if("bmp" == formatStr)
        {
            ui->casset_historgrm_widget->saveBmp(filePath.toLatin1().data());
        }else if("jpg" == formatStr)
        {
            ui->casset_historgrm_widget->saveJpg(filePath.toLatin1().data());
        }else if("png" == formatStr)
        {
            ui->casset_historgrm_widget->savePng(filePath.toLatin1().data());
        }else if("pdf" == formatStr)
        {
            ui->casset_historgrm_widget->savePdf(filePath.toLatin1().data());
        }

    }else
    {
        return ;
    }
}


//!
//! \brief MainWindow::on_casset_historgram_pushButton_clicked
//!  CASSET 直方图数据保存 保存的为原始顺序的数据
void MainWindow::on_casset_historgram_pushButton_clicked()
{
    if("HistData_save" == ui->casset_historgram_pushButton->text())
    {
        QString file_path = QFileDialog::getExistingDirectory(this,QStringLiteral("请选择文件保存路径..."),"./");
        if(file_path.isEmpty())
        {
           qDebug()<<QStringLiteral("没有选择路径")<<endl;
           QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("保存路径不能为空"));
            return;
        }
        else
        {
            file_path.append("/");
            qDebug() << file_path << endl;
            saveHistDataFilePath = file_path;
            saveHist_index = 1;  //文件标号
            isSaveHistData_flag = true;//开始保存
            ui->casset_historgram_pushButton->setText("Stop");
        }
    }else
    {
        isSaveHistData_flag = false;
        ui->casset_historgram_pushButton->setText("HistData_save");
    }
}




//!
//! \brief MainWindow::on_pixel_read_pushButton_clicked
//!//单pixel模式peak值读取: 5A 00 01 00 0F
void MainWindow::on_pixel_read_pushButton_clicked()
{
    QString cmdStr = "5A 00 01 00 0F ";
    emit sendSerialSignal(cmdStr);
}



//!
//! \brief MainWindow::on_singleReg_read_pushButton_clicked
//!单个寄存器的读取
//!  5A 00 03 00 0D DD DD
void MainWindow::on_singleReg_read_pushButton_clicked()
{
    QString single_addr = ui->singleReg_addr_lineEdit->text();
    QString single_value = "00";

    //地址1个字节 要判断长度
    if(single_addr.length()!=2)
    {
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("地址输入错误，请重新输入!"));
        ui->singleReg_addr_lineEdit->clear();
    }

    QString cmdStr = "5A 00 03 00 0D ";
    cmdStr.append(single_addr).append(single_value);
    emit sendSerialSignal(cmdStr);    
}



//!
//! \brief MainWindow::on_singleReg_write_pushButton_clicked   //单个寄存去的写入
//!  5A 01 03 00 0D DD DD
void MainWindow::on_singleReg_write_pushButton_clicked()
{
    QString single_addr = ui->singleReg_addr_lineEdit->text();
    QString single_value = ui->singleReg_value_lineEdit->text();
    //地址1个字节 要判断长度
    if(single_addr.length()!=2)
    {
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("地址输入错误，请重新输入!"));
        ui->singleReg_addr_lineEdit->clear();
    }
    //值1个字节 要判断长度
    if(single_value.length()!=2)
    {
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("地址输入错误，请重新输入!"));
        ui->singleReg_value_lineEdit->clear();
    }

    QString cmdStr = "5A 01 03 00 0D";
    cmdStr.append(single_addr).append(single_value);
    emit sendSerialSignal(cmdStr);

    //把值清空
    ui->singleReg_value_lineEdit->clear();

}



