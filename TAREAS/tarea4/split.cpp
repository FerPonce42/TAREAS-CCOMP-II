#include <iostream>
using namespace std;

void split(int* p, int* q) {
    while (p < q) {
        
        if (*p % 2 == 0) {
            p++;
        }
       
        else if (*q % 2 == 1) {
            q--;
        }
       
        else {
            swap(*p, *q);
            p++;
            q--;
        }
    }
}

int main() {
    int A[] = {3,7,2,6,12,35,8,10,99}; // ESTO IMPRIME: 10 8 2 6 12 35 7 3 99
    int* p = A;
    int* q = A + (sizeof(A) / sizeof(A[0])) - 1;

    cout << "ANTES:  ";
    for (int* ptr = p; ptr <= q; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    split(p, q);

    cout << "DESPUES:  ";
    for (int* ptr = A; ptr <= q; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;
}
