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

#include "Pascal.cpp"

int main()
{
	system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "|      Resolucion del Triangulo de Pascal       |" << endl;
        cout << "|                 BACKTRACKING                  |" << endl;
        cout << "| Grupo 3 - Almeida, Hernandez, Masacela, Reyes |" << endl;
        cout << "|           Estructura de Datos - 4698          |" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "      Ingrese el numero de filas del triangulo   " << endl;
        cout << "               Teclee 0 para salir               " << endl;
        cout << "-------------------------------------------------" << endl << endl; 
	IngresarDatos* ingreso;
	int dim = ingreso->ingresarDatos("de la cantidad de lineas");
	if (dim != 0)
	{
		Pascal* tableroPascal = new Pascal(dim);
		cout << endl << "Backtracking: Busca las soluciones una a una hasta dar con la indicada:"<<endl<<endl;
		tableroPascal->backtrackingPascal();
	}
    return 0;
}