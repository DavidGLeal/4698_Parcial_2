#pragma once
#include <iostream>
#include <fstream>
//#include "Ordenamiento.h"
using namespace std;

class ImprimirExterno{
    
    public:
   	 
   	  void abrir(fstream *f, char nom[], int tip = 1);
     	void cerrar(fstream *f);
     	void imprimir(char nom[]);
   	 //virtual void imprimir();
    
   	 
};
