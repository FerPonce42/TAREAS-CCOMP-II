#include <iostream>
using namespace std;

void cocktail(int* p, int* q) {
    bool cambio = true;

    while (p < q && cambio) {
        cambio = false;

        for (int* actual = p; actual < q; ++actual) {
            if (*actual > *(actual + 1)) {
                int temp = *actual;
                *actual = *(actual + 1);
                *(actual + 1) = temp;
                cambio = true;
            }
        }
        --q; 

        if (!cambio) break;

        cambio = false;

        for (int* actual = q; actual > p; --actual) {
            if (*actual < *(actual - 1)) {
                int temp = *actual;
                *actual = *(actual - 1);
                *(actual - 1) = temp;
                cambio = true;
            }
        }
        ++p; 
    }
}

int main() {
    int A[] = {10,9,8,7,6,5,4,3,2,1};
    int* p = A; 
    int* q = A + (sizeof(A) / sizeof(A[0])) - 1; 

    cout << "ANTES:  ";
    for (int* ptr = p; ptr <= q; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    cocktail(p, q);

    cout << "DESPUES: ";
    for (int* ptr = A; ptr <= q; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}
