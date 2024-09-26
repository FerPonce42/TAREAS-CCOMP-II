#include <iostream>
using namespace std;

int main(){

    int **A;
    A= new int*[3];

    for(int **p=A ; p<A+3 ; p++){
        *p= new int[2];
    }

    for(int **p=A ; p<A+3 ; p++){
        delete [] *p;
    }

    delete[]A;
}