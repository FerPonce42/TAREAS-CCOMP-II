#include <iostream>
using namespace std;

template <class T>
class LE {
public:
    struct nodo {
        T data;
        nodo* next;
        nodo(T val) : data(val), next(nullptr) {}
    };
    
    nodo* head = nullptr;  // Cabeza de la lista

    bool find(T VALOR, nodo*& pos) {
        pos = head;
        while (pos != nullptr && pos->data != VALOR) {
            pos = pos->next;
        }
        return pos != nullptr; // Retorna verdadero si se encontró el nodo
    }

    void DEL(T VALOR);
    
    ~LE(); // Declaración del destructor
};

template <class T>
void LE<T>::DEL(T VALOR) {
    nodo* tmp = nullptr;
    nodo* pos = nullptr;

    if (head == nullptr) return; // Si la lista está vacía, no hay nada que eliminar

    if (head->data == VALOR) {  // Caso especial si el nodo a eliminar es el head
        tmp = head;
        head = head->next;
    } else if (find(VALOR, pos)) { // Si se encuentra el valor en algún otro nodo
        tmp = pos->next;
        pos->next = tmp->next;
    }

    delete tmp; // Liberamos la memoria del nodo eliminado
}

// Destructor
template <class T>
LE<T>::~LE() {
    while (head) {
        DEL(head->data); // Eliminamos el nodo head hasta que no queden nodos
    }
}


//HA 3->5


//FUNCTOR objeto que se comporta como funcion o algo asi hablo el winni de Po
struct F{
    int a;
    F(int b) : a(b){};//Constructor

    int operator()(int x){ //sobrecarga al operador ( )
        return a+x;
    }
};

class SUMA{
    int a;
    public: 
    int suma(int b) : a(b){};
    int operator()(int x){
        return x+a;
    }
};

class MULTI{
        int a;
    public: 
    int multi(int b) : a(b){};
    int operator()(int x){
        return x+a;
    }
};


int main(){
    F objF(5); //llamo al constructor
    cout<< objF(3); //llamo a la sobrecarga

    //Imprime: 8
}