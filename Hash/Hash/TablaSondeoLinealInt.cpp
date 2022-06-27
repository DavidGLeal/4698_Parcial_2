#pragma once
#include "TablaSondeoLinealInt.h"


TablaSondeoLinealInt::TablaSondeoLinealInt() : TablaCerradaEnteros()
{
	/*tabla = new NodoCircularEntero*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }*/
}

TablaSondeoLinealInt::~TablaSondeoLinealInt()
{

}

int TablaSondeoLinealInt::hash2(int pos)
{
		int i=1;
		pos=(pos+i)%NCASILLAS;
	return pos;
}