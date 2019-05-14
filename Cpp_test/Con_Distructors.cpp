#include <iostream>
using namespace std;

class vec3D{
    private:
        double* addr;
    public:
        vec3D(){
            addr = new double[3];
            for(int i = 1; i <= 3; i++) addr[i] = 0;
        };
        void print();

};

int main()
{
    vec3D v1;
    v1.print();
    return 0;
}

void vec3D::print(){
    cout << "\n(";
    for(int i = 1; i <= 3; i++){
        cout << " " << addr[i-1] << ",";
    }
    cout << ")\n";
};