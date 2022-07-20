#include "Nodo.h"

Nodo::Nodo(){
    //
}

Nodo::Nodo(int valor,Nodo* sig=nullptr){
    this->valor=valor;
    this->siguiente=sig;
}

int Nodo:: getValor(){
    return valor;
}

Nodo* Nodo:: getSiguiente(){
    return siguiente;
}

Nodo* Nodo:: getPrevio(){
    return previo;
}

void Nodo:: setSiguiente(Nodo* siguiente){
    this->siguiente=siguiente;
}

void Nodo:: setPrevio(Nodo* previo){
    this->previo= previo;
}

void Nodo:: setValor(int val){
    this->valor=val;
}