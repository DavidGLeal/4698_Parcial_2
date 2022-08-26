/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE             
	AUTORES:
		Johan Romo
		Cristhopher Villamarin
		Sebastian Torres
                Jeanhela Nazate
                Milena Maldonado
                Shared Tinoco
		Brandon Masacela
		Juan Reyes
        GRUPOS: 7 - 10 - 11 - 14
        FECHA DE CREACION:        Viernes, 1 de julio de 2022 7:34:00 p. m. 	
	FECHA DE MODIFICACION:    Martes, 19 de junio de 2022 4:58:00 p. m.
        PROPOSITO: Proyecto Segundo Parcial - Arboles B
*/

#pragma once
#include <iostream>
#include <thread>

#include <stdlib.h>
#include "Usuario.cpp"
void marquesina(std::string text) {
HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ancho, alto;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleCursorPosition(conhandler, { 0, 4 });

    while (true) {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

        for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }

        SMALL_RECT pos = { 0, 0, ancho, 1 };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        free(buff);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}

void drawImage(std::string imagePath, HDC* console) {
    BMP image;
    image.ReadFromFile(imagePath.c_str());

    double original_width = image.TellWidth();
    double original_height = image.TellHeight();
    double ratio = ratio = original_width / original_height;

    double max_width = 500;
    double width = original_width;
    double height = original_height;

    if (original_width > max_width) {
        height = max_width / ratio;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                //SetPixel(*console, x, y, COLOUR);

                std::cout << "\033["
                    << 48
                    << ";2;"
                    << RED << ";"
                    << GREEN << ";"
                    << BLUE << "m"
                    << '##'
                    << "\033[0;00m";

                if (x == width - 1) {
                    std::cout << std::endl;
                }
            }
        }
    }
}

int main(){
std::string texto = "UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE ";
	std::thread t2(marquesina, texto);
	t2.detach();
	system("cls");
	cout << "\n";
 	Usuario usuario1;
	usuario1.menuInicial();
	return 0;
}