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

#include "Tablero.h"

Tablero::Tablero(int _dimension)
{
    tablero = new char *[_dimension];
    for (int i = 0; i < _dimension; ++i)
    {
        *(tablero + i) = new char;
    }
    for (int i = 0; i < _dimension; i++)
	{
		for (int j = 0; j < _dimension; j++)
		{
			*(*(tablero + i) + j) = '-';
		}
	}
    crearArchivo();
}

Tablero::~Tablero()
{
    delete tablero;
}
int Tablero::esAtacada(char** _tablero, int fila, int columna){
    // Ataque en la misma Columna
	for (int i = 0; i < fila; i++)
	{
		if (*(*(tablero + i) + columna) == 'R')
		{
			return 0;
		}
	}

	// Ataque en la misma Diagonal Principal
	for (int i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
	{
		if (*(*(tablero + i) + j) == 'R')
		{
			return 0;
		}
	}

	// Ataque en la misma Diagonal Secundaria
	for (int i = fila, j = columna; i >= 0 && j < N; i--, j++)
	{
		if (*(*(tablero + i) + j) == 'R')
		{
			return 0;
		}
	}

	return 1;
}
void Tablero::crearArchivo()
{
    archivo.open("solucion.txt", std::fstream::out);
    archivo << "Solucion " << reinas << " x " << N << std::endl
            << std::endl;
    std::cout << "Solucion " << reinas << " x " << N << std::endl
            << std::endl;
}
void Tablero::imprimirSoluciones(char** _tablero)
{
    archivo << "Solucion N: " << ++contadorSoluciones <<std::endl;
    std::cout << "Solucion N: " << contadorSoluciones <<std::endl;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			archivo<<*(*(tablero + i) + j) << " ";
			std::cout<<*(*(tablero + i) + j) << " ";
		}
		archivo<<std::endl;
		std::cout<<std::endl;
	}
	archivo<<std::endl;
	std::cout<<std::endl;
}
void Tablero::ubicarReinas(char** _tablero, int fila)
{
	if (fila == reinas)
	{
		imprimirSoluciones(tablero);
		return;
	}
	for (int i = 0; i < dimension; i++)
	{
		if (esAtacada(tablero, fila, i))
		{
			*(*(tablero + fila) + i) = 'R';
			ubicarReinas(tablero, fila + 1);
            // Esencia del Backtracking.
			*(*(tablero + fila) + i) = '-';
		}
	}
}
void Tablero::resolverTodasLasFilas(int n)
{
    reinas = n;
	int span = reinas - 1;
	for (int i = 0; i < N - span; i++)
	{
		ubicarReinas(tablero, i);
		reinas++;
	}
    archivo.close();
}