#include <iostream>
using namespace std;

void cocktail(int* arr, int n) {
    bool hayintercambio = true;
    int* ini = arr;           
    int* fin = arr + n - 1;   

    while (ini < fin && hayintercambio) {
        hayintercambio = false;

        // Movimiento de izquierda a derecha
        for (int* p = ini; p < fin; ++p) {
            if (*p > *(p + 1)) {
                swap(*p, *(p + 1));
                hayintercambio = true;
            }
        }

        // Reduzco el rango del final
        fin--;

        // Si HAY intercambios, el array está ordenado
        if (!hayintercambio) break;

        hayintercambio = false;

        // Movimiento de derecha a izquierda
        for (int* p = fin; p > ini; --p) {
            if (*(p - 1) > *p) {
                swap(*(p - 1), *p);
                hayintercambio = true;
            }
        }

        // Aumentorango del inicio
        ini++;
    }
}

int main() {
    int A[] = {51, 3, 28, 35, 4, 2, 7, 23, 15};  
    int tamaño = sizeof(A) / sizeof(A[0]);          

    cocktail(A, tamaño);

    cout << "Array ordenado: ";
    for (int* p = A; p < A + tamaño; ++p) {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
