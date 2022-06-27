#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "NodoEntero.h"
#define NCASILLAS 29

class TablaCerradaEnteros{
    protected:
        NodoCircularEntero **tabla;
    public:
        TablaCerradaEnteros();
        ~TablaCerradaEnteros();
        void insertar(int valor);
        void eliminar(int valor);
        void imprimir();
        void buscar(int valor);
        int hash(int valor);
        virtual int hash2(int valor)=0;
};