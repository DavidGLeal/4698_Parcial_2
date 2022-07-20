#ifndef PILA_H
#define PILA_H
#include<iostream>
#include<conio.h>
#include "Nodo.h"
using namespace std;

class Pila{
	private:
		Nodo *cabeza;
	public:
		Pila();
		bool PilaVacia();
		void push(int);
		void pop();	
		void mostrarPila();
		int obtenerMayor();
		
		Nodo *getCabeza();
		void setCabeza(Nodo *);
		
};

#endif
