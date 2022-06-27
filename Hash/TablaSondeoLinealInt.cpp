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
	/*for(int i = 0; i < NCASILLAS; i++){
        NodoCircularEntero *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;*/
}

int TablaSondeoLinealInt::hash2(int pos)
{
		int i=1;
	
	//while(tabla[pos]!=NULL){
		pos=(pos+i)%NCASILLAS;
		//i++;
	//}
	return pos;
}