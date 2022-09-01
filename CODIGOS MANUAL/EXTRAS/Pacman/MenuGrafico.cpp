/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	Juan Reyes
        Brandon Masacela
        GRUPO: 3
   FECHA DE CREACION:        Lunes, 22 de agosto de 2022 07:25 p.m. 	
   FECHA DE MODIFICACION:     Miercoles, 24 de agosto de 2022 01:52 a.m.
 * --------------------------
 * Planteamiento: Elaborar simulación del juego Pac-Man, aplicando algoritmos
 * --------------------------
 */

#pragma once
#include "MenuGrafico.h"
#include <iostream>

void Limpiar()
{
	system("cls");
}

void GotoXY(int x, int y)
{ // Posicionar el cursor en las coordenadas xy
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Escribir(const char *txt)
{
	printf("%s", txt);
}

void Escribir(int x, int y, const char *txt)
{
	GotoXY(x, y);
	printf("%s", txt);
}

void ColorTexto(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Replica(const char c, int can)
{
	for (int i = 0; i < can; i++)
	{
		printf("%c", c);
	}
}

void ReplicaH(int x, int y, const char *c, int can)
{
	for (int i = 0; i < can; i++)
	{
		Escribir(x + i, y, c);
	}
}

void ReplicaV(int x, int y, const char *c, int can)
{
	for (int i = 0; i < can; i++)
	{
		Escribir(x, y + i, c);
	}
}

void Rectangulo(int x, int y, int w, int h, const char *c)
{
	ReplicaH(x, y, c, w);		  // fila 1
	ReplicaH(x, y + h, c, w);	  // fila 2
	ReplicaV(x, y, c, h);		  // columna 1
	ReplicaV(x + w - 1, y, c, h); // columna 2
}

void PonerColorA(int color, int colorf)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
}
void PonerColorB(int color, int colorf)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf | BACKGROUND_INTENSITY);
}

void PonerColorC(int color, int colorf)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf);
}

MENU::MENU()
{
	con = 0;
	COLOR = 15;
	COLORB = 21;
	OPC_SEL = 1;
	ESPACIO = 1;
}

MENU::~MENU()
{
}

void MENU::Poner_Color(int color, int colorb)
{
	COLOR = color;
	COLORB = colorb;
}

void MENU::Agregar_Items(const char *txt, int index)
{
	Opcion[index].id = index;
	sprintf(Opcion[index].name, "%s", txt);
	con = con + 1;
}

void MENU::Poner_Espacio(int s)
{
	ESPACIO = s;
}

int MENU::Dibujar(int x, int y)
{
	int tecla;
	bool Sel = false;
	int FILA;
	while (tecla != 13)
	{
		FILA = y;
		for (int i = 1; i < con + 1; i++)
		{
			PonerColorA(COLOR, COLORB);

			if (OPC_SEL == i)
			{
				PonerColorA(15, 2);
			}
			GotoXY(x, FILA);
			printf("%s", Opcion[i].name);
			FILA = FILA + ESPACIO;
		}
		PonerColorC(15, 0);

		tecla = _getch();

		switch (tecla)
		{
		case 72: // Arriba
			OPC_SEL = OPC_SEL - 1;
			if (OPC_SEL < 1)
			{
				OPC_SEL = 1;
			}
			break;
		case 80: // Abajo
			OPC_SEL = OPC_SEL + 1;
			if (OPC_SEL > con)
			{
				OPC_SEL = con;
			}
			break;
		}
	}

	return OPC_SEL;
}

/* using namespace std;
int main()
{
	PonerColorC(15,10);
	cout << "Hola" <<endl;
	return 0;
} */
