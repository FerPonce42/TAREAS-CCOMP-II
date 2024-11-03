#include <iostream>
using namespace std;

class nodo {
public:
    int valor;
    nodo* next;

    nodo(int v, nodo* n = nullptr) {
        valor = v;
        next = n;
    }
};

void arrayTOLE(int *begin, int *end, nodo*& head) {
    head = nullptr;
    for (int *p = end; p >= begin; p--) {
        head = new nodo(*p, head);
    }
}

void print(nodo *head) {
    cout << "head-> ";
    for (nodo* p = head; p; p = p->next) {
        cout << p->valor << "->";
    }
    cout << "NULL" << endl;
}

void merge(nodo*& A, nodo*& B) {
    if (!A || (B && B->valor < A->valor)) {
        swap(A, B);
    }

    nodo* tempA = A;
    while (tempA && B) {
        while (tempA->next && tempA->next->valor <= B->valor) {
            tempA = tempA->next;
        }
        nodo* tempB = B;
        B = B->next;
        tempB->next = tempA->next;
        tempA->next = tempB;
        tempA = tempA->next;
    }
}

int main() {
    int A_arr[] = {13, 17, 20, 25, 30, 38};
    int B_arr[] = {1, 8, 13, 20, 23, 31, 38, 40, 53};

    nodo* LEA = nullptr;
    nodo* LEB = nullptr;
    arrayTOLE(A_arr, A_arr + 5, LEA);
    arrayTOLE(B_arr, B_arr + 8, LEB);

    cout << "LEA: ";
    print(LEA);
    cout << "LEB: ";
    print(LEB);

    merge(LEA, LEB);

    cout << "REZAR: ";
    print(LEA);

    return 0;
}
