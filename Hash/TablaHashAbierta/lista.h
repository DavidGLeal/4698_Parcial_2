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
