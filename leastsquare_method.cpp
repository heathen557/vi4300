#include "leastsquare_method.h"



MatrixXd x0(3,1);
leastSquare_method::leastSquare_method(QObject *parent) : QObject(parent)
{
    maxK= 200;   // %给出最大迭代次数
    rho = 0.55;
    sigma = 0.1;
    muk = 0.001;
    k = 0;
    epsilon = 1e-5;
    n = 3;

//    a = 1000;
//    b = 0;
//    c = 0;
    x0(0,0) = 10000;
    x0(1,0) = 10;
    x0(2,0) = 2847;

    pointSize = 10;  //点的个数


    vecPeak_10.resize(10);
    vecBias_10.resize(10);
    vecPeak_6.resize(6);
    vecBias_6.resize(6);
}

//!
//! \brief leastSquare_method::propgration
//! \param a
//! \param b
//! \param c
//! \param peak  1x10
//! \param bias  1x10
//!
//!  I = a./(peak+b)+c     1x10
//!  y = I - bias;
//! return  1x10
vector<float> leastSquare_method::propgration(MatrixXd theta,vector<float> peak,vector<float> bias)
{

    float a = theta(0,0);
    float b = theta(1,0);
    float c = theta(2,0);

//    qDebug()<<"propgration = "<<a<<"  "<<b<<"  "<<c;

    vector<float> des;
    des.resize(pointSize);
    for(int i=0; i<pointSize; i++)
    {
        float I = a/(peak[i]+b) + c;
        des[i] = I - bias[i];
    }
    return des;
}

//求导
//!
//! \brief leastSquare_method::back_propgration
//! \param a
//! \param b
//! \param c
//! \param peak  1x10
//!  return 3X(10)
vector<vector<float>> leastSquare_method::back_propgration(MatrixXd theta,vector<float> peak)
{
    float a = theta(0,0);
    float b = theta(1,0);
    float c = theta(2,0);

//    qDebug()<<"back_propgration = "<<a<<"  "<<b<<"  "<<c;

    vector<vector<float>> y;
    vector<float> x1;
    vector<float> x2;
    vector<float> x3;
    x1.resize(pointSize);
    x2.resize(pointSize);
    x3.resize(pointSize);

    for(int i=0; i<pointSize; i++)
    {
        x1[i] = 1/(peak[i] + b);
        x2[i] = -a/pow(peak[i]+b,2);
        x3[i] = 1;
    }
    y.push_back(x1);
    y.push_back(x2);
    y.push_back(x3);
    return y;

}

//最小二乘法
MatrixXd leastSquare_method::lmm()
{

//    qDebug()<<"MatrixXd leastSquare_method::lmm()";
    //初始化 mu
    //1、计算fk
    vector<float> fk;
    fk = propgration(x0,vecPeak_10,vecBias_10);   //1x10
    float muk = norm_cal(fk);


    while(k<maxK)
    {
//        qDebug()<<"k = "<<k;
//        vector<float> fk(pointSize);
        vector<float> fk;
        fk = propgration(x0,vecPeak_10,vecBias_10);   //1x10
        MatrixXd fk_matrix(pointSize,1);   //10x1 的矩阵
        for(int i=0; i<pointSize; i++)
        {
            fk_matrix(i,0) = fk[i];
        }

        //2、计算 jfk
//        vector<vector<float>> jfk(pointSize);
        vector<vector<float>> jfk;
        jfk = back_propgration(x0,vecPeak_10);             //(3) 1x10
        MatrixXd jfk_matrix(pointSize,3);    //10x3
        for(int i=0; i<pointSize; i++)
        {
            jfk_matrix(i,0) = jfk[0][i];
            jfk_matrix(i,1) = jfk[1][i];
            jfk_matrix(i,2) = jfk[2][i];
        }



        //3、得到1x3的矩阵  计算gk
        MatrixXd gk_matrix(3,1);
        gk_matrix = (jfk_matrix.transpose()) * fk_matrix;



        //4、 tempDk_matrix 3x3
        MatrixXd tempDk_matrix(3,3);
        tempDk_matrix = (jfk_matrix.transpose())*jfk_matrix;
        for(int i=0;i<3;i++)
        {
            tempDk_matrix(i,i) += muk * 1;
        }

//        dk_matrix   3x1
        MatrixXd dk_matrix(3,1);
        dk_matrix = -1*(tempDk_matrix.inverse())*gk_matrix;

        //5、 求范数
        vector<float> gk_vector(3);
        for(int i=0;i<3;i++)
        {
            gk_vector[i] = gk_matrix(i,0);
        }
        if(norm_cal(gk_vector)<epsilon)
        {
            qDebug()<<"norm_cal(gk_vector)<epsilon ";
            break;
        }



        int m=0;
        int mk = 0;

        float newf_flag=0;
        float oldf_flag=0;
        float tmpMatrix_num =0;
        while(m<20)
        {
            MatrixXd x0_temp(3,1);
            x0_temp = x0 + pow(rho,m)*dk_matrix;
            vector<float> newf(pointSize);
            newf = propgration(x0_temp,vecPeak_10,vecBias_10);
            vector<float> oldf(pointSize);
            oldf = propgration(x0,vecPeak_10,vecBias_10);

            newf_flag = pow(norm_cal(newf),2)/2;
            oldf_flag = pow(norm_cal(oldf),2)/2;

            MatrixXd tmp_matrix(1,1);
            tmp_matrix = gk_matrix.transpose()*dk_matrix;   //gk'*dk
            tmpMatrix_num = tmp_matrix(0,0);
            if(newf_flag<oldf_flag + sigma *pow(rho,m) * tmpMatrix_num)
            {
                mk = m;
//                qDebug()<<"newf_flag break";
                break;
            }
            m++;
        }

        x0 = x0 + pow(rho,mk) *dk_matrix;
        MatrixXd tmp2_matrix(1,1);
        tmp2_matrix = dk_matrix.transpose() * (jfk_matrix.transpose() * jfk_matrix ) * dk_matrix;
        float tmpMatrix_num2 = tmp2_matrix(0,0);
        float elta = (newf_flag-oldf_flag )/(tmpMatrix_num + 0.5*tmpMatrix_num2);
        if(elta>0.75)
            muk = 0.1*muk;
        else if(elta<=0.25)
            muk = 10*muk;

        k++;

//        cout<<"x0="<<x0;
//        qDebug()<<"k="<<k;

    }

    return x0;

}


