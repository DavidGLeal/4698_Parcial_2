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
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <math.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

#define UNO 49
#define DOS 50
#define TRES 51
#define CUATRO 52

using namespace std;

/*========================================= VARIABLES GLOBALES   =========================================   */
class Juego
{
private:

public:
	int puntaje = 20;
	int vidas = 0;
	int tmp = 0;
	void menuYouWin();
	void menuYouLose();
	void generarRespaldo(int puntaje);
	void recuperarPuntaje();
};

int puntos = 20;
int dirMenu = 0;
int dir = 0;
int vida = 3;
int nivel = 1;
int tiempo = 0;

char tecla;
char opcion;
fstream rec;

// Vector con los colores a utilizar en el programa
int color[8] = {
	14, //[0]	Color PacMan 	(Amarillo)
	12, //[1]	Color Blinky 	(Rojo)
	13, //[2]	Color Pinky		(Rosado)
	10, //[3]	Color Inky		(Verde)
	11, //[4]	Color Clyde		(Azul Claro)
	15, //[5]	Color 			(Blanco Brillante)
	9,	//[6]	Color Mapa		(Azul)
	7	//[7]	Color Monedas	(Blanco Palido)
};

/*========================================= VARIABLES DE SONIDO   =========================================   */
void Juego::recuperarPuntaje()
{
	int nuevo = 10;
	rec.flush();
   	rec.open("recuperacion.txt", ios::in);
   	rec >> nuevo;
   	rec.close();
	puntos += nuevo;
}
void Juego::generarRespaldo(int puntaje)
{
   rec.flush();
   rec.open("recuperacion.txt", ios::out);
   rec << puntaje;
   rec.close();
}
// Funcion para usar gotoxy
void gotoxy(int x, int y)
{
	HANDLE hCon;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

// Funcion para eliminar el cursor de la ventaja de ejecucion
void ocultarCursor()
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 100;
	cci.bVisible = FALSE; // EL FALSE hace que no se vea, con TRUE se vera con el tamano que indique dwSize
	SetConsoleCursorInfo(hcon, &cci);
}

// Funcion para definir colores (pasando como parametro el vector "color")
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*=====================================  MATRICES DE MENU  =====================================*/

/*===========  MATRIZ PAC-MAN   =========== */ // Ubicada en Menu Principal
char titulo[6][43] = {
	"        PPPPP PPPPP PPPPPP PPPPP",
	"        P     P     P    P P",
	"        PPPPP PPPPP PPPPPP PPPPP",
	"        P         P PP     P",
	"        PPPPP PPPPP PP     PPPPP"};

/*===========  MATRIZ FANTASMAS   =========== */ // Ubicada en Menu Principal
char tituloFantasmas[4][35] = {
	" aXXXa    eWWWe    gTTTg    iUUUi ",
	"aXdcXdc  eWdcWdc  gTdcTdc  iUdcUdc",
	"XXXXXXX  WWWWWWW  TTTTTTT  UUUUUUU",
	"XbXbXbX  WfWfWfW  ThThThT  UjUjUjU"};

/*========  MATRIZ FANTASMAS AZULES  ========= */ // Ubicada en CREDITOS
char fantasmasAzules[4][35] = {
	" cYYYc             aXXXa    aXXXa ",
	"YYYd       ee     aXaXaXa  aXaXaXa",
	"YYYc       ff     XbababX  XbababX",
	" dYYYd            XbXbXbX  XbXbXbX"};

// Funcion para LLENAR MATRIZ TITULO PACMAN (titulo en el menu)
void llenarTitulo()
{
	for (int i = 0; i < 43; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			gotoxy(12 + i, 5 + j);
			if (titulo[j][i] == 'P')
			{
				setColor(color[3]);
				cout << char(219);
			}
			else if (titulo[j][i] == 'O')
			{
				setColor(color[3]);
				cout << char(223);
			}
			else if (titulo[j][i] == 'Q')
			{
				setColor(color[3]);
				cout << char(220);
			}
			else
			{
				cout << char();
			}
		}
	}
}

