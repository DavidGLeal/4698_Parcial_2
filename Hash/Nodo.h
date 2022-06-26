#pragma once 
#include <iostream>

using namespace std;

class Nodo{
    private:
        char *cadena;
        Nodo *sig;
    public:
        Nodo(char *cad);
        ~Nodo();
        char *getCadena();
        Nodo *getSig();
        void setSig(Nodo *sig);
};