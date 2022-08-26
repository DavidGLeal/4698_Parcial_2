#include "Nodo.h"

Nodo::Nodo(){
	this->valor=0;
	this->padre=NULL;
	this->izquierda=NULL;
	this->derecha=NULL;
}

void Nodo::setValor(int _valor){
	this->valor=_valor;
}

void Nodo::setPadre(Nodo* _padre){
	this->padre=_padre;
}

void Nodo::setIzquierda(Nodo *_izquierda)
{
    izquierda = _izquierda;
}

void Nodo::setDerecha(Nodo *_derecha)
{
    derecha = _derecha;
}

int Nodo::getValor(){
	return valor;
}

Nodo *&Nodo::getPadre()
{
    return padre;
}

Nodo *&Nodo::getIzquierda()
{
    return izquierda;
}

Nodo *&Nodo::getDerecha()
{
    return derecha;
}