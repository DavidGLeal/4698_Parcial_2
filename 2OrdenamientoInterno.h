#pragma once
#include <iostream>
#include "0Vector.cpp"
#include "6ImprimirInterno.cpp"

using namespace std;

class OrdenamientoInterno: public ImprimirInterno{
	
	private:
		Vector vector;
		
	public:
		
		OrdenamientoInterno(Vector &v){
			this->vector = v;
		}
		void ordenarIntercambio();
		void ordenarBurbuja();
		void ordenarQuicksort(Vector &v, int inicio, int fin);
		void ordenarShellSort();
		void ordenarDistribucion();
		void ordenarBucket();
		void ordenarRadix();
		void imprimirInterno(); 	
		Vector getVector();
		void setVector(Vector _vector);

};
