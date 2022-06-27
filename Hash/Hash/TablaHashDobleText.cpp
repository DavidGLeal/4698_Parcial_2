#pragma once
#include "TablaHashDobleText.h"

TablaHashDobleText::TablaHashDobleText() : TablaHashCerrada(){
}

TablaHashDobleText::~TablaHashDobleText(){
}

TablaHashDobleText::hash2(int pos)
{
	int p = hash(tabla[pos]->getCadena());
    int indice;
        indice = pos + (7 -(p % 7));
        if(indice>NCASILLAS){
        	indice = indice%NCASILLAS;
		}
		
		return indice;
    }
    