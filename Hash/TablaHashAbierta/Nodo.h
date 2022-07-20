/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 10
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
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

