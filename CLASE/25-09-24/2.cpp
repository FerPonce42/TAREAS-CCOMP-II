#include <iostream>
using namespace std;

class X {
public:
    static int n; // Variable estática

//public:
    X() {
        n++;  // Incrementa la variable estática
        cout << n << endl;
    }
};

// Inicialización 
int X::n = 0;

int main() {
    X obj1; // 0+1= 1
    X obj2; // 1+1= 2 
    X obj3; // 2+1= 3

    cout<<obj1.n<<endl; //3
    cout<<obj2.n<<endl; //3
    cout<<obj3.n<<endl; //3
    //Cada atributo de la clase, la variable n no puede ser la misma en los objetos ("Tu huella digital es única")
    //Miembros estaticos: Se comparten los mismos atributos en todas las clases.
}
