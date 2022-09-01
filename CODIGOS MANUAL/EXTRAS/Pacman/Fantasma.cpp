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
#include "Fantasma.h"
#include "Juego.cpp"

/*=====================================  FANTASMAS  =====================================*/

/*=======================================  CLYDE  =======================================*/
Fantasma::Fantasma(/* args */)
{
}

// Funcion para IMPRIMIR CLYDE
void Fantasma::imprimirClyde(int iC, int jC)
{
	setColor(color[4]);
	tablero[iC][jC] = 67;
	gotoxy(11 + iC, 4 + jC);
	cout << tablero[iC][jC];
}

// Hay veces en que deja una moneda sin imprimir, en movimientos horizontales, remplazar los borrarClyde por esta funcion para ver los errores

// Funcion para REIMPRIMIR COMIDA detras de CLYDE
void Fantasma::imprimirComidaClyde(int iC, int jC, char movClyde)
{

	if (movClyde == UP)
	{ // BUENA
		if (comida[jC + 1][iC] == 1)
		{
			setColor(color[7]);
			gotoxy(11 + iC, 4 + (jC + 1));
			cout << char(250);
		}
		else if (comida[jC + 1][iC] == 0)
		{
			setColor(color[7]);
			gotoxy(11 + iC, 4 + (jC + 1));
			cout << char(32);
		}
	}

	else if (movClyde == DOWN)
	{ // BUENA
		if (comida[jC - 1][iC] == 1)
		{
			setColor(color[7]);
			gotoxy(11 + iC, 4 + (jC - 1));
			cout << char(250);
		}
		else if (comida[jC - 1][iC] == 0)
		{
			setColor(color[7]);
			gotoxy(11 + iC, 4 + (jC - 1));
			cout << char(32);
		}
	}

	else if (movClyde == LEFT)
	{
		if (comida[jC][iC + 1] == 1)
		{
			setColor(color[7]);
			gotoxy(11 + (iC + 1), 4 + jC);
			cout << char(250);
		}
		else if (comida[jC][iC + 1] == 0)
		{
			setColor(color[7]);
			gotoxy(11 + (iC + 1), 4 + jC);
			cout << char(32);
		}
	}

	else if (movClyde == RIGHT)
	{
		if (comida[jC][iC - 1] == 1)
		{
			setColor(color[7]);
			gotoxy(11 + (iC - 1), 4 + jC);
			cout << char(250);
		}
		else if (comida[jC][iC - 1] == 0)
		{
			setColor(color[7]);
			gotoxy(11 + (iC - 1), 4 + jC);
			cout << char(32);
		}
	}
}

// Funcion para BORRAR CLYDE
void Fantasma::borrarClyde(int iC, int jC)
{
	setColor(color[5]);
	tablero[iC][jC] = 32;
	gotoxy(11 + iC, 4 + jC);
	cout << tablero[iC][jC];
}

// Funcion RANDOM CLYDE
void Fantasma::randomClyde(int &movClydeAux, char &movClyde)
{

	movClydeAux = rand() % 4;

	if (movClydeAux == 0)
	{
		movClyde = UP;
	}
	else if (movClydeAux == 1)
	{
		movClyde = RIGHT;
	}
	else if (movClydeAux == 2)
	{
		movClyde = DOWN;
	}
	else if (movClydeAux == 3)
	{
		movClyde = LEFT;
	}
}

// Funcion CHOQUE CLYDE - PACMAN
// ARREGLAR
void Fantasma::choqueClyde(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj)
{

	// if(i == iC && j == jC )

	if (i == iC && j == jC || (movClyde == UP && dir == 1 || movClyde == DOWN && dir == 0 || movClyde == LEFT && dir == 3 || movClyde == RIGHT && dir == 2) && (jC == anteriorpj && iC == anteriorpi))
	{
		if (comida[i][j] == 0)
		{
			gotoxy(11 + i, 4 + j);
			cout << char(32);
		}

		i = 21;
		j = 21;
		iC = 26;
		jC = 13;
		dir = 7;
		vida = vida - 1;
	}
}

