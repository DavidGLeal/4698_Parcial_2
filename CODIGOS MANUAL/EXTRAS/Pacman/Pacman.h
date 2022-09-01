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

class Pacman
{
public:
    Pacman();
    void imprimirPacman(int i, int j);
    void borrarPacman(int i, int j);
    void puntosComida(int i, int j);
    void movArribaPacman(int &i, int &j);
    void movAbajoPacman(int &i, int &j);
    void movIzquierdaPacman(int &i, int &j);
    void movDerechaPacman(int &i, int &j);
    void movPasadizoIzq(int &i, int &j);
    void movPasadizoDer(int &i, int &j);
    void mover(int &i, int &j);
};
