//Archivo de cabecera Nodo.cpp en el que se van a encontrar desarrollados los métodos incluidos dentro de la clase 
//Nodo del archivo de cabecera Nodo.h

//Librerias
#include <iostream>
#include <conio.h>
#include "Nodo.h"//Libreria "Nodo.h" que contiene mi clase Nodo
using namespace std;

//Definicion del constructor Nodo()
Nodo::Nodo()
{
	this->x = 0;
	this->siguiente = NULL;
}//Fin del constructor vacio de la clase Nodo()

 //Setters
 //setX()
void Nodo::setX(int x)
{
	this->x = x;
}//Fin setX()
//setSigueinte()
void Nodo::setSiguiente(Nodo *siguiente)
{
	this->siguiente = siguiente;
}//Fin setSiguiente()

 //Getters
 //getX()
int Nodo::getX()
{
	return x;
}//Fin getX()

 //getSiguiente()
Nodo *Nodo::getSiguiente()
{
	return this->siguiente;
}

//agregarNodo()
void Nodo::agregarNodo(Nodo *cabeza, int x)
{
	Nodo *nuevo, *aux;
	aux = cabeza;
	if (aux->getX() == 0)//Si la lista cabeza no esta vacia (No está vacia porque a lo que llega como parámetro ya contine el valor de 0 como dato del nodo.))
	{
		aux->setX(x);
		aux->setSiguiente(NULL);
	}
	else
	{
	nuevo = new Nodo();
		nuevo->setX(x);
		nuevo->setSiguiente(NULL);

		while (aux->getSiguiente() != NULL)
		{
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo); //Me apunta aux->siguiente a nuevo
}//Fin else


}//Fin agregarNodo()

void Nodo::mostrarLista(Nodo **cabeza)
{
	Nodo *aux;
	aux = *cabeza;
	int cont = 0;

	if (aux->getX() == 0)
	{
		cout << "Lista vacia!!!. Debe ingresar datos." << endl;
	}
	else
	{

		while (aux != NULL)
		{
			cout << "-> " << cont + 1 << " " << aux->getX() << endl;
			aux = aux->getSiguiente();
			cont++;
		}
	}//Fin else


}//Fin mostrarlista()

 //mcd()


int Nodo::ContarValor(Nodo **cabeza, int numero,int &contador) // Función que borra todos los elementos con el valor
{
	Nodo *aux; //Declaramos un auxiliar tipo puntero *aux 
	aux = *cabeza;


	while (aux->getSiguiente() != NULL)
	{
if (numero == aux->getX())
		{
			contador++;
		}
		aux = aux->getSiguiente();
	}
	return contador;
}
