#pragma once
#include "TablaSondeoCuadraticoInt.h"


TablaSondeoCuadraticoInt::TablaSondeoCuadraticoInt() : TablaCerradaEnteros()
{
	/*tabla = new NodoCircularEntero*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }*/
    i=1;
}

TablaSondeoCuadraticoInt::~TablaSondeoCuadraticoInt()
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

int TablaSondeoCuadraticoInt::hash2(int pos)
{
	//while(tabla[pos]!=NULL){
		pos=pos+(i*i%NCASILLAS);
		i++;
	//}
	return pos;
}