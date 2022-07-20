//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Ordenamiento quicksort 
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto


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
