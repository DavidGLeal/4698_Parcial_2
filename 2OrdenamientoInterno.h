#pragma once
#include <iostream>

using namespace std;

class OrdenamientoInterno{
	
	private:
		Vector vector;
	public:
		
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
