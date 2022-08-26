/*Universidad de las Fuerzas Armadas - ESPE
TAREA #3 - Parcial 3: 
Graficar, en base a algoritmos, los distintos casos de la notación asintótica Big O.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 18/08/2022
FECHA DE MODIFICACIÓN: 19/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

/*
* @flie MenuProyectoUnidad.h
* @author Sebastian Arias - David Escobar - Estructura de Datos
* @date 20/7/2022
* @brief Archivo de cabecera para la clase MenuProyectoUnidad
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
 * Module:  MenuProyectoUnidad.h
 * Author:  matia
 * Modified: Thursday, June 9, 2022 9:35:53 PM
 * Purpose: Declaration of the class MenuProyectoUnidad
 ***********************************************************************/

#if !defined(__Class_Diagram_1_MenuProyectoUnidad_h)
#define __Class_Diagram_1_MenuProyectoUnidad_h
#include "FuncionesParaValidar.cpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstring>
#include<windows.h>
#include <thread>
using namespace std;
class MenuProyectoUnidad
{
	public:
		/**
 * @brief El metodo menuCursor() permite recorrer el menu 
 *
 * @param titulo
 * @param opciones[]
 * @param n
 */
   	int menuCursor(const char* titulo, const char* opciones[], int n);
   	/**
 * @brief El metodo gotoxy() permite ajustar posicion
 *
 * @param x
 * @param y
 */
   	void gotoxy(int x, int y);
   	/**
 * @brief El metodo presentarMenu() permite presentar el menu
 *
 * @param void
 */
   	void presentarMenu(void);
   	/**
 * @brief El metodo marquesina() permite recorrer la marquesina 
 *
 * @param string text
 */
   	void marquesina(string text);
   	
};

#endif