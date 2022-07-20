/*UFA-ESPE
* Deber 6
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 01/06/2022
* Fecha de modificación 02/06/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#include "Nodo.h"
Nodo::Nodo(){    
}
Nodo::Nodo(int val, Nodo* sig = NULL, Nodo* prev = NULL){
	this->valor = val;
	this->siguiente = sig;
    this->previo = prev;
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
Nodo* Nodo::getPrevio()
{
    return previo;
}
void Nodo::setValor(int val)
{
    valor = val;
}
void Nodo:: setSiguiente(Nodo* sig)
{
    this->siguiente=sig;
}
void Nodo::setPrevio(Nodo* prev)
{
    this->previo= prev;
}