#include <iostream>
using namespace std;

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int main() {
    // Arreglo de punteros a funciones
    int (*p[2])(int, int) = {suma, resta};

    // Arreglos A y B
    int A[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int B[10] = {1, 1, 1, 0, 1, 0, 0, 1, 1, 1};
    
    int C = 0; // Inicializa C

    // Bucle para aplicar la operación correspondiente
    for (int i = 0; i < 10; i++) {
        // Llamada a la función que corresponde a B[i] (0: resta, 1: suma)
        C = p[B[i]](C, A[i]);
    }
    
    // Imprime el valor final de C
    cout << C << endl;

    return 0;
}
