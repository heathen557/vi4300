#include "regisitersetdialog.h"
#include "ui_regisitersetdialog.h"

RegisiterSetDialog::RegisiterSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisiterSetDialog)
{
    ui->setupUi(this);

//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setColumnCount(2);
//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(240,240,240)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(240,240,240)}");

    for(int i=0; i<100 ; i++)
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
    for(int i=0; i<100 ; i++)
    {
        addressItem[i].setText("");
        valueItem[i].setText("");
    }
}

//显示控件内容
void RegisiterSetDialog::showItem()
{

}
//选择本地路径
void RegisiterSetDialog::on_toolButton_clicked()
{

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
    QString line[100];

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

//发送 寄存器配置
void RegisiterSetDialog::on_send_pushButton_clicked()
{
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

    //命令组帧
    QString cmdStr = "5A 03 04 00 0A 00 88 13 ";
    emit sendSerialSignal(cmdStr);
}

//读取 设备寄存器配置
void RegisiterSetDialog::on_read_pushButton_clicked()
{
    //命令组帧
    QString cmdStr = "5A 03 04 00 14 00 88 13 ";
    emit sendSerialSignal(cmdStr);
}

//窗口关闭
void RegisiterSetDialog::closeEvent(QCloseEvent *event)
{
        clearItem();   //首先清空内容
}