//!
//! \brief leastSquare_method::norm_cal
//! \param vec
//! \return
//!计算二范数的槽函数
float leastSquare_method::norm_cal(vector<float> vec)
{
    int len = vec.size();
    float des =0;
    for(int i=0;i<len; i++)
    {
        des += pow(vec[i],2);
    }

    return sqrt(des);
}


//接收处理的槽函数
void leastSquare_method::deal_receLeast_slot(vector<float> tof10_vec,vector<float> peak10_vec,vector<float> tof3_vec,vector<float> peak3_vec)
{

    for(int i=0;i<10; i++)
    {
        qDebug()<<"i1 = "<<tof10_vec[i]<<"   peak ="<<peak10_vec[i];
    }

    qDebug()<<endl;

    for(int i=0; i<6; i++)
    {
         qDebug()<<"i2 = "<<tof3_vec[i]<<"   peak ="<<peak3_vec[i];
    }

//    maxK= 200;   // %给出最大迭代次数
//    rho = 0.55;
//    sigma = 0.1;
//    muk = 0.001;
//    k = 0;
//    epsilon = 1e-5;
//    n = 3;

//    vecBias_10 = tof10_vec;
//    vecPeak_10 = peak10_vec;



//    for(int i=0;i<10; i++)
//    {
//        qDebug()<<"i1="<<i<<"  val="<<tof10_vec[i];

//    }

////    vecPeak_10 = tof10_vec ;
////    vecBias_10 = peak10_vec;

//    x0(0,0) = 10000;
//    x0(1,0) = 10;
//    x0(2,0) = 2872;

//    float min_bias = 100000;
//    for(int i=0; i<6; i++)
//    {
//        if(min_bias > vecBias_10[i])
//        {
//            min_bias = vecBias_10[i];
//        }

//    }
//    x0(2,0) = min_bias;



//    pointSize = 6 ;//这个时候是10个点的最小二乘法矫正       //先进行最小二
//    MatrixXd res1 = lmm();
////    cout<<"least res1 =  "<<res1;
//    float least_a1 = res1(0,0);
//    float least_b1 = res1(1,0);
//    float least_c1 = res1(2,0);

////    qDebug()<<"least_a1 = "<<least_a1;
////    qDebug()<<"least_b1 = "<<least_b1;
////    qDebug()<<"least_c1 = "<<least_c1;





//   /*****************第二段的系数计算*************************************/


//    maxK= 200;   // %给出最大迭代次数
//    rho = 0.55;
//    sigma = 0.1;
//    muk = 0.001;
//    k = 0;
//    epsilon = 1e-5;
//    n = 3;


//    for(int i=0;i<6; i++)
//    {
//        qDebug()<<"i2="<<i<<"  val="<<tof3_vec[i];

//    }



//   //再进行最小二
//    MatrixXd x_matrix(3,2);
//    x_matrix(0,0) = tof3_vec[1];
//    x_matrix(0,1) = 1;
//    x_matrix(1,0) = tof3_vec[3];
//    x_matrix(1,1) = 1;
//    x_matrix(2,0) = tof3_vec[5];
//    x_matrix(2,1) = 1;
//    MatrixXd y_matrix(3,1);
//    y_matrix(0,0) = 1000;
//    y_matrix(1,0) = 3000;
//    y_matrix(2,0) = 8000;

//    MatrixXd tmp1_matrix = x_matrix.transpose()*x_matrix;
//    tmp1_matrix = tmp1_matrix.inverse();
//    MatrixXd res2_matrix = tmp1_matrix*x_matrix.transpose()*y_matrix;
//    float least_a2 = res2_matrix(0,0);
//    float least_b2 = res2_matrix(1,0);
//    float least_c2 = 0;

//    qDebug()<<" least_a2="<<least_a2<<"least_b2= "<<least_b2;


////    vecBias_10.clear();
////    vecPeak_10.clear();
////    vecBias_10 = tof3_vec;
////    vecPeak_10 = peak3_vec;
////    x0(0,0) = 10000;
////    x0(1,0) = 10;
////    x0(2,0) = 2854.249;
////    min_bias = 100000;
////    for(int i=0; i<vecBias_10.size(); i++)
////    {
////        if(min_bias > vecBias_10[i])
////        {
////            min_bias = vecBias_10[i];
////        }

////    }
////    x0(2,0) = min_bias;
////    pointSize = 6 ;     //这个时候是3个点的最小二乘法矫正
////    MatrixXd res2 = lmm();
//////    cout<<"least res2 =  "<<res2;

////    float least_a2 = res2(0,0);
////    float least_b2 = res2(1,0);
////    float least_c2 = res2(2,0);
//////    qDebug()<<"least_a2 = "<<least_a2;
//////    qDebug()<<"least_b2 = "<<least_b2;
//////    qDebug()<<"least_c2 = "<<least_c2;



    // 1   100-300 一共是六个点
    MatrixXd x_matrix1(6,2);
    MatrixXd y_matrix1(6,1);

    for(int i=0;i<6;i++)
    {
        x_matrix1(i,0) = peak10_vec[i];
        x_matrix1(i,1) = 1;
        y_matrix1(i,0) = tof10_vec[i];;
    }
    y_matrix1(0,0) = y_matrix1(0,0) - 100;
    y_matrix1(1,0) = y_matrix1(1,0) - 100;
    y_matrix1(2,0) = y_matrix1(2,0) - 200;
    y_matrix1(3,0) = y_matrix1(3,0) - 200;
    y_matrix1(4,0) = y_matrix1(4,0) - 300;
    y_matrix1(5,0) = y_matrix1(5,0) - 300;



    cout<<" x_matrix1 = "<<x_matrix1;
    cout<<" y_matrix1 = "<<y_matrix1;
    MatrixXd tmp1_matrix = x_matrix1.transpose()*x_matrix1;
    tmp1_matrix = tmp1_matrix.inverse();
    MatrixXd res1_matrix = tmp1_matrix*x_matrix1.transpose()*y_matrix1;
    float least_a1 = res1_matrix(0,0);
    float least_b1 = res1_matrix(1,0);



    // 2、 300 -500
    MatrixXd x_matrix2(6,2);
    MatrixXd y_matrix2(6,1);
    for(int i=0;i<6;i++)
    {
        x_matrix2(i,0) = peak10_vec[i+4];
        x_matrix2(i,1) = 1;
        y_matrix2(i,0) = tof10_vec[i+4];
    }
    y_matrix2(0,0) = y_matrix2(0,0)- 300;
    y_matrix2(1,0) = y_matrix2(1,0)- 300;
    y_matrix2(2,0) = y_matrix2(2,0)- 400;
    y_matrix2(3,0) = y_matrix2(3,0)- 400;
    y_matrix2(4,0) = y_matrix2(4,0)- 500;
    y_matrix2(5,0) = y_matrix2(5,0)- 500;

    cout<<" x_matrix2 = "<<x_matrix2;
    cout<<" y_matrix2 = "<<y_matrix2;
    MatrixXd tmp2_matrix = x_matrix2.transpose()*x_matrix2;
    tmp2_matrix = tmp2_matrix.inverse();
    MatrixXd res2_matrix = tmp2_matrix*x_matrix2.transpose()*y_matrix2;
    float least_a2 = res2_matrix(0,0);
    float least_b2 = res2_matrix(1,0);


    // 3、 500 1000
    MatrixXd x_matrix3(4,2);
    x_matrix3(0,0) = peak10_vec[8];
    x_matrix3(1,0) = peak10_vec[9];
    x_matrix3(2,0) = peak3_vec[0] ;
    x_matrix3(3,0) = peak3_vec[1] ;
    x_matrix3(0,1) = 1;
    x_matrix3(1,1) = 1;
    x_matrix3(2,1) = 1;
    x_matrix3(3,1) = 1;

    MatrixXd y_matrix3(4,1);
    y_matrix3(0,0) = tof10_vec[8]- 500;
    y_matrix3(1,0) = tof10_vec[9]- 500;
    y_matrix3(2,0) = tof3_vec[0] - 1000;
    y_matrix3(3,0) = tof3_vec[1] - 1000;
    cout<<" x_matrix3 = "<<x_matrix3;
    cout<<" y_matrix3 = "<<y_matrix3;
    MatrixXd tmp3_matrix = x_matrix3.transpose()*x_matrix3;
    tmp3_matrix = tmp3_matrix.inverse();
    MatrixXd res3_matrix = tmp3_matrix*x_matrix3.transpose()*y_matrix3;
    float least_a3 = res3_matrix(0,0);
    float least_b3 = res3_matrix(1,0);



    // 3、 1000 -3000 - 8000
    MatrixXd x_matrix4(6,2);
    MatrixXd y_matrix4(6,1);
    for(int i=0;i<6;i++)
    {
        x_matrix4(i,0) = peak3_vec[i];
        x_matrix4(i,1) = 1;
        y_matrix4(i,0) = tof3_vec[i];
    }
    y_matrix4(0,0) = y_matrix4(0,0) - 1000;
    y_matrix4(1,0) = y_matrix4(1,0) - 1000;
    y_matrix4(2,0) = y_matrix4(2,0) - 3000;
    y_matrix4(3,0) = y_matrix4(3,0) - 3000;
    y_matrix4(4,0) = y_matrix4(4,0) - 8000;
    y_matrix4(5,0) = y_matrix4(5,0) - 8000;
    cout<<" x_matrix4 = "<<x_matrix4;
    cout<<" y_matrix4 = "<<y_matrix4;
    MatrixXd tmp4_matrix = x_matrix4.transpose()*x_matrix4;
    tmp4_matrix = tmp4_matrix.inverse();
    MatrixXd res4_matrix = tmp4_matrix*x_matrix4.transpose()*y_matrix4;
    float least_a4 = res4_matrix(0,0);
    float least_b4 = res4_matrix(1,0);




    emit send_leastResult_signal(least_a1,least_b1,least_a2,least_b2,least_a3,least_b3,least_a4,least_b4);
}



