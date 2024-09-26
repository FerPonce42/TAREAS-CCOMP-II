#include <iostream>
using namespace std;

int main(){

    int *p = new int;

    p= new int; //MEMORY LEAK hace falta un delete p;

}