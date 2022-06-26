#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "NodoEntero.h"
#define NCASILLAS 29

class TablaCerradaEnteros{
    private:
        NodoCircularEntero **tabla;
    public:
        TablaCerradaEnteros();
        ~TablaCerradaEnteros();
        void insertar(int valor);
        void eliminar(int valor);
        void imprimir();
        int hash(int valor);
        int hash(int);
};
