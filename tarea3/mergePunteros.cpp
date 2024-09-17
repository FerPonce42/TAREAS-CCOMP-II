#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *p, int *q) {
    int *fin = q + 5;  // Fin del arreglo
    int *izquierda = p; // Puntero izquierdo
    int *derecha = q;   // Puntero derecho

    // ORDENAR PARES
    while (p < q - 1) {
        if (*p > *(p + 1)) {
            swap(p, p + 1);
        }
        p++;
    }

    // ORDENAR IMPARES
    while (q < fin - 1) {
        if (*q > *(q + 1)) {
            swap(q, q + 1);
        }
        q++;
    }

    // FUSIONAR LAS MITADES
    while (izquierda < q && derecha < fin) {
        if (*izquierda > *derecha) {
            int temp = *derecha;
            int *mover = derecha;
            while (mover > izquierda) {
                *mover = *(mover - 1);
                mover--;
            }
            *izquierda = temp;
            derecha++;
        }
        izquierda++;
    }
}

int main() {
    int A[] = {2, 6, 8, 12, 20, 1, 3, 7, 11, 15};
    int tamaño = sizeof(A) / sizeof(A[0]);

    merge(A, A + 5);

    cout << "TE LO RUEGO: ";
    int *ptr = A;
    while (ptr < A + tamaño) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    return 0;
}
