/********************************************************************************
** Form generated from reading UI file 'regisitersetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISITERSETDIALOG_H
#define UI_REGISITERSETDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisiterSetDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loadLocal_pushButton;
    QPushButton *saveLocal_pushButton;
    QPushButton *send_pushButton;
    QPushButton *read_pushButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *RegisiterSetDialog)
    {
        if (RegisiterSetDialog->objectName().isEmpty())
            RegisiterSetDialog->setObjectName(QStringLiteral("RegisiterSetDialog"));
        RegisiterSetDialog->resize(539, 572);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/image/images/ccClippingBoxMultExport.png"), QSize(), QIcon::Normal, QIcon::Off);
        RegisiterSetDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(RegisiterSetDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(RegisiterSetDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        tableWidget = new QTableWidget(RegisiterSetDialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        line = new QFrame(RegisiterSetDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loadLocal_pushButton = new QPushButton(RegisiterSetDialog);
        loadLocal_pushButton->setObjectName(QStringLiteral("loadLocal_pushButton"));

        horizontalLayout_2->addWidget(loadLocal_pushButton);

        saveLocal_pushButton = new QPushButton(RegisiterSetDialog);
        saveLocal_pushButton->setObjectName(QStringLiteral("saveLocal_pushButton"));

        horizontalLayout_2->addWidget(saveLocal_pushButton);

        send_pushButton = new QPushButton(RegisiterSetDialog);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));

        horizontalLayout_2->addWidget(send_pushButton);

        read_pushButton = new QPushButton(RegisiterSetDialog);
        read_pushButton->setObjectName(QStringLiteral("read_pushButton"));

        horizontalLayout_2->addWidget(read_pushButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(317, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 1, 1, 1);


        retranslateUi(RegisiterSetDialog);

        QMetaObject::connectSlotsByName(RegisiterSetDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisiterSetDialog)
    {
        RegisiterSetDialog->setWindowTitle(QApplication::translate("RegisiterSetDialog", "\345\257\204\345\255\230\345\231\250\351\205\215\347\275\256\347\225\214\351\235\242", Q_NULLPTR));
        label->setText(QApplication::translate("RegisiterSetDialog", "\345\257\204\345\255\230\345\231\250\351\205\215\347\275\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RegisiterSetDialog", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200(16\350\277\233\345\210\266)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RegisiterSetDialog", "\345\257\204\345\255\230\345\231\250\345\200\274(16\350\277\233\345\210\266)", Q_NULLPTR));
        loadLocal_pushButton->setText(QApplication::translate("RegisiterSetDialog", "\345\212\240\350\275\275\346\234\254\345\234\260", Q_NULLPTR));
        saveLocal_pushButton->setText(QApplication::translate("RegisiterSetDialog", "\344\277\235\345\255\230\346\234\254\345\234\260", Q_NULLPTR));
        send_pushButton->setText(QApplication::translate("RegisiterSetDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        read_pushButton->setText(QApplication::translate("RegisiterSetDialog", "\350\257\273\345\217\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisiterSetDialog: public Ui_RegisiterSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISITERSETDIALOG_H
