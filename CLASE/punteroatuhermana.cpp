#include <iostream>
using namespace std;

void Bubble (int *ini, int*fin){
    bool sigue=true;
//Burbuja que ordena ASCENDENTEMENTE
    while((ini<fin) && sigue){
        sigue=false;
        for(int *p=ini; p<fin ; p++){
            if(*p > *(p+1)){ //ACa cambia el < > si quieres que sea ascendente o descendente.
                swap(*p,*(p+1));
                sigue=true;
            }
        }
        fin--;
    }
}

//O si quieres hacerlo más bonito:
/*
    bool ASC(int a, int b){
        return a>b;
    }
    bool DES(int a, int b){
        return a<b;
    }


*/

int main(){

}