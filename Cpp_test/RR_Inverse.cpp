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
    temp.set_table() << 0, 0, 0, 0,
                        0, l1, 0, M_PI_2,
                        0, l2, 0, 0;
    temp.print_table();
    cout << temp.TfMat() << "\n\n";
    cout << temp.a() << "\n";
    

};