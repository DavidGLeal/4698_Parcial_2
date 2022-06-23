#pragma once
#include <iostream>
#include "vector.h"
using namespace std;

class OrdenamientoInterno{
	
	public:
		
		virtual void ordenarIntercambio();
		virtual void ordenarBurbuja();
		virtual void ordenarQuicksort();
		virtual void ordenarShellSort();
		virtual void ordenarDistribucion();
		virtual void ordenarBucket();
		virtual void ordenarRadix();
		virtual void imprimirInterno(); 
		
};
