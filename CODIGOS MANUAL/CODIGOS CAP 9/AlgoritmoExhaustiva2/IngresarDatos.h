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