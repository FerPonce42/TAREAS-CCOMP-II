#include <iostream>
using namespace std;


struct nodo {
    int valor;   
    nodo* next;   

    // Constructor para inicializar el nodo
    nodo(int v, nodo* n = nullptr) {
        valor = v;
        next = n;
    }
};


void ArrayToLe (int *begin, int *end, nodo*&head){ //puntero a nodo por referencia (apunta a una lista enlazada)
    
    for(int *i=begin ; i<end ; i++){
        head = new nodo (*i, head);
    }
}

int main(){

    nodo* head=nullptr;

    int A[10]={1,3,7,11,23,3,7,5,9,2};

    ArrayToLe(A, A+9, head);
}