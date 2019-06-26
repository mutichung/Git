#include <iostream>
#include <Eigen/Dense>
#include <math.h>
using namespace std;
using namespace Eigen;

Matrix4d TfMat(MatrixX4d dh_table, int row);
class DHTable{
    private:
        unsigned int number_of_nodes;
        MatrixX4d table;
    public:
        DHTable(unsigned int number_of_nodes);
        ~DHTable();
        double alpha(unsigned int i), a(unsigned int i), d(unsigned int i), theta(unsigned int i);
        VectorXd alpha(), a(), d(), theta();
        void print_table() const;
        Matrix4d TfMat() const;
};
int main(){
    
    double l1 = 10, l2 = 8;
    double t1 = 0, t2 = 0;
    double px, py;

    DHTable temp(3);
    temp.print_table();
    //cout << endl << temp << "\n\n";
};

DHTable::DHTable(unsigned int number_of_nodes){
    this->number_of_nodes = number_of_nodes;
    table = MatrixX4d::Zero(this->number_of_nodes, 4);
};

DHTable::~DHTable(){
    //TODO: remove memory allocate
};

double DHTable::alpha(unsigned int i){  return table(i, 0); };
double DHTable::a(unsigned int i){  return table(i, 1); };
double DHTable::d(unsigned int i){  return table(i, 2); };
double DHTable::theta(unsigned int i){  return table(i, 3); };
VectorXd DHTable::alpha(){   return table.col(0);    };
VectorXd DHTable::a(){   return table.col(1);    };
VectorXd DHTable::d(){   return table.col(2);    };
VectorXd DHTable::theta(){   return table.col(3);    };
void DHTable::print_table() const{
    cout << endl << table << "\n\n";
};
Matrix4d DHTable::TfMat() const{
    Matrix4d temp, out;
    /* 
    for(int i = number_of_nodes-1; i >= 0; i--){
        temp << cos(theta(i)), -sin(theta(i)), 0, a(i),
                sin(theta(i))*cos(alpha(i)), cos(theta(i))*sin(alpha(i)), -sin(alpha(i)), -d(i)*sin(alpha(i)),
                sin(theta(i))*sin(alpha(i)), cos(theta(i))*sin(alpha(i)), cos(alpha(i)), d(i)*cos(alpha(i)),
                0, 0, 0, 1;
    
    }*/
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