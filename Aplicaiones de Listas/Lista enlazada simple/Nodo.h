#pragma once 
#include <iostream>

using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(int, Nodo*);
    ~Nodo();
    int getDato();
    Nodo* getSiguiente();
    void setDato(int);
    void setSiguiente(Nodo*);
private:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};