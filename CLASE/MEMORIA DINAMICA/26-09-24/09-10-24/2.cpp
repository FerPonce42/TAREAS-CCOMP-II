#include <iostream>
using namespace std;

void PrintLE(nodo*head){

}

int main(){

    nodo* head=nullptr;

    int A[10]={1,3,7,11,23,3,7,5,9,2};

    ArrayToLe(A, A+9, head);
}

//QUE IMPRIMA: head->1->3->7...->9->2->NULL