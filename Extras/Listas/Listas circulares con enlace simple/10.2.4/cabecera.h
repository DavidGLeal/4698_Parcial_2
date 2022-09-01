#include <iostream>
#include ”cabecera.h”
using namespace::std;
void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevo->dato; 
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "\n Ingrese el dato del nodo a Buscar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato == nodoBuscado){
				cout << "\n El nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato;
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}
