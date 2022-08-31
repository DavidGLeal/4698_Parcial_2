/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca de Veintemilla
				Kevin Vargas 
                Cristopher Iza
                Denisse Rea
					
	FECHA DE CREACION:        20-05-2022 	
	FECHA DE MODIFICACION:    24-05-2022
	Grupo #6
*/
#include <vector>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#pragma once
#include <stdio.h>
#include "EasyBMP.h"

class Imagen {
	public:
	/**
	 * @brief 
	 * 
	 */
	void Imagenes();

	/**
	 * @brief 
	 * 
	 * @return int 
	 */
	int runIMG();

	/**
	 * @brief 
	 * 
	 * @param imagePath 
	 * @param console 
	 */
	void drawImage(std::string imagePath, HDC* console);
};
