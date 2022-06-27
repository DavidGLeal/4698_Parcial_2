#pragma once 
#include <iostream>

using namespace std;

class NodoCircular{
    private:
        string cadena;
        NodoCircular *sig;
    public:
        NodoCircular(string cad);
        ~NodoCircular();
        string getCadena();
        NodoCircular *getSig();
        void setSig(NodoCircular *sig);
};
