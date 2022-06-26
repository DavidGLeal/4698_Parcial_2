#pragma once 
#include <iostream>
#include "Nodo.h"
#define NCASILLAS 29

class TablaHashCerrada{
    private:
        Nodo *tabla[NCASILLAS];
    public:
        TablaHashCerrada();
        ~TablaHashCerrada();
        void insertar(char *cad);
        void eliminar(char *cad);
        void imprimir();
        int hash(char *cad);
};

