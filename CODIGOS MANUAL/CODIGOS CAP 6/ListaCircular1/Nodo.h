#include <iostream>
#include <cstdlib>
#include "stdio.h"
#include "conio.h"
#include "string.h"

using namespace std;

class Nodo
{
private:
    char ID[5];
    char nombre[20];
    float n1, n2, n3;
    float promedio;
    Nodo *sig;

public:
    Nodo();
    ~Nodo();
    typedef Nodo *lista;
    typedef Nodo *fin;
    void setID(char *i);
    char *getID();
    void setNombre(char *nom);
    char *getNombre();
    void setN1(float);
    float getN1();
    void setN2(float);
    float getN2();
    void setN3(float);
    float getN3();
    float getPromedio();
    void setsig(Nodo *);
    Nodo *getsig();
    void ingreso(char *cd);
    void insertar(lista &, fin &, char *id, char *n, float n1, float n2, float n3, int &);
    void mostrar(lista lis);
    void agregarCPosicion(lista &, lista &, int, char[], char[], float, float, float, int &);
    void eliminar(lista &);
};
