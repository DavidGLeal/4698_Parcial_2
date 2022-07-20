/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
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









