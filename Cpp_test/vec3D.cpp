#include <iostream>
using namespace std;
typedef double vec_ele;

class vec3D{
    private:
        vec_ele* addr;
    public:
        vec3D();
        vec3D(vec_ele v1, vec_ele v2, vec_ele v3);
        ~vec3D();
        vec_ele x();
        vec_ele y();
        vec_ele z();
        void print();
        

};

int main()
{
    vec3D v1(1, 2, 3);
    //v1 = vec3D(4, 5, 6);
    v1.print();
    cout << "\n" << v1.z() << "\n";
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

vec3D::~vec3D(){
    delete [] addr;
}

vec_ele vec3D::x(){
    return addr[0];
}

vec_ele vec3D::y(){
    return addr[1];
}

vec_ele vec3D::z(){
    return addr[2];
}

void vec3D::print(){
    cout << "\n(";
    cout << this -> addr[0];
    for(int i = 2; i <= 3; i++) cout << ", " << this -> addr[i-1];
    cout << ")\n";
};