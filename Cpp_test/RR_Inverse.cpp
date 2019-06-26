#include <iostream>
//#include <Eigen/Dense>
//#include <math.h>
#include "DHTable.h"
using namespace std;

int main(){
    
    double l1 = 10, l2 = 8;
    double t1 = 0, t2 = 0;
    double px, py;

    DHTable temp(3);
    temp.set_a(2) = l1;
    temp.set_a(3) = l2;
    temp.set_theta(3) = M_PI_2;
    temp.print_table();
    cout << endl << temp.TfMat(0, 3) << "\n\n";
};
