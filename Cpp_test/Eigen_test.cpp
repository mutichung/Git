#include <iostream>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;

int main(){
    MatrixXd m(2, 2), n(2, 1);
    m(0, 0) = 2;
    m(1, 0) = 0;
    m(0, 1) = 0;
    m(1, 1) = 2;
    n(0, 0) = 3;
    n(1, 0) = 1;
    n = m*n;
    cout << n << endl;
    return 0;
}