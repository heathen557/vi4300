#include "mcuupgradedialog.h"
#include "ui_mcuupgradedialog.h"

McuUpgradeDialog::McuUpgradeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::McuUpgradeDialog)
{
    ui->setupUi(this);
    progressNum = 0;
}

McuUpgradeDialog::~McuUpgradeDialog()
{
    delete ui;
}

void McuUpgradeDialog::closeEvent(QCloseEvent *event)
{
    ui->send_textEdit->clear();
    ui->recv_plainTextEdit->clear();
    ui->filePath_lineEdit->clear();
    ui->progressBar->setValue(0);
    progressNum = 0;
}


//打开hex文件槽函数
void McuUpgradeDialog::on_openFile_pushButton_clicked()
{
    ui->send_textEdit->clear();
    msgList.clear();
    QString file_path;
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(QStringLiteral("请选择hex文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径

    QStringList mimeTypeFilters;
    mimeTypeFilters <<QStringLiteral("MCU配置文件(*.hex)|*.hex") ;
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
    if("hex" != checkStr)
    {
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("请选择hex文件！"));
        return ;
    }
    ui->filePath_lineEdit->setText(file_path);

    QString str;
    uint dataaddr = 0, i = 0;
    unsigned char *data_ptr;
    char data[48];
    upGradeFile = new QFile(file_path);
    if(upGradeFile->open(QFile::ReadOnly))
    {
        while(!upGradeFile->atEnd())
        {
            //读取一行数据，最多24*2个字符
            i = upGradeFile->readLine(data, (MAX_BUFFER_SIZE + 2) *2);
            QByteArray hexLineData(data, i);
            //解析数据
            if(hexObject.analysisHex(hexLineData))
            {
                str.clear();
                sendBuffer.clear();
                data_ptr = hexObject.getOneRecordData();
                //用来标识扩展线性地址的记录
                if(hexObject.getRecordType() == 0x04)
                {
                    dataaddr = (data_ptr[0] * 256 + data_ptr[1]) << 16;         //获取偏移地址
                }//数据
                else if(hexObject.getRecordType() == 0x00)
                {
                    //地址加偏移
                    str.append(QString("<strong>%1</strong> ").arg(dataaddr + hexObject.getLoadOffset(), 0, 16));

                    sendBuffer.append(QString("%1 ").arg(dataaddr + hexObject.getLoadOffset(), 0, 16));


                    for(i = 0; i < hexObject.getRecordLength(); i++)
                    {
                        str.append(QString("%1 ").arg(data_ptr[i], 2, 16, QLatin1Char('0')).toUpper());
                        sendBuffer.append(QString("%1 ").arg(data_ptr[i], 2, 16, QLatin1Char('0')).toUpper());
                        hexUsefulData.append(data_ptr[i]);                     //将数据保持到hexALLData
                    }

                    msgList.append(sendBuffer);   //存储所有的地址数据
//                  ui->send_plainTextEdit->appendPlainText(str);
                    ui->send_textEdit->append(str);
                }
                hexObject.DestoryOneRecord();                                //销毁数据
            }
//            qDebug()<<" sendBuffer = "<<sendBuffer<<endl;
        }
        //开始初始化信息
        initSendMsgSlot();
    }else
    {
        qDebug()<<"open File error! "<<endl;
    }
}


void McuUpgradeDialog::initSendMsgSlot()
{
    int len = msgList.length();
    qDebug()<<"msgList.length() = "<<msgList.length()<<endl;
//    ui->progressBar->setRange(0,len);

    int m = len/8;    //有多少个8组数据；    972/8 = 121   972%8 = 4
    int lest = len%8;
    QString tmpStr;
    QString sendStr;
    QByteArray sendArray;

    int k = 0;

    while(k<m)
    {
        if((k+1==m) && lest ==0)
        {
            //获取数据部分的长度
            int dataLen1 = 7*16 ;
            QString lastStr = msgList[m*8-1];
            lastStr = lastStr.replace(" ","");
            int dataLen2 = (lastStr.length()-7)/2;
            int allLen = dataLen1 + dataLen2 + 4;     //4个地址字节
            qDebug()<<" allLen =  "<<allLen<<endl;

            tmpStr = "5A 07 ";
            tmpStr.append(QString::number(allLen,16)).append(" 00 0");
            tmpStr.append(msgList[8*k]);
            for(int i=1; i<8; i++)
            {
                int tmpSize = msgList[k*8+i].length();
                tmpStr.append(msgList[k*8+i].right(tmpSize - 8));
            }

            //已经完成一个整包数据 数据整理 发送
//            tmpStr = addCheck(tmpStr);   //添加校验位
    //        qDebug()<<" tmpStr = "<<tmpStr;
            sendStr = tmpStr.replace(" ",""); //去除空格
            sendCmdString.append(sendStr);

            k++;
            break;
        }

        tmpStr = "5A 07 84 00 0";
        tmpStr.append(msgList[k*8]);
        for(int i=1; i<8;i++)
        {
            int tmpSize = msgList[k*8+i].length();
            tmpStr.append(msgList[k*8+i].right(tmpSize - 8));
        }
        //已经完成一个整包数据 数据整理 发送
//        tmpStr = addCheck(tmpStr);   //添加校验位
//        qDebug()<<" tmpStr = "<<tmpStr;
        sendStr = tmpStr.replace(" ",""); //去除空格
        sendCmdString.append(sendStr);
        k++;
    }

    qDebug()<<"k = "<<k<<"  m= "<<m<<endl;


    //数据不足一个整包的部分
    if(lest>0)
    {
        //获取数据部分的长度
        int dataLen1 = (lest-1)*16 ;
        QString lastStr = msgList[m*8 + lest-1];
        lastStr = lastStr.replace(" ","");
        int dataLen2 = (lastStr.length()-7)/2;
        int allLen = dataLen1 + dataLen2 + 4;     //4个地址字节
//        int allLen = 80;
        qDebug()<<" allLen =  "<<allLen<<endl;

        tmpStr = "5A 07 ";
        tmpStr.append(QString("%1").arg(allLen, 2, 16, QChar('0'))).append(" 00 0");


        tmpStr.append(msgList[8*m]);
        for(int i=1; i<lest; i++)
        {
            int tmpSize = msgList[k*8+i].length();
            tmpStr.append(msgList[8*m +i].right(tmpSize - 8));
        }

        //已经完成一个整包数据 数据整理 发送
//        tmpStr = addCheck(tmpStr);   //添加校验位
//        qDebug()<<" tmpStr = "<<tmpStr;
        sendStr = tmpStr.replace(" ",""); //去除空格
        sendCmdString.append(sendStr);

//        sendArray = hexstrTobyte(sendStr);
//        serial->write(sendArray);
//        qDebug()<<" sendArray = "<<sendArray<<endl;
    }

    int maxnum = sendCmdString.length();
    ui->progressBar->setRange(0,maxnum);
}



//测试
void McuUpgradeDialog::on_pushButton_clicked()
{
    sendCmdMsg_slot();
}


//开始升级
void McuUpgradeDialog::on_upgrade_pushButton_clicked()
{

    qDebug()<<QStringLiteral("开始升级槽函数");
    QString startCmd = "5A 06 01 00 01 ";
    emit sendSerialSignal(startCmd);
}

void McuUpgradeDialog::sendCmdMsg_slot()
{
    QByteArray sendArray;

    qDebug()<<"sendCmdString'S length = "<<sendCmdString.length()<<endl;

    if(sendCmdString.isEmpty())  //爲空发送升级结束命令
    {
        QString startCmd = "5A 06 01 00 00 ";
        emit sendSerialSignal(startCmd);

        progressNum = 0;

    }else
    {
        progressNum++;
        ui->progressBar->setValue(progressNum);
        qDebug()<<" progressNum = "<<progressNum;

        QString cmdStr = sendCmdString[0];
        sendCmdString.removeAt(0);
         emit sendSerialSignal(cmdStr);
    }
}


//!
//! \brief AckCmdUpgrade_signal
//!//升级相关的信号，参数为两个，1：“86”：开始升级命令应答    参数2： “01” ：开始升级成功
//!                                                            “81” ：开始升级失败
//!                                                            “00” ：结束升级成功
//!                                                            “88” ： 结束升级失败
//!                                                            其他：命令有误
//!                              “87”：升级过程中的命令应答 参数2： 应答的数据
void McuUpgradeDialog::AckCmdUpgrade_signal(QString returnCmdStr,QString cmdAck)
{
    if("86" == returnCmdStr)
    {
        if("01" == cmdAck)
        {
            sendCmdMsg_slot();  //开始发送升级内容
        }else if("81" == cmdAck)
        {
            QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("升级请求失败！"));
            return;
        }else if("00" == cmdAck)
        {
            QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("升级完成！"));
            return;
        }else if("88"  == cmdAck)
        {
            QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("结束升级失败！"));
            return;
        }
    }else if("87" == returnCmdStr)
    {
        ui->recv_plainTextEdit->appendPlainText(cmdAck);
        sendCmdMsg_slot();  //连续发送升级内容
    }
}



 void McuUpgradeDialog::changeEvent(QEvent *e)
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
