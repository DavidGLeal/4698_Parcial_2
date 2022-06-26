#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include "TablaHash.h"
#include "TablaHash.cpp"

#define NCASILLAS 29

using namespace std;

TablaHashCerrada tabla;
NodoCircular *aux;

int main(){

string cad,opcion;
do{
    cout << "Ingrese una letra"<< endl;
    cin >> cad;
    tabla.insertar(cad);
    cout << "Desea ingresar otra letra? (s/n)" << endl;
    cin >> opcion;
}while(opcion == "s");
    cout <<"Tabla hash cerrada"<< endl;
    tabla.imprimir();


}