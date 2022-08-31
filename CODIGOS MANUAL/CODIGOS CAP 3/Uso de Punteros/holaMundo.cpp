#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void imprimir();
int main() {
	imprimir();
	system("pause>null");
	return 0;
}
void imprimir() {
	char nombre[] = "Puntero Cadenas"; //Declaramos un arreglo de caracteres
	char *puntero = nombre;//Asignamos al puntero el comienzo del arreglo
	cout << "Nombre Predeterminado: " << puntero << endl;//Escribimos en pantalla nomb..	for (int i = 0; i <= 20; i++)
	{
		cout << "Ingrese un nuevo nombre para la cadena que se encuentra referenciada por medio del puntero: ";
		gets_s(nombre); //Leemos otro nombre		fflush(stdin); //Limpia nuestro arreglo para el nuevo ingreso
		cout << endl << "El nuevo nombre es: " << puntero << endl << endl; //Escribimos el nuevo nombre...
		fflush(stdin);
	} //Finalizamos el ciclo pidiendo nuevamente un nombre actualizado
}
