/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 26/06/2022
Fecha de modificacion: 29/06/2022
Grupo 10
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
*/

#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo{
	private:
		Nodo *siguiente;
		int valor;	
	
	public:
		Nodo();
		Nodo(int);
		~Nodo();
		int getValor();
		Nodo *getSiguiente();	
		void setValor(int);
		void setSiguiente(Nodo *);

		void imprimirNodo();
		
};

#endif

