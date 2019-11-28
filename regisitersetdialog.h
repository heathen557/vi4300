#ifndef REGISITERSETDIALOG_H
#define REGISITERSETDIALOG_H

#include <QDialog>
#include<QFileDialog>
#include<QTableWidgetItem>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class RegisiterSetDialog;
}

class RegisiterSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisiterSetDialog(QWidget *parent = 0);
    ~RegisiterSetDialog();

    QTableWidgetItem  addressItem[100];
    QTableWidgetItem  valueItem[100];

    void closeEvent(QCloseEvent *event);

private slots:
    void on_loadLocal_pushButton_clicked();

    void on_saveLocal_pushButton_clicked();

    void on_send_pushButton_clicked();

    void on_read_pushButton_clicked();

    void clearItem();

    void showItem();

    void on_toolButton_clicked();

signals:
    void sendSerialSignal(QString);             //串口发送信号

private:
    Ui::RegisiterSetDialog *ui;
};

#endif // REGISITERSETDIALOG_H
