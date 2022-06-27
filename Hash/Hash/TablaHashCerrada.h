#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#define NCASILLAS 29

class TablaHashCerrada{
    protected:
        NodoCircular **tabla;
        string dato;
    public:
        TablaHashCerrada();
        ~TablaHashCerrada();
        void insertar(string cad);
        void eliminar(string cad);
        void imprimir();
        void buscar(std::string valor);
        int hash(string cad); 
        virtual int hash2(int pos)=0;
};
