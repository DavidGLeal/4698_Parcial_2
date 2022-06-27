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
        void insertarLineal(int valor);
        void insertarCuadratico(int valor);
        void insertarDoble(int valor);
        void eliminar(int valor);
        void imprimir();
        int buscarLineal(int valor);
        int hash(int valor);
        int hashlineal(int indice);
        int hashCuadratico(int indice);
        int hash2(int);
};
