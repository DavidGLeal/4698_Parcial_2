
#include "HashStr.cpp"

#include <iostream>
using namespace std;

int main(){

    HashStr nuevo;
    cout<<"Holiss";
    nuevo.mensajito();
    nuevo.insertarElemento("ESPE");
    nuevo.insertarElemento("LOLA");
    nuevo.insertarElemento("HOLI");
    nuevo.insertarElemento("ALOL");
    nuevo.insertarElemento("EPSE");

    cout<<"Imprimido :3\n";
    nuevo.mostrarHash();
    nuevo.buscarElemento("ESPE");
    nuevo.eliminarElemento("EPSE");
    nuevo.mostrarHash();
    cout<<"Imprimido :3\n";
    nuevo.insertarElemento("LAAL");
    nuevo.mostrarHash();

}