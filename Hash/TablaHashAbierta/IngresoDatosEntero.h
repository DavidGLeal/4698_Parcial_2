/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 11
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
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