// Funcion MOVER ARRIBA CLYDE
void Fantasma::movArribaClyde(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == UP)
	{

		if (space[jC - 1][iC] == 0 || space[jC - 1][iC] == 2)
		{
			borrarClyde(iC, jC);
			jC = jC - 1;

			if (space[jC - 1][iC] == 2)
			{
				randomClyde(movClydeAux, movClyde);
			}
		}
		else
		{
			randomClyde(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER ABAJO CLYDE
void Fantasma::movAbajoClyde(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == DOWN)
	{

		if (space[jC + 1][iC] == 0 || space[jC + 1][iC] == 2)
		{
			borrarClyde(iC, jC);
			jC = jC + 1;

			if (space[jC + 1][iC] == 2)
			{
				randomClyde(movClydeAux, movClyde);
			}
		}
		else
		{
			randomClyde(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER IZQUIERDA CLYDE
void Fantasma::movIzquierdaClyde(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == LEFT)
	{

		if (space[jC][iC - 1] == 0 || space[jC][iC - 1] == 2)
		{
			borrarClyde(iC, jC);
			iC = iC - 1;

			if (space[jC][iC - 1] == 2)
			{
				randomClyde(movClydeAux, movClyde);
			}
		}
		else if (space[jC][iC - 1] == 4)
		{
			borrarClyde(iC, jC);
			iC = iC - 1;
			movClydeAux = 0;
			movClyde = UP;
		}
		else
		{
			randomClyde(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER DERECHA CLYDE
void Fantasma::movDerechaClyde(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == RIGHT)
	{

		if (space[jC][iC + 1] == 0 || space[jC][iC + 1] == 2)
		{
			borrarClyde(iC, jC);
			iC = iC + 1;

			if (space[jC][iC + 1] == 2)
			{
				randomClyde(movClydeAux, movClyde);
			}
		}
		else
		{

			randomClyde(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER CLYDE
void Fantasma::moverClyde(int &iC, int &jC, char &movClyde, int &movClydeAux)
{

	// Mover Arriba Clyde
	movArribaClyde(iC, jC, movClydeAux, movClyde);

	// Mover Abajo Clyde
	movAbajoClyde(iC, jC, movClydeAux, movClyde);

	// Mover Izquierda Clyde
	movIzquierdaClyde(iC, jC, movClydeAux, movClyde);

	// Mover Derecha
	movDerechaClyde(iC, jC, movClydeAux, movClyde);

	imprimirClyde(iC, jC);
	imprimirComidaClyde(iC, jC, movClyde);
}

/*=======================================  BLINKY  =======================================*/

// Funcion IMPRIMIR BLINKY
void Fantasma::imprimirBlinky(int iB, int jB)
{
	setColor(color[1]);
	tablero[iB][jB] = 66;
	gotoxy(11 + iB, 4 + jB);
	cout << tablero[iB][jB];
}

// Funcion BORRAR BLINKY
void Fantasma::borrarBlinky(int iB, int jB)
{

	setColor(color[5]);
	tablero[iB][jB] = 32;
	gotoxy(11 + iB, 4 + jB);
	cout << tablero[iB][jB];
}

void Fantasma::choqueBlinky(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj)
{

	// if(i == iC && j == jC )

	if (i == iC && j == jC)
	{
		if (comida[i][j] == 0)
		{
			gotoxy(11 + i, 4 + j);
			cout << char(32);
		}

		i = 21;
		j = 21;
		iC = 21;
		jC = 11;
		dir = 5;
		vida = vida - 1;
	}
}

// Funcion MOVER IZQUIERDA BLINKY
void Fantasma::movIzquierdaBlinky(int &iB, int &jB, int i, int j)
{

	if (i < iB)
	{
		if (space[jB][iB - 1] == 0 || space[jB][iB - 1] == 2)
		{
			borrarBlinky(iB, jB);
			iB = iB - 1;
		}
		else if (space[jB][iB - 1] == 1)
		{

			// Igual a rutina movArribaBlinky
			if (j < jB)
			{
				if (space[jB - 1][iB] == 0 || space[jB - 1][iB] == 2)
				{
					borrarBlinky(iB, jB);
					jB = jB - 1;
				}
			}
			// Igual a rutina movAbajoBlinky
			else if (j > jB)
			{
				if (space[jB + 1][iB] == 0 || space[jB + 1][iB] == 2)
				{
					borrarBlinky(iB, jB);
					jB = jB + 1;
				}
			}
		}
	}
	if (comida[jB][iB + 1] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + (iB + 1), 4 + jB);
		cout << char(250);
	}
	else if (comida[jB][iB + 1] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + (iB + 1), 4 + jB);
		cout << char(32);
	}
}

// Funcion MOVER DERECHA BLINKY
void Fantasma::movDerechaBlinky(int &iB, int &jB, int i, int j)
{

	if (i > iB)
	{
		if (space[jB][iB + 1] == 0 || space[jB][iB + 1] == 2)
		{
			borrarBlinky(iB, jB);
			iB = iB + 1;
		}
		else if (space[jB][iB + 1] == 1)
		{

			// Igual a rutina movArribaBlinky
			if (j < jB)
			{
				if (space[jB - 1][iB] == 0 || space[jB - 1][iB] == 2)
				{
					borrarBlinky(iB, jB);
					jB = jB - 1;
				}
			}
			// Igual a rutina movAbajoBlinky
			else if (j > jB)
			{
				if (space[jB + 1][iB] == 0 || space[jB + 1][iB] == 2)
				{
					borrarBlinky(iB, jB);
					jB = jB + 1;
				}
			}
		}
	}
	if (comida[jB][iB - 1] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + (iB - 1), 4 + jB);
		cout << char(250);
	}
	else if (comida[jB][iB - 1] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + (iB - 1), 4 + jB);
		cout << char(32);
	}
}

// Funcion MOVER ARRIBA BLINKY
void Fantasma::movArribaBlinky(int &iB, int &jB, int i, int j)
{

	if (j < jB)
	{
		if (space[jB - 1][iB] == 0 || space[jB - 1][iB] == 2)
		{
			borrarBlinky(iB, jB);
			jB = jB - 1;
		}
		else if (space[jB - 1][iB] == 1)
		{
			movIzquierdaBlinky(iB, jB, i, j);
			movDerechaBlinky(iB, jB, i, j);
		}
	}
}

// Funcion MOVER ABAJO BLYNKY
void Fantasma::movAbajoBlinky(int &iB, int &jB, int i, int j)
{

	if (j > jB)
	{
		if (space[jB + 1][iB] == 0 || space[jB + 1][iB] == 2)
		{
			borrarBlinky(iB, jB);
			jB = jB + 1;
		}
		else if (space[jB + 1][iB] == 1)
		{
			movIzquierdaBlinky(iB, jB, i, j);
			movDerechaBlinky(iB, jB, i, j);
		}
	}
}

// Funcion MOVER BLINKY
void Fantasma::moverBlinky(int &iB, int &jB, int i, int j, int dir, char &movClyde)
{

	// COLOCAR LO DEL CUADERNO Y ADEMAS COLOCAR CUANDO i=iB

	// Para Hacer que Blinky se mueva correctamente cuando comience el juego
	if (space[jB + 2][iB] == 4)
	{
		if (dir == 2)
		{
			movDerechaBlinky(iB, jB, i, j);
		}
		else if (dir == 3)
		{
			movIzquierdaBlinky(iB, jB, i, j);
		}
	}

	// Mover Arriba Blinky
	movArribaBlinky(iB, jB, i, j);
	if (comida[jB + 1][iB] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB + 1));
		cout << char(250);
	}
	else if (comida[jB + 1][iB] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB + 1));
		cout << char(32);
	}

	// Mover Abajo Blinky
	movAbajoBlinky(iB, jB, i, j);
	if (comida[jB - 1][iB] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB - 1));
		cout << char(250);
	}
	else if (comida[jB - 1][iB] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB - 1));
		cout << char(32);
	}

	if (j == jB)
	{
		// Mover Izquierda Blinky
		movIzquierdaBlinky(iB, jB, i, j);
		// Mover Derecha Blinky
		movDerechaBlinky(iB, jB, i, j);
	}

	imprimirBlinky(iB, jB);
	// imprimirComidaClyde(iB, jB, movClyde);
}

