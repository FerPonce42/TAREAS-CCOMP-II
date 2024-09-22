#include <iostream>
using namespace std;

bool ASC(int a, int b){
    return a>b;
}
bool DES(int a, int b){
    return a<b;
}

void Bubble (int *ini, int*fin, bool(*comp)(int,int)){
    bool sigue=true;

    while((ini<fin) && sigue){
        sigue=false;
        for(int *p=ini; p<fin ; p++){
            if(comp(*p,*(p+1))){ //Con los nuevos parametros
                swap(*p,*(p+1));
                sigue=true;
            }
        }
        fin--;
    }
}

int main(){
    int A[10]={6,3,2,5,1,4,37,41,9,7};

    Bubble(A,A+9,ASC);
    cout<<"ASCENDENTE"<<endl;
    for (int* p = A; p < A + 10; ++p) {
        cout << *p << " ";
    }
    cout << endl;

    cout<<"DESCENDENTE"<<endl;
    Bubble(A,A+9,DES);
    for (int* p = A; p < A + 10; ++p) {
        cout << *p << " ";
    }
    cout << endl;
}