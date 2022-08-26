/*Universidad de las Fuerzas Armadas ESPE
  Enunciado:QUICKSORT
  Autores:  Johanna Pila
            Adriana Diaz
            Ayme Escobar
            Mateo Tituaña
  Fecha de creación: 22/06/2022
  Fecha de modificación: 22/06/2022
  Github:
*/

#include <iostream>
#include "vector.h"
//#include "OrdenamientoInterno.cpp"
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
