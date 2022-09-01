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

#include "Grafico.cpp"
#include "Juego.cpp"
#include "Pacman.h"

Grafico graficoPacmanJuego;

Pacman::Pacman()
{
}

void Pacman::imprimirPacman(int i, int j)
{
	setColor(color[0]);
	graficoPacmanJuego.SetRadio(7.5);
	if (dir == 0)
	{
		tablero[i][j] = 255;//118;
		graficoPacmanJuego.DibujarPacman(106+9*i,90+20*j,graficoPacmanJuego.AMARILLO,0);
	}
	else if (dir == 1)
	{
		tablero[i][j] = 255;//94;
		graficoPacmanJuego.DibujarPacman(106+9*i,90+20*j,graficoPacmanJuego.AMARILLO,0);
	}
	else if (dir == 2)
	{
		tablero[i][j] = 255;//60;
		graficoPacmanJuego.DibujarPacman(106+9*i,90+20*j,graficoPacmanJuego.AMARILLO,0);
	}
	else if (dir == 3)
	{
		tablero[i][j] = 255;//62;
		graficoPacmanJuego.DibujarPacman(106+9*i,90+20*j,graficoPacmanJuego.AMARILLO,0);
	}

	gotoxy(11 + i, 4 + j);
	cout << tablero[i][j];
}

// Funcion para BORRAR PAC-MAN
void Pacman::borrarPacman(int i, int j)
{
	tablero[i][j] = 32;
	gotoxy(11 + i, 4 + j);
	cout << tablero[i][j];
}

// Funcion para los PUNTOS DE COMIDA
void Pacman::puntosComida(int i, int j)
{

	if (dir == 0 && comida[j - 1][i] == 1)
	{
		comida[j - 1][i] = 0;
		puntos = puntos + 10;
	}
	else if (dir == 1 && comida[j + 1][i] == 1)
	{
		comida[j + 1][i] = 0;
		puntos = puntos + 10;
	}
	else if (dir == 2 && comida[j][i + 1] == 1)
	{
		comida[j][i + 1] = 0;
		puntos = puntos + 10;
	}
	else if (dir == 3 && comida[j][i - 1] == 1)
	{

		comida[j][i - 1] = 0;
		puntos = puntos + 10;
	}
}

// Funcion MOVER ARRIBA PAC-MAN
void Pacman::movArribaPacman(int &i, int &j)
{

	if (dir == 0 && (space[j - 1][i] == 0 || space[j - 1][i] == 2))
	{
		puntosComida(i, j);
		marcador();
		borrarPacman(i, j);
		j = j - 1;
	}
}

// Funcion MOVER DERECHA PAC-MAN
void Pacman::movAbajoPacman(int &i, int &j)
{

	if (dir == 1 && (space[j + 1][i] == 0 || space[j + 1][i] == 2))
	{
		puntosComida(i, j);
		marcador();
		borrarPacman(i, j);
		j = j + 1;
	}
}

// Funcion para MOVER IZQUIERDA PAC-MAN
void Pacman::movIzquierdaPacman(int &i, int &j)
{

	if (dir == 3 && (space[j][i - 1] == 0 || space[j][i - 1] == 2 || space[j][i - 1] == 3))
	{
		puntosComida(i, j);
		marcador();
		borrarPacman(i, j);
		i = i - 1;
	}
}

// Funcion para MOVER DERECHA PAC-MAN
void Pacman::movDerechaPacman(int &i, int &j)
{

	if (dir == 2 && (space[j][i + 1] == 0 || space[j][i + 1] == 2 || space[j][i + 1] == 3))
	{
		puntosComida(i, j);
		marcador();
		borrarPacman(i, j);
		i = i + 1;
	}
}

// Funcion para MOVER PASADIZO IZQUIERDO PAC-MAN
void Pacman::movPasadizoIzq(int &i, int &j)
{
	if (i == 0)
	{
		borrarPacman(i, j);
		i = 42;
		movIzquierdaPacman(i, j);
	}
}

// Funcion para MOVER PASADIZO DERECHO PAC-MAN
void Pacman::movPasadizoDer(int &i, int &j)
{
	if (i == 42)
	{
		borrarPacman(i, j);
		i = 0;
		movDerechaPacman(i, j);
	}
}

// Funcion Mover Pacman
void Pacman::mover(int &i, int &j)
{
	// Movimiento para Arriba
	movArribaPacman(i, j);

	// Movimiento para Abajo
	movAbajoPacman(i, j);

	// Movimiento para la Izquierda
	movIzquierdaPacman(i, j);

	// Movimiento para la Derecha
	movDerechaPacman(i, j);

	imprimirPacman(i, j);
	Sleep(100);

	// Movimiento por el pasadizo. Pasadizo por la izquierda
	movPasadizoIzq(i, j);

	// Movimiento por el pasadizo. Pasadizo por la derecha
	movPasadizoDer(i, j);
}
