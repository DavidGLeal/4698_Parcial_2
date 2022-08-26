/*Universidad de las Fuerzas Armadas - ESPE
EXTRA - Parcial 3: 
Graficar en la consola un tablero de ajedrez.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 07/08/2022
FECHA DE MODIFICACIÓN: 07/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <thread>
#define IZQUIERDA 75
#define DERECHA 77
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define ESCAPE 27

using namespace std;

class Tablero
{
	private:
		HWND miConsola = GetConsoleWindow();
		HDC mdc = GetDC(miConsola);
		int x=100;
		int y=50;
		COLORREF COLOR = RGB(255,255,255);
		int dim;
	public:
		Tablero(int);
		Tablero();
		int getDim();
		void setDim(int);
		void graficarTablero();
		void dibujarBordes();
		void pintarCasillas(int,int);
		
		void jugarTorre();
		
};