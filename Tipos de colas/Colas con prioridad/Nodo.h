#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Nodo
{
public:
	
	Nodo();
	Nodo(int,int);
	//Getters y setters
	int getValor();
	int getPrioridad();
	Nodo*& getSiguiente();
	void setValor(int);
	void setPrioridad(int);
	void setSiguiente(Nodo*);

private:
	//Atributos
	int valor;//Puede ser de cualquier tipo
	int prioridad;
	Nodo* siguiente;
};

