#ifndef HISTORYTOF_DIALOG_H
#define HISTORYTOF_DIALOG_H

#include <QDialog>
#include<qcustomplot.h>

namespace Ui {
class HistoryTof_Dialog;
}

class HistoryTof_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryTof_Dialog(QWidget *parent = 0);
    ~HistoryTof_Dialog();

private slots:
    void on_toolButton_clicked();

private:
    Ui::HistoryTof_Dialog *ui;
};

#endif // HISTORYTOF_DIALOG_H
