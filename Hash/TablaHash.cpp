#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include <cstring>
#include "TablaHash.h"
#define NCASILLAS 29

using namespace std;

TablaHashCerrada :: TablaHashCerrada(){
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}
TablaHashCerrada :: ~TablaHashCerrada(){
    for(int i = 0; i < NCASILLAS; i++){
        Nodo *aux = tabla[i];
        while(aux != NULL){
            Nodo *aux2 = aux;
            aux = aux->getSig();
            delete aux2;
        }
    }
}
void TablaHashCerrada :: insertar(char *cad){
    int pos = hash(cad);
    Nodo *aux = tabla[pos];
    if(aux == NULL){
        tabla[pos] = new Nodo(cad);
    }
    else{
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new Nodo(cad));
    }
}
void TablaHashCerrada :: eliminar(char *cad){
    int pos = hash(cad);
    Nodo *aux = tabla[pos];
    if(aux != NULL){
        if(strcmp(aux->getCadena(), cad) == 0){
            tabla[pos] = aux->getSig();
            delete aux;
        }
        else{
            while(aux->getSig() != NULL){
                if(strcmp(aux->getSig()->getCadena(), cad) == 0){
                    Nodo *aux2 = aux->getSig();
                    aux->setSig(aux->getSig()->getSig());
                    delete aux2;
                    break;
                }
                aux = aux->getSig();
            }
        }
    }
}
void TablaHashCerrada :: imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        Nodo *aux = tabla[i];
        while(aux != NULL){
            cout << aux->getCadena() << " ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}
int TablaHashCerrada :: hash(char *cad){
    int suma = 0;
    for(int i = 0; i < strlen(cad); i++){
        suma += cad[i];
    }
    return suma % NCASILLAS;
}

