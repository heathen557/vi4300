#include "calhistogram_obj.h"

calHistogram_obj::calHistogram_obj(QObject *parent) : QObject(parent)
{

    qDebug()<<" calHistomgram start ";
}

void calHistogram_obj::calHistogram_slot(vector<double> vec)
{
    vector<double> tmpVec;     //暂存变量用于 统计个数时候用
    tmpVec = vec;

    std::sort(vec.begin(),vec.end());
    auto last = std::unique(vec.begin(),vec.end());
    vec.erase(last,vec.end());

    QVector<double> ticks_x;      //不同值的个数，并且从小到大进行排序存储的
    QVector<QString> labels;     //标签
    QVector<double> DataNum;     //统计直方图各个点的个数，和ticks_X一一对应的

    int xMax;
    for(int i=0; i<vec.size(); i++)
    {
        int cnt = std::count(tmpVec.begin(),tmpVec.end(),vec[i]);
//        qDebug()<<"i="<<i<<"   vec="<<vec[i]<<"  num="<<cnt;
        ticks_x<<i;
        labels<<QString::number(vec[i]);
        DataNum<<cnt;
        xMax = i;
    }
    int yMax = *max_element(DataNum.begin(),DataNum.end());
//    qDebug()<<" yMax = "<<yMax;

    emit toShowHistogram_signal(ticks_x,DataNum,labels,xMax,yMax);

}
