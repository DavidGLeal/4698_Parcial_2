#pragma once
#include <iostream>

using namespace std;

class Nodo{
    private:
        int dato;
        Nodo* siguiente;
        Nodo* anterior;
    public:
        Nodo();
        Nodo(int dato, Nodo* siguiente, Nodo* anterior);
        ~Nodo();
        int getDato();
        Nodo* getSiguiente();
        Nodo* getAnterior();
        void setDato(int dato);
        void setSiguiente(Nodo* siguiente);
        void setAnterior(Nodo* anterior);
};
