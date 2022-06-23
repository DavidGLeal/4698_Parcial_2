#pragma once 
#include "OrdenamientoInterno.h"
#include "vector.h"
#include "vector.cpp"

Vector <int> v;

void OrdenamientoInterno::ordenarIntercambio(){
    	
}

void OrdenamientoInterno::ordenarBurbuja(){ 
    //GRUPO 2
    v.push_back(1);
    v.push_back(5);
    v.push_back(7);
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);
    v.push_back(3);
    v.push_back(5);

    /*cout << "Vector antes de ordenar: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }*/
    cout << endl;
    int aux;
    int i, j;
    for (i = 0 ; i < v.size() ; i++) {
        for (j = 0 ; j < v.size() - 1 ; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    } 

    /*cout << "Ordenado por burbuja: ";
    for (int i = 0 ; i < v.size() ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;*/  
       
}

void OrdenamientoInterno::ordenarQuicksort(){
	
}

void OrdenamientoInterno::ordenarShellSort(){
	
}

void OrdenamientoInterno::ordenarDistribucion(){
	
}

void OrdenamientoInterno::ordenarRadix(){
	
}