// Funcion para LLENAR MATRIZ FANTASMAS (en el menu)
void llenarFantasmas()
{
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(14 + i, 25 + j);

			// Blinky
			if (tituloFantasmas[j][i] == 'X')
			{
				setColor(color[1]);
				cout << char(219);
			}
			else if (tituloFantasmas[j][i] == 'a')
			{
				setColor(color[1]);
				cout << char(220);
			}
			else if (tituloFantasmas[j][i] == 'b')
			{
				setColor(color[1]);
				cout << char(223);
			}

			// Pinky
			else if (tituloFantasmas[j][i] == 'W')
			{
				setColor(color[2]);
				cout << char(219);
			}
			else if (tituloFantasmas[j][i] == 'e')
			{
				setColor(color[2]);
				cout << char(220);
			}
			else if (tituloFantasmas[j][i] == 'f')
			{
				setColor(color[2]);
				cout << char(223);
			}

			// Clyde
			else if (tituloFantasmas[j][i] == 'T')
			{
				setColor(color[4]);
				cout << char(219);
			}
			else if (tituloFantasmas[j][i] == 'g')
			{
				setColor(color[4]);
				cout << char(220);
			}
			else if (tituloFantasmas[j][i] == 'h')
			{
				setColor(color[4]);
				cout << char(223);
			}

			// Inky
			else if (tituloFantasmas[j][i] == 'U')
			{
				setColor(color[3]);
				cout << char(219);
			}
			else if (tituloFantasmas[j][i] == 'i')
			{
				setColor(color[3]);
				cout << char(220);
			}
			else if (tituloFantasmas[j][i] == 'j')
			{
				setColor(color[3]);
				cout << char(223);
			}

			// Ojos
			else if (tituloFantasmas[j][i] == 'c')
			{
				setColor(color[5]);
				cout << char(223);
			}
			else if (tituloFantasmas[j][i] == 'd')
			{
				setColor(color[5]);
				cout << char(219);
			}

			else
			{
				cout << char();
			}
		}
	}
}

// Funcion para LLENAR MATRIZ FANTASMAS AZULES
void llenarFantasmasAzules()
{

	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(14 + i, 30 + j);

			// Fantasmas
			if (fantasmasAzules[j][i] == 'X')
			{
				setColor(color[6]);
				cout << char(219);
			}
			else if (fantasmasAzules[j][i] == 'a')
			{
				setColor(color[6]);
				cout << char(220);
			}
			else if (fantasmasAzules[j][i] == 'b')
			{
				setColor(color[6]);
				cout << char(223);
			}

			// PacMan
			else if (fantasmasAzules[j][i] == 'Y')
			{
				setColor(color[0]);
				cout << char(219);
			}
			else if (fantasmasAzules[j][i] == 'c')
			{
				setColor(color[0]);
				cout << char(220);
			}
			else if (fantasmasAzules[j][i] == 'd')
			{
				setColor(color[0]);
				cout << char(223);
			}

			// Punto
			else if (fantasmasAzules[j][i] == 'e')
			{
				setColor(color[5]);
				cout << char(220);
			}
			else if (fantasmasAzules[j][i] == 'f')
			{
				setColor(color[5]);
				cout << char(223);
			}
			else
			{
				cout << char();
			}
		}
	}
}

/*=====================================  TABLERO PRINIPAL  =====================================*/

// tablero [filas][columnas]
char tablero[29][44] = {
	"AxxxxxxxxxxxxxxxxxxxB AxxxxxxxxxxxxxxxxxxxB",
	"I________+__________I I__________+________I",
	"I_AxxxxxB_AxxxxxxxB_I I_AxxxxxxxB_AxxxxxB_I",
	"I_I     I_I       I_I I_I       I_I     I_I",
	"I_DxxxxxC_DxxxxxxxC_DxC_DxxxxxxxC_DxxxxxC_I",
	"I+_______+___+_____+___+_____+___+_______+I",
	"I_AxxxxxB_AxB_AxxxxxxxxxxxxxB_AxB_AxxxxxB_I",
	"I_DxxxxxC_I I_DxxxxB   AxxxxC_I I_DxxxxxC_I",
	"I________+I I______I   I______I I+________I",
	"DxxxxxxxB_I DxxxxB I   I AxxxxC I_AxxxxxxxC",
	"        I_I AxxxxC DxxxC DxxxxB I_I        ",
	"        I_I I                 I I_I        ",
	"xxxxxxxxC_DxC Axxxxxx xxxxxxB DxC_Dxxxxxxxx",
	"         +    I      *      I    +         ",
	"xxxxxxxxB_AxB DxxxxxxxxxxxxxC AxB_Axxxxxxxx",
	"        I_I I                 I I_I        ",
	"        I_I I AxxxxxxxxxxxxxB I I_I        ",
	"AxxxxxxxC_DxC DxxxxB   AxxxxC DxC_DxxxxxxxB",
	"I________+_________I   I_________+________I",
	"I_AxxxxxB_AxxxxxxB_I   I_AxxxxxxB_AxxxxxB_I",
	"I_DxxxB I_DxxxxxxC_DxxxC_DxxxxxxC_I AxxxC_I",
	"I_____I I+________+_____+________+I I_____I",
	"DxxxB_I I_AxB_AxxxxxxxxxxxxxB_AxB_I I_AxxxC",
	"AxxxC_DxC_I I_DxxxxB   AxxxxC_I I_DxC_DxxxB",
	"I____+____I I______I   I______I I____+____I",
	"I_AxxxxxxxC DxxxxB_I   I_AxxxxC DxxxxxxxB_I",
	"I_DxxxxxxxxxxxxxxC_DxxxC_DxxxxxxxxxxxxxxC_I",
	"I_________________+_____+_________________I",
	"DxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxC",
};

