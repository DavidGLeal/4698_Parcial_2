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
