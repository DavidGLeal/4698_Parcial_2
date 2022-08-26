/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 23/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#include "MenuProyectoUnidad.cpp"
#include <stdlib.h>
#include <iostream>
#include <thread>
#include "Login.cpp"

void marquesina(string text) {

HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SHORT ancho, alto;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleCursorPosition(conhandler, { 0, 4 });
    HWND hWnd = GetConsoleWindow();
ShowWindow(hWnd,SW_SHOWMAXIMIZED);
    while (true) {
        string temp = text;
        text.erase(0, 1);
        text += temp[0];
        CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

        for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }

        SMALL_RECT pos = { 20, 0, ancho, 1 };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        free(buff);
        this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main()
{
	MenuProyectoUnidad objMenu;
	string texto = "BIENVENIDO AL PROYECTO UNIDAD 3 - GRUPO 5 - UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
	thread t2(marquesina, texto);
	t2.detach();
	system("cls");
	cout << "\n\n";
	Login objLogin;
	if(objLogin.verificarIngreso()==true)
	{
		objMenu.presentarMenu();
	}

	MenuProyectoUnidad uni;
	uni.presentarMenu();
	
	return 0;
}