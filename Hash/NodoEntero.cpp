#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "NodoEntero.h"

NodoCircularEntero :: NodoCircularEntero(int valor){
    this->valor = valor;
    sig = NULL;
}
NodoCircularEntero :: ~NodoCircularEntero(){
    delete sig;
}
int NodoCircularEntero :: getValor(){
    return valor;
}
NodoCircularEntero *NodoCircularEntero :: getSig(){
    return sig;
}
void NodoCircularEntero :: setSig(NodoCircularEntero *sig){
    this->sig = sig;
}
