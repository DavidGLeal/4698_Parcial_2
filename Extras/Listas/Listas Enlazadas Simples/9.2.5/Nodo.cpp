//Librerias
#include <iostream>
#include <conio.h>
#include "Nodo.h"
using namespace std;

Nodo::Nodo()
{

}

void Nodo::insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevo->dato;
	
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}      

void Nodo::buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Nodo::modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado";
				cout << "\n Ingrese el Nuevo dato para este Nodo: ";
				cin >> actual->dato;
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

// primero = 12    ultimo = 6    actual =  13     anterior = 6    encontrado  = true     nodoBuscado = 98         lis 12 . 45 . 6 . 13                 98

//Lista Simple =                 12 ->  98 ->  6 ->  null        13 -> NULL      

void Nodo::eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado\n\n";
				
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				cout << "\n Nodo ELiminado con exito\n\n";
				
				encontrado = true;
			}
			
			anterior = actual;
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Nodo::desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){
			cout << " " << actual->dato  << endl;
			actual = actual->siguiente;
		}
		
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}


