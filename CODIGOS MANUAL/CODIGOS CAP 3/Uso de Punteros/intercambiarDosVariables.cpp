// Define el punto de entrada de la aplicación de consola.
#include <stdio.h>
#include <iostream>
using namespace std;
//Incluyo librerías


//Declaro funciones:
void intercambiar(int *, int *);//Prototipo de la función

int main()
{
	//Declaro variables:
	int a, b;

	//Introducir datos:
	cout<<"\nIngrese los datos a intercambiar: \n"<<endl;
	cout<<"\na = "<<endl;	
	cin>>a;
	cout<<"\nb = "<<endl;	
	cin>>b;

	intercambiar(&a, &b);

	cout<<"\nValores despues del intercambio: \n"<<endl;
	cout<<"\na = "<<a<<"\nb = "<<b<<endl;
	system("pause");
	return 0;
}
//Desarrollo de la funcion intercambiar
void intercambiar(int *a, int *b)
{
	//Declaro variables:
	int aux;
	aux = *a; //Se asigna el valor del puntero (*a) a la  variable aux
	*a = *b; //se le asigna el valor del puntero(*b)a la variable(*a)
	*b = aux; //se le asigna el valo(aux) al puntero  (*b)
}
