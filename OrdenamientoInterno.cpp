#pragma once 
#include "OrdenamientoInterno.h"
#include "vector.h"
#include "vector.cpp"

Vector <int> v;

void OrdenamientoInterno::ordenarIntercambio(Vector<int> &arreglo){
    for (int i{}; i < arreglo.size(); i++) {
        for (int j = 0; j < arreglo.size() - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) {
                int aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }
}

void OrdenamientoInterno::ordenarBurbuja(){ 
    int aux;
    int i, j;
    for (i = 0 ; i < v.size() ; i++) {
        for (j = 0 ; j < v.size() - 1 ; j++) {
            if (*(v.get(j)) > *(v.get(j + 1))) {
                aux = *(v.get(j));
                *(v.get(j)) = *(v.get(j + 1));
                *(v.get(j + 1)) = aux;
            }
        }
    }
}

void OrdenamientoInterno::ordenarQuicksort(){
	
}

void OrdenamientoInterno::ordenarShellSort(){
	
}

void OrdenamientoInterno::ordenarDistribucion(){
	
}

void OrdenamientoInterno::ordenarRadix(){
	
}
