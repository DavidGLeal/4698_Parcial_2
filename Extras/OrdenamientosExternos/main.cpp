#include <iostream>
#include "MetodosExternos.cpp"
using namespace std;

int main(){

    MetodoExterno *m = new MetodoExterno("datos.txt");
    //m->ordenarPorNatural();
    m->ordenarPorDirecta();
    m->imprimir("datos.txt");
    cout<<"\n";
    system("pause");
    return 0;
}