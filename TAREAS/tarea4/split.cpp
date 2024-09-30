#include <iostream>
using namespace std;

void split(int *p, int *q) {
    
    for (int *f = p; f <= q; f++) { 
        
        if (*p % 2 == 1) { 
            for (int *r = q; r > p; r--) { 
                swap(*p, *r); 
            }
        } else {
            p++; 
        }
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    int* p = A; 
    int* q = A + (sizeof(A) / sizeof(A[0])) - 1; 

    cout << "ANTES:  ";
    for (int* ptr = p; ptr <= q; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    split(p, q);

    cout << "DESPUES: ";
    for (int* ptr = A; ptr <= q; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;
}