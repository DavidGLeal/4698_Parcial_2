#include <iostream>
#include "2OrdenamientoInterno.cpp"
#include "0Vector.cpp"

using namespace std;

class Ordenamiento_Guarderas_David
{
	private:
		OrdenamientoInterno func;
		Vector orde;
		int inter;
	public:
		int getInter();
		void setInter(int);
		Vector getOrde();
		void setOrde(Vector);
		void ordenamiento_Guarderas_David();
		void imprimir(Vector);
};