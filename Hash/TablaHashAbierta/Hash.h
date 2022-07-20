/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 26/06/2022
Fecha de modificacion: 29/06/2022
Grupo 10
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
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
