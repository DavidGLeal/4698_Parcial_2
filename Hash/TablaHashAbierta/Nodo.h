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

