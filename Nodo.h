/*
	*Universidad de las Fuerzas Armadas "ESPE"
        *Enunciado del problema:
	*Realizar un pograma de manejo de árboles binarios con todas sus funciones.
        *Autores:
	*Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 04-07-2022
	*Fecha de modificacion:
        * 08-07-2022
        *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Parcial_2
*/

#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Nodo
{
public:
	int getValor();
	Nodo*& getDerecha();
	Nodo*& getIzquierda();
	void setValor(int);
	void setDerecha(Nodo*);
	void setIzquierda(Nodo*);

private:
	int valor;
	Nodo* derecha;
	Nodo* izquierda;
};

