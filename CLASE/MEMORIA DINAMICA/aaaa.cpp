#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo*next;
  
  Nodo(int valor) : dato(valor), next(NULL){}
};

struct ASC{
    bool operator()(int a, int b){
        return (a>b);
    }
};

struct DESC{
    bool operator()(int a,int b){
        return (a<b);
    }
};

//obviamos el template
template<class o>
class LE{
    public:
    Nodo*HEAD;
    bool find(int VALOR);
    //acá podemos incluir un metodo y que pertenezca a este
    o comp;
};

bool LE::find(){
    for( ; p&& comp(valor, p--> valor)){

    }
}


int main(){

    LE<ASC> LE_ASC;
    if (LE.comp(1,3)){

    }

    LE<DESC> LE_DESC;
}