#ifndef LEASTSQUARE_METHOD_H
#define LEASTSQUARE_METHOD_H
#include<QDebug>
#include <QObject>
#include <iostream>
#include<math.h>

#include<Eigen/Eigen>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;


#define N 3
using namespace std;

class leastSquare_method : public QObject
{
    Q_OBJECT
public:
    explicit leastSquare_method(QObject *parent = 0);

    //前一段校正的变量
    vector<float> vecPeak_10;
    vector<float> vecBias_10;

    vector<float> vecPeak_6;
    vector<float> vecBias_6;


    int maxK;   // %给出最大迭代次数
    float rho ;
    float sigma ;
    float muk;
    float k;
    float epsilon;
    int n;

    int pointSize;

//    float a,b,c;


    int size;
signals:

    void send_leastResult_signal(float,float,float,float,float,float,float,float);


public slots:

    vector<float> propgration(MatrixXd theta,vector<float> peak,vector<float> bias);

    vector<vector<float>> back_propgration(MatrixXd theta, vector<float> peak);

    MatrixXd lmm();

    float norm_cal(vector<float> vec); //计算二范数的槽函数


    void deal_receLeast_slot(vector<float>,vector<float>,vector<float>,vector<float>);  //10\ 10 3 3




//    MatrixXd lmm_2();

    //矩阵相关
//    矩阵乘法

//    bool GetMatrixInverse(double src[N][N],int n,double des[N][N]);
//    double getA(double arcs[N][N],int n);
//    void getAStart(double arcs[N][N],int n,double ans[N][N]);
//    bool mutiply(double A[10][10],int n,double B[10][10],double des[N][N]);    //len =中间的长度


};

#endif // LEASTSQUARE_METHOD_H
