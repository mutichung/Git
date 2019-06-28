#include <iostream>
#include "DHTable.h"
using namespace std;

VectorXd IK_ana(Vector3d desired_pos, DHTable dh);
double rad2deg(double input);
double deg2rad(double inpud);
VectorXd rad2deg(VectorXd input);

int main(){
    
    double l1 = 10, l2 = 8;
    double t1 = 0, t2 = 0;
    double px, py;
    double t = 50;

    DHTable temp(2);
    temp.set_table() << 0, 0, 0, deg2rad(102.6803835),
                        0, l1, 0, deg2rad(90),
                        0, l2, 0, 0;
    //cout << endl << temp.TfMat() << endl;
    //temp.print_table();
    Vector3d destination;
    destination << -12, 20, 0;

    //cout << endl << destination << endl;

    VectorXd sol(2);
    sol = IK_ana(destination, temp);
    cout << endl << rad2deg(sol) << endl;

    temp.set_table().block<2,1>(0,3) = sol;
    cout << endl << temp.TfMat() << endl;
};


VectorXd IK_ana(Vector3d desired_pos, DHTable dh){
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
        cout << test.get_translational() << endl;
        error = pow(x - test.get_translational()(0),2) + pow(y-test.get_translational()(1),2);
        //error = 0;
        if( error < 0.0001 )    break;
    }
    //TODO: rase error if( error > 0.0001) 
    return sol;
}

double deg2rad(double input){ return input / 180 * M_PI; }
double rad2deg(double input){
    double temp = input / M_PI * 180;
    return temp;    }
VectorXd rad2deg(VectorXd input){
    VectorXd temp(input.size());
    for(int i = 0; i < input.size(); i++)   temp(i) = input(i) / M_PI * 180;
    return temp;    }