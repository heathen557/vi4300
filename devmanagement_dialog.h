#ifndef DEVMANAGEMENT_DIALOG_H
#define DEVMANAGEMENT_DIALOG_H

#include <QDialog>
#include"pagewidget.h"
#include<QSqlQuery>
#include<adddev_dialog.h>
#include<QDebug>
#include<QTableWidgetItem>

namespace Ui {
class devManagement_Dialog;
}

class devManagement_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit devManagement_Dialog(QWidget *parent = 0);
    ~devManagement_Dialog();

    PageWidget *devPageWidget;

    QLabel *lable1;

    addDev_Dialog addDevDia;

    QTableWidgetItem snItem[50];
    QTableWidgetItem uuidItem[50];
    QTableWidgetItem updateTime[50];
    QTableWidgetItem noteItem[50];

    void initTable();

    int currentClickIndex;



    void clear_tableWidgetItem();

    int onePageNotesNum;

    QStringList devInfoList;

public slots:
    void showSpecifiedPage(int);

    void initSelect();
signals:
    void setMaxPage_signal(int);


private slots:



    void on_query_toolButton_clicked();

    void on_add_pushButton_clicked();

    void on_returnAll_pushButton_clicked();

    void on_del_pushButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::devManagement_Dialog *ui;
};

#endif // DEVMANAGEMENT_DIALOG_H
