#pragma once
#include <iostream>
#include <stdio.h>
#include "Nodo.h"
#include "Nodo.cpp"

using namespace std;

class Lista{
    private:
        Nodo* primero;
        Nodo* ultimo;
        int dato;
    public:
        Lista();
        bool listavacia();
        void insertarporcabeza(int dato);
        void insertarporcola(int dato);
        void insertarporposicion(int dato, int posicion);
        void eliminarporcabeza();
        void eliminarporcola();
        void eliminarporposicion(int posicion);
        void buscar(int dato);
        void imprimir();
};
