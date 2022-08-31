/*Universidad de las Fuerzas Armadas - ESPE
TAREA #3 - Parcial 3: 
Graficar, en base a algoritmos, los distintos casos de la notación asintótica Big O.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 18/08/2022
FECHA DE MODIFICACIÓN: 19/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#pragma once
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

class BigO
{
	private:
		int x;
		int y;
		HWND miConsola;
		HDC mdc;
		COLORREF COLOR;
	public:
		BigO(int,int);
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		void grafiPlano(int,int);
		void o1(int);
		void oN(int);
		void oLog(int);
		void oCua(int);
		void oCub(int);
		void oNLog(int);
		void o2N(int);
};