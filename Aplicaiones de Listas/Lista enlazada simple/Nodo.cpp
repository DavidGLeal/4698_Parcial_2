#pragma once

#include <iostream>
#include "Nodo.h"

using namespace std;

Nodo::Nodo() {
    this->dato ;
    this->siguiente = NULL;
    this->anterior = NULL;
}
Nodo::Nodo(int dato, Nodo* siguiente ) {
    this->dato = dato;
    this->siguiente = siguiente;
}
Nodo::~Nodo() {
    delete this->siguiente;
}
int Nodo::getDato() {
    return this->dato;
}
Nodo* Nodo::getSiguiente() {
    return this->siguiente;
}
void Nodo::setDato(int dato) {
    this->dato = dato;
}
void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

