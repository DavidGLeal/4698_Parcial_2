#pragma once
#ifndef HASHSTR_H
#define HASHSTR_H

#include <iostream>
#include <conio.h>
#include "ListaStr.cpp"


using namespace std;

class HashStr{
    private:
		int total_elementos;
        ListaStr *listaP;
        int getClave(string);

	
	public:
        HashStr();
		~HashStr();
        void insertarElemento(string);
        void eliminarElemento(string);
        void mostrarHash();
		void mensajito();
		int getNumNodos();
        bool buscarElemento(string);
};

#endif 