/*=======================================  PINKY  =======================================*/

// Funcion Imprimir Pinky
void Fantasma::imprimirPinky(int iP, int jP)
{
	setColor(color[2]);
	tablero[iP][jP] = 80;
	gotoxy(11 + iP, 4 + jP);
	cout << tablero[iP][jP];
}

void Fantasma::borrarPinky(int iP, int jP)
{

	setColor(color[5]);
	tablero[iP][jP] = 32;
	gotoxy(11 + iP, 4 + jP);
	cout << tablero[iP][jP];
}

void Fantasma::choquePinky(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj)
{

	// if(i == iC && j == jC )

	if (i == iC && j == jC)
	{
		if (comida[i][j] == 0)
		{
			gotoxy(11 + i, 4 + j);
			cout << char(32);
		}

		i = 21;
		j = 21;
		iC = 21;
		jC = 11;
		dir = 5;
		vida = vida - 1;
	}
}

// Funcion MOVER IZQUIERDA BLINKY
void Fantasma::movIzquierdaPinky(int &iB, int &jB, int i, int j)
{

	if (i < iB)
	{
		if (space[jB][iB - 1] == 0 || space[jB][iB - 1] == 2)
		{
			borrarPinky(iB, jB);
			iB = iB - 1;
		}
		else if (space[jB][iB - 1] == 1)
		{

			// Igual a rutina movArribaBlinky
			if (j < jB)
			{
				if (space[jB - 1][iB] == 0 || space[jB - 1][iB] == 2)
				{
					borrarPinky(iB, jB);
					jB = jB - 1;
				}
			}
			// Igual a rutina movAbajoBlinky
			else if (j > jB)
			{
				if (space[jB + 1][iB] == 0 || space[jB + 1][iB] == 2)
				{
					borrarPinky(iB, jB);
					jB = jB + 1;
				}
			}
		}
	}
	if (comida[jB][iB + 1] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + (iB + 1), 4 + jB);
		cout << char(250);
	}
	else if (comida[jB][iB + 1] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + (iB + 1), 4 + jB);
		cout << char(32);
	}
}

