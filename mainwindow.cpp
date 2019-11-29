#include "mainwindow.h"
#include "ui_mainwindow.h"


Settings currentSettings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUILanguage();

//    ui->groupBox_5->setEnabled(false);
    ui->ResultHistory_textEdit->document()->setMaximumBlockCount(7000);    //最多显示10000行，滑动存储  10w

    qRegisterMetaType<vector<double>>("vector<double>");   //注册函数
    qRegisterMetaType<vector<int>>("vector<int>");       //注册函数
    qRegisterMetaType<QVector<double>>("QVector<double>");   //注册函数
    qRegisterMetaType<QVector<QString>>("QVector<QString>");   //注册函数

    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,2);
    ui->splitter->setStretchFactor(2,5);
    ui->groupBox_2->setVisible(false);


    ui->savePath_lineEdit->setReadOnly(true);
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
    ui->calibration_pushButton->setEnabled(false);
    ui->outSetting_pushButton->setEnabled(false);
    ui->singleMeasure_pushButton->setEnabled(false);
    ui->delayMeasure_pushButton->setEnabled(false);
    ui->stopMeasure_pushButton->setEnabled(false);

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
    ui->outSetting_pushButton->setEnabled(true);
    ui->singleMeasure_pushButton->setEnabled(true);
    ui->delayMeasure_pushButton->setEnabled(true);
    ui->stopMeasure_pushButton->setEnabled(true);
}

void MainWindow::initUINum()
{
//    ui->botelv_comboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
//    ui->botelv_comboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
//    ui->botelv_comboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
//    ui->botelv_comboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
//    ui->botelv_comboBox->addItem(QStringLiteral("256000"), QSerialPort::Baud256000);
}



//语言的初始化
void MainWindow::initUILanguage()
{
//    ui->groupBox_3->setTitle(QStringLiteral("串口设置"));
}



