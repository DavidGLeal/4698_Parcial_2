#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Nodo
{
public:
	Nodo(float _dato, Nodo* _siguiente);
	Nodo(float _dato);
	Nodo();
	float getDato(void);
	void setDato(float newDato);
	Nodo* getSiguiente(void);
	void setSiguiente(Nodo* newSiguiente);

protected:
private:
	float dato;
	Nodo* siguiente;
};
