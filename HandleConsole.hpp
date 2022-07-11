/*
	*Universidad de las Fuerzas Armadas "ESPE"
        *Enunciado del problema:
	*Realizar un pograma de manejo de árboles binarios con todas sus funciones.
        *Autores:
	*Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 04-07-2022
	*Fecha de modificacion:
        * 08-07-2022
        *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Parcial_2
*/

#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    public:
        static void setCursorPosition(SHORT x, SHORT y);
        static void setCursorVisibilitie(bool isEnabled);
};

#endif
