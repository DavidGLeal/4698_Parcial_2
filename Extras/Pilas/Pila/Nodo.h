/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    #Grupo 7
				Brandon Raul Masacela - 	 brmasacela@espe.edu.ec
				Juan Francisco Reyes -       jfreyes4@espe.edu.ec
	FECHA DE CREACION:        14-06-2022 	
	FECHA DE MODIFICACION:    14-06-2022
*/

#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
		Nodo(int _valor, Nodo *siguiente);
        Nodo();
		friend class Pila;
};
