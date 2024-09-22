#include <iostream>
using namespace std;

void merge(int* p, int* q) {
    int* fin = q + (q - p) + (q - (p + (q - p)));

    while ((p < q) && (q < fin)) {
        if (*p < *q) {
            p++;
        } else {
            int* r = q;
            int temp = *q;

            while (r > p) {
                *r = *(r - 1);
                r--;
            }

            *p = temp;
            p++;
            q++;
        }
    }
}

int main() {
    int A[] = {2, 10, 12, 32, 42, 1, 5, 11, 27, 39};
    int* p = A;
    int* q = A + (sizeof(A) / sizeof(A[0])) / 2;  

    for (int* ptr = p; ptr < p + (sizeof(A) / sizeof(A[0])); ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl; 

    merge(p, q);

    for (int* ptr = p; ptr < p + (sizeof(A) / sizeof(A[0])); ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl; 

}