// Funcion MOVER DERECHA BLINKY
void Fantasma::movDerechaPinky(int &iB, int &jB, int i, int j)
{

	if (i > iB)
	{
		if (space[jB][iB + 1] == 0 || space[jB][iB + 1] == 2)
		{
			borrarPinky(iB, jB);
			iB = iB + 1;
		}
		else if (space[jB][iB + 1] == 1)
		{

			// Igual a rutina movArribaBlinky
			if (j < jB)
			{
				if (space[jB - 1][iB] == 0 || space[jB - 1][iB] == 2)
				{
					borrarPinky(iB, jB);
					jB = jB - 1;
				}
			}
			// Igual a rutina movAbajoBlinky
			else if (j > jB)
			{
				if (space[jB + 1][iB] == 0 || space[jB + 1][iB] == 2)
				{
					borrarPinky(iB, jB);
					jB = jB + 1;
				}
			}
		}
	}
	if (comida[jB][iB + 1] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + (iB + 1), 4 + jB);
		cout << char(250);
	}
	else if (comida[jB][iB + 1] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + (iB + 1), 4 + jB);
		cout << char(32);
	}
}

// Funcion MOVER ARRIBA BLINKY
void Fantasma::movArribaPinky(int &iB, int &jB, int i, int j)
{

	if (j < jB)
	{
		if (space[jB - 1][iB] == 0 || space[jB - 1][iB] == 2)
		{
			borrarPinky(iB, jB);
			jB = jB - 1;
		}
		else if (space[jB - 1][iB] == 1)
		{
			movDerechaPinky(iB, jB, i, j);
			movIzquierdaPinky(iB, jB, i, j);
		}
	}
}

