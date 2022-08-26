/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 23/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#pragma once
#include "RGBcode.cpp"
#include <iostream>
#include <windows.h>
#include <math.h>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <thread>
#include <fstream>
#include <cmath>
#include "pdf.cpp"
#include "metrics.cpp"
#include <sstream>
#include <iomanip>
#include <complex>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#define ESCAPE 27
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define P 112
#define T 116
#define B 98
#define R 114
#define C 99


using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

class Paleta
{
	private:
		int dim;
		RGBcode** paleta,**paletita;
		RGBcode** desorden;
		bool** comprob,compro=false;
		int xIn;
		int yIn;
		int xNueva;
		int yNueva;
		int xW;
		int yW;
		int xB;
		int yB;
		int xL;
		int yL;
		int movimientos=0;
		HWND miConsola = GetConsoleWindow();
		HDC mdc = GetDC(miConsola);
		COLORREF color;
	public:
		Paleta(int);
		Paleta(int,int,int);
		int getXIn();
		int getYIn();
		int getDim();
		void setXIn(int);
		void setYIn(int);
		void setDim(int);
		void crearPaleta(int);
		void mostrarPaleta();
		void mostrarCompleto();
		void degradar(int);
		void clonar();
		void falsificar();
		void jugar();
		bool comprobar();
		void solucionar();
		void mover();
		void buscar();
		void gotoxy(int x, int y);
		void ocultarCursor();
		void generarArchivosTxT();
		void escribirArchivo(ofstream &archi,string dirSR);
		void generarBackup();
		void leerBackup();
		void generarArchivosPDF(string);
		void escribir(int);
		void pintarBlanco(int, int, int, int);
};

