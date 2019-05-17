#include <iostream>
#include <cmath>
using namespace std;
#define GET_VARIABLE_NAME(Variable) (#Variable)

class Array2D{
    private:
        double** a;
        unsigned int r, c;
    public:
        Array2D(unsigned int r, unsigned int c);
        ~Array2D();
        
        double operator()(unsigned int r, unsigned int c);
        //double& operator()(unsigned int r, unsigned int c);
        Array2D operator+(const Array2D& A) const;

        void print() const;
};

int main(){
    Array2D A(3, 2);
    A.print();

    return 0;
};

Array2D::Array2D(unsigned int r, unsigned int c){
    this->r = r;
    this->c = c;
    a = new double*[r];
    for(int i = 0; i < r; i++)
        a[i] = new double[c];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            a[i][j] = 0;
    }
};

Array2D::~Array2D(){
    for(int i = 0; i < r; i++)
        delete [] a[i];
    delete [] a;
}
/*
double Array2D::operator(unsigned int r, unsigned int c){
    return a[r][c];
};

Array2D Array2D::operator+(const Array2D& A) const{
    //if()
    Array2D temp(this->r, this->c);
    for(int i = 0; i < this->r; i++){
        for(int j = 0; j < this->c; j++)
            temp[i][j] = this->a[i][j] + A[i][j];
    }
    return temp;
};
*/
void Array2D::print() const{
    //string name = GET_VARIABLE_NAME();
    //cout << "\n" << name << " =\n";
    for(int i = 0; i < this->r; i++){
        cout <<"\n ";
        for(int j = 0; j < this->c; j++){
            cout << "  "<< this->a[i][j];
        }
    }
    cout << "\n\n";
}