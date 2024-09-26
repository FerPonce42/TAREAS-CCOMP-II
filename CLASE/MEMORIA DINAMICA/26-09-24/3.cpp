#include <iostream>
using namespace std;

int main(){

    int *p= new int[10];

    cout<< &p <<endl; // 0x3cc17ff7e8
    cout<< p <<endl; // 0x248a6b915f0
    cout<< *p <<endl; // -1497818784
    //Cómo hacemos para llenar el array de valores?
    for(int *q = p ; q < p+10 ; q++){
        *q = 0;
    }
    delete []p;
}