int space[29][44];
int comida[29][44];

/*
	=============================  SIGNIFICADO DE LOS VALORES DE LAS MATRICES  =============================

		* MATRIZ TABLERO (Matriz base)
			El x : Se encuentra un muro horizontal en ese espacio
			El _ : Se encuentra un punto de comida
			El' ': Se encuentra un espacio vacio
			El I : Se encuentra un muro vertical
			El A : Se encuentra una esquina superio izquierda del muro
			El B : Se encuentra una esquina superio derecha del muro
			El C : Se encuentra una esquina inferior derecha del muro
			El D : Se encuentra una esquina inferior izquierda del muro
			El * : Se encuentra la salida de la Guarida de los Fantasmas
			El + : Se encuentra un cruce de 3 alternativas, no hay punto de comida
		* MATRIZ SPACE
			El 1: Se encuentra un muro en ese espacio
			El 2: Se encuentra un cruce de 3 alternativas
			El 3: Se encuentra el comienzo del pasadio
			El 4: Se encuentra la salida de la Guarida de los Fantasmas
		* MATRIZ COMIDA
			El 0: Ese espacio no contiene ningun punto
			El 1: Se encuentra un punto de comida
			El 2: Se encuentra una muro
			El 3:
*/

// Funcion para LLENAR EL TABLERO (recorre Primero las columnas y luego cada fila)
void llenarMapa()
{
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 43; j++)
		{

			// COLOCAR(11+J)(4+I)
			gotoxy(11 + j, 4 + i);

			if (tablero[i][j] == 'x')
			{
				setColor(color[6]);
				cout << char(205);
				space[i][j] = 1;
				comida[i][j] = 2;
			}
			else if (tablero[i][j] == '_')
			{
				setColor(color[7]);
				cout << char(250);
				space[i][j] = 0;
				comida[i][j] = 1;
			}
			else if (tablero[i][j] == ' ')
			{
				space[i][j] = 0;
				comida[i][j] = 0;
			}
			else if (tablero[i][j] == 'I')
			{
				setColor(color[6]);
				cout << char(186);
				space[i][j] = 1;
				comida[i][j] = 2;
			}
			else if (tablero[i][j] == 'A')
			{
				setColor(color[6]);
				cout << char(201);
				space[i][j] = 1;
				comida[i][j] = 2;
			}
			else if (tablero[i][j] == 'B')
			{
				setColor(color[6]);
				cout << char(187);
				space[i][j] = 1;
				comida[i][j] = 2;
			}
			else if (tablero[i][j] == 'C')
			{
				setColor(color[6]);
				cout << char(188);
				space[i][j] = 1;
				comida[i][j] = 2;
			}
			else if (tablero[i][j] == 'D')
			{
				setColor(color[6]);
				cout << char(200);
				space[i][j] = 1;
				comida[i][j] = 2;
			}
			else if (tablero[i][j] == '*')
			{
				setColor(color[5]);
				cout << char(32);
				space[i][j] = 4;
				comida[i][j] = 0;
			}
			else if (tablero[i][j] == '+')
			{
				setColor(color[5]);
				cout << char(250);
				space[i][j] = 2;
				comida[i][j] = 1;
			}
		}
	}
	// Valor para Pasadizo
	space[13][0] = 3;
	space[13][42] = 3;
	// space[13][26] = 5;
}

/*===================================  IMPRIMIR MATRICES NO VISIBLES  ===================================*/

void imprimirSpace()
{

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 43; j++)
		{
			gotoxy(11 + j, 4 + i); // COLOCAR(11+J)(4+I)

			if (space[i][j] == 0)
			{
				setColor(color[5]);
			}
			else if (space[i][j] == 1)
			{
				setColor(color[1]);
			}
			else if (space[i][j] == 3)
			{
				setColor(color[3]);
			}
			else if (space[i][j] == 4)
			{
				setColor(color[4]);
			}
			cout << space[i][j];
		}
		cout << endl;
	}
}

