#pragma once
#include "TablaHashDobleText.h"

TablaHashDobleText::TablaHashDobleText() : TablaHashCerrada(){
}

TablaHashDobleText::~TablaHashDobleText(){
}

TablaHashDobleText::hash2(int pos)
{
	int p = hash(tabla[pos]->getCadena());/*[](string cad){
    	int suma = 0;
    	for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
	    }
	    return suma % NCASILLAS;
	}(cad);*/
    int indice;// = p;
    /*int t = [](string cad, int p){
    	int suma = 0;
	    int indice = 0;
	    suma = p;
	    indice = 7 -( suma % 7);
	    return indice;
	}(tabla[pos]->getCadena(),p);*/
    //while(tabla[indice] != NULL){
        indice = pos + (7 -(p % 7));
        if(indice>NCASILLAS){
        	indice = indice%NCASILLAS;
		}
		
		return indice;
    }
    	//cout<<indice<<endl;
    