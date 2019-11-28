/********************************************************************************
** Form generated from reading UI file 'mcuupgradedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCUUPGRADEDIALOG_H
#define UI_MCUUPGRADEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_McuUpgradeDialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QFrame *line;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *filePath_lineEdit;
    QPushButton *openFile_pushButton;
    QPushButton *upgrade_pushButton;
    QPushButton *pushButton;
    QSplitter *splitter;
    QTextEdit *send_textEdit;
    QPlainTextEdit *recv_plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *McuUpgradeDialog)
    {
        if (McuUpgradeDialog->objectName().isEmpty())
            McuUpgradeDialog->setObjectName(QStringLiteral("McuUpgradeDialog"));
        McuUpgradeDialog->resize(864, 630);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/image/images/ccMerge.png"), QSize(), QIcon::Normal, QIcon::Off);
        McuUpgradeDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(McuUpgradeDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(McuUpgradeDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QStringLiteral("QProgressBar {   border: 2px solid grey;   border-radius: 5px;   background-color: #FFFFFF;}QProgressBar::chunk {   background-color: #05B8CC;   width: 20px;}QProgressBar {   border: 2px solid grey;   border-radius: 5px;   text-align: center;}"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        line = new QFrame(McuUpgradeDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filePath_lineEdit = new QLineEdit(McuUpgradeDialog);
        filePath_lineEdit->setObjectName(QStringLiteral("filePath_lineEdit"));

        horizontalLayout_2->addWidget(filePath_lineEdit);

        openFile_pushButton = new QPushButton(McuUpgradeDialog);
        openFile_pushButton->setObjectName(QStringLiteral("openFile_pushButton"));

        horizontalLayout_2->addWidget(openFile_pushButton);

        upgrade_pushButton = new QPushButton(McuUpgradeDialog);
        upgrade_pushButton->setObjectName(QStringLiteral("upgrade_pushButton"));

        horizontalLayout_2->addWidget(upgrade_pushButton);

        pushButton = new QPushButton(McuUpgradeDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        splitter = new QSplitter(McuUpgradeDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        send_textEdit = new QTextEdit(splitter);
        send_textEdit->setObjectName(QStringLiteral("send_textEdit"));
        splitter->addWidget(send_textEdit);
        recv_plainTextEdit = new QPlainTextEdit(splitter);
        recv_plainTextEdit->setObjectName(QStringLiteral("recv_plainTextEdit"));
        splitter->addWidget(recv_plainTextEdit);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(McuUpgradeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setRowStretch(2, 2);
        gridLayout->setRowStretch(3, 2);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 1);

        retranslateUi(McuUpgradeDialog);

        QMetaObject::connectSlotsByName(McuUpgradeDialog);
    } // setupUi

    void retranslateUi(QDialog *McuUpgradeDialog)
    {
        McuUpgradeDialog->setWindowTitle(QApplication::translate("McuUpgradeDialog", "MCU\347\250\213\345\272\217\345\215\207\347\272\247", Q_NULLPTR));
        openFile_pushButton->setText(QApplication::translate("McuUpgradeDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        upgrade_pushButton->setText(QApplication::translate("McuUpgradeDialog", "\345\274\200\345\247\213\345\215\207\347\272\247", Q_NULLPTR));
        pushButton->setText(QApplication::translate("McuUpgradeDialog", "test", Q_NULLPTR));
        label->setText(QApplication::translate("McuUpgradeDialog", "MCU\345\215\207\347\272\247\351\205\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class McuUpgradeDialog: public Ui_McuUpgradeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCUUPGRADEDIALOG_H
