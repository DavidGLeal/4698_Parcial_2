#include "Arbol.cpp"
#include <iostream>

Nodo *arbol = NULL;
using namespace std;

int main(int argc, char** argv) {
    Arbol obj;
	obj.insertarNodo(arbol, 56);
    obj.insertarNodo(arbol, 53);
    obj.insertarNodo(arbol, 79);
    obj.insertarNodo(arbol, 60);
    obj.insertarNodo(arbol, 12);
    cout<<"----Recorrido en Preorden---";
    cout<<"\n";
    obj.preOrden(arbol)
    cout<<"\n";
    system("pause");
	return 0;
}