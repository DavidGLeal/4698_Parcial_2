#include <iostream>
#include <stdio.h>
#include <stdlib.h>
class Nodo
{
private:
	int datos;
	Nodo* siguiente;
public:
	Nodo();
	Nodo(int, Nodo *_siguiente);
	void setDatos(int);
	void setSiguiente(Nodo *_siguiente);
	int getDatos();
	Nodo* getSiguiente();
};
