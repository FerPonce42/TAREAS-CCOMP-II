#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *inicio, int tamaño) {
    int *ptr1 = inicio;
    int *ptr2;

    while (ptr1 < inicio + tamaño) {
        ptr2 = ptr1 + 1; // se compara con el sigueinte
        while (ptr2 < inicio + tamaño) {
            if (*ptr1 > *ptr2) {
                // Si ptr1 > Intercambio valores
                swap(ptr1, ptr2);
            }
            ptr2++;  // next next
        }
        ptr1++;  // avanza el primero puntero
    }
}

int main() {
    int arr[] = {12, 2, 20, 8, 6, 15, 3, 7, 11, 1};
    int tamaño = sizeof(arr) / sizeof(arr[0]);

    
    merge(arr, tamaño);

 
    cout << "DECIDO CREER ";
    int *ptr = arr;  // Puntero al iniciio

    while (ptr < arr + tamaño) {
        cout << *ptr << " "; 
        ptr++; 
    }
    cout << endl;

    return 0;
}