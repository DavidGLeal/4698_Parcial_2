#pragma once
#include "0Vector.h"

class OrdenamientoSectores {
public:
    OrdenamientoSectores(int total_fragmentos);
    void rellenar(int cantidad, int minimo, int maximo);
    void ordenamiento_zambrano_cristopher();

private:
    int _total_fragmentos;
    Vector* _vector;

    int aleatorio_entre(int minimo, int maximo);
    void shell_sort(int* arreglo, int tamanio);
};
