#include "NodoCircular.h"
NodoCircular::NodoCircular(int val)
{
	valor = val;
	sig = NULL;
}
NodoCircular::~NodoCircular()
{
	delete sig;
}
 
int NodoCircular::getValor()
{
	return valor;
}
NodoCircular* NodoCircular::getSig()
{
	return sig;
}
void NodoCircular::setSig(NodoCircular *_sig)
{
	this->sig = _sig;
}
