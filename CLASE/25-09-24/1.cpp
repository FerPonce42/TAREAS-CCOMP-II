#include <iostream>
using namespace std;

class Foo {

public:
    int sumar(int a, int b) {
        return a + b;
    }
    
    int multiplicar(int a, int b) {
        return a * b;
    }
    
    static int negar(int a) {
        return -a;
    }
};

int ejecutar1(int a, int b, Foo* obj, int(Foo::*metodo)(int, int)) {
    return (obj->*metodo)(a, b);
}

typedef int(Foo::*MetodoFoo)(int, int);

int ejecutar2(int a, int b, Foo* obj, MetodoFoo metodo) {
    return (obj->*metodo)(a, b);
/*
        ->
    class x{
        public:
        int a;
        int Algo(int b);
    };
        x obj;
        obj.a;
        obj.Algo(2)   = p->Algo(3)

        x *p;
        p=&obj;
        (*p).a;       =    p->a; 
*/
}

typedef auto(*Funcion)(int) -> int;

//typedef sustituye los tipos de datos
/*
EJEM:
typedeff int A[10];
A b;  b<--Array de 10 enteros.
*/

int ejecutar3(int a, Funcion funcion) {
    return funcion(a);
}

int main() {
    Foo foo;
    cout << "Foo::sumar(2,4) = " << ejecutar1(2, 4, &foo, &Foo::sumar) << endl;
    cout << "Foo::multiplicar(3,5) = " << ejecutar2(3, 5, &foo, &Foo::multiplicar) << endl;
    cout << "Foo::negar(6) = " << ejecutar3(6, &Foo::negar) << endl;
    return 0;
}
