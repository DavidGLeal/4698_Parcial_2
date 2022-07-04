#include "Nodo.h"

void Nodo::setValor(int _dato)
{
    valor = _dato;
}
void Nodo::setIzquierda(Nodo *_izquierda)
{
    izquierda = _izquierda;
}
void Nodo::setDerecha(Nodo *_derecha)
{
    derecha = _derecha;
}
int Nodo::getValor()
{
    return valor;
}
Nodo*& Nodo::getIzquierda()
{
    return izquierda;
}
Nodo*& Nodo::getDerecha()
{
    return derecha;
}