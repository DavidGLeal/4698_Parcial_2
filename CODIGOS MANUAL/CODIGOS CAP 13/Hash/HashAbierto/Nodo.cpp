#include "Nodo.h"
Nodo::Nodo()
{
	this->datos = 0;
	this->siguiente = NULL;
}
Nodo::Nodo(int _dato, Nodo* _siguiente)
{
	this->datos = _dato;
	this->siguiente = _siguiente;
}
void Nodo::setDatos(int dato)
{
	datos = dato;
}
void Nodo::setSiguiente(Nodo* _siguiente)
{
	siguiente = _siguiente;
}
int Nodo::getDatos()
{
	return datos;
}
Nodo* Nodo::getSiguiente()
{
	return siguiente;
}
