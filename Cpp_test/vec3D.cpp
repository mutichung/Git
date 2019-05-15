#include <iostream>
//#include <cstlib>
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
        void print() const;
        
        vec_ele operator[](int i) const;
};

int main()
{
    vec3D v1(1, 2, 3);
    vec3D v2(v1);
    v2.print();
    cout << "\n" << v2[2] << "\n";
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

vec_ele vec3D::operator[](int i) const{
    //if(i < 0 || i >= 3) exit(1);
    return addr[i];
};

vec3D::~vec3D(){
    delete [] addr;
}

void vec3D::print() const{
    cout << "\n(";
    cout << this -> addr[0];
    for(int i = 2; i <= 3; i++) cout << ", " << this -> addr[i-1];
    cout << ")\n";
};