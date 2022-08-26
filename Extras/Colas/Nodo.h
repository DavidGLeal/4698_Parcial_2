#ifndef NODO_H
#define NODO_H
#include<iostream>
#include<conio.h>
using namespace std;

class Nodo{
	
	private:
		int dato;
		Nodo *siguiente;
		
	public:
		Nodo();
		Nodo(int);
		
		int getDato();
		Nodo *getSiguiente();
		
		void setDato(int);
		void setSiguiente(Nodo *);
			
};

#endif