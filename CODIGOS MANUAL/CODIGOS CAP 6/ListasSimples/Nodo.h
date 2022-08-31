#pragma once
#include <iostream>

using namespace std;
#ifndef NULL 
#define NULL 0
#endif
class Nodo
{
public:
	Nodo(int _dato, Nodo* _siguiente);
	Nodo(int _dato);
	Nodo();
	int getDato(void);
	void setDato(int newDato);
	Nodo* getSiguiente(void);
	void setSiguiente(Nodo* newSiguiente);


protected:
private:
	int dato;
	Nodo* siguiente;


};

