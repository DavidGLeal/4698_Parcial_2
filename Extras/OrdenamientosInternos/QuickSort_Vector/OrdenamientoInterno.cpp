#include "OrdenamientoInterno.h"

void OrdenamientoInterno::ordenarQuicksort(Vector &arr, int izq, int der) {

    int pivot = arr[(izq + der) / 2]; //pivote 
    int i = izq;
    int j = der;

    while (izq <= der) {

        while (arr[izq] < pivot) ++izq;

        while (arr[der] > pivot) --der;

        if (izq <= der) {
            std::swap(arr[izq], arr[der]);
            ++izq;
            --der;
        }
    }

    if (izq < j)
        ordenarQuicksort(arr, izq, j);

    if (i < der)
        ordenarQuicksort(arr, i, der);

}
