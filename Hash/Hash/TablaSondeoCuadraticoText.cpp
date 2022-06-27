#include "TablaSondeoCuadraticoText.h"


TablaSondeoCuadraticoText::TablaSondeoCuadraticoText() : TablaHashCerrada()
{
    i=1;
}

TablaSondeoCuadraticoText::~TablaSondeoCuadraticoText()
{
}

int TablaSondeoCuadraticoText::hash2(int pos)
{	
	int suma =0;
    int indice =0;
    suma = hash(tabla[pos]->getCadena());
    indice = (pos + i*i) % NCASILLAS;
    i++;
	return indice;   
}