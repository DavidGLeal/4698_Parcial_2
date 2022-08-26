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
