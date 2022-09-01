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
   FECHA DE MODIFICACION:    Jueves, 04 de agosto de 2022 11:20 p.m.
 * --------------------------
 * Planteamiento: Resolver el Problema de colocar k Reinas en un Tablero de N x N.
 * --------------------------
 * Este programa implementa una solución al Problema de colocar N reinas en un tablero
 * de ajedrez de 8x8, donde k = 1, 2, 3, 4, ..., N.
 */


#include "Tablero.cpp"
#include "IngresarDatos.cpp"

int main()
{
	int n = 0;
    IngresarDatos* ingreso = new IngresarDatos();
    Tablero* tablero = new Tablero(N);
    system("cls");
    cout << "-------------------------------------------------" <<endl;
    cout << "|  Simulacion de k Reinas en un Tablero de 8x8  |" <<endl;
    cout << "| Grupo 5 - Almeida, Hernandez, Masacela, Reyes |" <<endl;
    cout << "|           Estructura de Datos - 4698          |" <<endl;
    cout << "-------------------------------------------------" <<endl;
    n = 0;
    while(n > 8 || n < 1)
    {
        n = ingreso->ingresarDatos("del numero 'k' de Reinas a colocar en el tablero.");
    }
    std::cout << std::endl;
    tablero->resolverTodasLasFilas(n);
	return 0;
}