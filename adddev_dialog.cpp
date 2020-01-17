#include "adddev_dialog.h"
#include "ui_adddev_dialog.h"
#include<QDebug>

extern QSqlQuery sql_query;

addDev_Dialog::addDev_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDev_Dialog)
{
    ui->setupUi(this);
}

addDev_Dialog::~addDev_Dialog()
{
    delete ui;
}

void addDev_Dialog::on_ok_pushButton_clicked()
{
    QString sn_num = ui->SN_lineEdit->text();
    QString UUID_num = ui->UUID_lineEdit->text();
    QString note = ui->note_lineEdit->text();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString current_time = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    sql_query.prepare("INSERT INTO DEV_TABLE(SN,UUID,NOTE,updateTime) VALUES(:SN,:UUID,:NOTE,:updateTime)");
    sql_query.bindValue(":SN",sn_num);
    sql_query.bindValue(":UUID",UUID_num);
    sql_query.bindValue(":NOTE",note);
    sql_query.bindValue(":updateTime",current_time);
    bool buscess = sql_query.exec();
    if(!buscess)
    {
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("新增设备失败"));
        return;
    }

    ui->SN_lineEdit->clear();
    ui->UUID_lineEdit->clear();
    ui->note_lineEdit->clear();
    this->hide();

    emit update_signal();
}

void addDev_Dialog::on_cancel_pushButton_clicked()
{
    ui->SN_lineEdit->clear();
    ui->UUID_lineEdit->clear();
    this->hide();
}
