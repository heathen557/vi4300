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
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QFormLayout *formLayout_5;
    QPushButton *singleMeasure_pushButton;
    QPushButton *delayMeasure_pushButton;
    QPushButton *stopMeasure_pushButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout;
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
    QPushButton *rowData_pushButton;
    QWidget *page_4;
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *SN_lineEdit;
    QLabel *label_2;
    QComboBox *botelv_comboBox;
    QLabel *label_18;
    QComboBox *CAIJI_frequency_comboBox;
    QLabel *label_20;
    QComboBox *deviceType_comboBox;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *UUID_lineEdit;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *YULIU_lineEdit;
    QPushButton *read_outFactory_pushButton;
    QPushButton *send_outFactory_pushButton;
    QPushButton *reStoreFactory_pushButton;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_9;
    QLabel *label_6;
    QLineEdit *realDisFactory_lineEdit;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *calibration_pushButton;
    QFrame *line;
    QPushButton *gaofan_pushButton;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_11;
    QRadioButton *realDis_out_radioButton;
    QRadioButton *LSB_out_radioButton;
    QSpacerItem *verticalSpacer;
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
    QToolButton *selectSavePathtoolButton;
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
    QRadioButton *TOF_radioButton;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *Histogram_radioButton;
    QSpacerItem *horizontalSpacer_4;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QCustomPlot *TOF_widget;
    QWidget *page_3;
    QGridLayout *gridLayout_13;
    QCustomPlot *Histogram_widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *savePicture_pushButton;
    QPushButton *HistogramData_pushButton;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1180, 714);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(220, 0));
        toolBox->setMaximumSize(QSize(220, 16777215));
        toolBox->setStyleSheet(QLatin1String(".QToolBox{\n"
"font: 10pt \"Times New Roman\";}"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 220, 565));
        page->setStyleSheet(QLatin1String(".QWidget{\n"
"font: 11pt \"Times New Roman\";}"));
        gridLayout_7 = new QGridLayout(page);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_5 = new QGroupBox(page);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
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


        gridLayout_6->addLayout(formLayout_5, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        serialPortInfoListBox = new QComboBox(groupBox_3);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, serialPortInfoListBox);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        baudRateBox = new QComboBox(groupBox_3);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, baudRateBox);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        dataBitsBox = new QComboBox(groupBox_3);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dataBitsBox);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        stopBitsBox = new QComboBox(groupBox_3);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, stopBitsBox);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        parityBox = new QComboBox(groupBox_3);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, parityBox);

        portScan_pushButton = new QPushButton(groupBox_3);
        portScan_pushButton->setObjectName(QStringLiteral("portScan_pushButton"));

        formLayout->setWidget(5, QFormLayout::LabelRole, portScan_pushButton);

        openPort_pushButton = new QPushButton(groupBox_3);
        openPort_pushButton->setObjectName(QStringLiteral("openPort_pushButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, openPort_pushButton);


        gridLayout_4->addLayout(formLayout, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(page);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
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


        gridLayout_7->addWidget(groupBox_4, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(page);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, 2, -1, 2);
        plotSet_off_radioButton = new QRadioButton(groupBox_8);
        plotSet_off_radioButton->setObjectName(QStringLiteral("plotSet_off_radioButton"));
        plotSet_off_radioButton->setChecked(true);

        gridLayout_8->addWidget(plotSet_off_radioButton, 0, 1, 1, 1);

        plotSet_on_radioButton = new QRadioButton(groupBox_8);
        plotSet_on_radioButton->setObjectName(QStringLiteral("plotSet_on_radioButton"));

        gridLayout_8->addWidget(plotSet_on_radioButton, 0, 0, 1, 1);

        rowData_pushButton = new QPushButton(groupBox_8);
        rowData_pushButton->setObjectName(QStringLiteral("rowData_pushButton"));

        gridLayout_8->addWidget(rowData_pushButton, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_8, 3, 0, 1, 1);

        gridLayout_7->setRowStretch(0, 5);
        gridLayout_7->setRowStretch(1, 2);
        gridLayout_7->setRowStretch(2, 5);
        gridLayout_7->setRowStretch(3, 2);
        toolBox->addItem(page, QString::fromUtf8("            \345\237\272\346\234\254\350\256\276\347\275\256"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 220, 565));
        page_4->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_14 = new QGridLayout(page_4);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        groupBox_7 = new QGroupBox(page_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_3 = new QGridLayout(groupBox_7);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
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

        CAIJI_frequency_comboBox = new QComboBox(groupBox_7);
        CAIJI_frequency_comboBox->setObjectName(QStringLiteral("CAIJI_frequency_comboBox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, CAIJI_frequency_comboBox);

        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_20);

        deviceType_comboBox = new QComboBox(groupBox_7);
        deviceType_comboBox->setObjectName(QStringLiteral("deviceType_comboBox"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, deviceType_comboBox);

        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_17);

        horizontalSpacer_8 = new QSpacerItem(105, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(4, QFormLayout::FieldRole, horizontalSpacer_8);

        UUID_lineEdit = new QLineEdit(groupBox_7);
        UUID_lineEdit->setObjectName(QStringLiteral("UUID_lineEdit"));

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, UUID_lineEdit);

        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_19);

        horizontalSpacer_11 = new QSpacerItem(105, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(6, QFormLayout::FieldRole, horizontalSpacer_11);

        YULIU_lineEdit = new QLineEdit(groupBox_7);
        YULIU_lineEdit->setObjectName(QStringLiteral("YULIU_lineEdit"));

        formLayout_2->setWidget(7, QFormLayout::SpanningRole, YULIU_lineEdit);

        read_outFactory_pushButton = new QPushButton(groupBox_7);
        read_outFactory_pushButton->setObjectName(QStringLiteral("read_outFactory_pushButton"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, read_outFactory_pushButton);

        send_outFactory_pushButton = new QPushButton(groupBox_7);
        send_outFactory_pushButton->setObjectName(QStringLiteral("send_outFactory_pushButton"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, send_outFactory_pushButton);

        reStoreFactory_pushButton = new QPushButton(groupBox_7);
        reStoreFactory_pushButton->setObjectName(QStringLiteral("reStoreFactory_pushButton"));

        formLayout_2->setWidget(9, QFormLayout::SpanningRole, reStoreFactory_pushButton);


        gridLayout_3->addLayout(formLayout_2, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(page_4);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_9 = new QGridLayout(groupBox_9);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_6 = new QLabel(groupBox_9);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_9->addWidget(label_6, 0, 0, 1, 1);

        realDisFactory_lineEdit = new QLineEdit(groupBox_9);
        realDisFactory_lineEdit->setObjectName(QStringLiteral("realDisFactory_lineEdit"));

        gridLayout_9->addWidget(realDisFactory_lineEdit, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(75, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        calibration_pushButton = new QPushButton(groupBox_9);
        calibration_pushButton->setObjectName(QStringLiteral("calibration_pushButton"));

        gridLayout_9->addWidget(calibration_pushButton, 1, 1, 1, 1);

        line = new QFrame(groupBox_9);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line, 2, 0, 1, 2);

        gaofan_pushButton = new QPushButton(groupBox_9);
        gaofan_pushButton->setObjectName(QStringLiteral("gaofan_pushButton"));

        gridLayout_9->addWidget(gaofan_pushButton, 3, 0, 1, 2);


        gridLayout_14->addWidget(groupBox_9, 1, 0, 1, 1);

        groupBox_10 = new QGroupBox(page_4);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_11 = new QGridLayout(groupBox_10);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        realDis_out_radioButton = new QRadioButton(groupBox_10);
        realDis_out_radioButton->setObjectName(QStringLiteral("realDis_out_radioButton"));
        realDis_out_radioButton->setChecked(true);

        gridLayout_11->addWidget(realDis_out_radioButton, 0, 0, 1, 1);

        LSB_out_radioButton = new QRadioButton(groupBox_10);
        LSB_out_radioButton->setObjectName(QStringLiteral("LSB_out_radioButton"));

        gridLayout_11->addWidget(LSB_out_radioButton, 0, 1, 1, 1);


        gridLayout_14->addWidget(groupBox_10, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer, 3, 0, 1, 1);

        toolBox->addItem(page_4, QString::fromUtf8("            \350\256\276\345\244\207\351\205\215\347\275\256"));
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

        selectSavePathtoolButton = new QToolButton(groupBox);
        selectSavePathtoolButton->setObjectName(QStringLiteral("selectSavePathtoolButton"));

        horizontalLayout_7->addWidget(selectSavePathtoolButton);


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
        TOF_radioButton = new QRadioButton(groupBox_2);
        TOF_radioButton->setObjectName(QStringLiteral("TOF_radioButton"));
        TOF_radioButton->setChecked(true);

        horizontalLayout_2->addWidget(TOF_radioButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        Histogram_radioButton = new QRadioButton(groupBox_2);
        Histogram_radioButton->setObjectName(QStringLiteral("Histogram_radioButton"));

        horizontalLayout_2->addWidget(Histogram_radioButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 3);

        gridLayout_12->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(groupBox_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        TOF_widget = new QCustomPlot(page_2);
        TOF_widget->setObjectName(QStringLiteral("TOF_widget"));

        gridLayout_2->addWidget(TOF_widget, 0, 0, 1, 1);

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

        stackedWidget->addWidget(page_3);

        gridLayout_12->addWidget(stackedWidget, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        savePicture_pushButton = new QPushButton(groupBox_2);
        savePicture_pushButton->setObjectName(QStringLiteral("savePicture_pushButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/image/images/ccSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        savePicture_pushButton->setIcon(icon3);

        horizontalLayout_5->addWidget(savePicture_pushButton);

        HistogramData_pushButton = new QPushButton(groupBox_2);
        HistogramData_pushButton->setObjectName(QStringLiteral("HistogramData_pushButton"));
        HistogramData_pushButton->setIcon(icon3);

        horizontalLayout_5->addWidget(HistogramData_pushButton);

        horizontalSpacer_7 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(2, 8);

        gridLayout_12->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_10->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1180, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
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
        menu_2->addAction(Register_action);
        menu_2->addAction(menu_4->menuAction());
        menu_4->addAction(actionEnglish);
        menu_4->addAction(action_china);
        menu_3->addAction(actionMCU);
        mainToolBar->addAction(Register_action);
        mainToolBar->addAction(actionMCU);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VI4300\351\205\215\347\275\256\347\250\213\345\272\217", Q_NULLPTR));
        actionMCU->setText(QApplication::translate("MainWindow", "MCU\345\215\207\347\272\247", Q_NULLPTR));
        Register_action->setText(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\351\205\215\347\275\256", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        action_china->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207\347\256\200\344\275\223", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\346\265\213\351\207\217\357\274\232", Q_NULLPTR));
        singleMeasure_pushButton->setText(QApplication::translate("MainWindow", "\345\215\225\346\254\241\346\265\213\351\207\217", Q_NULLPTR));
        delayMeasure_pushButton->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\346\265\213\351\207\217", Q_NULLPTR));
        stopMeasure_pushButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        portScan_pushButton->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\243\200\346\265\213", Q_NULLPTR));
        openPort_pushButton->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
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
        rowData_pushButton->setText(QApplication::translate("MainWindow", "RawData", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "            \345\237\272\346\234\254\350\256\276\347\275\256", Q_NULLPTR));
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
        );
        label_18->setText(QApplication::translate("MainWindow", "\351\207\207\351\233\206\351\242\221\347\216\207\357\274\232", Q_NULLPTR));
        CAIJI_frequency_comboBox->clear();
        CAIJI_frequency_comboBox->insertItems(0, QStringList()
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
        label_20->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        deviceType_comboBox->clear();
        deviceType_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "VI4300", Q_NULLPTR)
        );
        label_17->setText(QApplication::translate("MainWindow", "UUID:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "\351\242\204\347\225\231\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        read_outFactory_pushButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", Q_NULLPTR));
        send_outFactory_pushButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        reStoreFactory_pushButton->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215\345\207\272\345\216\202\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "offset\346\240\241\345\207\206\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\347\234\237\345\256\236\350\267\235\347\246\273(mm):", Q_NULLPTR));
        calibration_pushButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        gaofan_pushButton->setText(QApplication::translate("MainWindow", "\351\253\230\345\217\215\346\240\241\345\207\206", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\350\276\223\345\207\272\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        realDis_out_radioButton->setText(QApplication::translate("MainWindow", "\347\234\237\345\256\236\350\267\235\347\246\273", Q_NULLPTR));
        LSB_out_radioButton->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213LSB", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("MainWindow", "            \350\256\276\345\244\207\351\205\215\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\273\223\346\236\234\350\256\260\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\267\262\350\256\260\345\275\225\346\225\260\346\215\256:", Q_NULLPTR));
        HistoryData_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "DPS:", Q_NULLPTR));
        DPS_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Transform_checkBox->setText(QApplication::translate("MainWindow", "\350\275\254\346\215\242", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266\350\267\257\345\276\204", Q_NULLPTR));
        TimingSave_checkBox->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\344\277\235\345\255\230", Q_NULLPTR));
        selectSavePathtoolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        save_pushButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        timeInnterval_label->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\351\227\264\351\232\224(S):", Q_NULLPTR));
        timeInnterval_lineEdit->setText(QApplication::translate("MainWindow", "60", Q_NULLPTR));
        clear_pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\224\273\345\233\276", Q_NULLPTR));
        TOF_radioButton->setText(QApplication::translate("MainWindow", "TOF\345\233\276", Q_NULLPTR));
        Histogram_radioButton->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        savePicture_pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230", Q_NULLPTR));
        HistogramData_pushButton->setText(QApplication::translate("MainWindow", "HistData_save", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\257\255\350\250\200(language)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\205\266\344\273\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
