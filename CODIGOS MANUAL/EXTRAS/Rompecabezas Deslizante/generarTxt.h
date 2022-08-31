/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 10/05/2022
Fecha de modificacion: 10/05/2022
Grupo 9
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
*/

/**
 * Project Untitled
 */
#ifndef GENERARTXT_H
#define GENERARTXT_H

#include <iostream>
#include <string>
#include <fstream>//abrir, cerrar y guardar archivos

class generarTxt{
    public:

/**
 * @param ListaCelulares
 */

void generarTxtCelulares(ListaCelulares);

/**
 * @param ListaCompras
 */

void generarTxtCompras(ListaCompras);
};
#endif //_GENERARTXT_H