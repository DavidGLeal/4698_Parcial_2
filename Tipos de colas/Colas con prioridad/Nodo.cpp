#include "Nodo.h"
//Constructor
Nodo::Nodo(){
	this->valor=0;
	this->siguiente=NULL;
	this->prioridad=0;
}
//Constructor sobrecargado
Nodo::Nodo(int dato,int priori){
	this->valor=dato;
	this->siguiente=NULL;
	this->prioridad=priori;
}
//Setters
void Nodo::setValor(int _dato)
{
    valor = _dato;
}
void Nodo::setPrioridad(int _dato)
{
    prioridad = _dato;
}
void Nodo::setSiguiente(Nodo *_Siguiente)
{
    siguiente = _Siguiente;
}
//Getters
int Nodo::getValor()
{
    return valor;
}
int Nodo::getPrioridad()
{
    return prioridad;
}
Nodo*& Nodo::getSiguiente()
{
    return siguiente;
}