#include "Nodo.h"
#ifndef NULL
#define NULL 0
#endif

Nodo::Nodo(int _dato, Nodo* _siguiente)
{
	this->dato = _dato;
	this->siguiente = _siguiente;
}
Nodo::Nodo(int _dato)
{
	this->dato = _dato;
	this->siguiente = NULL;
}
Nodo::Nodo()
{
	this->dato = 0;
	this->siguiente = NULL;
}
int Nodo::getDato(void)
{
	return dato;
}
void Nodo::setDato(int newDato)
{
	this->dato = newDato;
}
Nodo* Nodo::getSiguiente(void)
{
	return this->siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente)
{
	this->siguiente = newSiguiente;
}
