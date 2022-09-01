#include "Arbol.cpp"
#include <iostream>

Nodo *arbol = NULL;
using namespace std;

int main(int argc, char** argv) {
    Arbol obj;
    int cont = 0;
	obj.insertarNodo(arbol, 6);
    obj.insertarNodo(arbol, 4);
    obj.insertarNodo(arbol, 8);
    obj.insertarNodo(arbol, 2);
    obj.insertarNodo(arbol, 5);
    obj.insertarNodo(arbol, 7);
    obj.insertarNodo(arbol, 10);
    cout<<"\n";
    obj.mostrar(arbol,cont);
    cout<<"\n\n\n";
    cout<<"PESO: "<<obj.peso(arbol);
    cout<<"\n";
    cout<<"Nodos Hijos: ";obj.nodoHijos(arbol);
    cout<<"\n";
    cout<<"ALTURA: "<<obj.altura(arbol);
    cout<<"\n";
    if (obj.simetrias(arbol)) {
        cout << "Arbol Perfecto";
    }
    else {
        cout << "Arbol Imperfecto";
    }
    
	return 0;
}
