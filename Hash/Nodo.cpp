#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Nodo.h"

using namespace std;

Nodo :: Nodo(char *cad){
    cadena = new char[strlen(cad) + 1];
    strcpy(cadena, cad);
    sig = NULL;
}
Nodo :: ~Nodo(){
    delete[] cadena;
}
char *Nodo :: getCadena(){
    return cadena;
}
Nodo *Nodo :: getSig(){
    return sig;
}
void Nodo :: setSig(Nodo *sig){
    this->sig = sig;
}
