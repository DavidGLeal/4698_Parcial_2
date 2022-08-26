/*
* @flie FuncionesParaValidar.h
* @author Sebastian Arias - David Escobar - Estructura de Datos
* @date 20/7/2022
* @brief Archivo de cabecera para la clase FuncionesParaValidar
* @version 1.0
* 
*@copyright Copyright (c) 2022,Sebastian Arias - David Escobar
*@license MIT License

* @version 1.0
* 
*@copyright Copyright (c) 2022,Sebastian Arias - David Escobar
*@license MIT License
*/
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
/**
 * @brief El metodo ingresarDatos() permite insertar un dato
 *
 * @param msj
 */
   char* ingresarDatos(const char* msj);
   /**
 * @brief El metodo ingresarDatosReales() permite insertar un dato
 *
 * @param msj
 */
   char* ingresarDatosReales(const char* msj);
   /**
 * @brief El metodo validarNombre() permite la validacion de Ingreso de Nombre
 *
 * @param c
 */
   int validarNombre(char c[]);
};

#endif