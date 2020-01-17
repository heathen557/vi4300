#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include<qsqlquery.h>


QSqlQuery sql_query;
void initSQL()
{
    QSqlDatabase db;
    QStringList drivers = QSqlDatabase::drivers();

    if (!QSqlDatabase::contains("test"))
      {
          db = QSqlDatabase::addDatabase("QMYSQL");   //, "localhost@3306"
          db.setHostName("localhost");    //数据库主机名
          db.setDatabaseName("batchproduct_database");    //数据库名
          db.setUserName("root");        //数据库用户名
          db.setPassword("");        //数据库密码
      }

      bool bisOpenn = db.open();          //打开数据库连接
      qDebug()<<"bisOpenn="<<bisOpenn;

      if (!db.open())
      {
//          QMessageBox::information(NULL,"warn","can't link MySQL dataBase");
          return;
      }
      db.exec("SET NAMES 'UTF-8'"); ///设置utf-8编码


      //创建数据表
      QSqlQuery sqlQuery(db);
      sql_query = sqlQuery;   //赋值给全局变量
      QString sqlStr;
      bool buscess;
      // 1 创建用户表
      sqlStr = "create table DEV_TABLE(ID int primary key AUTO_INCREMENT, SN varchar(20), UUID varchar(20),updateTime varchar(50), NOTE varchar(500)) charset=utf8;";
      buscess = sqlQuery.exec(sqlStr);
      if (!buscess)
      {
          qDebug("create DEV_TABLE  error");
      }

}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
     initSQL();
//    QTranslator translator;
//    translator.load("translate/myApp_EN.qm");
//    a.installTranslator(&translator);


    MainWindow w;
    w.show();

    return a.exec();
}
