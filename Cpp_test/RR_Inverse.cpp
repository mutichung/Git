#include <iostream>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using namespace Eigen;

int main(){
    
    double l1 = 10, l2 = 8;
    double t1 = 0, t2 = 0;
    double px, py;
    
    MatrixX4d DH = MatrixX4d::Zero(2, 4);
    
    cout << endl << DH << "\n\n";

}