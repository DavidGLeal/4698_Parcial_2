/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 10
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
*/
#ifndef LISTASTR_H
#define LISTASTR_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

//#include "NodoStr.h"
#include "NodoStr.cpp"

using namespace std;

class ListaStr{
	private:
		
		NodoStr *actual;
		int numNodos;

	public:
		NodoStr *cabeza;//primero
		ListaStr();
		~ListaStr();
		
		int getNumNodos();
		NodoStr *getCabeza();
		NodoStr *getActual();	
		void setNumNodos(int);
		void setCabeza(NodoStr *);
		void setActual(NodoStr *);
		
		bool ListaVacia();
		void agregarCabeza(string);
		void agregarCola(string);
		bool buscar(string);
		void borrarCabeza();
		void borrarCola();
		void imprimirLista();
		void borrarEnPosicion(string);
		int buscarPosicion(string);

};


#endif 
