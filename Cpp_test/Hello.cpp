#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int bad = 0;
    for(int i = 0; i <= 100; i++){
        float f = sqrt(i);
        cout << f << " " << f * f << " ";

        if(f * f != i){
            cout << "!!!";
            bad++;
        }
    cout << "\n";
    }
    cout << "bad precision: " << bad << "\n\n";
    return 0;
}