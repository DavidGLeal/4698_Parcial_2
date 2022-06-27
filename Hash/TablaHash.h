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
<<<<<<< HEAD
        int hash(string cad);
        int quadraticProbing(int pos);        
=======
        int hash(string cad);  
        int hashDoble(string cad); 
         void insertarDoble(string cad);     
>>>>>>> 6fabb043d6bbb28e1d7c8a09caf2878eadd4579d
};
