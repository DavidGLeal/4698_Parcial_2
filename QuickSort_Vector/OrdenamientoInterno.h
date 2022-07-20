//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Ordenamiento quicksort 
//Autores:Camila Morales, Anthony Sinchiguano.
//Fecha de creación: 16/07/2022
//Fecha de modificación: 16/07/2022
//Github: https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto

#pragma once
#include <iostream>
#include "vector.h"
using namespace std;

class OrdenamientoInterno {

public:
	virtual void ordenarQuicksort(Vector &arreglo, int izq, int der);

};
