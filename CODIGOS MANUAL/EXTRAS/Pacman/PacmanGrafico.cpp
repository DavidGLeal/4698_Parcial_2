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
#include <iostream>
int main()
{
    Grafico grafico;
    grafico.DibujarPacman(120,40,grafico.AMARILLO,0);
    grafico.DibujarPacman(120,80,grafico.AMARILLO,1);
    grafico.DibujarPacman(120,120,grafico.AMARILLO,2);
    grafico.DibujarPacman(120,160,grafico.AMARILLO,3);
    grafico.SetRadio(40);
    grafico.DibujarPacman(150,300,grafico.AMARILLO,4);
    grafico.DibujarFantasma(120,240,grafico.CYAN);
    //grafico.DibujarCuadrado(0,0,40,grafico.CYAN);
    cin.ignore();
    return 0;
}