//MatrixXd leastSquare_method::lmm_2()
//{

//}











///*******************************************/
////按第一行展开计算|A|
//double leastSquare_method::getA(double arcs[N][N],int n)
//{
//    if(n==1)
//     {
//         return arcs[0][0];
//     }
//     double ans = 0;
//     double temp[N][N]={0.0};
//     int i,j,k;
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<n-1;j++)
//         {
//             for(k=0;k<n-1;k++)
//             {
//                 temp[j][k] = arcs[j+1][(k>=i)?k+1:k];

//             }
//         }
//         double t = getA(temp,n-1);
//         if(i%2==0)
//         {
//             ans += arcs[0][i]*t;
//         }
//         else
//         {
//             ans -=  arcs[0][i]*t;
//         }
//     }
//     return ans;
// }


//bool leastSquare_method::GetMatrixInverse(double src[N][N],int n,double des[N][N])
//{
//    double flag=getA(src,n);
//    double t[N][N];
//    if(flag==0)
//    {
//        qDebug()<<" 110  flag = 0";
//        return false;
//    }
//     else
//     {
//         getAStart(src,n,t);
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 des[i][j]=t[i][j]/flag;
//             }

//         }
//     }
//     return true;

// }


////计算每一行每一列的每个元素所对应的余子式，组成A*
//void leastSquare_method::getAStart(double arcs[N][N],int n,double ans[N][N])
//{
//    if(n==1)
//    {
//        ans[0][0] = 1;
//        return;
//    }
//    int i,j,k,t;
//    double temp[N][N];
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            for(k=0;k<n-1;k++)
//            {
//                for(t=0;t<n-1;t++)
//                {
//                    temp[k][t] = arcs[k>=i?k+1:k][t>=j?t+1:t];
//                }
//            }


//            ans[j][i]  =  getA(temp,n-1);  //此处顺便进行了转置
//            if((i+j)%2 == 1)
//            {
//                ans[j][i] = - ans[j][i];
//            }
//        }
//    }
//}


//bool leastSquare_method::mutiply(double A[10][10],int len,double B[10][10],double des[N][N])
//{

//    // A:   3X10
//    // B:   10X3
//    // dst: 3x3
//    for(int i=0; i<3; i++)
//    {
//        for(int j=0; j<3; j++)
//        {
//            des[i][j] = 0;
//            for(int n=10; n<len;n++)
//            {
//                des[i][j] += A[i][n] * B[n][j];
//            }
//        }

//    }

//    return true;
//}
