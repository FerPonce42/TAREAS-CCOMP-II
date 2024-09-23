/*Comprobar si un numeros es par e impar y señalar la posicon de memoria donde se encuentra guardado el numero con punteros*/
#include <iostream>
using namespace std;

int main(){
    int numero,*direc;
    cout<<"Ingresa el numero: ";cin>>numero;

    direc=&numero;

    if(*direc%2==0){
        cout<<"ES PAR "<<"|| direccion: "<<direc<<endl;
    }else{
        cout<<"ES IMPAR "<<"|| direccion: "<<direc<<endl;
    }

    
}