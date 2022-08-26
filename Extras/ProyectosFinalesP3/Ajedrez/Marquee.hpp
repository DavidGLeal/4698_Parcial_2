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
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <thread>
#ifndef MARQUEE_HPP
#define MARQUEE_HPP
class Marquee{
    private:
    
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD CursorPosition; 
    /**
     * @brief Sets the cursor to the x and y position of the screen
     * 
     * @param x 
     * @param y 
     */
    void gotoXY(int x,int y);
    public:
    /**
     * @brief Displays continuous Marquee
     * 
     */
    void displayMarquee();
};

#endif
