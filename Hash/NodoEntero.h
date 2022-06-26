#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class NodoCircularEntero{
    private:
        int valor;
        NodoCircularEntero *sig;
    public:
        NodoCircularEntero(int valor);
        ~NodoCircularEntero();
        int getValor();
        NodoCircularEntero *getSig();
        void setSig(NodoCircularEntero *sig);
};
