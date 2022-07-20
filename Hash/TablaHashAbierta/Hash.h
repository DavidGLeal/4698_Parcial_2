/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 11
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
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
