/*
Escribir un programa que permita demostrar el uso de los operadores de dirección y de indirección.*/

/*Librerías*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*Función principal*/
int main()
{
	/*Declaración de variables*/
	int edad = 50;
	/*Se asigna el valor de edad al puntero */
	int *p_edad = &edad;
	char *p;
	char alfa = 'A';
	/*Se asigna la dirección de memoria de alfa a puntero p*/
	p = &alfa;
	char cd[] = "Compacto";
	char *c;
	/*Puntero c = arreglo cd*/
	c = cd;
       char *a = "PUNTEROS";
	/*Impresión de datos*/
      	cout << "\t Operadores de dirección y de indirección" << endl;
	printf("%c\n", *p);
	printf("%p\n", c);
	cout << c << endl;
	printf("%s\n", a);
	/*Pausa el programa*/
	system("pause");
}
