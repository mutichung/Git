#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
//don't do a = a.transpose()
int main(){

    MatrixXd dh(6, 3);
    dh << 0, 0, 0,
          -90, -30, 0,
          0, 340, 0,
          -90, -40, 338,
          90, 0, 0,
          -90, 0, 0;
    
    Vector3d p_dc;
    p_dc << -500, 452, 410;

    return 0;
}