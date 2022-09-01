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

#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    public:
        /**
         * @brief Set the Cursor Position object
         * 
         * @param x coordinate
         * @param y coordinate
         */
        static void setCursorPosition(SHORT x, SHORT y);

        /**
         * @brief Set the Cursor Visibilitie object
         * 
         * @param isEnabled 
         */
        static void setCursorVisibilitie(bool isEnabled);
};

#endif
