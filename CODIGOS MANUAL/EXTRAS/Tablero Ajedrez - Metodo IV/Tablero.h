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
#include <cmath>
#include <windows.h>
//#include <gdiplus.h>

using namespace std;

class Tablero
{
	private:
		HWND miConsola = GetConsoleWindow();
		HDC mdc = GetDC(miConsola);
		int x=100;
		int y=50;
		COLORREF COLOR = RGB(255,255,255);
	public:
		
		void graficarTablero();
		void dibujarBordes();
		void pintarCasillas(int,int);
};