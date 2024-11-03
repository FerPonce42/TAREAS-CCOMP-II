#include <iostream>
using namespace std;

struct nodo{

    int valor;
    nodo* next;
};


int main(){
    nodo* head;

    head= new nodo;

    head->valor = 1;

    head->next = new nodo;

    head->next->valor = 2;

    head->next->next = new nodo;

    head->next->next->valor = 3;

    head->next->next->next = nullptr; // NULL, 0;

    //PARA IMPRIMIR:
    cout<<"HEAD-> ";            //p++
    for(nodo*p = head ; p ; p=p->next){       //Si p apunta algo es Verdadero, si no, falso p

        cout<<p->valor<<" -> ";
        cout<<" NULL "<<endl; //EsO FUE UNA LISTA ENLAZADA
    }

    //aohra para borrar:
    nodo*p= head; int *tmp;
    while(p){
        tmp=p;
        p=p->next;
        delete tmp;
    }
}