// Funcion MOVER ABAJO BLYNKY
void Fantasma::movAbajoPinky(int &iB, int &jB, int i, int j)
{

	if (j > jB)
	{
		if (space[jB + 1][iB] == 0 || space[jB + 1][iB] == 2)
		{
			borrarPinky(iB, jB);
			jB = jB + 1;
		}
		else if (space[jB + 1][iB] == 1)
		{
			movDerechaPinky(iB, jB, i, j);
			movIzquierdaPinky(iB, jB, i, j);
		}
	}
}

// Funcion MOVER BLINKY
void Fantasma::moverPinky(int &iB, int &jB, int i, int j, int dir, char &movClyde)
{

	// COLOCAR LO DEL CUADERNO Y ADEMAS COLOCAR CUANDO i=iB

	// Para Hacer que Blinky se mueva correctamente cuando comience el juego
	if (space[jB + 2][iB] == 4)
	{
		if (dir == 3)
		{
			movDerechaPinky(iB, jB, i, j);
			if (comida[jB][iB + 1] == 1)
			{
				setColor(color[7]);
				gotoxy(11 + (iB + 1), 4 + jB);
				cout << char(250);
			}
			else if (comida[jB][iB + 1] == 0)
			{
				setColor(color[7]);
				gotoxy(11 + (iB + 1), 4 + jB);
				cout << char(32);
			}
		}
		else if (dir == 2)
		{
			movIzquierdaPinky(iB, jB, i, j);
		}
		else if (dir != 2 || dir != 3)
		{
			movDerechaPinky(iB, jB, i, j);
			if (comida[jB][iB + 1] == 1)
			{
				setColor(color[7]);
				gotoxy(11 + (iB + 1), 4 + jB);
				cout << char(250);
			}
			else if (comida[jB][iB + 1] == 0)
			{
				setColor(color[7]);
				gotoxy(11 + (iB + 1), 4 + jB);
				cout << char(32);
			}
		}
	}

	// Mover Arriba Blinky
	movArribaPinky(iB, jB, i, j);
	if (comida[jB + 1][iB] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB + 1));
		cout << char(250);
	}
	else if (comida[jB + 1][iB] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB + 1));
		cout << char(32);
	}

	// Mover Abajo Blinky
	movAbajoPinky(iB, jB, i, j);
	if (comida[jB - 1][iB] == 1)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB - 1));
		cout << char(250);
	}
	else if (comida[jB - 1][iB] == 0)
	{
		setColor(color[7]);
		gotoxy(11 + iB, 4 + (jB - 1));
		cout << char(32);
	}

	if (j == jB)
	{
		// Mover Izquierda Blinky
		movIzquierdaPinky(iB, jB, i, j);

		// Mover Derecha Blinky
		movDerechaPinky(iB, jB, i, j);
	}

	imprimirPinky(iB, jB);
	imprimirComidaClyde(iB, jB, movClyde);
}

/*=======================================  INKY  =======================================*/

// Funcion Imprimir Inky
void Fantasma::imprimirInky(int iI, int jI)
{
	setColor(color[3]);
	tablero[iI][jI] = 73;
	gotoxy(11 + iI, 4 + jI);
	cout << tablero[iI][jI];
}

