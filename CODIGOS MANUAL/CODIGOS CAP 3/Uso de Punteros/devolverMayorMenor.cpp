/*
Escribir un programa que utilice una función que devuelva el mayor, el menor y la media de los valores de un array de números. (Utilizar punteros).
*/
/*Declaración de librerías*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
/*Declaración de función*/
void estadisticaArray(double *array, int t, double *mayor, double *menor, double*media);

/*Función principal*/
int main()
{
	double A[5];
	/*Ingreso de datos al vector*/
	cout << "\tDevolucion de mayor, menor y la media de los valores de un array de numeros " << endl;
	cout << "Ingrese 5 numeros" << endl;
	for (int i = 0; i <= 4; i++){
		cin >> A[i];
	}
	double mx, mn, md;
	/*Impresión de datos por pantalla*/
	estadisticaArray(A, 5, &mx, &mn, &md);
	printf("Mayor %lf, Menor %lf, Media %lf\n", mx, mn, md);
	/*Pausa el programa*/
	system("pause");
}
void estadisticaArray(double *array, int t, double *mayor, double *menor, double *media){
	int i;
	/* Almacena la suma de los contenidos del array */
	double suma = 0;
	/*Se crea una copia del vector principal tanto para variable puntero    mayor y menor*/
	*mayor = *array; *menor = *array;
	/*Se compara los vectores con el fin de determinar el mayor y menor del mismo*/
	for (i = 0; i<t; i++){
		if (*mayor<array[i]) *mayor = array[i];
		if (*menor>array[i]) *menor = array[i];
		suma += array[i];
	}
	/*Se efectua la operacion para encontrar la media aritmetica*/
	*media = suma / t;
}
