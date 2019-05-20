#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
//don't do a = a.transpose()

double Deg2Rad(double deg);

int main(){

    MatrixXd dh(6, 3);
    dh << 0, 0, 0,
          -90, -30, 0,
          0, 340, 0,
          -90, -40, 338,
          90, 0, 0,
          -90, 0, 0;
    
    Vector3d p_d2c, p_w2d, p_w20, p_w2c;
    p_d2c << -500, 452, 410;
    p_w2d << 830, 20, 330;
    p_w20 << 0, 0, 373;

    p_w2c = p_d2c + p_w2d;
    //cout << endl << p_w2c << endl;


    Matrix4d t_w20, t_w2c, t_62c, t_02c, t_026;

    t_w20 = Matrix4d::Identity();
    t_w20.block<3, 1>(0, 3) = p_w20;

    t_w2c = Matrix4d::Identity();
    t_w2c.block<3, 1>(0, 3) = p_w2c;
    t_w2c(0, 0) = 0.5; t_w2c(0, 2) = -sin(Deg2Rad(60));
    t_w2c(2, 0) = sin(Deg2Rad(60)); t_w2c(2, 2) = 0.5;
    
    t_62c = Matrix4d::Identity();
    t_62c.topLeftCorner(3, 3) << 0, 0, 1,
                                 0, -1, 0,
                                 1, 0, 0;
    t_62c.block<1, 1>(2, 3) << 206;
    
    t_026 = t_w20.inverse()*t_w2c*t_62c.inverse();

    cout << t_026 << "\n\n";

    return 0;
}

double Deg2Rad(double deg){
    double temp;
    temp = deg/180.*M_PI;
    return temp;
}