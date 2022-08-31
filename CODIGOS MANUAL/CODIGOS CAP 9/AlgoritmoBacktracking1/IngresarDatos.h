/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
		Juan Reyes
        Brandon Masacela
        GRUPO: 5
   FECHA DE CREACION:        Jueves, 04 de agosto de 2022 05:42 p.m. 	
   FECHA DE MODIFICACION:    Jueves, 04 de agosto de 2022 10:54 p.m.
 * --------------------------
 * Planteamiento: Resolver el Problema de colocar k Reinas en un Tablero de N x N.
 * --------------------------
 * Este programa implementa una solución al Problema de colocar N reinas en un tablero
 * de ajedrez de 8x8, donde k = 1, 2, 3, 4, ..., N.
 */

#pragma once
#include <iostream>

using namespace std;

class IngresarDatos
{
private:
public:
    IngresarDatos();
    ~IngresarDatos();
    int ingresarDatos(const char* prompt);
    int ingresarDatosLim(const char* prompt, int _limite);
    string ingresarDatosNumSt(const char* prompt, int _limite);
    float ingresarDatosF(const char* prompt, int _limite);
    string ingresarDatosS(const char* prompt);
    string ingresarDatosStringPermisivo(const char* prompt);
    string ingresarDatosOculto(const char* prompt);
};