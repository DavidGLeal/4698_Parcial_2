#pragma once
#include <iostream>
#include "vector.h"
using namespace std;

class OrdenamientoInterno{
	
	public:
		
		virtual void ordenarIntercambio(Vector<int> &arreglo);
		virtual void ordenarBurbuja();
		virtual void ordenarQuicksort(Vector <int> &arreglo, int left, int right);
		virtual void ordenarShellSort();
		virtual void ordenarDistribucion();
		virtual void ordenarRadix();
		
};
