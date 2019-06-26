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
    temp.set_a(1) = l1;
    temp.set_a(2) = l2;
    //temp.print_table();
    cout << endl << temp.TfMat() << "\n\n";
};
