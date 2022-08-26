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
#include "Pacman.cpp"
#include "Fantasma.cpp"
class Iniciar
{
private:
public:
	Juego jg;
	void comenzarJuego();
};

void Iniciar::comenzarJuego()
{
	Fantasma f;
	Pacman p;
	
	int i = 21, j = 21;

	int anteriorpi, anteriorpj;

	// Variables Posicion Inicial Fantasmas

	// i=Columna j=Fila
	int iC = 26, jC = 13; // iC,jC ----> Clyde
	int iB = 21, jB = 11; // iB,jB ----> BLinky
	int iP = 21, jP = 11; // iP,jP ----> Pinky
	int iI = 21, jI = 11; // iI,jI ----> Inky

	int hacerClyde = 0;
	int hacerBlinky = 0;
	int hacerInky = 0;
	int hacerPinky = 0;

	// Variables Movimiento Clyde
	char movClyde;
	char movPinky;
	char movBlinky;
	int movClydeAux;
	char movInkyde;
	int movInkydeAux;

	// Variable de Ciclo Juego
	bool game_over = false;

	ocultarCursor();

		// Menu
		menu();

		if (dirMenu == 1 || dirMenu == 2 || dirMenu == 3)
		{
			system("cls");
			llenarMapa();
			marcadorFijo();

			/*=========== Impreciones de Matrices no Visibles ===========*/

			// imprimirSpace();
			// imprimirComida();

			/*===========  Impreciones Iniciales de Fantasmas y Pacman  ===========*/

			p.imprimirPacman(i, j);
			f.imprimirClyde(iC, jC);
			f.imprimirBlinky(iB, jB);
			f.imprimirPinky(iP, jP);
			f.imprimirInky(iI, jI);

			f.randomClyde(movClydeAux, movClyde);
			f.randomInky(movInkydeAux, movInkyde);

			/*=========== Ciclo de Juego ===========*/

			while (game_over == false && vida > 0 && dir != 4 && puntos < 18600)
			{
				ocultarCursor();
				tiempo = tiempo + 1;

				// Reinicializar al pasar de nivel
				if (puntos == 3330 || puntos == 6600 || puntos == 9900 || puntos == 13200)
				{
					jg.menuYouWin();
				}

				// Aca comienza el ciclo
				anteriorpi = i;
				anteriorpj = j;

				teclear();
				p.mover(i, j);

				f.choqueClyde(i, j, iC, jC, dir, movClyde, anteriorpi, anteriorpj);
				f.choqueBlinky(i, j, iB, jB, dir, movBlinky, anteriorpi, anteriorpj);
				f.choqueInky(i, j, iI, jI, dir, movInkyde, anteriorpi, anteriorpj);
				f.choquePinky(i, j, iP, jP, dir, movPinky, anteriorpi, anteriorpj);

				anteriorpi = i;
				anteriorpj = j;

				hacerClyde++;
				if (hacerClyde % 3 == 0)
				{
					f.moverClyde(iC, jC, movClyde, movClydeAux);
				}

				hacerBlinky++;
				if (hacerBlinky % 2 == 0)
				{
					f.moverBlinky(iB, jB, i, j, dir, movBlinky);
				}

				hacerPinky++;
				if (hacerPinky % 4 == 0)
				{

					f.moverPinky(iP, jP, i + 2, j + 2, dir - 2, movPinky);
				}

				hacerInky++;
				if (hacerInky % 1 == 0)
				{
					movInkydeAux = +3;
					f.moverInky(iI, jI, movInkyde, movInkydeAux);
				}
			}
		}

		if (puntos > 1800)
		{
			jg.menuYouWin();
		}
		else if (vida == 0)
		{
			jg.menuYouLose();
		}
	cout << "\n\n\n\n\n\n\n\n" << endl;
	system("pause>nul");
}
