/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 26/06/2022
Fecha de modificacion: 29/06/2022
Grupo 10
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
*/

#include "Nodo.h"

Nodo::Nodo() {
	valor = 0;
	siguiente=NULL;
}

Nodo::Nodo(int _valor){
	this->valor =_valor;
	this->siguiente =NULL;
}

Nodo::~Nodo(){

}

Nodo* Nodo::getSiguiente(){
	return this->siguiente;
}

void Nodo::setSiguiente (Nodo *_siguiente){
	this->siguiente=_siguiente;
}

int Nodo::getValor() {
	return this->valor;
}

void Nodo::setValor(int _valor){
	this->valor=_valor;
} 

void Nodo::imprimirNodo(){
	cout<< valor;
}









