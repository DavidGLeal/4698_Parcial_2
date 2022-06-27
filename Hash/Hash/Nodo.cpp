#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Nodo.h"

using namespace std;

NodoCircular :: NodoCircular(string cad){
    cadena = cad;
    sig = NULL;
}
NodoCircular :: ~NodoCircular(){
    delete sig;
}
string NodoCircular :: getCadena(){
    return cadena;
}
NodoCircular *NodoCircular :: getSig(){
    return sig;
}
void NodoCircular :: setSig(NodoCircular *sig){
    this->sig = sig;
}

