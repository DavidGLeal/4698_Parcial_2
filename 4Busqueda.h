#pragma once 
#include <iostream>
#include "0Vector.cpp"
#include "2OrdenamientoInterno.cpp"
using namespace std;
class Busqueda{

	private: 
		Vector vector;
		OrdenamientoInterno ordenado;
		int dato{0};
	public:

		Busqueda(){
		}

		virtual void busquedaBinaria();
		virtual void busquedaSecuencial();

		void setVector(Vector &_vector);

		void  vaciarVector();

		void  setDato(int &a);

		void copiarVector(Vector &_vector);
};