void imprimirComida()
{

	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 43; j++)
		{
			gotoxy(11 + j, 4 + i); // COLOCAR(11+J)(4+I)

			if (comida[i][j] == 0)
			{
				setColor(color[0]);
			}
			else if (comida[i][j] == 1)
			{
				setColor(color[1]);
			}
			else if (comida[i][j] == 2)
			{
				setColor(color[4]);
			}
			else if (comida[i][j] == 3)
			{
				setColor(color[3]);
			}
			cout << comida[i][j];
		}
		cout << endl;
	}
}

/*=====================================  TECLADO  =====================================*/

// Funcion TECLAS EN MENU
void teclearMenu()
{

	opcion = getch();
	switch (opcion)
	{
	case UNO:
		dirMenu = 1; // Jugar
		break;

	case DOS:
		dirMenu = 2; // Ayuda
		break;

	case TRES:
		dirMenu = 3; // Creditos
		break;

	case CUATRO: // Salir
		dirMenu = 4;
		break;
	}
}

// Funcion TECLAS EN JUEGO
void teclear()
{
	tiempo = tiempo + 1;
	if (kbhit())
	{
		tecla = getch();
		switch (tecla)
		{
		case UP:
			dir = 0;
			break;

		case DOWN:
			dir = 1;
			break;

		case RIGHT:
			dir = 2;
			break;

		case LEFT:
			dir = 3;
			break;

		case ESC:
			dir = 4;
			break;
		}
	}
}

/*===================================  FUNCIONES MENU  =====================================*/

// Funcion para MENU PRINCIPAL
void menu()
{

	llenarTitulo();
	llenarFantasmas();

	setColor(color[5]);
	gotoxy(21, 15);
	cout << "1.  Empezar a jugar";

	setColor(color[3]);
	gotoxy(0, 11);
	cout << "\t\t    " << "*Proyecto Tercer Parcial*";
	
	setColor(color[2]);
	gotoxy(0, 13);
	cout << "\t\t\t   " << "PAC - MAN";

	teclearMenu();
}

/*===================================  MARCADOR FIJO  ===================================*/

void marcadorFijo()
{

	setColor(color[0]);

	gotoxy(29, 1);
	cout << "PAC-MAN";

	setColor(color[5]);

	gotoxy(12, 2);
	cout << "PUNTAJE";
	gotoxy(43, 2);
	cout << "TIEMPO";
	gotoxy(12, 34);
	cout << "VIDAS";
}

/*================================== MARCADOR CAMBIABLE ==================================*/

void marcador()
{

	// Puntos
	gotoxy(20, 2);
	setColor(color[0]);
	cout << puntos;

	// 	Tiempo
	gotoxy(50, 2);
	setColor(color[0]);
	cout << tiempo << " ms";

	// Vidas

	gotoxy(19, 34);
	cout << vida << " < ";

	// Nivel

	gotoxy(29, 3);
	cout << "Nivel " << nivel;
}

/*========================  PANTALLAS DE GANAR Y PERDER  ======================== */

// Pantalla de GANAR
void Juego::menuYouWin()
{

	system("cls");

	llenarTitulo();
	llenarFantasmasAzules();

	gotoxy(28, 15);
	setColor(color[0]);
	cout << "Ganaste!";

	setColor(color[0]);
	gotoxy(21, 19);
	cout << "Tu puntaje es:  ";
	setColor(color[5]);
	cout << puntos;
	this->puntaje = puntos;
	this->tmp = tiempo;
	this->vidas = vida;
	generarRespaldo(puntos);

	setColor(color[0]);
	gotoxy(13, 21);
	cout << "Presiona ESC para salir";
	teclear();
	
	if (dir == 4){
		return;
	}
}

// Pantalla de PERDER
void Juego::menuYouLose()
{

	system("cls");

	llenarTitulo();
	llenarFantasmas();

	gotoxy(27, 15);
	setColor(color[0]);
	cout << "Perdiste! D:";

	setColor(color[0]);
	gotoxy(10, 21);
	cout << "           GRACIAS POR JUGAR!";

	setColor(color[0]);
	gotoxy(21, 19);
	cout << "Tu puntaje es:  ";
	setColor(color[5]);
	cout << puntos;
	this->puntaje = puntos;
	generarRespaldo(puntos);
	
	setColor(color[0]);
	gotoxy(13, 23);
	cout << "       Presiona ESC para salir";
	teclear();
	
	if (dir == 4){
		return;
	}

}

