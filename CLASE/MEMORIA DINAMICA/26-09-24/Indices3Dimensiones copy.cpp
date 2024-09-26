#include <iostream>
using namespace std;

int main(){
    //  f  c
    //A[3][2][4]
    //  *  *  *
    int ***A= new int**[3];
//rellenamos
    for(int i=0 ; i<3 ; i++){
        A[i]= new int*[2];
        for(int j=0 ; j<2 ; j++){
            A[i][j]= new int[4];
        }
    }  
//liberamos
    for (int i=0 ; i<3 ; i++){
        for(int j=0; j<2 ; j++){
            delete[]A[i][j];
        }
        delete[]A[i];
    }
    delete[]A;
}