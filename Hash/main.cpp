#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include "TablaHash.h"
#include "TablaHash.cpp"
#include "TablaHashInt.h"
#include "TablaHashInt.cpp"
#include "NodoEntero.h"
#include "NodoEntero.cpp"
#define NCASILLAS 29

using namespace std;

TablaHashCerrada tabla;
TablaCerradaEnteros tablaInt;

int main(){
int posicion=12;
string cad,opcion;
do{
cout <<"Sondeo cuadratico"<<endl;
cout <<"Ingrese una cadena: ";
cin >> cad;
tabla.insertar(cad,2);
tabla.imprimir();
cout <<"Desea continuar? (s/n): ";
cin >> opcion;
}while(opcion == "s");
return 0;
}
