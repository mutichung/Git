#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
//don't do a = a.transpose()
int main(){
    Matrix2d m(2, 2);
    Vector2d n(2, 1);
    m << 2, 0,
         0, 2;
    n << 3, 1;
    n = m*n;
    cout << "\nm*n = \n\n" << n.transpose() << endl;
    return 0;
}