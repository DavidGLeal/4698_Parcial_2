/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 10
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
*

#ifndef LISTA_H
#define LISTA_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Nodo.h"
#include "Nodo.cpp"

using namespace std;

class Lista{
	private:
		
		Nodo *actual;
		int numNodos;

	public:
		Nodo *cabeza;//primero
		Lista();
		~Lista();
		
		int getNumNodos();
		Nodo *getCabeza();
		Nodo *getActual();	
		void setNumNodos(int);
		void setCabeza(Nodo *);
		void setActual(Nodo *);
		
		bool ListaVacia();
		void agregarCabeza(int);
		void agregarCola(int);
		bool buscar(int);
		void borrarCabeza();
		void borrarCola();
		void imprimirLista();
		void borrarEnPosicion(int);
		int buscarPosicion(int);

};


#endif 
