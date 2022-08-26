#pragma once
//Archivo de cabecera Nodo.h en el cual voy a tener mi clase Nodo 

#include <iostream>

//Clase Nodo
class Nodo
{
	//Atributos de la clase Nodo
private:
int x;
	Nodo *siguiente;

public:
	//Constructor vacio
	Nodo();
	//Métodos Setter /Getters
	//Setters
	void setX(int x);
	//setSiguiente()
	void setSiguiente(Nodo *siguiente);
	//Getters
	int getX();
	Nodo *getSiguiente();
	//Métodos definidos por el usuario
	void agregarNodo(Nodo *cabeza, int x);
	void mostrarLista(Nodo **cabeza);
	int ContarValor(Nodo **cabeza, int numero, int &contador);

};//Fin clase Nodo
