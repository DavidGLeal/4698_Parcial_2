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
        void insertar(string cad,int opc);
        void eliminar(string cad);
        void imprimir();
        int hash(string cad); 
        int quadraticProbing(string cad , int i);
        int hashDoble(string cad); 
        void sondeoLineal(int pos);
        int hashF(string cad, int i);
        void insertarDoble(string cad);   
};
