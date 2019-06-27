#ifndef DHTABLE_H
#define DHTABLE_H

#include <iostream>
#include <Eigen/Dense>
#include <cmath>
using namespace std;
using namespace Eigen;

class DHTable{
    private:
        unsigned int number_of_rows;
        MatrixX4d table;
    public:
        DHTable(unsigned int number_of_nodes);
        ~DHTable();
        MatrixX4d &set_table();
        unsigned int get_number_of_rows();
        double alpha(unsigned int i), a(unsigned int i), d(unsigned int i), theta(unsigned int i);
        VectorXd alpha(), a(), d(), theta();
        double &set_alpha(unsigned int i), &set_a(unsigned int i), &set_d(unsigned int i), &set_theta(unsigned int i);
        Vector3d &set_theta();
        void print_table() const;
        Matrix4d TfMat();
        Matrix4d TfMat(unsigned int cur_frame, unsigned int ref_frame);
};
#endif

DHTable::DHTable(unsigned int number_of_nodes){
    number_of_rows = number_of_nodes+1;
    table = MatrixX4d::Zero(this->number_of_rows, 4);
};

DHTable::~DHTable(){
    //TODO: remove memory allocate
};

MatrixX4d &DHTable::set_table(){ return table; };

unsigned int DHTable::get_number_of_rows(){ return number_of_rows; };

double DHTable::alpha(unsigned int i){  return table(i-1, 0); };
double DHTable::a(unsigned int i){  return table(i-1, 1); };
double DHTable::d(unsigned int i){  return table(i-1, 2); };
double DHTable::theta(unsigned int i){  return table(i-1, 3); };

VectorXd DHTable::alpha(){ return table.col(0); };
VectorXd DHTable::a(){ return table.col(1); };
VectorXd DHTable::d(){ return table.col(2); };
VectorXd DHTable::theta(){ return table.col(3); };

double &DHTable::set_alpha(unsigned int i){ return table(i-1, 0); };
double &DHTable::set_a(unsigned int i){ return table(i-1, 1); };
double &DHTable::set_d(unsigned int i){ return table(i-1, 2); };
double &DHTable::set_theta(unsigned int i){ return table(i-1, 3); };

//Vector3d &DHTable::set_theta(){ return table.block<this->number_of_rows, 1>(0, 3); };


void DHTable::print_table() const{
    cout << "\n===DH Table===\n\n" << table << "\n\n==============\n\n";
};

Matrix4d DHTable::TfMat(){
    Matrix4d temp, out = Matrix4d::Identity(4, 4);
    for(int i = number_of_rows; i > 0; i--){
        temp << cos(theta(i)), -sin(theta(i)), 0, a(i),
                sin(theta(i))*cos(alpha(i)), cos(theta(i))*cos(alpha(i)), -sin(alpha(i)), -d(i)*sin(alpha(i)),
                sin(theta(i))*sin(alpha(i)), cos(theta(i))*sin(alpha(i)), cos(alpha(i)), d(i)*cos(alpha(i)),
                0, 0, 0, 1;
        out = temp*out;
    }
    return out;
}

Matrix4d DHTable::TfMat(unsigned int ref_frame, unsigned int cur_frame){
    Matrix4d temp, out = Matrix4d::Identity(4, 4);
    for(int i = cur_frame; i > ref_frame; i--){
        temp << cos(theta(i)), -sin(theta(i)), 0, a(i),
                sin(theta(i))*cos(alpha(i)), cos(theta(i))*cos(alpha(i)), -sin(alpha(i)), -d(i)*sin(alpha(i)),
                sin(theta(i))*sin(alpha(i)), cos(theta(i))*sin(alpha(i)), cos(alpha(i)), d(i)*cos(alpha(i)),
                0, 0, 0, 1;
        out *= temp;
    }
    return out;
}