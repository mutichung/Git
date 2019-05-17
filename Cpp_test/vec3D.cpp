#include <iostream>
//#include <cstlib>
#include <cmath>
using namespace std;
typedef double vec_ele;

class vec3D{
    private:
        vec_ele* addr;
    public:
        vec3D();
        vec3D(vec_ele v1, vec_ele v2, vec_ele v3);
        vec3D(const vec3D& v);
        ~vec3D();
        
        vec_ele operator[](int i) const;
        vec_ele& operator[](int i);
        void operator()(vec_ele x, vec_ele y, vec_ele z);
        void operator=(const vec3D& v);
        
        void print() const;

        vec3D cross(const vec3D& v) const;
        double dot(const vec3D& v) const;
        
};

int main()
{
    vec3D v1(1, 0, 0);
    vec3D v2(0, 1, 0);
    double ip = v1.dot(v2);
    vec3D v3 = v2.cross(v2);
    v3.print();
    cout << ip << "\n";
    return 0;
}

vec3D::vec3D(){
    addr = new vec_ele[3];
    for(int i = 1; i <= 3; i++) addr[i-1] = 0;
};

vec3D::vec3D(vec_ele v1, vec_ele v2, vec_ele v3){
    addr = new vec_ele[3];
    addr[0] = v1;
    addr[1] = v2;
    addr[2] = v3;
};

vec3D::vec3D(const vec3D& v){
    addr = new vec_ele[3];
    for(int i = 0; i < 3; i++)  addr[i] = v[i];
};

vec3D::~vec3D(){
    delete [] addr;
};

vec_ele vec3D::operator[](int i) const{
    //if(i < 0 || i >= 3) exit(1);
    return addr[i];
};

vec_ele& vec3D::operator[](int i){
    return addr[i];
};

void vec3D::operator=(const vec3D& v){
    for(int i = 0; i <= 2; i++) 
        this->addr[i] = v.addr[i];
};

void vec3D::operator()(vec_ele x, vec_ele y, vec_ele z){
    this->addr[0] = x;
    this->addr[1] = y;
    this->addr[2] = z;
};


void vec3D::print() const{
    cout << "\n(";
    cout << this -> addr[0];
    for(int i = 2; i <= 3; i++) cout << ", " << this -> addr[i-1];
    cout << ")\n";
};

vec3D vec3D::cross(const vec3D& v) const{
    vec3D temp;
    temp[0] = this->addr[1]*v[2] - this->addr[2]*v[1];
    temp[1] = this->addr[2]*v[0] - this->addr[0]*v[2];
    temp[2] = this->addr[0]*v[1] - this->addr[1]*v[0];    
    return temp;
};

double vec3D::dot(const vec3D& v) const{
    double temp = 0;
    for(int i = 0; i <= 2; i++)
        temp += addr[i]*v[i];
    return temp;
}
