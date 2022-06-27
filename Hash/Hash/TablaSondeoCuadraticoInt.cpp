#include "TablaSondeoCuadraticoInt.h"


TablaSondeoCuadraticoInt::TablaSondeoCuadraticoInt() : TablaCerradaEnteros()
{
    i=1;
}

TablaSondeoCuadraticoInt::~TablaSondeoCuadraticoInt()
{

}

int TablaSondeoCuadraticoInt::hash2(int pos)
{
	int suma =0;
    int indice =0;
    suma = hash(tabla[pos]->getValor());
    indice = (pos + i*i) % NCASILLAS;
    i++;
	return indice;
}