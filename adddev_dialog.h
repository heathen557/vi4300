#ifndef ADDDEV_DIALOG_H
#define ADDDEV_DIALOG_H

#include <QDialog>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDateTime>

namespace Ui {
class addDev_Dialog;
}

class addDev_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDev_Dialog(QWidget *parent = 0);
    ~addDev_Dialog();

private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

signals:
    void update_signal();

private:
    Ui::addDev_Dialog *ui;
};

#endif // ADDDEV_DIALOG_H
