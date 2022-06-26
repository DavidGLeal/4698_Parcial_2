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

string cad,opcion;
int num,op;
do{
    cout<<"Ingrese una opcion: "<<endl;
    cout<<"1. Insertar valor entero"<<endl;
    cout<<"2. Insertar valor string"<<endl;
    cin >> op;
    switch (op){
        case 1:
        do{
            cout<<"Ingrese un numero: "<<endl;
            cin >> num;
            tablaInt.insertar(num);
            cout<<"Desea ingresar otro numero? (s/n): "<<endl;
            cin >> opcion;
        }while(opcion == "s");
            cout << "Tabla hash cerrada: " << endl;
            tablaInt.imprimir();
            break;
        case 2:
            do{
                cout << "Ingrese una letra"<< endl;
                cin >> cad;
                tabla.insertar(cad);
                cout << "Desea ingresar otra letra? (s/n)" << endl;
                cin >> opcion;
            }while(opcion == "s");
                cout <<"Tabla hash cerrada"<< endl;
                tabla.imprimir();
            system ("pause");
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
    }
}while (opcion != "2");

return 0;
}