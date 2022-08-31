#pragma once
#define FIL 20
#define COL 50

class Laberinto
{
public:

    void  EmpezarGen ();
    void  EmpezarJug ();
    void Inicializar();
    void Imprimir();
	void ImprimirA();
    void GenerarCamino(int i, int j);
    void GenerarParedes();
    void FinGenerar();
    void mover(int tecla);

private:
    char lab[FIL][COL];
    int x;
    int y;

};
