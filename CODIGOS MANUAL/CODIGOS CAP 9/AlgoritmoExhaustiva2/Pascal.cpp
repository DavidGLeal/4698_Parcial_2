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
   FECHA DE CREACION:        Miércoles, 09 de agosto de 2022 10:25 a.m. 	
   FECHA DE MODIFICACION:    Miércoles, 09 de agosto de 2022 11:48 a.m.
 * --------------------------
 * Planteamiento: Resolver un Triángulo de Pascal utilizando un algoritmo de resolución.
 * --------------------------
 * Este programa implementa una solución usando:
 * - Backtracking
 * - Se simula el tiempo computacional que se demora colocando un temporizador de
 *   pausa: "Sleep";
 */

#pragma once
#include "Pascal.h"
using namespace std;

Pascal::Pascal(int _dimension)
{
	dimension = _dimension;
}

Pascal::~Pascal()
{
}

void Pascal::backtrackingPascal()
{
    int nM = 0;
	for (int linea = 1; linea <= dimension; linea++)
	{
		int inicial = 1; 

		// Imprime Espacios
		for (int i = 1; i < (dimension - linea + 1); i++){
			cout << " ";
		}

		for (int i = 1; i <= linea; i++)
		{
			cout << inicial << " ";
			// Backtracking: Busca las mejores soluciones
			// "Poda": Salida del bucle.
            while (nM != (linea - i) / i)
            {
                Sleep(100);
                nM++;
            }
			inicial = inicial * (linea - i) / i;
            nM = 0;
		}
		cout << "\n";
	}
}
