#include <iostream>
using namespace std;

class vec3D{
    private:
        typedef double vec_ele;
        vec_ele* addr;
    public:
        vec3D();
        vec3D(vec_ele v1, vec_ele v2, vec_ele v3);
        //~vec3D();
        vec_ele x();
        vec_ele y();
        vec_ele z();
        void print();

};

int main()
{
    vec3D v1(1, 2, 3);
    v1.print();
    cout << "\n";
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

void vec3D::print(){
    cout << "\n(";
    cout << addr[0];
    for(int i = 2; i <= 3; i++) cout << ", " << addr[i-1];
    cout << ")\n";
};