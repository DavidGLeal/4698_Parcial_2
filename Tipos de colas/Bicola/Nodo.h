#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Nodo
{
public:
	
	Nodo();
	//Getters y setters
	int getValor();
	Nodo*& getSiguiente();
	void setValor(int);
	void setSiguiente(Nodo*);

private:
	//Atributos
	int valor;//Puede ser de cualquier tipo
	Nodo* siguiente;
};

