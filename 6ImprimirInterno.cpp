#pragma once
#include "6ImprimirInterno.h"


void ImprimirInterno::imprimir(Vector &vector){
    for(int i = 0; i < vector.getElementos(); i++){
        cout << vector[i] << " ";
    }    
}

void ImprimirInterno::imprimirB(Vector &vector){
    	for(int i = vector.getElementos()-10; i < vector.getElementos(); i++){
        cout << vector[i] << " ";
    	}    
	
	
	
}