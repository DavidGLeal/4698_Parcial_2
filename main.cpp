#include "Arbol.cpp"
#include <iostream>

Nodo *arbol = NULL;
using namespace std;

int main(int argc, char** argv) {
    Arbol obj;
    int num;
    int cont = 0;
    obj.insertarNodo(arbol, 56);
    obj.insertarNodo(arbol, 53);
    obj.insertarNodo(arbol, 79);
    obj.insertarNodo(arbol, 60);
    obj.insertarNodo(arbol, 12);
    obj.insertarNodo(arbol, 55);
    obj.insertarNodo(arbol, 82);
	
    cout<<"\n";
    obj.mostrar(arbol,cont);
    cout<<"\n";
    cout<<"PESO: "<<obj.peso(arbol);
    cout<<"\n";
    cout<<"ALTURA: "<<obj.altura(arbol);
    cout<<"\n";
    if (obj.simetrias(arbol)) {
        cout << "Arbol Perfecto";
    }
    else {
        cout << "Arbol Imperfecto";
    }	
    
    cout<<"----Recorrido en Preorden---";
    cout<<"\n";
    obj.preOrden(arbol);
    cout<<"\n";

    cout<<"----Recorrido en Inorden---";
    cout<<"\n";
    obj.inOrden(arbol);
    cout<<"\n";
    

    cout<<"----Recorrido en Postorden---";
    cout<<"\n";
    obj.postOrden(arbol);
    cout<<"\n";

    cout<<"----Buscar---";
    cout<<"\n";
    cout <<"Ingrese valor a buscar";
    cin>>num;
    obj.buscar(arbol,num);
 
    cout<<"----Buscar por Nivel---";
    cout<<"\n";
    cout<<"Ingrese el numero a buscar: ";
    cin>>num;
    obj.buscarporNivel(arbol, num);
    cout<<"\n";
    
    system("pause");
	return 0;
	
}
