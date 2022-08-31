#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

int leerCantidad();
void leer(int, int*);
void imprimir(int, int*);

int main() {
	system ("COLOR 0f");
	int cantidad = leerCantidad();
	int *numeros;

	//Reservamos memoria dinamica con malloc
	numeros = (int*)malloc(cantidad * sizeof(int));  

	//funcion para leer los numeros que llenaran la memoria dinamica
	leer(cantidad, numeros);  
	cout<<"\n\tLos numeros se han guardado en la memoria dinamica ";
	cout<<"\n";

	//funcion para imprmir los datos de la memoria dinamica	
	imprimir(cantidad, numeros);  

	//liberamos el espacio utlizado x la memoria dinamica
	free(numeros); 
	cout<<"\n\t\Liberamos la memoria usando free()";
   getch();
}

int leerCantidad() {
	int cantidad;
	cout<<"\n\tCuantos numeros va a ingresar?:  ";
	cin>>"%i", &cantidad;
	return cantidad;
}

void leer(int cantidad, int *numeros) {
	int i = 0;
	for (; i < cantidad; i++) {
		cout<<"\n\tIngrese el numero %d\t", i + 1;
		cin>>"%i", &numeros[i];
	}
}

void imprimir(int cantidad, int *numeros) {
	int i = 0;
	cout<<"\n\n\tLos numeros ingresados son: \n\n\t";
	for (; i < cantidad; i++) {
		cout<<"%i ", numeros[i];
	}
}
