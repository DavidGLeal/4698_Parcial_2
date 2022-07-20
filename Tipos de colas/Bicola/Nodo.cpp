#include "Nodo.h"
Nodo::Nodo(){
	this->valor=0;
	this->siguiente=NULL;
}
void Nodo::setValor(int _dato)
{
    valor = _dato;
}
void Nodo::setSiguiente(Nodo *_Siguiente)
{
    siguiente = _Siguiente;
}

int Nodo::getValor()
{
    return valor;
}
Nodo*& Nodo::getSiguiente()
{
    return siguiente;
}