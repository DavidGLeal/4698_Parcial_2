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
