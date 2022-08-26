/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 23/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#if !defined(__Class_Diagram_1_MenuProyectoUnidad_h)
#define __Class_Diagram_1_MenuProyectoUnidad_h
#include "FuncionesParaValidar.cpp"
#include "Paleta.cpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstring>
#include<windows.h>
#include <thread>
#include "Imagen.cpp"
using namespace std;
class MenuProyectoUnidad
{
	public:
	int menuCursor(const char* titulo, const char* opciones[], int n);
   	int menuCursorColor(const char* titulo, RGBcode* opciones, int n);
   	void gotoxy(int x, int y);
   	void presentarMenu();
   	void ocultarCursor();
};

#endif