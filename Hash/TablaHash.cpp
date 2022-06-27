#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include <cstring>
#include "TablaHash.h"
#define NCASILLAS 29

using namespace std;

TablaHashCerrada::TablaHashCerrada(){
    tabla = new NodoCircular*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}
TablaHashCerrada::~TablaHashCerrada(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircular *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;
}
void TablaHashCerrada::eliminar(string cad){
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    if(aux->getCadena() == cad){
        tabla[pos] = tabla[pos]->getSig();
        delete aux;
    }
    else{
        while(aux->getSig()->getCadena() != cad){
            aux = aux->getSig();
        }
        aux->setSig(aux->getSig()->getSig());
        delete aux->getSig();
    }
}
void TablaHashCerrada::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircular *aux = tabla[i];
        int pos = i;
        aux = tabla[i];
        while(aux != NULL){
            cout << pos<<"<-"<<aux->getCadena() <<" ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}
int TablaHashCerrada::quadraticProbing(int pos){
    int i = 1;
    if (tabla[pos] == NULL){
        return pos;
    }
    else{
        while(tabla[pos] != NULL){
            pos=(pos+(i*i)%NCASILLAS);
            i++;
        }
    return pos;
    }
}
void TablaHashCerrada::insertar(string cad){
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];

    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircular(cad);
    }else{
        pos = quadraticProbing(pos);
        tabla[pos] = new NodoCircular(cad);
    }
}
int TablaHashCerrada::hash(string cad){
    int suma = 0;
    for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
    }
    return suma % NCASILLAS;
}

int TablaHashCerrada::hashDoble(string cad){

    int p = [](string cad){
    	int suma = 0;
    	for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
	    }
	    return suma % NCASILLAS;
	}(cad);
    int indice = p;
    int t = [](string cad, int p){
    	int suma = 0;
	    int indice = 0;
	    suma = p;
	    indice = 7 -( suma % 7);
	    return indice;
	}(cad,p);
    while(tabla[indice] != NULL){
        indice = indice + t;
        if(indice>NCASILLAS){
        	indice = indice%NCASILLAS;
		}
    }
    	//cout<<indice<<endl;
    return indice;
}
void TablaHashCerrada::insertarDoble(string cad){
    int pos = hashDoble(cad);
    NodoCircular *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircular(cad);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircular(cad));
    }
}
