#pragma once
#include <iostream>
#include "vector.h"
using namespace std;

class OrdenamientoInterno{
	
	private:
		Vector vector;
		//exclusivos para el metodo Radixsort
		int maxm();
		void countingSort(int);
		///
	public:
		
		virtual Vector &ordenarIntercambio();
		virtual void ordenarBurbuja();
		virtual void ordenarQuicksort(Vector &v, int inicio, int fin);
		virtual void ordenarShellSort();
		virtual void ordenarDistribucion();
		virtual void ordenarBucket();
		virtual void ordenarRadix();
		virtual void imprimirInterno(); 
	
		Vector getVector();
		void setVector(Vector vector);
};
