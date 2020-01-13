#include "historytof_dialog.h"
#include "ui_historytof_dialog.h"

HistoryTof_Dialog::HistoryTof_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryTof_Dialog)
{
    ui->setupUi(this);

    ui->lineEdit->setReadOnly(true);

    ui->tof_widget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);

    ui->tof_widget->legend->setVisible(true);
    ui->tof_widget->legend->setFont(QFont("Helvetica", 9));
    ui->tof_widget->yAxis->setRange(0,500);
    ui->tof_widget->xAxis->setRange(0,256);
    ui->tof_widget->addGraph();
    ui->tof_widget->graph(0)->setName(QStringLiteral("TOF"));





}

HistoryTof_Dialog::~HistoryTof_Dialog()
{
    delete ui;
}

void HistoryTof_Dialog::on_toolButton_clicked()
{
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
    mimeTypeFilters <<QStringLiteral("数据文件(*.txt)|*.txt") ;
    fileDialog->setNameFilters(mimeTypeFilters);


    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }else
    {
        return;
    }
    ////////////////////////////////////////////////////////////////////////////////////////

    file_path = fileNames[0];
    qDebug()<<" file_path = "<<fileNames[0]<<endl;

    QString checkStr = file_path.right(3);
    if("txt" != checkStr)
    {
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("文件格式不正确！"));
        return ;
    }

    ui->lineEdit->setText(file_path);



    QVector<double> label_x;
    QVector<double> tofValue;
    label_x.clear();
    tofValue.clear();


    //数据加载
    QFile file(file_path);
    QString line;
    int tof = 0;
    int valueMin = 1000, valueMax = 0;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd())
        {
            line = in.readLine();
            label_x.append(i);
            tof = line.left(5).toInt();
            tofValue.append(tof);

            valueMin = valueMin>tof ? tof:valueMin;
            valueMax = valueMax>tof ? valueMax:tof;    //统计tof的最大值，方便显示
            i++;
        }
        file.close();


        ui->tof_widget->xAxis->setRange(0,i);
        ui->tof_widget->yAxis->setRange(valueMin-1,valueMax+1);
        ui->tof_widget->graph(0)->setData(label_x,tofValue);
        ui->tof_widget->replot();

    }

}
