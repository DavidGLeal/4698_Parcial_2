#include "Arbol.cpp"
#include <iostream>

Nodo *arbol = NULL;
using namespace std;

int main(int argc, char** argv) {
    Arbol obj;
    int num;
	obj.insertarNodo(arbol, 56);
    obj.insertarNodo(arbol, 53);
    obj.insertarNodo(arbol, 79);
    obj.insertarNodo(arbol, 60);
    obj.insertarNodo(arbol, 12);
	obj.insertarNodo(arbol, 55);
	obj.insertarNodo(arbol, 82);
	
    cout<<"----Recorrido en Preorden---";
    cout<<"\n";
    obj.preOrden(arbol);
    cout<<"\n";
    
    cout<<"----Buscar---";
    cout<<"\n";
<<<<<<< HEAD
    cout<<"----Recorrido en Preorden---";
    cout<<"\n";
    obj.postOrden(arbol);
    cout<<"\n";
=======
    cout <<"Ingrese valor a buscar";
    cin>>num;
    
    obj.buscar(arbol,num);
>>>>>>> 43921ee9ed286a3d641a34c157eddc7e5593c36b
    system("pause");
	return 0;
	
}
