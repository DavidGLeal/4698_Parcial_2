/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	      Juan Reyes
        Brandon Masacela
        GRUPO: 3
  FECHA DE CREACION:        Miércoles, 14 de agosto de 2022 5:00 p.m. 	
  FECHA DE MODIFICACION:    Miércoles, 14 de agosto de 2022 9:15 a.m.
 * --------------------------
 * Planteamiento: Resolver el Problema de Cambio de Monedas
 * --------------------------
 * Este programa implementa una solución al problema del cambio de 
 * monedas.
 */
 
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Cambio{
	public:
		vector<int>values = {0, 1, 5, 10, 20};
		int total;
		void funcionamiento();
		
};
