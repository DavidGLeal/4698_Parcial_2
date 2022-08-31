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
class Fantasma
{
public:
    Fantasma();
    void imprimirClyde(int iC, int jC);
    void imprimirComidaClyde(int iC, int jC, char movClyde);
    void borrarClyde(int iC, int jC);
    void randomClyde(int &movClydeAux, char &movClyde);
    void choqueClyde(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj);
    void movArribaClyde(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void movAbajoClyde(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void movIzquierdaClyde(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void movDerechaClyde(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void moverClyde(int &iC, int &jC, char &movClyde, int &movClydeAux);
    void imprimirBlinky(int iB, int jB);
    void borrarBlinky(int iB, int jB);
    void choqueBlinky(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj);
    void movIzquierdaBlinky(int &iB, int &jB, int i, int j);
    void movDerechaBlinky(int &iB, int &jB, int i, int j);
    void movArribaBlinky(int &iB, int &jB, int i, int j);
    void movAbajoBlinky(int &iB, int &jB, int i, int j);
    void moverBlinky(int &iB, int &jB, int i, int j, int dir, char &movClyde);
    void imprimirPinky(int iP, int jP);
    void borrarPinky(int iP, int jP);
    void choquePinky(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj);
    void movIzquierdaPinky(int &iB, int &jB, int i, int j);
    void movDerechaPinky(int &iB, int &jB, int i, int j);
    void movArribaPinky(int &iB, int &jB, int i, int j);
    void movAbajoPinky(int &iB, int &jB, int i, int j);
    void moverPinky(int &iB, int &jB, int i, int j, int dir, char &movClyde);
    void imprimirInky(int iI, int jI);
    void borrarInky(int i, int j);
    void randomInky(int &movClydeAux, char &movClyde);
    void choqueInky(int &i, int &j, int &iC, int &jC, int &dir, char movClyde, int anteriorpi, int anteriorpj);
    void movArribaInky(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void movAbajoInky(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void movIzquierdaInky(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void movDerechaInky(int &iC, int &jC, int &movClydeAux, char &movClyde);
    void moverInky(int &iC, int &jC, char &movClyde, int &movClydeAux);
};
