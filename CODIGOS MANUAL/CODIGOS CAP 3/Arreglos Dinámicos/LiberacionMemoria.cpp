#include <stdio.h>
#include <conio.h>
#include <stdlib.h> /* requerida para malloc y free funciones */
#include <iostream>

using namespace std;

void inverso(int*,int);

int main() {
	int number;
	int *ptr;
	int i;

	cout<<"Cuantos numeros enteros desea imprimir en orden inverso: ";
	cin>> number;

	/* Creamos el espacio de memoria en forma dinámica */
	ptr = (int *)malloc(number*sizeof(int)); 

	/* Llamamos a la funcion inversa que imprimira los numeros*/
	inverso(ptr,number);
/* Liberamos la memoria reservada */
	free(ptr); 
	cout<<"Se libero la memoria usando free()"<<endl;

   getche();

}

void inverso(int* ptr, int number){
	int i;
	if (ptr != NULL) {
	for (i = 0; i<=number; i++) {
		*(ptr + i) = i;
	}

	for (i = number; i>0; i--) {

	/* Imprimimos en orden inverso*/
		cout<<" "<< *(ptr + (i))<<endl; 
	}

}
	else {
cout<<"\nLa reserva de memoria no suficiente memoria.\n";
	}
}