void MainWindow::initConnect()
{
    //接收数据线程 接收并处理数据后，将处理结果发送给主线程的信号与槽
    connect(receSerial_Obj,SIGNAL(dealedData_signal(QString,vector<double>,vector<double>)),this,SLOT(dealedData_slot(QString,vector<double>,vector<double>)));
    connect(receSerial_Obj,SIGNAL(showResultMsg_signal(QStringList)),SLOT(showResultMsg_slot(QStringList)));
    //link info slot
    connect(this,SIGNAL(openOrCloseSerial_signal(bool)),receSerial_Obj,SLOT(openOrCloseSerial_slot(bool)));
    connect(receSerial_Obj,SIGNAL(returnLinkInfo_signal(QString, bool)),this,SLOT(returnLinkInfo_slot(QString, bool)));

    // calculate histogram connect
    connect(this,SIGNAL(calHistogram_signal(vector<double>)),calHis_obg,SLOT(calHistogram_slot(vector<double>)));
    connect(calHis_obg,SIGNAL(toShowHistogram_signal(QVector<double>,QVector<double>,QVector<QString>,int ,int )),this,SLOT(toShowHistogram_slot(QVector<double>,QVector<double>,QVector<QString>,int ,int )));

    //刷新定时器 信号与槽的连接
    connect(&showTimer,SIGNAL(timeout()),this,SLOT(showTimerSlot()));
    connect(&oneSecondTimer,SIGNAL(timeout()),this,SLOT(oneSecondTimer_slot()));
    connect(&plotShowTimer,SIGNAL(timeout()),this,SLOT(plotShowTimer_slot()));

    //主界面串口发送数据相关
    connect(this,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));
    connect(&keepSendMeasureTimer,SIGNAL(timeout()),this,SLOT(keepSendMeasureSlot()));   //持续发送命令的槽函数
    connect(receSerial_Obj,SIGNAL(AckCmdMain_signal(QString,QString)),this,SLOT(AckCmdMain_slot(QString,QString)));

    //MCU 升级相关
    connect(&McuUpgradeDia,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));
    connect(receSerial_Obj,SIGNAL(AckCmdUpgrade_signal(QString,QString)),&McuUpgradeDia,SLOT(AckCmdUpgrade_signal(QString,QString)));

    //寄存器读写相关
    connect(&registerDia,SIGNAL(sendSerialSignal(QString)),receSerial_Obj,SLOT(sendSerialSlot(QString)));
    connect(receSerial_Obj,SIGNAL(AckCmdRegister_signal(QString,QString)),&registerDia,SLOT(AckCmdRegister_slot(QString,QString)));


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
//    ui->Histogram_widget->setBackground(QBrush(gradient));//设置图表背景（用画刷设置）

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
    ui->baudRateBox->addItem(QStringLiteral("256000"), QSerialPort::Baud256000);
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
    if(ui->openPort_pushButton->text() == QStringLiteral("打开串口"))
    {
        currentSettings.name = ui->serialPortInfoListBox->currentText();

        if (ui->baudRateBox->currentIndex() == 4) {
            currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
        } else {
            currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                        ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
        }
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

//        receSerial_Obj->serial->setPortName(currentSettings.name);
//        receSerial_Obj->serial->setBaudRate(currentSettings.baudRate);
//        receSerial_Obj->serial->setDataBits(currentSettings.dataBits);
//        receSerial_Obj->serial->setParity(currentSettings.parity);
//        receSerial_Obj->serial->setStopBits(currentSettings.stopBits);
//        receSerial_Obj->serial->setFlowControl(currentSettings.flowControl);
//        if (receSerial_Obj->serial->open(QIODevice::ReadWrite)) {
//            isLinked = true;
//             ui->serialPortInfoListBox->setEnabled(false);
//             ui->baudRateBox->setEnabled(false);
//             ui->dataBitsBox->setEnabled(false);
//             ui->parityBox->setEnabled(false);
//             ui->stopBitsBox->setEnabled(false);

//             portOffSetting();

//        } else {
//            isLinked = false;
//            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("打开串口失败！"));
//            return;

//        }

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

//        ui->openPort_pushButton->setText("ClosePort");
//        beginTimer();
    }
    else
    {
        emit openOrCloseSerial_signal(false);
//        receSerial_Obj->serial->close();
//        stopTimer();
//        ui->openPort_pushButton->setText("OpenPort");
//        ui->serialPortInfoListBox->setEnabled(true);
//        ui->baudRateBox->setEnabled(true);
//        ui->dataBitsBox->setEnabled(true);
//        ui->parityBox->setEnabled(true);
//        ui->stopBitsBox->setEnabled(true);
//        portOnSetting();
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
             ui->openPort_pushButton->setText(QStringLiteral("关闭串口"));
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
            ui->openPort_pushButton->setText(QStringLiteral("打开串口"));
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


    //text_BOX上面的数据显示   分为显示解析后的TOF数据 或者16进制的数据  ;看是否需要判断 isTranslateFlag
    for(int i=0 ;i<DistanceStr.length();i++ )
    {
        ui->ResultHistory_textEdit->appendPlainText(DistanceStr[i]);
    }
    DistanceStr.clear();    //清空暂存的变量
    ui->HistoryData_label->setText(QString::number(allCountNum));   //显示记录条数

}

//选择文件的保存路径
void MainWindow::on_selectSavePathtoolButton_clicked()
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
        ui->savePath_lineEdit->setText(file_path);
    }
}


//选中文件保存功能
void MainWindow::on_save_pushButton_clicked()
{

    QString text = ui->ResultHistory_textEdit->toPlainText();

    QString sFilePath = ui->savePath_lineEdit->text() ;
    if(sFilePath.isEmpty())
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("请先选择文件保存路径"));
        return;
    }


    QDateTime currTime = QDateTime::currentDateTime();
    QString fileName = currTime.toString("yyyyMMdd_hh_mm_ss");
    fileName.append(".txt");
    sFilePath.append(fileName);     //加上文件名


    QFile file(sFilePath);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out<<text.toLocal8Bit()<<endl;
    file.close();

    QString strMsg = QStringLiteral("已保存在指定路径下，文件名为：") + fileName;
    QMessageBox::information(NULL,QStringLiteral("提示"),strMsg);
}


//接收串口处理线程发送来的用于界面上显示的字符串连接
void MainWindow::showResultMsg_slot(QStringList DisStr)
{
    Count_num++;

    allCountNum++;

    DistanceStr.append(DisStr);

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
                file.open(QIODevice::WriteOnly|QIODevice::Text);
                QTextStream out(&file);
                out<<textBox_Data.toLocal8Bit()<<endl;
                file.close();

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
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("请先选择文件保存路径"));
        ui->TimingSave_checkBox->setChecked(false);
        return;
    }

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

    ui->ResultHistory_textEdit->clear();
    allCountNum = 0;
}


