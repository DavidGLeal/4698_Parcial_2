#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#define NCASILLAS 29

class TablaHashCerrada{
    private:
        NodoCircular **tabla;
        string dato;
    public:
        TablaHashCerrada();
        ~TablaHashCerrada();
        void insertar(string cad);
        void eliminar(string cad);
        void imprimir();
        int hash(string cad); 
        int quadraticProbing(int pos);
        int hashDoble(string cad); 
        void insertarDoble(string cad);     
};
