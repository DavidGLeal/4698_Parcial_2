//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Ordenamiento quicksort 
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto

#include <iostream>
#include "vector.h"
#include "OrdenamientoInterno.h"

int main(){

    Vector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(9);
    vec1.push_back(6);
    vec1.push_back(0);
    vec1.push_back(98);
    vec1.push_back(5);
    vec1.push_back(23);
    vec1.push_back(12);
    
    OrdenamientoInterno ordenador;

    ordenador.ordenarQuicksort(vec1,0,8);
    
    for (int i = 0; i < vec1.size(); i++) {
        std::cout << vec1[i] << '\n';
    }

}
