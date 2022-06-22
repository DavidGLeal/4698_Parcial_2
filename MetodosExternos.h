#include <iostream>
#include <string.h>
using namespace std;
#pragma once
   
class MetodosExternos{

    private:
        string nombreArchivo; 
    public:

    MetodosExternos(string);
    ~MetodosExternos();
    void ordenarPorDirecta();
    void ordenarPorNatural();
    
};