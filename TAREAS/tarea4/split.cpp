#include <iostream>
using namespace std;

void split(int*& p, int* q) {
    int* r = p; 
    while (p <= q) { 
        if (*p % 2 == 0) {
            
            p++; 
            r++; 
        } 
        
        if (*p % 2 != 0) { 
            
            swap(r, q); 
            while (r > p) { 
                swap(*p, *r); 
                r--; 
            }
            
            continue; 
        }
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    int* p = A;
    int* q = A + (sizeof(A) / sizeof(A[0])) - 1;

    split(p, q);

}