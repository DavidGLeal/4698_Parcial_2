/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 26/06/2022
Fecha de modificacion: 29/06/2022
Grupo 10
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
*/

#ifndef INGRESODATOSENTERO_H
#define INGRESODATOSENTERO_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
using namespace std;


class IngresoDatos{
    public:
        IngresoDatos();
        virtual char *ingresoDatosEntero(const char*);
        virtual int convertirEntero();
};


#endif