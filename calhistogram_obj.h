#ifndef CALHISTOGRAM_OBJ_H
#define CALHISTOGRAM_OBJ_H

#include <QObject>
#include<QDebug>
#include<vector>
using namespace std;

class calHistogram_obj : public QObject
{
    Q_OBJECT
public:
    explicit calHistogram_obj(QObject *parent = 0);

signals:

    void toShowHistogram_signal(QVector<double>,QVector<double>,QVector<QString>,int ,int );   //x,y,xlabel,xmax,ymax
public slots:

    void calHistogram_slot(vector<double>);
};

#endif // CALHISTOGRAM_OBJ_H
