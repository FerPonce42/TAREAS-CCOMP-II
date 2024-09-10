#include <iostream>
using namespace std;

void merge(int *pares_ptr, int *impares_ptr, int tamaño_total) {
    int tamaño_pares = tamaño_total / 2;  
    int tamaño_impares = tamaño_total - tamaño_pares;  
    int *result = new int[tamaño_total]; 
    int *result_ptr = result; 
    int *final_pares = impares_ptr; 
    int *final_impares = impares_ptr + tamaño_impares;  

    // Mezclamos mientras ambos punteros tengan elementos válidos
    while (pares_ptr < final_pares && impares_ptr < final_impares) {
        if (*pares_ptr < *impares_ptr) {
            *result_ptr = *pares_ptr;  // Copiamos el valor menor desde los pares
            pares_ptr++;      // Avanzamos el puntero de pares
        } else {
            *result_ptr = *impares_ptr;  // Copiamos el valor menor desde los impares
            impares_ptr++;      // Avanzamos el puntero de impares
        }
        result_ptr++;  // Avanzamos en el arreglo resultante
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

    // Copiamos el contenido de result de vuelta al arreglo original usando punteros
    pares_ptr -= tamaño_pares;  // Regresamos el puntero pares_ptr al inicio del arreglo original
    result_ptr = result;  // Reiniciamos el puntero result_ptr al inicio del arreglo temporal
    while (tamaño_total--) {
        *pares_ptr = *result_ptr;  // Copiamos el valor de result al arreglo original
        pares_ptr++;
        result_ptr++;
    }

    delete[] result;  // Liberamos la memoria del arreglo temporal
}

int main() {
  
    int arr[] = {2, 6, 8, 12, 20, 1, 3, 7, 11, 15};
    int tamaño = sizeof(arr) / sizeof(arr[0]);


    int *pares_ptr = arr;         // Puntero al inicio del arreglo
    int *impares_ptr = arr + tamaño / 2;  // Puntero al inicio de la segunda mitad


    merge(pares_ptr, impares_ptr, tamaño);

    // Imprimimos 
    cout << "ELIJO CREER = ";
    int *ptr = arr;  // Puntero al inicio del arreglo
    while (ptr < arr + tamaño) {
        cout << *ptr << " ";  // Imprimimos el valor al que apunta ptr
        ptr++;  // Avanzamos al siguiente elemento
    }
    cout << endl;

    return 0;
}
