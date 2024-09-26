#include <iostream>
using namespace std;

int main(){
    //  f  c
    //A[3][2]
    //  *  *
    int **A;
    A= new int*[3];

    for(int i=0 ; i<3 ; i++){
        A[i]=new int[2];
    }
    //primero las columnas
    for (int i=0 ; i<3 ; i++){
        delete[]A[i]; //liberara a los hijos
    }

    delete[]A;//liberamos al padre
}