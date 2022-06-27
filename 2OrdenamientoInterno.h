#pragma once
#include <iostream>
#include "0Vector.cpp"
#include "6ImprimirInterno.cpp"

using namespace std;

class OrdenamientoInterno: public ImprimirInterno{
	
	private:
		Vector vector;	
		int dividir(Vector&, size_t, size_t); //Metodo para que funcione el Quicksort
		void ordenarQuick(Vector&, size_t, size_t); //Metodo para que funcione el Quicksort
		
	public:
		
		OrdenamientoInterno(Vector &v){
			this->vector = v;
		}
		void ordenarIntercambio();
		void ordenarBurbuja();
		void ordenarQuicksort();
		void ordenarShellSort();
		void ordenarDistribucion();
		void ordenarBucket();
		void ordenarRadix();	
		Vector getVector();
		void setVector(Vector _vector);
		void imprimirInterno();

};
