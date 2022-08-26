/***********************************************************************
 * Module:  FuncionesParaValidar.h
 * Author:  matia
 * Modified: Thursday, June 9, 2022 9:32:06 PM
 * Purpose: Declaration of the class FuncionesParaValidar
 ***********************************************************************/

#if !defined(__Class_Diagram_1_FuncionesParaValidar_h)
#define __Class_Diagram_1_FuncionesParaValidar_h

#include<iostream>
using namespace std;

class FuncionesParaValidar
{
public:
   char* ingresarDatos(const char* msj);
   char* ingresarDatosReales(const char* msj);
   int validarNombre(char c[]);
};

#endif