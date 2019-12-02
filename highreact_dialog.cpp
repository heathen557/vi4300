#include "highreact_dialog.h"
#include "ui_highreact_dialog.h"

HighReact_Dialog::HighReact_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighReact_Dialog)
{
    ui->setupUi(this);

//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(30);
    ui->tableWidget->setColumnCount(1);
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(240,240,240)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(240,240,240)}");

    for(int i=0; i<30 ; i++)
    {
        ui->tableWidget->setItem(i,0,&valueItem[i]);
        valueItem[i].setTextAlignment(Qt::AlignCenter);
    }
}

HighReact_Dialog::~HighReact_Dialog()
{
    delete ui;
}


void HighReact_Dialog::clearItem()
{
    for(int i=0; i<30; i++)
    {
        valueItem[i].setText("");
    }
}


//!
//! \brief HighReact_Dialog::on_send_pushButton_clicked
//! 发送校正 5A 01 3C 00 05 DD.DD
void HighReact_Dialog::on_send_pushButton_clicked()
{
    QString cmdStr = "5A 01 3C 00 05 ";
    int value;
    QString tmpStr ;
    QString singleStr;
    for(int i=0 ;i<30; i++)
    {
        value = valueItem[i].text().toInt();
        tmpStr = QString("%1").arg(value,4,16,QLatin1Char('0'));
        singleStr = tmpStr.mid(2,2) + tmpStr.mid(0,2);
        cmdStr.append(singleStr);
    }
    emit sendSerialSignal(cmdStr);
}


void HighReact_Dialog::closeEvent(QCloseEvent *event)
{
    clearItem();
}


void HighReact_Dialog::on_cancel_pushButton_clicked()
{
    this->hide();
    clearItem();
}
