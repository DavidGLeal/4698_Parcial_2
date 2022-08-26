#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Cola.cpp"


using namespace std;

int main(){

    Cola cola1;
    cola1.push(1);
    cola1.push(2);
    cola1.push(15);
    cola1.push(18);
    cola1.push(2);
    cola1.push(20);

    cola1.mostrarCola();
    cola1.obtenerMayor();

    cola1.pop();
    cola1.mostrarCola();

    return 0;
}