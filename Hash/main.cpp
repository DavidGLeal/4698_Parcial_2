#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include "TablaHash.h"
#include "TablaHash.cpp"

#define NCASILLAS 29

using namespace std;

TablaHashCerrada tabla;
Nodo *nodo ;


int main(){
do{
    cout << "Ingrese una cadena: ";
    char cad[100];
    cin >> cad;
    tabla.insertar(cad);
    cout << "Desea ingresar otra cadena? (s/n): ";
    char resp;
    cin >> resp;
    if(resp == 'n'){
        break;
    }
}while(true);
tabla.imprimir();
}

