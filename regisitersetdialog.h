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

    QTableWidgetItem  addressItem[150];
    QTableWidgetItem  valueItem[150];

    void changeEvent(QEvent *e);

    void closeEvent(QCloseEvent *event);

private slots:
    void on_loadLocal_pushButton_clicked();

    void on_saveLocal_pushButton_clicked();

    void on_send_pushButton_clicked();

    void on_read_pushButton_clicked();

    void clearItem();

    //!
    //! \brief AckCmdRegister_signal
    //!寄存器返回命令的相关信号   参数1：“81”：写寄存器应答  参数2 暂无
    //!                              “80”：读寄存器应答  参数2 寄存器的数据区
    void AckCmdRegister_slot(QString,QString);

signals:
    void sendSerialSignal(QString);             //串口发送信号

private:
    Ui::RegisiterSetDialog *ui;
};

#endif // REGISITERSETDIALOG_H
