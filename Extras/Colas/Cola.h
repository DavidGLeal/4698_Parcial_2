/* 
* La cola es una estructura FIFO 
* Métodos: insetar y eliminar
*/

#ifndef COLA_H
#define COLA_H
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"Nodo.cpp"

using namespace std;

class Cola{
	
	private:
    Nodo *cabeza = NULL;
    Nodo *cola = NULL;
		
	public:
		Cola();
        bool colaVacia();
		void push(int);//inserta en la cola
        void pop();
        void mostrarCola();
		int obtenerMayor();

        int getNumNodos();
		Nodo *getCabeza();
		Nodo *getCola();	
		void setNumNodos(int);
		void setCabeza(Nodo *);
		void setCola(Nodo *);
	
};

#endif