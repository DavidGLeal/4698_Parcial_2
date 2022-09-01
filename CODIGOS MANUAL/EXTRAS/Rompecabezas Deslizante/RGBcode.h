
/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 21/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#pragma once

#include <iostream>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

class RGBcode
{
	private:
		int x;
		int y;
		int rad;
		int rojo;
		int azul;
		int verde;
		COLORREF color;
		HWND miConsola= GetConsoleWindow();
		HDC mdc = GetDC(miConsola);
	public:
		RGBcode(int,int);
		RGBcode(int,int,int);
		RGBcode();
		int getRad();
		void setRad(int);
//		int* getColor();
		void setColor(int,int,int);
		int getX();
		int getY();
		int getR();
		int getG();
		int getB();
		void setR(int);
		void setG(int);
		void setB(int);
		void setX(int);
		void setY(int);
		void randRGB(int);
		void mostrar();
};