//显示TOF的统计信息   刷新频率为50ms
void MainWindow::on_TOF_radioButton_clicked()
{
    if(plotShowTimer.isActive())
        plotShowTimer.stop();
    plotShowTimer.start(70);

    plot_type = 0;
    ui->stackedWidget->setCurrentIndex(0);
}

//显示统计直方图   由于耗时严重，由专门的线程进行处理 直方图定时器为300ms
void MainWindow::on_Histogram_radioButton_clicked()
{
    if(plotShowTimer.isActive())
        plotShowTimer.stop();
    plotShowTimer.start(370);      //定时器改为300ms进行一次刷新

    plot_type = 1;
    ui->stackedWidget->setCurrentIndex(1);
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
        if(0 == plot_type)          //显示tof的统计信息
        {
            int len = PlotData_vector.size();
            if(len<1)
                return;
            for(int i=0; i< len; i++)
            {
                label_x[i] = i;
                tofValue[i] = PlotData_vector[i];

                valueMin = valueMin>tofValue[i] ? tofValue[i]:valueMin;
                valueMax = valueMax>tofValue[i] ? valueMax:tofValue[i];    //统计tof的最大值，方便显示
            }
            labelMax = PlotData_vector.size();

            ui->TOF_widget->xAxis->setRange(0,labelMax);
            ui->TOF_widget->yAxis->setRange(valueMin-10,valueMax+10);
            ui->TOF_widget->graph(0)->setData(label_x,tofValue);
            ui->TOF_widget->replot();


        }else if(1 == plot_type)    //显示直方图的信息
        {
            emit calHistogram_signal(PlotData_vector);

        }
    }
}


//显示统计直方图放的槽函数
void MainWindow::toShowHistogram_slot(QVector<double> xTicks,QVector<double> numData,QVector<QString> xLabels,int xMax,int yMax)
{

//    qDebug()<<" xTicks = "<<xTicks;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
//    textTicker->addTicks(ticks, labels);
    textTicker->setTicks(xTicks, xLabels);
    ui->Histogram_widget->xAxis->setTicker(textTicker);

    ui->Histogram_widget->xAxis->setRange(0,xMax);
    ui->Histogram_widget->yAxis->setRange(0,yMax);

    regen->setData(xTicks, numData);        //只不过第一个向量xTicks的每个元素表示“第几个柱子”，然后后面对应的values表示对应“柱子的值”
    ui->Histogram_widget->replot();
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
//!单次测量的槽函数
void MainWindow::on_singleMeasure_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A FF";
    emit sendSerialSignal(cmdStr);
}

//!
//! \brief MainWindow::on_delayMeasure_pushButton_clicked
//!
//!连续测量的槽函数
//! 1、开启连续测量以后 其他串口相关的操作都关闭 防止程序崩溃 ，除了停止按键以外
void MainWindow::on_delayMeasure_pushButton_clicked()
{

    SerialSetting_Enable_false();
    ui->stopMeasure_pushButton->setEnabled(true);
    keepSendMeasureTimer.start(5);    //暂定5ms发一次

}

//!
//! \brief MainWindow::keepSendMeasureSlot
//!  根据定时器 持续送测试命令
void MainWindow::keepSendMeasureSlot()
{
    QString cmdStr = "5A 01 05 34";
    emit sendSerialSignal(cmdStr);
}

//!
//! \brief MainWindow::on_stopMeasure_pushButton_clicked
//! 停止  测量的槽函数
void MainWindow::on_stopMeasure_pushButton_clicked()
{
    SerialSetting_Enable_true();
}


//!
//! \brief MainWindow::on_read_outFactory_pushButton_clicked
//! 读取出厂设置 槽函数  5A 00 02 22 00 DDD..D XX
void MainWindow::on_read_outFactory_pushButton_clicked()
{

    //命令组帧 0X22 34
    QString data = QString("%1").arg(0,68,16,QLatin1Char('0'));

    QString cmdStr = "5A 00 02 22 00 ";
    cmdStr.append(data);
    emit sendSerialSignal(cmdStr);
}


