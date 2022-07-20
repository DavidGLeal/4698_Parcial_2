#pragma once
#include <iostream>
#include "0Vector.cpp"

using namespace std;

class Radix{
	
	private:
		Vector vector;	
		int getMax(Vector &v);
		void encerar(Vector &v);
		void encerar(int *vec, int tam);
		void imprimir(Vector &vector);
		
	public:
		
		Radix(Vector &v){
			this->vector = v;
		}
		Radix(){
		}
		void ordenarRadix();	
		Vector& getVector();	
		void setVector(Vector &_vector);
		void imprimirInterno();

		void copiarVector(Vector &_vector);

		void  vaciarVector();
		
};