#include "regisitersetdialog.h"
#include "ui_regisitersetdialog.h"

RegisiterSetDialog::RegisiterSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisiterSetDialog)
{
    ui->setupUi(this);

//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(150);
    ui->tableWidget->setColumnCount(2);
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(240,240,240)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(240,240,240)}");

    for(int i=0; i<150 ; i++)
    {
        ui->tableWidget->setItem(i,0,&addressItem[i]);
        ui->tableWidget->setItem(i,1,&valueItem[i]);

        addressItem[i].setTextAlignment(Qt::AlignCenter);
        valueItem[i].setTextAlignment(Qt::AlignCenter);
    }
}



RegisiterSetDialog::~RegisiterSetDialog()
{
    delete ui;
}

//清除控件内容
void RegisiterSetDialog::clearItem()
{
    for(int i=0; i<150 ; i++)
    {
        addressItem[i].setText("");
        valueItem[i].setText("");
    }
}


//加载本地
void RegisiterSetDialog::on_loadLocal_pushButton_clicked()
{
    clearItem();   //首先清空内容


    QString file_path;
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("请选择配置文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList mimeTypeFilters;
    mimeTypeFilters <<QStringLiteral("寄存器配置文件(*.para)|*.para") ;
    fileDialog->setNameFilters(mimeTypeFilters);
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }else
    {
        return;
    }
    file_path = fileNames[0];
    qDebug()<<" file_path = "<<fileNames[0]<<endl;

    QString checkStr = file_path.right(4);
    if("para" != checkStr)
    {
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("请选择正确的配置文件！"));
        return ;
    }

    QFile file(file_path);
    QString line[150];

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd())
        {
            line[i] = in.readLine();
            addressItem[i].setText(line[i].mid(0,2));
            valueItem[i].setText(line[i].mid(3,2));
            qDebug()<<"line["<<i<<"] = "<<line[i];
            i++;
        }
        file.close();
    }
}



//保存本地   具体格式为 ：XX XX   16进制数据
void RegisiterSetDialog::on_saveLocal_pushButton_clicked()
{
    QString filePath;

    QFileDialog *fileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
    fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
    fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
    fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
    fileDialog->setGeometry(10,30,300,200);//设置文件对话框的显示位置
    fileDialog->setDirectory(".");//设置文件对话框打开时初始打开的位置
    QStringList mimeTypeFilters;
    mimeTypeFilters <<QStringLiteral("芯片配置文件(*.para)|*.para") ;
    fileDialog->setNameFilters(mimeTypeFilters);


    if(fileDialog->exec() == QDialog::Accepted)
    {
        filePath = fileDialog->selectedFiles()[0];//得到用户选择的文件名
        qDebug()<<" filePath = "<<filePath<<endl;
    }else
    {
        return ;
    }

    //获取当前控件上的内容,组装成 字符串
    int index = 0;
    QString textString;
    QString addrStr,valStr;
    while(1)
    {
        addrStr = addressItem[index].text().toUpper();
        valStr = valueItem[index].text().toUpper();
        if(addrStr.isEmpty() || valStr.isEmpty())
        {
            break;
        }
        textString.append(addrStr).append(" ").append(valStr).append("\n");
        index++;
    }


    QFile file(filePath);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out<<textString.toLocal8Bit()<<endl;

    QString str = QStringLiteral("文件保存成功，路径：") + filePath;
    QMessageBox::information(NULL,QStringLiteral("提示"),str);
}

//发送 寄存器配置   5A 01 LL LL  01  DD...DD XX
void RegisiterSetDialog::on_send_pushButton_clicked()
{
    //获取当前控件上的内容,组装成 字符串
    int index = 0;
    QStringList textString;
    QString addrStr,valStr;
    while(1)
    {
        addrStr = addressItem[index].text().toUpper();
        valStr = valueItem[index].text().toUpper();
        if(addrStr.isEmpty() || valStr.isEmpty())
        {
            break;
        }
//        textString.append(addrStr).append(valStr);
        textString.append(addrStr);
        textString.append(valStr);
        index++;
    }

    //命令组帧   5A 01 NN DD...DD XX
    QString cmdStr = "5A 01 ";
    int dataLen = textString.length();
    QString lenStrTmp = QString("%1").arg(dataLen + 1 ,4,16,QLatin1Char('0'));  //长度2个字节
    QString lenStr  = lenStrTmp.mid(2,2) + lenStrTmp.mid(0,2);             //转换成小端
    cmdStr.append(lenStr);
    cmdStr.append("01");                //寄存器地址
    foreach (QString str, textString) {
        cmdStr.append(str);
    }
    emit sendSerialSignal(cmdStr);
}

//读取 设备寄存器配置  5A 00 02 00 01 00
void RegisiterSetDialog::on_read_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A 00 02 00 01 00 ";
    emit sendSerialSignal(cmdStr);
}




//!
//! \brief AckCmdRegister_signal
//!寄存器返回命令的相关信号   参数1：“81”：写寄存器应答  参数2 暂无
//!                              “80”：读寄存器应答  参数2 寄存器的数据区
void RegisiterSetDialog::AckCmdRegister_slot(QString returnCmdStr,QString cmdAck)
{
    if("81" == returnCmdStr)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("写入寄存器成功！"));
        return;
    }else if("80" == returnCmdStr)
    {
        clearItem();                            //首先清空控件上已有的内容
        int index = 0;
        for(int i=0; i<cmdAck.length();i+=4)    //4个为一组 前两个字符为地址 后两个地址为值
        {
            addressItem[index].setText(cmdAck.mid(i,2));
            valueItem[index].setText(cmdAck.mid(i+2,2));
            index++;
        }
    }
}




//窗口关闭
void RegisiterSetDialog::closeEvent(QCloseEvent *event)
{
        clearItem();   //首先清空内容
}


void RegisiterSetDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

