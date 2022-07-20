/*UFA-ESPE
* Deber 5
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 25/05/2022
* Fecha de modificación 30/05/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#include "Nodo.h"


Nodo::Nodo(int val, Nodo* sig = NULL) {
	this->valor = val;
	this->siguiente = sig;
}
Nodo::~Nodo(){
    delete siguiente;   
}
int Nodo::getValor()
{
    return valor;
}

Nodo* Nodo::getSiguiente()
{
    return siguiente;
}

void Nodo::setValor(int val)
{
    valor = val;
}

void Nodo:: setSiguiente(Nodo* sig)
{
    this->siguiente=sig;
}