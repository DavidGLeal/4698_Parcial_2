#pragma once
#include <iostream>

using namespace std;

class OrdenamientoInterno{
	
	private:
		Vector vector;
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