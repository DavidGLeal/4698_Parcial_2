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
#include <iostream>
#include <fstream>
#include <string.h>

#define N 8
int contadorSoluciones = 0;

class Tablero
{
private:
    int dimension = N;
    int reinas = 1;
    char** tablero;
	std::fstream archivo;
public:
    Tablero(int _dimension);
    ~Tablero();
    int esAtacada(char** _tablero, int fila, int columna);
	void crearArchivo();
    void imprimirSoluciones(char** _tablero);
    void ubicarReinas(char** _tablero, int fila);
    void resolverTodasLasFilas(int n);
};