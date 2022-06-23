#pragma once 
#include "OrdenamientoInterno.h"
#include "vector.h"
#include "vector.cpp"

Vector <int> v;

void OrdenamientoInterno::ordenarIntercambio(Vector<int> &arreglo){
    for (int i{}; i < arreglo.size(); i++) {
        for (int j = i; j < arreglo.size(); j++) {
            if (arreglo[i] > arreglo[j]) {
                auto aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
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

void OrdenamientoInterno::ordenarQuicksort(Vector< int > &arreglo, int izq, int der) {

        int pivot = arreglo[(izq + der) / 2]; //pivote 
        int i = izq;
        int j = der;

        while (izq <= der) {

            while (arreglo[izq] < pivot) ++izq;

            while (arreglo[der] > pivot) --der;

            if (izq <= der) {
                std::swap(arreglo[izq], arreglo[der]);
                ++izq;
                --der;
            }
        }

        if (izq < j)
            ordenarQuicksort(arreglo, izq, j);

        if (i < der)
            ordenarQuicksort(arreglo, i, der);
}


void OrdenamientoInterno::ordenarShellSort(){
	
}

void OrdenamientoInterno::ordenarDistribucion(){
	
}

void OrdenamientoInterno::ordenarRadix(){
	
}
