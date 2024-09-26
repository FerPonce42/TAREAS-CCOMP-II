#include <iostream>
using namespace std;

int main(){

    int *p= new int;
    delete p;//el puntero sigue apuntando aqui, pero ya lo liberaste.

    p=nullptr;
}