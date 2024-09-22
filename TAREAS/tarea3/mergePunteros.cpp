#include <iostream>
using namespace std;

int main() {
    //int A[] = {1,2,3,4,5,6,7,8,9,10};
    //int A[] = {1,2,3,4,5,6};
    //int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int A[]={32,42,76,234,76,24,754,11,44,27};

    int *p = A;
    int *fin = A + (sizeof(A) / sizeof(A[0])) - 1;  // Puntero al último elemento
    int *q = p + ((fin - p) / 2);

    // Imprimir el valor en la mitad del arreglo
    cout << *p << endl;
    cout << *q << endl;


    return 0;
}