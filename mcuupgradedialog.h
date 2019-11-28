#ifndef MCUUPGRADEDIALOG_H
#define MCUUPGRADEDIALOG_H

#include <QDialog>
#include<hex.h>
#include<QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QDebug>

namespace Ui {
class McuUpgradeDialog;
}

class McuUpgradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit McuUpgradeDialog(QWidget *parent = 0);
    ~McuUpgradeDialog();

    void closeEvent(QCloseEvent *event);

    void initSendMsgSlot();

    QFile *upGradeFile;
    Hex hexObject;
    QVector<unsigned char> hexUsefulData;


    QStringList msgList;
    QString sendBuffer;
    QString m_buffer;   //接收数据的缓存区
    QStringList sendCmdString;

    int progressNum;

private slots:
    void on_openFile_pushButton_clicked();

    void on_pushButton_clicked();

    void on_upgrade_pushButton_clicked();

    void sendCmdMsg_slot();

    void AckCmdUpgrade_signal(QString returnCmdStr,QString cmdAck);

signals:
    void sendSerialSignal(QString);             //串口发送信号

private:
    Ui::McuUpgradeDialog *ui;
};

#endif // MCUUPGRADEDIALOG_H
