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

#ifndef NODOSTR_H
#define NODOSTR_H

#include <iostream>

using namespace std;

class NodoStr{
	private:
		NodoStr *siguiente;
		string valor;	
	
	public:
		NodoStr();
		NodoStr(string);
		~NodoStr();
		string getValor();
		NodoStr *getSiguiente();	
		void setValor(string);
		void setSiguiente(NodoStr *);

		void imprimirNodo();
		
};

#endif
