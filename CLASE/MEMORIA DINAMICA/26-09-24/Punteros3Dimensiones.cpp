#include <iostream>
using namespace std;

int main() {
    // A[3][2][4]
    int ***A;

    // Reservamos memoria para las primeras 3 dimensiones
    A = new int**[3];  // nivel 1: A es un puntero a punteros a punteros (3 bloques)

    for (int ***p = A; p < A + 3; p++) {  // nivel 2: cada elemento es un puntero a punteros
        *p = new int*[2];  // nivel 2: reservamos memoria para las 2 filas

        for (int **q = *p; q < *p + 2; q++) {  // nivel 3: cada elemento es un puntero a enteros
            *q = new int[4];  // nivel 3: reservamos memoria para las 4 columnas
        }
    }

    // Liberamos la memoria, en el orden inverso al que fue reservada
    for (int ***p = A; p < A + 3; p++) {  // nivel 1: recorremos los 3 bloques
        for (int **q = *p; q < *p + 2; q++) {  // nivel 2: recorremos los 2 punteros a punteros
            delete[] *q;  // nivel 3: liberamos las 4 columnas
        }
        delete[] *p;  // nivel 2: liberamos las 2 filas
    }

    delete[] A;  // nivel 1: liberamos el bloque de 3 punteros

    return 0;
}
