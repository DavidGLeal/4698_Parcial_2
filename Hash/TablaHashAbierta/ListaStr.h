/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
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
