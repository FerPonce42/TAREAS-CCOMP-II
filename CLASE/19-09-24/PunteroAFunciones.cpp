#include <iostream>
using namespace std;

int suma(int a,int b){
    return a+b;
}

int resta(int a,int b){
    return a-b;
}

int main(){

    //PUNTERO A UNA FUNCION "QUE APUNTA A CUALQUIER FUNCION"
    int(*p)(int,int);//recibe 2 enteros y retorna 1 entero

    //Entonces:
    p=&suma;    //puntero que apunta a la función
    cout<<(*p)(5,3)<<endl; //el valor de p (que es una función) = 8

    p=&resta;
    cout<<(*p)(5,3)<<endl; // 2

    //Nota: (*p)= "Callback"
    //Esta operación no es tan eficiente.


    /*---OTRA FORMA DE HACERLo, MAS MEH---*/
    p=suma;
    cout<<p(5,3)<<endl;
    p=resta;
    cout<<p(5,3);
}