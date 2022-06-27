#pragma once
#include "TablaHashDobleInt.h"

TablaHashDobleInt::TablaHashDobleInt() : TablaCerradaEnteros()
{
	/*tabla = new NodoCircularEntero*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }*/
}

TablaHashDobleInt::~TablaHashDobleInt()
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

int TablaHashDobleInt::hash2(int pos)
{	
	int dob = pos + (7 - tabla[pos]->getValor()%7); 
	if(dob>28)
	{
		dob=NCASILLAS-dob;
	}
	return dob;
}