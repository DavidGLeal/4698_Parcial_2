#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

class Nodo{
	private:
		int valor; // Contiene la clave
		Nodo *padre; // Puntero al padre
		Nodo *izquierda; // Puntero al hijo izquierdo
		Nodo *derecha; // Puntero al hijo derecho
	public:
		Nodo();
		int getValor();
		Nodo *&getPadre();
		Nodo *&getDerecha();
		Nodo *&getIzquierda();
		void setValor(int);
		void setPadre(Nodo*);
		void setDerecha(Nodo*);
		void setIzquierda(Nodo*);
			
};
