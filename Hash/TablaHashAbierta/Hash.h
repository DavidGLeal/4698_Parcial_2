/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash cerrado de enteros y strings .
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 24-06-2022
	*Fecha de modificacion:
        * 29-06-2022
    *GitHub del grupo:	
        
*/

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <conio.h>
#include "Lista.cpp"


using namespace std;

class Hash{
    private:
		int total_elementos;
        Lista *listaP;
        int getClave(int);

	
	public:
        Hash();
		~Hash();
        void insertarElemento(int);
        void eliminarElemento(int);
        void mostrarHash();
		void mensajito();
		int getNumNodos();
        bool buscarElemento(int);

		


};

#endif 
