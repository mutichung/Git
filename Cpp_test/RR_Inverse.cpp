#include <iostream>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using namespace Eigen;

Matrix4d TfMat(MatrixX4d dh_table, int row);

int main(){
    
    double l1 = 10, l2 = 8;
    double t1 = 0, t2 = 0;
    double px, py;
    MatrixX4d dh = MatrixX4d::Zero(2, 4);
    Matrix4d temp = TfMat(dh, 0);    


    cout << endl << temp << "\n\n";

}

class DHTable{
    private:
        unsigned int number_of_nodes;
        double** table;
    public:
        DHTable(unsigned int number_of_nodes);
        
};

DHTable::DHTable(unsigned int number_of_nodes){
    this->number_of_nodes = number_of_nodes;
    table = new double*[this->number_of_nodes];
    for(int i = 0; i < this->number_of_nodes; i++)  table[i] = new double[4];
    for(int i = 0; i < this->number_of_nodes; i++){
        for(int j = 0; j < 4, j++)  table[i][j] = 0;
    }
};



Matrix4d TfMat(MatrixX4d dh_table, int row){
    Matrix4d temp = Matrix4d::Identity(4, 4);
    temp(0, 0) = cos(dh_table(row, 3));
    temp(0, 1) = -sin(dh_table(row, 3));
    temp(0, 3) = dh_table(row, 1);
    temp(1, 0) = sin(dh_table(row, 3))*cos(dh_table(row, 0));
    temp(1, 1) = cos(dh_table(row, 3))*sin(dh_table(row, 1));
    temp(1, 2) = -sin(0);
    return temp;
}