#include <iostream>
#include <ctime>
#include "DHTable.h"
using namespace std;

VectorXd IK_ana(Vector3d desired_pos, DHTable dh);
VectorXd IK_num(Vector3d desired_pos, VectorXd cur_theta, DHTable dh);
double rad2deg(double input);
double deg2rad(double input);
VectorXd rad2deg(VectorXd input);

int main(){
    
    double l1 = 10, l2 = 8;
    double t1 = 0, t2 = 0;
    double px = -10, py = 8;
    double start, stop;
    start = clock();
    stop = clock();


    DHTable temp(2);
    temp.set_table() << 0, 0, 0, 0,
                        0, l1, 0, 0,
                        0, l2, 0, 0;
    
    Vector3d destination;
    destination << px, py, 0;

    VectorXd sol(2);
    sol = IK_ana(destination, temp);
    cout << endl << rad2deg(sol) << endl;

    temp.set_table().block<2,1>(0,3) = sol;
    cout << endl << temp.TfMat() << endl;
};


VectorXd IK_ana(Vector3d desired_pos, DHTable dh){
    
    double start, stop;
    start = clock();

    VectorXd sol(dh.get_number_of_rows()-1);  //theta1, theta2
    int i;
    double error;
    double x = desired_pos(0);
    double y = desired_pos(1);
    double l1 = dh.a(2);
    double l2 = dh.a(3);

    //solve theta2
    double t2 = acos((pow(x,2) + pow(y,2) - pow(l1,2) - pow(l2,2)) / (2*l1*l2));
    
    //solve theta1
    double a, b, c;
    a = x + l1 + l2*cos(t2);
    b = 2*l2*sin(t2);
    c = x - l1 - l2*cos(t2);
    
    double t1[4];
    t1[0] = 2*atan((-b + sqrt(pow(b,2) - 4*a*c)) / (2*a));
    t1[1] = 2*atan((-b - sqrt(pow(b,2) - 4*a*c)) / (2*a));

    a = y + l2*sin(t2);
    b = -2*(l1 + l2*cos(t2));
    c = y-l2*sin(t2);
    t1[2] = 2*atan((-b + sqrt(pow(b,2) - 4*a*c)) / (2*a));
    t1[3] = 2*atan((-b - sqrt(pow(b,2) - 4*a*c)) / (2*a));


    DHTable test(dh.get_number_of_rows());
    test = dh;
    for(i = 0; i <= 3; i++){
        sol << t1[i], t2;
        test.set_table().block<2,1>(0,3) = sol;
        //cout << test.get_translational() << endl;
        error = pow(x - test.get_translational()(0),2) + pow(y-test.get_translational()(1),2);
        cout << x << endl << test.get_translational()(0) << endl << y << endl << test.get_translational()(1) << endl;
        if( error < 0.0001 )    break;
    }
    //TODO: raise error if( error > 0.0001) 
    stop = clock();
    cout << "\nTime = " << double(stop - start) / CLOCKS_PER_SEC << " sec"<<endl;
    return sol;
}

double deg2rad(double input){ return input / 180 * M_PI; }
double rad2deg(double input){ return input / M_PI * 180; }
VectorXd rad2deg(VectorXd input){
    VectorXd temp(input.size());
    for(int i = 0; i < input.size(); i++)   temp(i) = input(i) / M_PI * 180;
    return temp;    
}

VectorXd IK_num(Vector3d desired_pos, VectorXd cur_theta, DHTable dh){
    VectorXd sol = cur_theta;
    bool done = false;
    while (!done) {
        //execute gradient descent
    }

    return sol;
}

double CostFunc(Vector3d desired_pos, Vector3d cur_pos, DHTable dh){
    return 0;
}

Vector3d grad(Vector3d desired_pos, VectorXd cur_theta, DHTable dh){
    dh.set_table().block<2,1>(0,3) = cur_theta;
    return desired_pos;
}