void Fantasma::borrarInky(int i, int j)
{
	tablero[i][j] = 32;
	gotoxy(11 + i, 4 + j);
	cout << tablero[i][j];
}

void Fantasma::randomInky(int &movClydeAux, char &movClyde)
{

	movClydeAux = rand() % 4;

	if (movClydeAux == 0)
	{
		movClyde = LEFT;
	}
	else if (movClydeAux == 1)
	{
		movClyde = RIGHT;
	}
	else if (movClydeAux == 2)
	{
		movClyde = DOWN;
	}
	else if (movClydeAux == 3)
	{
		movClyde = UP;
	}
}

// Funcion CHOQUE CLYDE - PACMAN
// ARREGLAR
void Fantasma::choqueInky(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj)
{

	// if(i == iC && j == jC )

	if (i == iC && j == jC || (movClyde == UP && dir == 1 || movClyde == DOWN && dir == 0 || movClyde == LEFT && dir == 3 || movClyde == RIGHT && dir == 2) && (jC == anteriorpj && iC == anteriorpi))
	{
		if (comida[i][j] == 0)
		{
			gotoxy(11 + i, 4 + j);
			cout << char(32);
		}

		i = 21;
		j = 21;
		iC = 26;
		jC = 13;
		dir = 5;
		vida = vida - 1;
	}
}

// Funcion MOVER ARRIBA CLYDE
void Fantasma::movArribaInky(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == UP)
	{

		if (space[jC - 1][iC] == 0 || space[jC - 1][iC] == 2)
		{
			borrarInky(iC, jC);
			jC = jC - 1;

			if (space[jC - 1][iC] == 2)
			{
				randomInky(movClydeAux, movClyde);
			}
		}
		else
		{
			randomInky(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER ABAJO CLYDE
void Fantasma::movAbajoInky(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == DOWN)
	{

		if (space[jC + 1][iC] == 0 || space[jC + 1][iC] == 2)
		{
			borrarInky(iC, jC);
			jC = jC + 1;

			if (space[jC + 1][iC] == 2)
			{
				randomInky(movClydeAux, movClyde);
			}
		}
		else
		{
			randomInky(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER IZQUIERDA CLYDE
void Fantasma::movIzquierdaInky(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == LEFT)
	{

		if (space[jC][iC - 1] == 0 || space[jC][iC - 1] == 2)
		{
			borrarInky(iC, jC);
			iC = iC - 1;

			if (space[jC][iC - 1] == 2)
			{
				randomInky(movClydeAux, movClyde);
			}
		}
		else if (space[jC][iC - 1] == 4)
		{
			borrarInky(iC, jC);
			iC = iC - 1;
			movClydeAux = 0;
			movClyde = UP;
		}
		else
		{
			randomInky(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER DERECHA CLYDE
void Fantasma::movDerechaInky(int &iC, int &jC, int &movClydeAux, char &movClyde)
{

	if (movClyde == RIGHT)
	{

		if (space[jC][iC + 1] == 0 || space[jC][iC + 1] == 2)
		{
			borrarInky(iC, jC);
			iC = iC + 1;

			if (space[jC][iC + 1] == 2)
			{
				randomInky(movClydeAux, movClyde);
			}
		}
		else
		{

			randomInky(movClydeAux, movClyde);
		}
	}
}

// Funcion MOVER CLYDE
void Fantasma::moverInky(int &iC, int &jC, char &movClyde, int &movClydeAux)
{

	// Mover Arriba Clyde
	movArribaInky(iC, jC, movClydeAux, movClyde);

	// Mover Abajo Clyde
	movAbajoInky(iC, jC, movClydeAux, movClyde);

	// Mover Izquierda Clyde
	movIzquierdaInky(iC, jC, movClydeAux, movClyde);

	// Mover Derecha
	movDerechaInky(iC, jC, movClydeAux, movClyde);

	imprimirInky(iC, jC);
	imprimirComidaClyde(iC, jC, movClyde);
}
