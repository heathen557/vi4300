#ifndef HIGHREACT_DIALOG_H
#define HIGHREACT_DIALOG_H

#include <QDialog>
#include<QTableWidgetItem>

namespace Ui {
class HighReact_Dialog;
}

class HighReact_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit HighReact_Dialog(QWidget *parent = 0);
    ~HighReact_Dialog();

    void changeEvent(QEvent *e);

    void clearItem();

    void closeEvent(QCloseEvent *event);

    QTableWidgetItem  valueItem[30];

private slots:
    void on_send_pushButton_clicked();

    void on_cancel_pushButton_clicked();

signals:
    void sendSerialSignal(QString);             //串口发送信号

private:
    Ui::HighReact_Dialog *ui;
};

#endif // HIGHREACT_DIALOG_H
