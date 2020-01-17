#include "devmanagement_dialog.h"
#include "ui_devmanagement_dialog.h"

extern QSqlQuery sql_query;

devManagement_Dialog::devManagement_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::devManagement_Dialog)
{
    ui->setupUi(this);

    onePageNotesNum = 30;

    currentClickIndex = -1;


    //界面上添加分页控件
    devPageWidget = new PageWidget();
    lable1 = new QLabel();
    lable1->setText(QStringLiteral("总记录数：0"));


    //CP物资管理页
    QLabel *PCTMP1 = new QLabel();
    QLabel *PCTMP2 = new QLabel();
    QLabel *PCTMP3 = new QLabel();
    QLabel *PCTMP4 = new QLabel();

    QHBoxLayout *hLayout = new QHBoxLayout(ui->page_widget);
    hLayout->addWidget(lable1,2);
    hLayout->addWidget(PCTMP1,1);
    hLayout->addWidget(PCTMP2,2);
    hLayout->addWidget(PCTMP3,1);
    hLayout->addWidget(PCTMP4,10);
    hLayout->addWidget(devPageWidget,4);


    connect(this,SIGNAL(setMaxPage_signal(int)),devPageWidget,SLOT(setMaxPage(int)));
    connect(devPageWidget,SIGNAL(currentPageChanged(int)),this,SLOT(showSpecifiedPage(int)));     //插件页数变换的时候，发出信号，然后更新

    connect(&addDevDia,SIGNAL(update_signal()),this,SLOT(initSelect()));

    emit setMaxPage_signal(1);
    initTable();
}


void devManagement_Dialog::initTable()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(onePageNotesNum);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->setColumnWidth(2,150);
//    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
//    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");

    for(int i=0;i<onePageNotesNum;i++)
    {
        ui->tableWidget->setItem(i,0,&snItem[i]);
        ui->tableWidget->setItem(i,1,&uuidItem[i]);
        ui->tableWidget->setItem(i,2,&updateTime[i]);
        ui->tableWidget->setItem(i,3,&noteItem[i]);

        snItem[i].setTextAlignment(Qt::AlignCenter);
        uuidItem[i].setTextAlignment(Qt::AlignCenter);
        updateTime[i].setTextAlignment(Qt::AlignCenter);
        noteItem[i].setTextAlignment(Qt::AlignCenter);
    }
}



void devManagement_Dialog::initSelect()
{
    //查询所有的晶圆批号
    QString sqlStr;
    bool buscess;
    sqlStr = "SELECT DISTINCT SN FROM DEV_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select SN error"<<endl;
        return;
    }
    QStringList SNList;
    SNList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        SNList.append(tmpStr);
    }
    ui->SN_comboBox->clear();
    ui->SN_comboBox->addItems(SNList);


    //查询所有的CPtest_num
    sqlStr = "SELECT DISTINCT UUID FROM DEV_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select UUID error"<<endl;
        return;
    }
    QStringList UUID_List;
    UUID_List.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        UUID_List.append(tmpStr);
    }
    ui->UUID_comboBox->clear();
    ui->UUID_comboBox->addItems(UUID_List);

}






devManagement_Dialog::~devManagement_Dialog()
{
    delete ui;
}


//!
//! \brief devManagement_Dialog::on_query_toolButton_clicked
//!查询的槽函数
void devManagement_Dialog::on_query_toolButton_clicked()
{
    QString SN_num = ui->SN_comboBox->currentText();
    QString UUID_num = ui->UUID_comboBox->currentText();
    QString tmpSql;
    QString sqlStr = "SELECT * FROM DEV_TABLE WHERE 1=1 ";
    if(!SN_num.isEmpty())
    {
        tmpSql = " and SN = '"+SN_num+"'";
        sqlStr.append(tmpSql);
    }
    if(!UUID_num.isEmpty())
    {
        tmpSql = " and UUID = '"+UUID_num+"'";
        sqlStr.append(tmpSql);
    }
    sqlStr.append(";");

    bool buscess = sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"devManagement_Dialog::on_query_toolButton_clicked()"<<sqlStr;
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("查询失败!"));
        return;
    }

    devInfoList.clear();
    while(sql_query.next())
    {
        QString SNStr = sql_query.value(1).toString();
        QString UUIDStr = sql_query.value(2).toString();
        QString updateTimeStr = sql_query.value(3).toString();
        QString noteStr = sql_query.value(4).toString();

        devInfoList.append(SNStr);
        devInfoList.append(UUIDStr);
        devInfoList.append(updateTimeStr);
        devInfoList.append(noteStr);
    }

    int allNotes = devInfoList.length()/4;
    QString str = QStringLiteral("总记录数：") + QString::number(allNotes);    //显示记录数
    lable1->setText(str);

    int maxPage = 1 ;
    emit setMaxPage_signal(maxPage);
    showSpecifiedPage(1);


}

