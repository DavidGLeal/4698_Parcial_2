#pragma once 
#include <iostream>
#include "Nodo.h"

using namespace std;

Nodo::Nodo(){
    this->dato = 0;
    this->siguiente = NULL;
    this->anterior = NULL;
}
Nodo::Nodo(int dato, Nodo* siguiente, Nodo* anterior){
    this->dato = dato;
    this->siguiente = siguiente;
    this->anterior = anterior;
}
Nodo::~Nodo(){
    this->dato = 0;
    this->siguiente = NULL;
    this->anterior = NULL;
}
int Nodo::getDato(){
    return this->dato;
}
Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}
Nodo* Nodo::getAnterior(){
    return this->anterior;
}
void Nodo::setDato(int dato){
    this->dato = dato;
}
void Nodo::setSiguiente(Nodo* siguiente){
    this->siguiente = siguiente;
}
void Nodo::setAnterior(Nodo* anterior){
    this->anterior = anterior;
}

