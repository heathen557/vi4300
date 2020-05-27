/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMCU;
    QAction *Register_action;
    QAction *actionEnglish;
    QAction *action_china;
    QAction *showTOF_action_TOF;
    QAction *manageMent_action;
    QAction *about_action;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_18;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QComboBox *serialPortInfoListBox;
    QLabel *label_8;
    QComboBox *baudRateBox;
    QLabel *label_11;
    QComboBox *dataBitsBox;
    QLabel *label_7;
    QComboBox *stopBitsBox;
    QLabel *label_9;
    QComboBox *parityBox;
    QPushButton *portScan_pushButton;
    QPushButton *openPort_pushButton;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QFormLayout *formLayout_5;
    QPushButton *singleMeasure_pushButton;
    QPushButton *delayMeasure_pushButton;
    QPushButton *stopMeasure_pushButton;
    QPushButton *startlds_pushButton;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout_3;
    QComboBox *pixel_timeOffset_comboBox;
    QPushButton *pixel_time_pushButton;
    QPushButton *CAS_pix1_pushButton;
    QPushButton *CAS_pix2_pushButton;
    QPushButton *rowData_pushButton;
    QPushButton *pixel_read_pushButton;
    QPushButton *delayLine_pushButton;
    QPushButton *openOrClose_laser_pushButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_12;
    QLabel *currentDistance11_label;
    QLabel *label_14;
    QLabel *mean_label;
    QLabel *label_16;
    QLabel *std_label;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QRadioButton *plotSet_off_radioButton;
    QRadioButton *plotSet_on_radioButton;
    QWidget *page_4;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_11;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *SN_lineEdit;
    QLabel *label_2;
    QComboBox *botelv_comboBox;
    QLabel *label_18;
    QLineEdit *versionNum_lineEdit;
    QLabel *label_20;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *UUID_lineEdit;
    QPushButton *read_outFactory_pushButton;
    QPushButton *send_outFactory_pushButton;
    QPushButton *reStoreFactory_pushButton;
    QLineEdit *deviceType_lineEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_12;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_19;
    QFormLayout *formLayout_6;
    QLabel *label_27;
    QLineEdit *singleReg_addr_lineEdit;
    QLabel *label_28;
    QLineEdit *singleReg_value_lineEdit;
    QPushButton *singleReg_read_pushButton;
    QPushButton *singleReg_write_pushButton;
    QWidget *page_5;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *realDisFactory_lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *K1_lineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_26;
    QLineEdit *tempture_k_lineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_32;
    QComboBox *sunPower_set_comboBox;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_29;
    QLineEdit *offset_maxValue_lineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_30;
    QComboBox *filter_comboBox;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_31;
    QComboBox *offset_caiji_comboBox;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_34;
    QLineEdit *peakOffset_lineEdit;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *calibration_pushButton;
    QPushButton *calibration_read_pushButton;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_16;
    QFormLayout *formLayout_4;
    QLabel *label_15;
    QLineEdit *realDisFactory_2_lineEdit;
    QLabel *label_22;
    QLineEdit *temperature_lineEdit;
    QLabel *label_23;
    QLineEdit *offset_jiaozhun_lineEdit;
    QLabel *label_21;
    QLineEdit *K2_lineEdit;
    QLabel *label_33;
    QLineEdit *sunPower_read_lineEdit;
    QPushButton *gaofan_pushButton;
    QWidget *page_6;
    QGridLayout *gridLayout_22;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_21;
    QLabel *label_43;
    QComboBox *serialPortInfoListBox_2;
    QLabel *label_45;
    QComboBox *baudRateBox_2;
    QLabel *label_47;
    QComboBox *dataBitsBox_2;
    QLabel *label_49;
    QComboBox *stopBitsBox_2;
    QLabel *label_50;
    QComboBox *parityBox_2;
    QPushButton *portScan_pushButton_2;
    QPushButton *openPort_pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QPushButton *black_01_pushButton;
    QPushButton *white_01_pushButton;
    QLabel *black01_label;
    QLabel *white_01_label;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_37;
    QPushButton *black_02_pushButton;
    QPushButton *white_02_pushButton;
    QLabel *black02_label;
    QLabel *white_02_label;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_41;
    QPushButton *black_03_pushButton;
    QPushButton *white_03_pushButton;
    QLabel *black03_label;
    QLabel *white_03_label;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_44;
    QPushButton *black_04_pushButton;
    QPushButton *white_04_pushButton;
    QLabel *black04_label;
    QLabel *white_04_label;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_46;
    QPushButton *black_05_pushButton;
    QPushButton *white_05_pushButton;
    QLabel *black05_label;
    QLabel *white_05_label;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_48;
    QPushButton *black_1_pushButton;
    QPushButton *white_1_pushButton;
    QLabel *black1_label;
    QLabel *white_1_label;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_51;
    QPushButton *black_3_pushButton;
    QPushButton *white_3_pushButton;
    QLabel *black3_label;
    QLabel *white_3_label;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_54;
    QPushButton *black_8_pushButton;
    QPushButton *white_8_pushButton;
    QLabel *black8_label;
    QLabel *white_8_label;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_17;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_25;
    QLabel *A1_label;
    QLabel *label_36;
    QLabel *B1_label;
    QLabel *label_39;
    QLabel *C1_label;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_35;
    QLabel *A2_label;
    QLabel *label_38;
    QLabel *B2_label;
    QLabel *label_40;
    QLabel *C2_label;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_42;
    QLabel *least_offset_label;
    QTextEdit *res_textEdit;
    QPushButton *startAutoAdjust_pushButton;
    QPushButton *fuwei_pushButton;
    QWidget *page_7;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_23;
    QLabel *label_52;
    QLabel *read_a1_label;
    QLabel *label_55;
    QLabel *read_b1_label;
    QLabel *label_57;
    QLabel *read_c1_label;
    QLabel *label_63;
    QLabel *read_a2_label;
    QLabel *label_60;
    QLabel *read_b2_label;
    QLabel *label_61;
    QLabel *read_c2_label;
    QLabel *label_65;
    QLabel *read_offset_label;
    QGroupBox *groupBox_16;
    QLabel *label_53;
    QLineEdit *sendPoint_lineEdit;
    QPushButton *startMove_pushButton;
    QTextEdit *readMCU_textEdit;
    QPushButton *readMCU_pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *HistoryData_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *DPS_label;
    QSpacerItem *horizontalSpacer;
    QCheckBox *Transform_checkBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QCheckBox *TimingSave_checkBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *savePath_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *save_pushButton;
    QLabel *timeInnterval_label;
    QLineEdit *timeInnterval_lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *clear_pushButton;
    QPlainTextEdit *ResultHistory_textEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_24;
    QComboBox *plot_comboBox;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_10;
    QCustomPlot *TOF_widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *savePicture_pushButton;
    QSpacerItem *horizontalSpacer_7;
    QWidget *page_3;
    QGridLayout *gridLayout_13;
    QCustomPlot *Histogram_widget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *savePicture_his_pushButton;
    QPushButton *HistogramData_pushButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *casset_historgram_page;
    QGridLayout *gridLayout_20;
    QCustomPlot *casset_historgrm_widget;
    QPushButton *casset_imageSave_pushButton;
    QPushButton *casset_historgram_pushButton;
    QSpacerItem *horizontalSpacer_9;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_3;
    QMenu *menu_5;
    QMenu *menu_6;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1433, 944);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/image/images/icon_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionMCU = new QAction(MainWindow);
        actionMCU->setObjectName(QStringLiteral("actionMCU"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/image/images/ccMerge.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMCU->setIcon(icon1);
        Register_action = new QAction(MainWindow);
        Register_action->setObjectName(QStringLiteral("Register_action"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/image/images/ccClippingBoxMultExport.png"), QSize(), QIcon::Normal, QIcon::Off);
        Register_action->setIcon(icon2);
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        action_china = new QAction(MainWindow);
        action_china->setObjectName(QStringLiteral("action_china"));
        showTOF_action_TOF = new QAction(MainWindow);
        showTOF_action_TOF->setObjectName(QStringLiteral("showTOF_action_TOF"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/image/images/monitor.svg"), QSize(), QIcon::Normal, QIcon::Off);
        showTOF_action_TOF->setIcon(icon3);
        manageMent_action = new QAction(MainWindow);
        manageMent_action->setObjectName(QStringLiteral("manageMent_action"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/image/images/dbContainerSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        manageMent_action->setIcon(icon4);
        about_action = new QAction(MainWindow);
        about_action->setObjectName(QStringLiteral("about_action"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/image/images/dbViewportSymbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        about_action->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(300, 0));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        toolBox->setStyleSheet(QLatin1String(".QToolBox{\n"
"font: 10pt \"Times New Roman\";}"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 300, 713));
        page->setStyleSheet(QLatin1String(".QWidget{\n"
"font: 11pt \"Times New Roman\";}"));
        gridLayout_18 = new QGridLayout(page);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setContentsMargins(-1, 2, -1, 2);
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        serialPortInfoListBox = new QComboBox(groupBox_3);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        gridLayout_4->addWidget(serialPortInfoListBox, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        baudRateBox = new QComboBox(groupBox_3);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout_4->addWidget(baudRateBox, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        dataBitsBox = new QComboBox(groupBox_3);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        gridLayout_4->addWidget(dataBitsBox, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        stopBitsBox = new QComboBox(groupBox_3);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        gridLayout_4->addWidget(stopBitsBox, 3, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 4, 0, 1, 1);

        parityBox = new QComboBox(groupBox_3);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        gridLayout_4->addWidget(parityBox, 4, 1, 1, 1);

        portScan_pushButton = new QPushButton(groupBox_3);
        portScan_pushButton->setObjectName(QStringLiteral("portScan_pushButton"));

        gridLayout_4->addWidget(portScan_pushButton, 5, 0, 1, 1);

        openPort_pushButton = new QPushButton(groupBox_3);
        openPort_pushButton->setObjectName(QStringLiteral("openPort_pushButton"));

        gridLayout_4->addWidget(openPort_pushButton, 5, 1, 1, 1);


        gridLayout_18->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(page);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 3, -1, 3);
        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        singleMeasure_pushButton = new QPushButton(groupBox_5);
        singleMeasure_pushButton->setObjectName(QStringLiteral("singleMeasure_pushButton"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, singleMeasure_pushButton);

        delayMeasure_pushButton = new QPushButton(groupBox_5);
        delayMeasure_pushButton->setObjectName(QStringLiteral("delayMeasure_pushButton"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, delayMeasure_pushButton);

        stopMeasure_pushButton = new QPushButton(groupBox_5);
        stopMeasure_pushButton->setObjectName(QStringLiteral("stopMeasure_pushButton"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, stopMeasure_pushButton);

        startlds_pushButton = new QPushButton(groupBox_5);
        startlds_pushButton->setObjectName(QStringLiteral("startlds_pushButton"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, startlds_pushButton);


        gridLayout_6->addLayout(formLayout_5, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(page);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_7 = new QGridLayout(groupBox_6);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        pixel_timeOffset_comboBox = new QComboBox(groupBox_6);
        pixel_timeOffset_comboBox->setObjectName(QStringLiteral("pixel_timeOffset_comboBox"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, pixel_timeOffset_comboBox);

        pixel_time_pushButton = new QPushButton(groupBox_6);
        pixel_time_pushButton->setObjectName(QStringLiteral("pixel_time_pushButton"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, pixel_time_pushButton);

        CAS_pix1_pushButton = new QPushButton(groupBox_6);
        CAS_pix1_pushButton->setObjectName(QStringLiteral("CAS_pix1_pushButton"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, CAS_pix1_pushButton);

        CAS_pix2_pushButton = new QPushButton(groupBox_6);
        CAS_pix2_pushButton->setObjectName(QStringLiteral("CAS_pix2_pushButton"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, CAS_pix2_pushButton);

        rowData_pushButton = new QPushButton(groupBox_6);
        rowData_pushButton->setObjectName(QStringLiteral("rowData_pushButton"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, rowData_pushButton);

        pixel_read_pushButton = new QPushButton(groupBox_6);
        pixel_read_pushButton->setObjectName(QStringLiteral("pixel_read_pushButton"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, pixel_read_pushButton);

        delayLine_pushButton = new QPushButton(groupBox_6);
        delayLine_pushButton->setObjectName(QStringLiteral("delayLine_pushButton"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, delayLine_pushButton);

        openOrClose_laser_pushButton = new QPushButton(groupBox_6);
        openOrClose_laser_pushButton->setObjectName(QStringLiteral("openOrClose_laser_pushButton"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, openOrClose_laser_pushButton);


        gridLayout_7->addLayout(formLayout_3, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_6, 4, 0, 1, 1);

        groupBox_4 = new QGroupBox(page);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 3, -1, 3);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        currentDistance11_label = new QLabel(groupBox_4);
        currentDistance11_label->setObjectName(QStringLiteral("currentDistance11_label"));
        currentDistance11_label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));

        verticalLayout->addWidget(currentDistance11_label);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout->addWidget(label_14);

        mean_label = new QLabel(groupBox_4);
        mean_label->setObjectName(QStringLiteral("mean_label"));
        mean_label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));

        verticalLayout->addWidget(mean_label);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout->addWidget(label_16);

        std_label = new QLabel(groupBox_4);
        std_label->setObjectName(QStringLiteral("std_label"));
        std_label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));

        verticalLayout->addWidget(std_label);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_4, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(page);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, 2, -1, 2);
        plotSet_off_radioButton = new QRadioButton(groupBox_8);
        plotSet_off_radioButton->setObjectName(QStringLiteral("plotSet_off_radioButton"));
        plotSet_off_radioButton->setChecked(false);

        gridLayout_8->addWidget(plotSet_off_radioButton, 0, 1, 1, 1);

        plotSet_on_radioButton = new QRadioButton(groupBox_8);
        plotSet_on_radioButton->setObjectName(QStringLiteral("plotSet_on_radioButton"));
        plotSet_on_radioButton->setChecked(true);

        gridLayout_8->addWidget(plotSet_on_radioButton, 0, 0, 1, 1);


        gridLayout_18->addWidget(groupBox_8, 3, 0, 1, 1);

        gridLayout_18->setRowStretch(0, 3);
        gridLayout_18->setRowStretch(1, 1);
        gridLayout_18->setRowStretch(2, 3);
        gridLayout_18->setRowStretch(3, 1);
        gridLayout_18->setRowStretch(4, 3);
        toolBox->addItem(page, QString::fromUtf8("              \345\237\272\346\234\254\350\256\276\347\275\256"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 300, 713));
        page_4->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_15 = new QGridLayout(page_4);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        groupBox_7 = new QGroupBox(page_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_11 = new QGridLayout(groupBox_7);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        SN_lineEdit = new QLineEdit(groupBox_7);
        SN_lineEdit->setObjectName(QStringLiteral("SN_lineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, SN_lineEdit);

        label_2 = new QLabel(groupBox_7);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        botelv_comboBox = new QComboBox(groupBox_7);
        botelv_comboBox->setObjectName(QStringLiteral("botelv_comboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, botelv_comboBox);

        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_18);

        versionNum_lineEdit = new QLineEdit(groupBox_7);
        versionNum_lineEdit->setObjectName(QStringLiteral("versionNum_lineEdit"));
        versionNum_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, versionNum_lineEdit);

        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_20);

        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_17);

        horizontalSpacer_8 = new QSpacerItem(105, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(4, QFormLayout::FieldRole, horizontalSpacer_8);

        UUID_lineEdit = new QLineEdit(groupBox_7);
        UUID_lineEdit->setObjectName(QStringLiteral("UUID_lineEdit"));

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, UUID_lineEdit);

        read_outFactory_pushButton = new QPushButton(groupBox_7);
        read_outFactory_pushButton->setObjectName(QStringLiteral("read_outFactory_pushButton"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, read_outFactory_pushButton);

        send_outFactory_pushButton = new QPushButton(groupBox_7);
        send_outFactory_pushButton->setObjectName(QStringLiteral("send_outFactory_pushButton"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, send_outFactory_pushButton);

        reStoreFactory_pushButton = new QPushButton(groupBox_7);
        reStoreFactory_pushButton->setObjectName(QStringLiteral("reStoreFactory_pushButton"));

        formLayout_2->setWidget(7, QFormLayout::SpanningRole, reStoreFactory_pushButton);

        deviceType_lineEdit = new QLineEdit(groupBox_7);
        deviceType_lineEdit->setObjectName(QStringLiteral("deviceType_lineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, deviceType_lineEdit);


        gridLayout_11->addLayout(formLayout_2, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_7, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer, 3, 0, 1, 1);

        groupBox_10 = new QGroupBox(page_4);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_3 = new QGridLayout(groupBox_10);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox_10);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_3->addWidget(comboBox, 0, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_13, 0, 2, 1, 1);


        gridLayout_14->addWidget(groupBox_10, 1, 0, 1, 1);

        groupBox_12 = new QGroupBox(page_4);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_19 = new QGridLayout(groupBox_12);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        label_27 = new QLabel(groupBox_12);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_27);

        singleReg_addr_lineEdit = new QLineEdit(groupBox_12);
        singleReg_addr_lineEdit->setObjectName(QStringLiteral("singleReg_addr_lineEdit"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, singleReg_addr_lineEdit);

        label_28 = new QLabel(groupBox_12);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_28);

        singleReg_value_lineEdit = new QLineEdit(groupBox_12);
        singleReg_value_lineEdit->setObjectName(QStringLiteral("singleReg_value_lineEdit"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, singleReg_value_lineEdit);

        singleReg_read_pushButton = new QPushButton(groupBox_12);
        singleReg_read_pushButton->setObjectName(QStringLiteral("singleReg_read_pushButton"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, singleReg_read_pushButton);

        singleReg_write_pushButton = new QPushButton(groupBox_12);
        singleReg_write_pushButton->setObjectName(QStringLiteral("singleReg_write_pushButton"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, singleReg_write_pushButton);


        gridLayout_19->addLayout(formLayout_6, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_12, 2, 0, 1, 1);

        gridLayout_14->setRowStretch(0, 4);
        gridLayout_14->setRowStretch(1, 1);
        gridLayout_14->setRowStretch(2, 2);
        gridLayout_14->setRowStretch(3, 1);

        gridLayout_15->addLayout(gridLayout_14, 0, 0, 1, 1);

        toolBox->addItem(page_4, QString::fromUtf8("              \350\256\276\345\244\207\351\205\215\347\275\256"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 300, 713));
        groupBox_9 = new QGroupBox(page_5);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(9, 9, 230, 303));
        gridLayout_9 = new QGridLayout(groupBox_9);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_9);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        realDisFactory_lineEdit = new QLineEdit(groupBox_9);
        realDisFactory_lineEdit->setObjectName(QStringLiteral("realDisFactory_lineEdit"));

        horizontalLayout_6->addWidget(realDisFactory_lineEdit);


        gridLayout_9->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_8->addWidget(label_13);

        K1_lineEdit = new QLineEdit(groupBox_9);
        K1_lineEdit->setObjectName(QStringLiteral("K1_lineEdit"));

        horizontalLayout_8->addWidget(K1_lineEdit);


        gridLayout_9->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_26 = new QLabel(groupBox_9);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_10->addWidget(label_26);

        tempture_k_lineEdit = new QLineEdit(groupBox_9);
        tempture_k_lineEdit->setObjectName(QStringLiteral("tempture_k_lineEdit"));

        horizontalLayout_10->addWidget(tempture_k_lineEdit);


        gridLayout_9->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_32 = new QLabel(groupBox_9);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_11->addWidget(label_32);

        sunPower_set_comboBox = new QComboBox(groupBox_9);
        sunPower_set_comboBox->setObjectName(QStringLiteral("sunPower_set_comboBox"));

        horizontalLayout_11->addWidget(sunPower_set_comboBox);


        gridLayout_9->addLayout(horizontalLayout_11, 3, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_29 = new QLabel(groupBox_9);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_12->addWidget(label_29);

        offset_maxValue_lineEdit = new QLineEdit(groupBox_9);
        offset_maxValue_lineEdit->setObjectName(QStringLiteral("offset_maxValue_lineEdit"));

        horizontalLayout_12->addWidget(offset_maxValue_lineEdit);


        gridLayout_9->addLayout(horizontalLayout_12, 4, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_30 = new QLabel(groupBox_9);
        label_30->setObjectName(QStringLiteral("label_30"));

        horizontalLayout_13->addWidget(label_30);

        filter_comboBox = new QComboBox(groupBox_9);
        filter_comboBox->setObjectName(QStringLiteral("filter_comboBox"));

        horizontalLayout_13->addWidget(filter_comboBox);


        gridLayout_9->addLayout(horizontalLayout_13, 5, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_31 = new QLabel(groupBox_9);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_14->addWidget(label_31);

        offset_caiji_comboBox = new QComboBox(groupBox_9);
        offset_caiji_comboBox->setObjectName(QStringLiteral("offset_caiji_comboBox"));

        horizontalLayout_14->addWidget(offset_caiji_comboBox);


        gridLayout_9->addLayout(horizontalLayout_14, 6, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_34 = new QLabel(groupBox_9);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout_15->addWidget(label_34);

        peakOffset_lineEdit = new QLineEdit(groupBox_9);
        peakOffset_lineEdit->setObjectName(QStringLiteral("peakOffset_lineEdit"));

        horizontalLayout_15->addWidget(peakOffset_lineEdit);


        gridLayout_9->addLayout(horizontalLayout_15, 7, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        calibration_pushButton = new QPushButton(groupBox_9);
        calibration_pushButton->setObjectName(QStringLiteral("calibration_pushButton"));

        horizontalLayout_16->addWidget(calibration_pushButton);

        calibration_read_pushButton = new QPushButton(groupBox_9);
        calibration_read_pushButton->setObjectName(QStringLiteral("calibration_read_pushButton"));

        horizontalLayout_16->addWidget(calibration_read_pushButton);


        gridLayout_9->addLayout(horizontalLayout_16, 8, 0, 1, 1);

        groupBox_11 = new QGroupBox(page_5);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(9, 342, 224, 171));
        gridLayout_16 = new QGridLayout(groupBox_11);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_15 = new QLabel(groupBox_11);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_15);

        realDisFactory_2_lineEdit = new QLineEdit(groupBox_11);
        realDisFactory_2_lineEdit->setObjectName(QStringLiteral("realDisFactory_2_lineEdit"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, realDisFactory_2_lineEdit);

        label_22 = new QLabel(groupBox_11);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_22);

        temperature_lineEdit = new QLineEdit(groupBox_11);
        temperature_lineEdit->setObjectName(QStringLiteral("temperature_lineEdit"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, temperature_lineEdit);

        label_23 = new QLabel(groupBox_11);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_23);

        offset_jiaozhun_lineEdit = new QLineEdit(groupBox_11);
        offset_jiaozhun_lineEdit->setObjectName(QStringLiteral("offset_jiaozhun_lineEdit"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, offset_jiaozhun_lineEdit);

        label_21 = new QLabel(groupBox_11);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_21);

        K2_lineEdit = new QLineEdit(groupBox_11);
        K2_lineEdit->setObjectName(QStringLiteral("K2_lineEdit"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, K2_lineEdit);

        label_33 = new QLabel(groupBox_11);
        label_33->setObjectName(QStringLiteral("label_33"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_33);

        sunPower_read_lineEdit = new QLineEdit(groupBox_11);
        sunPower_read_lineEdit->setObjectName(QStringLiteral("sunPower_read_lineEdit"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, sunPower_read_lineEdit);


        gridLayout_16->addLayout(formLayout_4, 0, 0, 1, 1);

        gaofan_pushButton = new QPushButton(page_5);
        gaofan_pushButton->setObjectName(QStringLiteral("gaofan_pushButton"));
        gaofan_pushButton->setGeometry(QRect(20, 540, 201, 20));
        toolBox->addItem(page_5, QString::fromUtf8("              \350\256\276\345\244\207\346\240\241\345\207\206"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 300, 713));
        gridLayout_22 = new QGridLayout(page_6);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        groupBox_14 = new QGroupBox(page_6);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_21 = new QGridLayout(groupBox_14);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        label_43 = new QLabel(groupBox_14);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_21->addWidget(label_43, 0, 0, 1, 1);

        serialPortInfoListBox_2 = new QComboBox(groupBox_14);
        serialPortInfoListBox_2->setObjectName(QStringLiteral("serialPortInfoListBox_2"));

        gridLayout_21->addWidget(serialPortInfoListBox_2, 0, 1, 1, 1);

        label_45 = new QLabel(groupBox_14);
        label_45->setObjectName(QStringLiteral("label_45"));

        gridLayout_21->addWidget(label_45, 1, 0, 1, 1);

        baudRateBox_2 = new QComboBox(groupBox_14);
        baudRateBox_2->setObjectName(QStringLiteral("baudRateBox_2"));

        gridLayout_21->addWidget(baudRateBox_2, 1, 1, 1, 1);

        label_47 = new QLabel(groupBox_14);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_21->addWidget(label_47, 2, 0, 1, 1);

        dataBitsBox_2 = new QComboBox(groupBox_14);
        dataBitsBox_2->setObjectName(QStringLiteral("dataBitsBox_2"));

        gridLayout_21->addWidget(dataBitsBox_2, 2, 1, 1, 1);

        label_49 = new QLabel(groupBox_14);
        label_49->setObjectName(QStringLiteral("label_49"));

        gridLayout_21->addWidget(label_49, 3, 0, 1, 1);

        stopBitsBox_2 = new QComboBox(groupBox_14);
        stopBitsBox_2->setObjectName(QStringLiteral("stopBitsBox_2"));

        gridLayout_21->addWidget(stopBitsBox_2, 3, 1, 1, 1);

        label_50 = new QLabel(groupBox_14);
        label_50->setObjectName(QStringLiteral("label_50"));

        gridLayout_21->addWidget(label_50, 4, 0, 1, 1);

        parityBox_2 = new QComboBox(groupBox_14);
        parityBox_2->setObjectName(QStringLiteral("parityBox_2"));

        gridLayout_21->addWidget(parityBox_2, 4, 1, 1, 1);

        portScan_pushButton_2 = new QPushButton(groupBox_14);
        portScan_pushButton_2->setObjectName(QStringLiteral("portScan_pushButton_2"));

        gridLayout_21->addWidget(portScan_pushButton_2, 5, 0, 1, 1);

        openPort_pushButton_2 = new QPushButton(groupBox_14);
        openPort_pushButton_2->setObjectName(QStringLiteral("openPort_pushButton_2"));

        gridLayout_21->addWidget(openPort_pushButton_2, 5, 1, 1, 1);


        gridLayout_22->addWidget(groupBox_14, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_19 = new QLabel(page_6);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_17->addWidget(label_19);

        black_01_pushButton = new QPushButton(page_6);
        black_01_pushButton->setObjectName(QStringLiteral("black_01_pushButton"));

        horizontalLayout_17->addWidget(black_01_pushButton);

        white_01_pushButton = new QPushButton(page_6);
        white_01_pushButton->setObjectName(QStringLiteral("white_01_pushButton"));

        horizontalLayout_17->addWidget(white_01_pushButton);

        black01_label = new QLabel(page_6);
        black01_label->setObjectName(QStringLiteral("black01_label"));

        horizontalLayout_17->addWidget(black01_label);

        white_01_label = new QLabel(page_6);
        white_01_label->setObjectName(QStringLiteral("white_01_label"));

        horizontalLayout_17->addWidget(white_01_label);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 1);
        horizontalLayout_17->setStretch(2, 1);
        horizontalLayout_17->setStretch(3, 2);
        horizontalLayout_17->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_37 = new QLabel(page_6);
        label_37->setObjectName(QStringLiteral("label_37"));

        horizontalLayout_18->addWidget(label_37);

        black_02_pushButton = new QPushButton(page_6);
        black_02_pushButton->setObjectName(QStringLiteral("black_02_pushButton"));

        horizontalLayout_18->addWidget(black_02_pushButton);

        white_02_pushButton = new QPushButton(page_6);
        white_02_pushButton->setObjectName(QStringLiteral("white_02_pushButton"));

        horizontalLayout_18->addWidget(white_02_pushButton);

        black02_label = new QLabel(page_6);
        black02_label->setObjectName(QStringLiteral("black02_label"));

        horizontalLayout_18->addWidget(black02_label);

        white_02_label = new QLabel(page_6);
        white_02_label->setObjectName(QStringLiteral("white_02_label"));

        horizontalLayout_18->addWidget(white_02_label);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 1);
        horizontalLayout_18->setStretch(3, 2);
        horizontalLayout_18->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_41 = new QLabel(page_6);
        label_41->setObjectName(QStringLiteral("label_41"));

        horizontalLayout_19->addWidget(label_41);

        black_03_pushButton = new QPushButton(page_6);
        black_03_pushButton->setObjectName(QStringLiteral("black_03_pushButton"));

        horizontalLayout_19->addWidget(black_03_pushButton);

        white_03_pushButton = new QPushButton(page_6);
        white_03_pushButton->setObjectName(QStringLiteral("white_03_pushButton"));

        horizontalLayout_19->addWidget(white_03_pushButton);

        black03_label = new QLabel(page_6);
        black03_label->setObjectName(QStringLiteral("black03_label"));

        horizontalLayout_19->addWidget(black03_label);

        white_03_label = new QLabel(page_6);
        white_03_label->setObjectName(QStringLiteral("white_03_label"));

        horizontalLayout_19->addWidget(white_03_label);

        horizontalLayout_19->setStretch(0, 1);
        horizontalLayout_19->setStretch(1, 1);
        horizontalLayout_19->setStretch(2, 1);
        horizontalLayout_19->setStretch(3, 2);
        horizontalLayout_19->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_44 = new QLabel(page_6);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout_20->addWidget(label_44);

        black_04_pushButton = new QPushButton(page_6);
        black_04_pushButton->setObjectName(QStringLiteral("black_04_pushButton"));

        horizontalLayout_20->addWidget(black_04_pushButton);

        white_04_pushButton = new QPushButton(page_6);
        white_04_pushButton->setObjectName(QStringLiteral("white_04_pushButton"));

        horizontalLayout_20->addWidget(white_04_pushButton);

        black04_label = new QLabel(page_6);
        black04_label->setObjectName(QStringLiteral("black04_label"));

        horizontalLayout_20->addWidget(black04_label);

        white_04_label = new QLabel(page_6);
        white_04_label->setObjectName(QStringLiteral("white_04_label"));

        horizontalLayout_20->addWidget(white_04_label);

        horizontalLayout_20->setStretch(0, 1);
        horizontalLayout_20->setStretch(1, 1);
        horizontalLayout_20->setStretch(2, 1);
        horizontalLayout_20->setStretch(3, 2);
        horizontalLayout_20->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_46 = new QLabel(page_6);
        label_46->setObjectName(QStringLiteral("label_46"));

        horizontalLayout_21->addWidget(label_46);

        black_05_pushButton = new QPushButton(page_6);
        black_05_pushButton->setObjectName(QStringLiteral("black_05_pushButton"));

        horizontalLayout_21->addWidget(black_05_pushButton);

        white_05_pushButton = new QPushButton(page_6);
        white_05_pushButton->setObjectName(QStringLiteral("white_05_pushButton"));

        horizontalLayout_21->addWidget(white_05_pushButton);

        black05_label = new QLabel(page_6);
        black05_label->setObjectName(QStringLiteral("black05_label"));

        horizontalLayout_21->addWidget(black05_label);

        white_05_label = new QLabel(page_6);
        white_05_label->setObjectName(QStringLiteral("white_05_label"));

        horizontalLayout_21->addWidget(white_05_label);

        horizontalLayout_21->setStretch(0, 1);
        horizontalLayout_21->setStretch(1, 1);
        horizontalLayout_21->setStretch(2, 1);
        horizontalLayout_21->setStretch(3, 2);
        horizontalLayout_21->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_48 = new QLabel(page_6);
        label_48->setObjectName(QStringLiteral("label_48"));

        horizontalLayout_22->addWidget(label_48);

        black_1_pushButton = new QPushButton(page_6);
        black_1_pushButton->setObjectName(QStringLiteral("black_1_pushButton"));

        horizontalLayout_22->addWidget(black_1_pushButton);

        white_1_pushButton = new QPushButton(page_6);
        white_1_pushButton->setObjectName(QStringLiteral("white_1_pushButton"));

        horizontalLayout_22->addWidget(white_1_pushButton);

        black1_label = new QLabel(page_6);
        black1_label->setObjectName(QStringLiteral("black1_label"));

        horizontalLayout_22->addWidget(black1_label);

        white_1_label = new QLabel(page_6);
        white_1_label->setObjectName(QStringLiteral("white_1_label"));

        horizontalLayout_22->addWidget(white_1_label);

        horizontalLayout_22->setStretch(0, 1);
        horizontalLayout_22->setStretch(1, 1);
        horizontalLayout_22->setStretch(2, 1);
        horizontalLayout_22->setStretch(3, 2);
        horizontalLayout_22->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_51 = new QLabel(page_6);
        label_51->setObjectName(QStringLiteral("label_51"));

        horizontalLayout_23->addWidget(label_51);

        black_3_pushButton = new QPushButton(page_6);
        black_3_pushButton->setObjectName(QStringLiteral("black_3_pushButton"));

        horizontalLayout_23->addWidget(black_3_pushButton);

        white_3_pushButton = new QPushButton(page_6);
        white_3_pushButton->setObjectName(QStringLiteral("white_3_pushButton"));

        horizontalLayout_23->addWidget(white_3_pushButton);

        black3_label = new QLabel(page_6);
        black3_label->setObjectName(QStringLiteral("black3_label"));

        horizontalLayout_23->addWidget(black3_label);

        white_3_label = new QLabel(page_6);
        white_3_label->setObjectName(QStringLiteral("white_3_label"));

        horizontalLayout_23->addWidget(white_3_label);

        horizontalLayout_23->setStretch(0, 1);
        horizontalLayout_23->setStretch(1, 1);
        horizontalLayout_23->setStretch(2, 1);
        horizontalLayout_23->setStretch(3, 2);
        horizontalLayout_23->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_54 = new QLabel(page_6);
        label_54->setObjectName(QStringLiteral("label_54"));

        horizontalLayout_24->addWidget(label_54);

        black_8_pushButton = new QPushButton(page_6);
        black_8_pushButton->setObjectName(QStringLiteral("black_8_pushButton"));

        horizontalLayout_24->addWidget(black_8_pushButton);

        white_8_pushButton = new QPushButton(page_6);
        white_8_pushButton->setObjectName(QStringLiteral("white_8_pushButton"));

        horizontalLayout_24->addWidget(white_8_pushButton);

        black8_label = new QLabel(page_6);
        black8_label->setObjectName(QStringLiteral("black8_label"));

        horizontalLayout_24->addWidget(black8_label);

        white_8_label = new QLabel(page_6);
        white_8_label->setObjectName(QStringLiteral("white_8_label"));

        horizontalLayout_24->addWidget(white_8_label);

        horizontalLayout_24->setStretch(0, 1);
        horizontalLayout_24->setStretch(1, 1);
        horizontalLayout_24->setStretch(2, 1);
        horizontalLayout_24->setStretch(3, 2);
        horizontalLayout_24->setStretch(4, 2);

        verticalLayout_2->addLayout(horizontalLayout_24);


        gridLayout_22->addLayout(verticalLayout_2, 1, 0, 1, 2);

        groupBox_13 = new QGroupBox(page_6);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_17 = new QGridLayout(groupBox_13);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setHorizontalSpacing(3);
        gridLayout_17->setContentsMargins(1, -1, 1, -1);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_25 = new QLabel(groupBox_13);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_25->addWidget(label_25);

        A1_label = new QLabel(groupBox_13);
        A1_label->setObjectName(QStringLiteral("A1_label"));

        horizontalLayout_25->addWidget(A1_label);

        label_36 = new QLabel(groupBox_13);
        label_36->setObjectName(QStringLiteral("label_36"));

        horizontalLayout_25->addWidget(label_36);

        B1_label = new QLabel(groupBox_13);
        B1_label->setObjectName(QStringLiteral("B1_label"));

        horizontalLayout_25->addWidget(B1_label);

        label_39 = new QLabel(groupBox_13);
        label_39->setObjectName(QStringLiteral("label_39"));

        horizontalLayout_25->addWidget(label_39);

        C1_label = new QLabel(groupBox_13);
        C1_label->setObjectName(QStringLiteral("C1_label"));

        horizontalLayout_25->addWidget(C1_label);


        gridLayout_17->addLayout(horizontalLayout_25, 0, 0, 1, 1);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_35 = new QLabel(groupBox_13);
        label_35->setObjectName(QStringLiteral("label_35"));

        horizontalLayout_26->addWidget(label_35);

        A2_label = new QLabel(groupBox_13);
        A2_label->setObjectName(QStringLiteral("A2_label"));

        horizontalLayout_26->addWidget(A2_label);

        label_38 = new QLabel(groupBox_13);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_26->addWidget(label_38);

        B2_label = new QLabel(groupBox_13);
        B2_label->setObjectName(QStringLiteral("B2_label"));

        horizontalLayout_26->addWidget(B2_label);

        label_40 = new QLabel(groupBox_13);
        label_40->setObjectName(QStringLiteral("label_40"));

        horizontalLayout_26->addWidget(label_40);

        C2_label = new QLabel(groupBox_13);
        C2_label->setObjectName(QStringLiteral("C2_label"));

        horizontalLayout_26->addWidget(C2_label);


        gridLayout_17->addLayout(horizontalLayout_26, 1, 0, 1, 1);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_42 = new QLabel(groupBox_13);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_27->addWidget(label_42);

        least_offset_label = new QLabel(groupBox_13);
        least_offset_label->setObjectName(QStringLiteral("least_offset_label"));

        horizontalLayout_27->addWidget(least_offset_label);


        gridLayout_17->addLayout(horizontalLayout_27, 2, 0, 1, 1);


        gridLayout_22->addWidget(groupBox_13, 2, 0, 1, 2);

        res_textEdit = new QTextEdit(page_6);
        res_textEdit->setObjectName(QStringLiteral("res_textEdit"));

        gridLayout_22->addWidget(res_textEdit, 3, 0, 1, 2);

        startAutoAdjust_pushButton = new QPushButton(page_6);
        startAutoAdjust_pushButton->setObjectName(QStringLiteral("startAutoAdjust_pushButton"));

        gridLayout_22->addWidget(startAutoAdjust_pushButton, 4, 0, 1, 1);

        fuwei_pushButton = new QPushButton(page_6);
        fuwei_pushButton->setObjectName(QStringLiteral("fuwei_pushButton"));

        gridLayout_22->addWidget(fuwei_pushButton, 4, 1, 1, 1);

        toolBox->addItem(page_6, QString::fromUtf8("            \350\207\252\345\212\250\346\240\241\345\207\206\347\252\227\345\217\243"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 300, 713));
        groupBox_15 = new QGroupBox(page_7);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        groupBox_15->setGeometry(QRect(20, 20, 261, 121));
        gridLayout_23 = new QGridLayout(groupBox_15);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        label_52 = new QLabel(groupBox_15);
        label_52->setObjectName(QStringLiteral("label_52"));

        gridLayout_23->addWidget(label_52, 0, 0, 1, 1);

        read_a1_label = new QLabel(groupBox_15);
        read_a1_label->setObjectName(QStringLiteral("read_a1_label"));

        gridLayout_23->addWidget(read_a1_label, 0, 1, 1, 1);

        label_55 = new QLabel(groupBox_15);
        label_55->setObjectName(QStringLiteral("label_55"));

        gridLayout_23->addWidget(label_55, 0, 2, 1, 1);

        read_b1_label = new QLabel(groupBox_15);
        read_b1_label->setObjectName(QStringLiteral("read_b1_label"));

        gridLayout_23->addWidget(read_b1_label, 0, 3, 1, 1);

        label_57 = new QLabel(groupBox_15);
        label_57->setObjectName(QStringLiteral("label_57"));

        gridLayout_23->addWidget(label_57, 0, 4, 1, 1);

        read_c1_label = new QLabel(groupBox_15);
        read_c1_label->setObjectName(QStringLiteral("read_c1_label"));

        gridLayout_23->addWidget(read_c1_label, 0, 5, 1, 1);

        label_63 = new QLabel(groupBox_15);
        label_63->setObjectName(QStringLiteral("label_63"));

        gridLayout_23->addWidget(label_63, 1, 0, 1, 1);

        read_a2_label = new QLabel(groupBox_15);
        read_a2_label->setObjectName(QStringLiteral("read_a2_label"));

        gridLayout_23->addWidget(read_a2_label, 1, 1, 1, 1);

        label_60 = new QLabel(groupBox_15);
        label_60->setObjectName(QStringLiteral("label_60"));

        gridLayout_23->addWidget(label_60, 1, 2, 1, 1);

        read_b2_label = new QLabel(groupBox_15);
        read_b2_label->setObjectName(QStringLiteral("read_b2_label"));

        gridLayout_23->addWidget(read_b2_label, 1, 3, 1, 1);

        label_61 = new QLabel(groupBox_15);
        label_61->setObjectName(QStringLiteral("label_61"));

        gridLayout_23->addWidget(label_61, 1, 4, 1, 1);

        read_c2_label = new QLabel(groupBox_15);
        read_c2_label->setObjectName(QStringLiteral("read_c2_label"));

        gridLayout_23->addWidget(read_c2_label, 1, 5, 1, 1);

        label_65 = new QLabel(groupBox_15);
        label_65->setObjectName(QStringLiteral("label_65"));

        gridLayout_23->addWidget(label_65, 2, 0, 1, 2);

        read_offset_label = new QLabel(groupBox_15);
        read_offset_label->setObjectName(QStringLiteral("read_offset_label"));

        gridLayout_23->addWidget(read_offset_label, 2, 2, 1, 2);

        groupBox_16 = new QGroupBox(page_7);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        groupBox_16->setGeometry(QRect(20, 380, 251, 141));
        label_53 = new QLabel(groupBox_16);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(30, 50, 91, 16));
        sendPoint_lineEdit = new QLineEdit(groupBox_16);
        sendPoint_lineEdit->setObjectName(QStringLiteral("sendPoint_lineEdit"));
        sendPoint_lineEdit->setGeometry(QRect(120, 50, 81, 20));
        startMove_pushButton = new QPushButton(groupBox_16);
        startMove_pushButton->setObjectName(QStringLiteral("startMove_pushButton"));
        startMove_pushButton->setGeometry(QRect(110, 100, 80, 20));
        readMCU_textEdit = new QTextEdit(page_7);
        readMCU_textEdit->setObjectName(QStringLiteral("readMCU_textEdit"));
        readMCU_textEdit->setGeometry(QRect(20, 150, 261, 181));
        readMCU_pushButton = new QPushButton(page_7);
        readMCU_pushButton->setObjectName(QStringLiteral("readMCU_pushButton"));
        readMCU_pushButton->setGeometry(QRect(20, 340, 75, 20));
        toolBox->addItem(page_7, QString::fromUtf8("\350\257\273\345\217\226MCU "));
        splitter->addWidget(toolBox);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        HistoryData_label = new QLabel(groupBox);
        HistoryData_label->setObjectName(QStringLiteral("HistoryData_label"));
        HistoryData_label->setMinimumSize(QSize(70, 0));
        HistoryData_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(HistoryData_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        DPS_label = new QLabel(groupBox);
        DPS_label->setObjectName(QStringLiteral("DPS_label"));
        DPS_label->setMinimumSize(QSize(50, 0));
        DPS_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(DPS_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Transform_checkBox = new QCheckBox(groupBox);
        Transform_checkBox->setObjectName(QStringLiteral("Transform_checkBox"));
        Transform_checkBox->setChecked(true);

        horizontalLayout->addWidget(Transform_checkBox);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 5);
        horizontalLayout->setStretch(6, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        TimingSave_checkBox = new QCheckBox(groupBox);
        TimingSave_checkBox->setObjectName(QStringLiteral("TimingSave_checkBox"));

        horizontalLayout_3->addWidget(TimingSave_checkBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 7);

        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        savePath_lineEdit = new QLineEdit(groupBox);
        savePath_lineEdit->setObjectName(QStringLiteral("savePath_lineEdit"));

        horizontalLayout_7->addWidget(savePath_lineEdit);


        gridLayout->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        save_pushButton = new QPushButton(groupBox);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));

        horizontalLayout_4->addWidget(save_pushButton);

        timeInnterval_label = new QLabel(groupBox);
        timeInnterval_label->setObjectName(QStringLiteral("timeInnterval_label"));
        timeInnterval_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(timeInnterval_label);

        timeInnterval_lineEdit = new QLineEdit(groupBox);
        timeInnterval_lineEdit->setObjectName(QStringLiteral("timeInnterval_lineEdit"));
        timeInnterval_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(timeInnterval_lineEdit);

        horizontalSpacer_6 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        clear_pushButton = new QPushButton(groupBox);
        clear_pushButton->setObjectName(QStringLiteral("clear_pushButton"));

        horizontalLayout_4->addWidget(clear_pushButton);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 5);

        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        ResultHistory_textEdit = new QPlainTextEdit(groupBox);
        ResultHistory_textEdit->setObjectName(QStringLiteral("ResultHistory_textEdit"));
        ResultHistory_textEdit->setStyleSheet(QString::fromUtf8("font: 9pt \"Source Code Pro\";\n"
"font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(ResultHistory_textEdit, 1, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_12 = new QGridLayout(groupBox_2);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_2->addWidget(label_24);

        plot_comboBox = new QComboBox(groupBox_2);
        plot_comboBox->setObjectName(QStringLiteral("plot_comboBox"));

        horizontalLayout_2->addWidget(plot_comboBox);

        horizontalSpacer_3 = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_12->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(groupBox_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_10 = new QGridLayout(page_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        TOF_widget = new QCustomPlot(page_2);
        TOF_widget->setObjectName(QStringLiteral("TOF_widget"));

        gridLayout_10->addWidget(TOF_widget, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        savePicture_pushButton = new QPushButton(page_2);
        savePicture_pushButton->setObjectName(QStringLiteral("savePicture_pushButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/image/images/ccSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        savePicture_pushButton->setIcon(icon6);

        horizontalLayout_5->addWidget(savePicture_pushButton);

        horizontalSpacer_7 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 8);

        gridLayout_10->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        gridLayout_10->setRowStretch(0, 18);
        gridLayout_10->setRowStretch(1, 1);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_13 = new QGridLayout(page_3);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        Histogram_widget = new QCustomPlot(page_3);
        Histogram_widget->setObjectName(QStringLiteral("Histogram_widget"));

        gridLayout_13->addWidget(Histogram_widget, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        savePicture_his_pushButton = new QPushButton(page_3);
        savePicture_his_pushButton->setObjectName(QStringLiteral("savePicture_his_pushButton"));
        savePicture_his_pushButton->setIcon(icon6);

        horizontalLayout_9->addWidget(savePicture_his_pushButton);

        HistogramData_pushButton = new QPushButton(page_3);
        HistogramData_pushButton->setObjectName(QStringLiteral("HistogramData_pushButton"));
        HistogramData_pushButton->setIcon(icon6);

        horizontalLayout_9->addWidget(HistogramData_pushButton);

        horizontalSpacer_4 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        gridLayout_13->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        gridLayout_13->setRowStretch(0, 18);
        gridLayout_13->setRowStretch(1, 1);
        gridLayout_13->setRowMinimumHeight(0, 18);
        gridLayout_13->setRowMinimumHeight(1, 1);
        stackedWidget->addWidget(page_3);
        casset_historgram_page = new QWidget();
        casset_historgram_page->setObjectName(QStringLiteral("casset_historgram_page"));
        gridLayout_20 = new QGridLayout(casset_historgram_page);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        casset_historgrm_widget = new QCustomPlot(casset_historgram_page);
        casset_historgrm_widget->setObjectName(QStringLiteral("casset_historgrm_widget"));

        gridLayout_20->addWidget(casset_historgrm_widget, 0, 0, 1, 3);

        casset_imageSave_pushButton = new QPushButton(casset_historgram_page);
        casset_imageSave_pushButton->setObjectName(QStringLiteral("casset_imageSave_pushButton"));

        gridLayout_20->addWidget(casset_imageSave_pushButton, 1, 0, 1, 1);

        casset_historgram_pushButton = new QPushButton(casset_historgram_page);
        casset_historgram_pushButton->setObjectName(QStringLiteral("casset_historgram_pushButton"));

        gridLayout_20->addWidget(casset_historgram_pushButton, 1, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(horizontalSpacer_9, 1, 2, 1, 1);

        stackedWidget->addWidget(casset_historgram_page);

        gridLayout_12->addWidget(stackedWidget, 1, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1433, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menuBar);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        mainToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        mainToolBar->setOrientation(Qt::Horizontal);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu_6->menuAction());
        menu_2->addAction(Register_action);
        menu_2->addAction(menu_4->menuAction());
        menu_4->addAction(actionEnglish);
        menu_4->addAction(action_china);
        menu_3->addAction(actionMCU);
        menu_3->addAction(showTOF_action_TOF);
        menu_5->addAction(manageMent_action);
        menu_6->addAction(about_action);
        mainToolBar->addAction(Register_action);
        mainToolBar->addAction(actionMCU);
        mainToolBar->addAction(showTOF_action_TOF);
        mainToolBar->addAction(manageMent_action);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(3);
        pixel_timeOffset_comboBox->setCurrentIndex(2);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VI4300\351\205\215\347\275\256\347\250\213\345\272\217(v2.0)", Q_NULLPTR));
        actionMCU->setText(QApplication::translate("MainWindow", "MCU\345\215\207\347\272\247", Q_NULLPTR));
        Register_action->setText(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\351\205\215\347\275\256", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        action_china->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207\347\256\200\344\275\223", Q_NULLPTR));
        showTOF_action_TOF->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256TOF\345\233\276", Q_NULLPTR));
        manageMent_action->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\256\241\347\220\206", Q_NULLPTR));
        about_action->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        portScan_pushButton->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\243\200\346\265\213", Q_NULLPTR));
        openPort_pushButton->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\346\265\213\351\207\217\357\274\232", Q_NULLPTR));
        singleMeasure_pushButton->setText(QApplication::translate("MainWindow", "\345\215\225\346\254\241\346\265\213\351\207\217", Q_NULLPTR));
        delayMeasure_pushButton->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\265\213\351\207\217", Q_NULLPTR));
        stopMeasure_pushButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        startlds_pushButton->setText(QApplication::translate("MainWindow", "startlds$", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\350\257\273\345\217\226\357\274\232", Q_NULLPTR));
        pixel_timeOffset_comboBox->clear();
        pixel_timeOffset_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "100ms", Q_NULLPTR)
         << QApplication::translate("MainWindow", "200ms", Q_NULLPTR)
         << QApplication::translate("MainWindow", "500ms", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1000ms", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2000ms", Q_NULLPTR)
        );
        pixel_time_pushButton->setText(QApplication::translate("MainWindow", "pixel\345\256\232\346\227\266\350\257\273\345\217\226", Q_NULLPTR));
        CAS_pix1_pushButton->setText(QApplication::translate("MainWindow", "pix_1\345\256\232\346\227\266\350\257\273", Q_NULLPTR));
        CAS_pix2_pushButton->setText(QApplication::translate("MainWindow", "pix_2\345\256\232\346\227\266\350\257\273", Q_NULLPTR));
        rowData_pushButton->setText(QApplication::translate("MainWindow", "RawData", Q_NULLPTR));
        pixel_read_pushButton->setText(QApplication::translate("MainWindow", "Pixel", Q_NULLPTR));
        delayLine_pushButton->setText(QApplication::translate("MainWindow", "delay line", Q_NULLPTR));
        openOrClose_laser_pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\277\200\345\205\211\345\231\250", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\273\223\346\236\234\346\230\276\347\244\272:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\267\235\347\246\273:(mm)", Q_NULLPTR));
        currentDistance11_label->setText(QApplication::translate("MainWindow", "0.00", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\350\277\2211000\346\254\241\347\273\223\346\236\234\345\235\207\345\200\274(mm)\357\274\232", Q_NULLPTR));
        mean_label->setText(QApplication::translate("MainWindow", "0.00", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\350\277\2211000\346\254\241\347\273\223\346\236\234\346\240\207\345\207\206\345\267\256\357\274\232", Q_NULLPTR));
        std_label->setText(QApplication::translate("MainWindow", "0.00", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\347\224\273\345\233\276\345\212\237\350\203\275:", Q_NULLPTR));
        plotSet_off_radioButton->setText(QApplication::translate("MainWindow", "OFF", Q_NULLPTR));
        plotSet_on_radioButton->setText(QApplication::translate("MainWindow", "ON", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "              \345\237\272\346\234\254\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\345\207\272\345\216\202\350\256\276\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "SN \345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        botelv_comboBox->clear();
        botelv_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "256000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "56000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "43000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "230400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "460800", Q_NULLPTR)
        );
        label_18->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\345\217\267\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "UUID:", Q_NULLPTR));
        read_outFactory_pushButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", Q_NULLPTR));
        send_outFactory_pushButton->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        reStoreFactory_pushButton->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\350\276\223\345\207\272\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "\347\234\237\345\256\236\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\216\237\345\247\213LSB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\270\251\345\272\246\346\240\241\346\255\243\347\232\204mm\346\225\260\346\215\256", Q_NULLPTR)
        );
        groupBox_12->setTitle(QApplication::translate("MainWindow", "\345\215\225\344\270\252\345\257\204\345\255\230\345\231\250\350\257\273\345\206\231\357\274\232", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "\345\234\260\345\235\200(0x)\357\274\232", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "  \345\200\274(0x)\357\274\232", Q_NULLPTR));
        singleReg_read_pushButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", Q_NULLPTR));
        singleReg_write_pushButton->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("MainWindow", "              \350\256\276\345\244\207\351\205\215\347\275\256", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "offset\346\240\241\345\207\206\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\350\267\235\347\246\273(mm):     ", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\347\263\273\346\225\260K(float): ", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\347\263\273\346\225\260\357\274\232    ", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "\346\212\227\351\230\263\345\205\211\345\274\272\345\272\246\357\274\232", Q_NULLPTR));
        sunPower_set_comboBox->clear();
        sunPower_set_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        label_29->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\351\207\217\347\250\213(mm)\357\274\232", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        filter_comboBox->clear();
        filter_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\235\207\345\200\274\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\273\221\345\212\250\347\252\227\345\217\243\346\273\244\346\263\242", Q_NULLPTR)
        );
        label_31->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\351\242\221\347\216\207\357\274\232", Q_NULLPTR));
        offset_caiji_comboBox->clear();
        offset_caiji_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "4500", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "500", Q_NULLPTR)
         << QApplication::translate("MainWindow", "200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "100", Q_NULLPTR)
         << QApplication::translate("MainWindow", "50", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        label_34->setText(QApplication::translate("MainWindow", "PEAK\351\230\210\345\200\274\357\274\232     ", Q_NULLPTR));
        calibration_pushButton->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        calibration_read_pushButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "offset\346\240\241\345\207\206\347\273\223\346\236\234\350\257\273\345\217\226\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\347\234\237\345\256\236\350\267\235\347\246\273(mm):", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "\346\240\241\345\207\206\346\227\266\346\270\251\345\272\246(C):", Q_NULLPTR));
        temperature_lineEdit->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "Offset\345\200\274\357\274\232", Q_NULLPTR));
        offset_jiaozhun_lineEdit->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\347\263\273\346\225\260K(float):", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "\346\212\227\351\230\263\345\205\211\345\274\272\345\272\246\357\274\232", Q_NULLPTR));
        gaofan_pushButton->setText(QApplication::translate("MainWindow", "\351\253\230\345\217\215\346\240\241\345\207\206", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("MainWindow", "              \350\256\276\345\244\207\346\240\241\345\207\206", Q_NULLPTR));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_45->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_47->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        label_49->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        label_50->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        portScan_pushButton_2->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\243\200\346\265\213", Q_NULLPTR));
        openPort_pushButton_2->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "0.1m", Q_NULLPTR));
        black_01_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_01_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black01_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_01_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "0.2m", Q_NULLPTR));
        black_02_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_02_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black02_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_02_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "0.3m", Q_NULLPTR));
        black_03_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_03_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black03_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_03_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_44->setText(QApplication::translate("MainWindow", "0.4m", Q_NULLPTR));
        black_04_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_04_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black04_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_04_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_46->setText(QApplication::translate("MainWindow", "0.5m", Q_NULLPTR));
        black_05_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_05_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black05_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_05_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_48->setText(QApplication::translate("MainWindow", "1.0m", Q_NULLPTR));
        black_1_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_1_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black1_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_1_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_51->setText(QApplication::translate("MainWindow", "3.0m", Q_NULLPTR));
        black_3_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_3_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black3_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_3_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_54->setText(QApplication::translate("MainWindow", "8.0m", Q_NULLPTR));
        black_8_pushButton->setText(QApplication::translate("MainWindow", "\351\273\221", Q_NULLPTR));
        white_8_pushButton->setText(QApplication::translate("MainWindow", "\347\231\275", Q_NULLPTR));
        black8_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        white_8_label->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "\346\240\241\345\207\206\345\217\202\346\225\260\357\274\232", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "A1\357\274\232", Q_NULLPTR));
        A1_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "B1\357\274\232", Q_NULLPTR));
        B1_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "C1\357\274\232", Q_NULLPTR));
        C1_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "A2\357\274\232", Q_NULLPTR));
        A2_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "B2\357\274\232", Q_NULLPTR));
        B2_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "C2\357\274\232", Q_NULLPTR));
        C2_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "OFFSET:", Q_NULLPTR));
        least_offset_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        startAutoAdjust_pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257\350\207\252\345\212\250\346\240\241\346\255\243", Q_NULLPTR));
        fuwei_pushButton->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("MainWindow", "            \350\207\252\345\212\250\346\240\241\345\207\206\347\252\227\345\217\243", Q_NULLPTR));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_52->setText(QApplication::translate("MainWindow", "A1\357\274\232", Q_NULLPTR));
        read_a1_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_55->setText(QApplication::translate("MainWindow", "B1\357\274\232", Q_NULLPTR));
        read_b1_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_57->setText(QApplication::translate("MainWindow", "C1\357\274\232", Q_NULLPTR));
        read_c1_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_63->setText(QApplication::translate("MainWindow", "A2\357\274\232", Q_NULLPTR));
        read_a2_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_60->setText(QApplication::translate("MainWindow", "B2\357\274\232", Q_NULLPTR));
        read_b2_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_61->setText(QApplication::translate("MainWindow", "C2\357\274\232", Q_NULLPTR));
        read_c2_label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_65->setText(QApplication::translate("MainWindow", "OFFSET:", Q_NULLPTR));
        read_offset_label->setText(QApplication::translate("MainWindow", "OFFSET:", Q_NULLPTR));
        groupBox_16->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_53->setText(QApplication::translate("MainWindow", "\346\214\207\345\256\232\344\275\215\347\275\256(mm)\357\274\232", Q_NULLPTR));
        startMove_pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\247\273\345\212\250", Q_NULLPTR));
        readMCU_pushButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("MainWindow", "\350\257\273\345\217\226MCU ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\273\223\346\236\234\350\256\260\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\267\262\350\256\260\345\275\225\346\225\260\346\215\256:", Q_NULLPTR));
        HistoryData_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "DPS:", Q_NULLPTR));
        DPS_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Transform_checkBox->setText(QApplication::translate("MainWindow", "\350\275\254\346\215\242", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266\350\267\257\345\276\204", Q_NULLPTR));
        TimingSave_checkBox->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\344\277\235\345\255\230", Q_NULLPTR));
        save_pushButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        timeInnterval_label->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\351\227\264\351\232\224(S):", Q_NULLPTR));
        timeInnterval_lineEdit->setText(QApplication::translate("MainWindow", "60", Q_NULLPTR));
        clear_pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\224\273\345\233\276", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "\347\224\273\345\233\276\351\200\211\351\241\271\357\274\232", Q_NULLPTR));
        plot_comboBox->clear();
        plot_comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "TOF\345\233\276", Q_NULLPTR)
         << QApplication::translate("MainWindow", "VI4300\347\233\264\346\226\271\345\233\276", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CASSATT\347\233\264\346\226\271\345\233\276", Q_NULLPTR)
        );
        savePicture_pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230", Q_NULLPTR));
        savePicture_his_pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230", Q_NULLPTR));
        HistogramData_pushButton->setText(QApplication::translate("MainWindow", "HistData_save", Q_NULLPTR));
        casset_imageSave_pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230", Q_NULLPTR));
        casset_historgram_pushButton->setText(QApplication::translate("MainWindow", "HistorgramData", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\257\255\350\250\200(language)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\205\266\344\273\226", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        menu_6->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
