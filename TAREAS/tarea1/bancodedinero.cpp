#include <iostream>
#include <cmath>//pal redondeo de centimos
using namespace std;

//Funcion para designar la cantidad de bilelst

void cantidad_soles(double cantidad){
    //banco
    int billetes[5]= {200,100,50,20,10};
    int monedas[3]= {5,2,1};
    double centimos[3]= {0.50, 0.20, 0.10};

    //contadores
    int cantidad_billetes[5]={};
    int cantidad_monedas[3]={};
    int cantidad_centimos[3]={};

/*************************************/
//CALCULAR CANTIDAD NECESARIA DE BILLETES:
    for(int i=0 ; i<5 ; i++){
        cantidad_billetes[i] = cantidad / billetes[i];
        cantidad -= cantidad_billetes[i] * billetes[i];
    }

//CALCULAR CANTIDAD NECESARIA DE MONEDAS:
    for(int i=0 ; i<3 ; i++){
        cantidad_monedas[i] = cantidad / monedas[i];
        cantidad -= cantidad_monedas[i] * monedas[i];
    }

//CALCULAR CANTIDAD NECESARIA DE CENTIMOS:
    for(int i = 0; i < 3; i++) {
        cantidad_centimos[i] = cantidad / centimos[i];
        cantidad -= cantidad_centimos[i] * centimos[i];
        cantidad = round(cantidad * 100.0) / 100.0;  // Redondear para evitar errores de precisión
    }
//Finalmente resultados:

    cout<<"Billetes: "<<endl;
    for(int i=0 ; i<5 ; i++){
        cout<<"S/. "<<billetes[i]<<" = "<<cantidad_billetes[i]<<endl;
    }
    
    cout<<"Monedas: "<<endl;
    for(int i=0 ; i<3 ; i++){
        cout<<"S/. "<<monedas[i]<<" = "<<cantidad_monedas[i]<<endl;
    }

    cout<<"Centimos: "<<endl;
    for(int i=0 ; i<3 ; i++){
        cout<<"S/. "<<centimos[i]<<" = "<<cantidad_centimos[i]<<endl;
    }
}

int main(){

    double cantidad;

    cout<<"Ingresa la cantidad: S/. ";cin>>cantidad;

    if(cantidad<0){
        cout<<"oe, se serio. Eso esta en negativo."<<endl;
        return false;
    }

    cantidad_soles(cantidad);

    return 0;
}