//!
//! \brief MainWindow::on_outFactory_pushButton_clicked
//!  出厂设置 点击发送的槽函数  （SN 、 波特率）  5A 01 02 25 00 DD..DD XX
//! SN :      4
//! UUID :    12
//! BAUDRATE: 4
//! CAIJI:    1
//! YULIU:    16
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

    //采集频率
    QString caiji_str = QString("%1").arg(ui->CAIJI_frequency_comboBox->currentIndex(),2,16,QLatin1Char('0'));
    qDebug()<<" caiji_str = "<<caiji_str<<" len="<<caiji_str.length();

    //设备类型
    QString deviceType = QString("%1").arg(ui->ui->deviceType_comboBox->currentIndex(),2,16,QLatin1Char('0'));
    qDebug()<<" deviceType = "<<deviceType<<" len="<<deviceType.length();


    //预留数据
    QString YuLiu_num = ui->YULIU_lineEdit->text();
    QString YuLiu_str = YuLiu_num.replace(" ","");
    if(YuLiu_str.length()>30)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("预留数据过长，请重新输入！"));
        return;
    }
    str = "00000000000000000000000000000000" + YuLiu_str;
    YuLiu_str = str.right(30);
    qDebug()<<" YuLiu_str = "<<YuLiu_str<<" len="<<YuLiu_str.length();


    //命令组帧
    QString cmdStr = "5A 01 02 22 00 ";
    cmdStr.append(SN_numberStr).append(UUID_str).append(banuRateStr).append(caiji_str).append(deviceType).append(YuLiu_str);

    emit sendSerialSignal(cmdStr);
}

//!
//! \brief MainWindow::on_reStoreFactory_pushButton_clicked
//! 恢复出厂设置 5A 01 01 00 03 00
void MainWindow::on_reStoreFactory_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A 01 01 00 03 00 ";
    emit sendSerialSignal(cmdStr);
}




//!
//! \brief MainWindow::on_calibration_pushButton_clicked
//! 出厂校准 点击发送的槽函数 （真实距离）
void MainWindow::on_calibration_pushButton_clicked()
{
    QString realDis = ui->realDisFactory_lineEdit->text();

    //命令组帧
    QString cmdStr = "5A 00";
    emit sendSerialSignal(cmdStr);
}


//!
//! \brief MainWindow::on_outSetting_pushButton_clicked
//! 输出设置 发送槽函数 真实距离 原始距离
void MainWindow::on_outSetting_pushButton_clicked()
{
    QString realDisOut = ui->realDisOut_lineEdit->text();
    QString orialDisOut = ui->orialDisOut_lineEdit->text();

    //命令组帧
    QString cmdStr = "5A 01";
    emit sendSerialSignal(cmdStr);

}


//!
//! \brief AckCmdMain_signal
//!主界面配置的相关信息返回信号    参数1：“8102”：写入出厂设置成功，参数2暂无
//!                             参数1：“8002”：读取出厂设置 ，参数2 数据
//!                             参数1：“8103”：恢复出厂设置成功 参数2暂无
void MainWindow::AckCmdMain_slot(QString returnCmdStr,QString cmdAck)
{
    if("8102" ==returnCmdStr )
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("出厂设置成功！"));
        return;
    }
    else if("8002" == returnCmdStr)
    {
        QString SN_str = cmdAck.mid(0,8);
        QString UUID_str = cmdAck.mid(8,24);
        int baudRateIndex = cmdAck.mid(32,2).toInt(NULL,16);
        int caijiIndex = cmdAck.mid(34,2).toInt(NULL,16);
        int deviceTypeIndex = cmdAck.mid(36,2).toInt(NULL,16);
        QString YuLiuStr = cmdAck.mid(38,30);

        ui->SN_lineEdit->setText(SN_str);
        ui->UUID_lineEdit->setText(UUID_str);
        ui->botelv_comboBox->setCurrentIndex(baudRateIndex);
        ui->CAIJI_frequency_comboBox->setCurrentIndex(caijiIndex);
        ui->deviceType_comboBox->setCurrentIndex(deviceTypeIndex);
        ui->YULIU_lineEdit->setText(YuLiuStr);
        return;
    }
    else if("8103" == returnCmdStr)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("恢复出厂设置成功！"));
        return;
    }
}



