#include <iostream>
using namespace std;

void Split(int *ini, int *fin) {
    int *p = ini;  
    int *r = fin - 1;  

    while (p <= r) {
        if (*p % 2 == 0) {
            // ES PAR avanzo el puntero p
            p++;
        } else {
            // ES IMPAR, intercambio r y reduzco r
            swap(*p, *r);
            r--;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};  
    int size = sizeof(arr) / sizeof(arr[0]);

    Split(arr, arr + size);  

    for (int *ptr = arr; ptr < arr + size; ptr++) {
        cout << *ptr << " ";
    }


    return 0;
}
