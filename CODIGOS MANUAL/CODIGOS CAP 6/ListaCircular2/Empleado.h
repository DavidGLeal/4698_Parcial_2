#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Empleado
{
public:
    int ident;
    char ap[20], nom[20], cargo[20];
    double sueldo;
    Empleado *avanc;
    Empleado();
    ~Empleado();
    Empleado *insertar_nodo_inicial(void);
    void insertar_nodos_circular(Empleado *&, int c);
    int progenc(Empleado *);
    void empleadosmayora(Empleado *);
    void sumanomina(Empleado *);
    char opciones(Empleado *);
    void ordenar(Empleado *);
    void imprime_lista_circ(Empleado *);
    void eliminar_nodo_circ(Empleado *&cab, int i);
};
