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
		int getMax(Vector &v);
		void encerar(Vector &v);
		void encerar(int *vec, int tam);
		
	public:
		
		OrdenamientoInterno(Vector &v){
			this->vector = v;
		}
		OrdenamientoInterno(){
		}
		void ordenarIntercambio();
		void ordenarBurbuja();
		void ordenarQuicksort();
		void ordenarDistribucion();
		void ordenarCountingSort();
		void ordenarBucket();
		void ordenarRadix();	
		void ordenarShellSort();
		Vector getVector();	
		void setVector(Vector &_vector);
		void imprimirInterno();

		void copiarVector(Vector &_vector);
		
};
