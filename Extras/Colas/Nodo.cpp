#include "Nodo.h"

Nodo::Nodo() {
	this->dato =0;
	this->siguiente=NULL;
}

Nodo::Nodo(int _dato){
	this->dato=_dato;
	this->siguiente=NULL; 
} 

int Nodo::getDato(){
	return this->dato;
}

Nodo* Nodo::getSiguiente(){
	return this->siguiente;
}

void Nodo::setDato(int _dato){
	this->dato=_dato;
} 

void Nodo::setSiguiente(Nodo *_siguiente){
	this->siguiente=_siguiente;
} 

