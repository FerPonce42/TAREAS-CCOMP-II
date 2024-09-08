#include <iostream>
using namespace std;

// Función merge del profe
void merge(int *pares_ptr, int *impares_ptr, int tamano_total) {
    int tamano_pares = tamano_total / 2;  // Tamaño de la primera mitad (pares)
    int tamano_impares = tamano_total - tamano_pares;  // Tamaño de la segunda mitad (impares)

    int *result = new int[tamano_total];  // Arreglo temporal dinámico
    int *result_ptr = result; // Puntero al inicio del arreglo resultante
    int *final_pares = impares_ptr;  // Fin de la primera mitad (pares)
    int *final_impares = impares_ptr + tamano_impares; // Fin de la segunda mitad (impares)

    // Mezclamos mientras ambos punteros tengan elementos válidos
    while (pares_ptr < final_pares && impares_ptr < final_impares) {
        if (*pares_ptr < *impares_ptr) {
            *result_ptr = *pares_ptr;  // Copiamos el valor menor desde los pares
            pares_ptr++;      // Avanzamos el puntero de pares
        } else {
            *result_ptr = *impares_ptr;  // Copioel valor menor desde los impares
            impares_ptr++;      // Avanzamos el puntero de impares
        }
        result_ptr++;          // Avanzamos en el arreglo resultante
    }

    // Si quedan elementos en la primera mitad (pares)
    while (pares_ptr < final_pares) {
        *result_ptr = *pares_ptr;
        pares_ptr++;
        result_ptr++;
    }

    // Si quedan elementos en la segunda mitad (impares)
    while (impares_ptr < final_impares) {
        *result_ptr = *impares_ptr;
        impares_ptr++;
        result_ptr++;
    }

    // Copiamos el contenido de result de vuelta al arreglo original
    for (int i = 0; i < tamano_total; i++) {
        *(pares_ptr - tamano_pares + i) = result[i];
    }

    delete[] result;  // Liberamos la memoria del arreglo temporal
}

int main() {
    
    int arr[] = {2, 6, 8, 12, 20, 1, 3, 7, 11, 15};
    int tamano = sizeof(arr) / sizeof(arr[0]);

    // Punteros que indican las dos mitades del arreglo
    int *pares_ptr = arr;         // Puntero al inicio del arreglo (pares)
    int *impares_ptr = arr + tamano / 2;  // Puntero al inicio de la segunda mitad (impares)

    // Llamo al merg
    merge(pares_ptr, impares_ptr, tamano);

    cout << "100% FE: ";
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
