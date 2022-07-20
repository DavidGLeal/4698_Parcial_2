#include "Nodo.h"

/**
 * Nodo::Nodo() {
 * 	this->dato =0;
 * 	this->siguiente=NULL;
 * }
 */
Nodo::Nodo() {
	this->dato =0;
	this->siguiente=NULL;
}

/**
 * Nodo::Nodo(int _dato){
 * 	this->dato=_dato;
 * 	this->siguiente=NULL; 
 * }
 * 
 * @param _dato Los datos que se almacenarán en el nodo.
 */
Nodo::Nodo(int _dato){
	this->dato=_dato;
	this->siguiente=NULL; 
} 

/**
 * Devuelve el valor del nodo.
 * 
 * @return El valor de la variable dato.
 */
int Nodo::getDato(){
	return this->dato;
}

/**
 * Devuelve el siguiente nodo.
 * 
 * @return El siguiente nodo.
 */
Nodo* Nodo::getSiguiente(){
	return this->siguiente;
}

/**
 * Establece el valor de la variable dato al valor de la variable _dato.
 * 
 * @param _dato The data that will be stored in the node.
 */
void Nodo::setDato(int _dato){
	this->dato=_dato;
} 

/**
 * 
 * 
 * @param _siguiente El siguiente nodo de la lista.
 */
void Nodo::setSiguiente(Nodo *_siguiente){
	this->siguiente=_siguiente;
} 

/**
 * Esta función imprime los datos del nodo
 */
void Nodo::imprimirNodo() {
	cout<<"\n\t"<<this->dato<<"\n"<<endl;
}
