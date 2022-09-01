//Dirección de memoria final de operaciones realizadas por medio de aritmética de punteros.
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
	int* ptr;			/* el puntero */
	int vector[100];	/* el vector */
	int i;			/* variable contadora */
	ptr = &vector[0];	/* ptr apunta al origen del vector */
	ptr += 10;			/* ptr apunta a vector[10] */
	for (i = 0; i <= 10; i++){
		*ptr = 1;	/*	asigna 1 a la posición de memoria apuntada por "ptr" */
		ptr++;		/* 	ptr pasa al siguiente elemento */}
	cout <<"La direccion de memoria final despues de las operaciones realizadas por medio de aritmetica de punteros es: " <<ptr << endl;
	system("pause>null");
}