//!
//! \brief devManagement_Dialog::on_add_pushButton_clicked
//!新增设备的槽函数
void devManagement_Dialog::on_add_pushButton_clicked()
{
    addDevDia.setModal(true);
    addDevDia.show();
}

//!
//! \brief devManagement_Dialog::on_returnAll_pushButton_clicked
//!返回总库槽函数
void devManagement_Dialog::on_returnAll_pushButton_clicked()
{
    QString sqlStr = "SELECT * FROM DEV_TABLE; ";

    bool buscess = sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"devManagement_Dialog::on_query_toolButton_clicked()"<<sqlStr;
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("查询失败!"));
        return;
    }

    devInfoList.clear();
    while(sql_query.next())
    {
        QString SNStr = sql_query.value(1).toString();
        QString UUIDStr = sql_query.value(2).toString();
        QString updateTimeStr = sql_query.value(3).toString();
        QString noteStr = sql_query.value(4).toString();

        devInfoList.append(SNStr);
        devInfoList.append(UUIDStr);
        devInfoList.append(updateTimeStr);
        devInfoList.append(noteStr);
    }

    int allNotes = devInfoList.length()/4;
    QString str = QStringLiteral("总记录数：") + QString::number(allNotes);    //显示记录数
    lable1->setText(str);

    int maxPage = 1 ;
    maxPage = allNotes/onePageNotesNum ;
    if(0 != allNotes%onePageNotesNum )
    {
        maxPage = maxPage + 1;
    }


    emit setMaxPage_signal(maxPage);
    showSpecifiedPage(1);
}


void devManagement_Dialog::clear_tableWidgetItem()
{
    for(int i=0; i<onePageNotesNum; i++)
    {
        snItem[i].setText("");
        uuidItem[i].setText("");
        updateTime[i].setText("");
        noteItem[i].setText("");
    }
}


//!
//! \brief devManagement_Dialog::showSpecifiedPage
//!
void devManagement_Dialog::showSpecifiedPage(int pageNum)
{
    devPageWidget->setLineEdit(pageNum);

    //先清空CP_tableWidget上的显示
    clear_tableWidgetItem();

    //第一条的记录序号为  (page-1)*onePageNotesNum;
    //最后一条的记录序号为 page*onePageNotesNum - 1;  要对比和总条数的大小，选最小的那个
    int beginNum = (pageNum-1) * onePageNotesNum;

    int last =  pageNum*onePageNotesNum -1;
    int allNoteNum = devInfoList.length()/4;
    int lastNum = last<allNoteNum ? last+1:allNoteNum;   //选取最小的

    qDebug()<<"beginNum="<<beginNum<<"  lastNum="<<lastNum<<endl;

    int index = 0;
    for(int i=beginNum; i<lastNum; i++)     //i为记录的序号
    {
        snItem[index].setText(devInfoList[i*4+0]);
        uuidItem[index].setText(devInfoList[i*4+1]);
        QString updateTimeStr = devInfoList[i*4+2];
        updateTimeStr = updateTimeStr.replace("T"," ");
        updateTime[index].setText(updateTimeStr);
        noteItem[index].setText(devInfoList[i*4+3]);
        index++;
    }
}

//!
//! \brief devManagement_Dialog::on_tableWidget_clicked
//! \param index
//!单击选中行
void devManagement_Dialog::on_tableWidget_clicked(const QModelIndex &index)
{
    currentClickIndex = index.row();
}

void devManagement_Dialog::on_del_pushButton_clicked()
{
    if(currentClickIndex < 0)
    {
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("请先选中要删除的行!"));
        return;
    }
    QString snNum = snItem[currentClickIndex].text();
    sql_query.prepare("DELETE FROM DEV_TABLE WHERE SN=:SN;");
    sql_query.bindValue(":SN",snNum);
    bool buscess = sql_query.exec();
    if(!buscess)
    {
        QMessageBox::warning(NULL,QStringLiteral("提示"),QStringLiteral("删除失败"));
        return;
    }
    snItem[currentClickIndex].setText("-");
    uuidItem[currentClickIndex].setText("-");
    updateTime[currentClickIndex].setText("-");
    noteItem[currentClickIndex].setText("-");

    initSelect();

}


