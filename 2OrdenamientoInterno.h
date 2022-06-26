#pragma once
#include <iostream>
#include "0Vector.cpp"

using namespace std;

class OrdenamientoInterno{
	
	private:
		Vector *vector = new Vector();
		
	public:
		
		OrdenamientoInterno(){}
		Vector &ordenarIntercambio();
		void ordenarBurbuja();
		void ordenarQuicksort(Vector &v, int inicio, int fin);
		void ordenarShellSort();
		void ordenarDistribucion();
		void ordenarBucket();
		void ordenarRadix();
		void imprimirInterno(); 	
		Vector getVector();
		void setVector(Vector vector);
};
