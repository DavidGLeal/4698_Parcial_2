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

#pragma once
#include "HandleConsole.hpp"

void HandleConsole::setCursorPosition(SHORT x, SHORT y) {
    HANDLE consoleIndentificator{GetStdHandle(STD_OUTPUT_HANDLE)};
    COORD position{x, y};
    SetConsoleCursorPosition(consoleIndentificator, position);
}

void HandleConsole::setCursorVisibilitie(bool isEnabled) {
    HANDLE consoleIdentificator{GetStdHandle(STD_OUTPUT_HANDLE)};
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = isEnabled;
    const short DEFAULT_CURSOR_SIZE{3};
    const short INVISIBLE_CURSOR_SIZE{1};
    cursor.bVisible = isEnabled;
    cursor.dwSize = (isEnabled) ? INVISIBLE_CURSOR_SIZE: DEFAULT_CURSOR_SIZE;
    SetConsoleCursorInfo(consoleIdentificator, &cursor);
}
