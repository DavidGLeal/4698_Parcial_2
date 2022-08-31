/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	Juan Reyes
        Brandon Masacela
        GRUPO: 3
   FECHA DE CREACION:        Lunes, 22 de agosto de 2022 07:25 p.m. 	
   FECHA DE MODIFICACION:     Miercoles, 24 de agosto de 2022 01:52 a.m.
 * --------------------------
 * Planteamiento: Elaborar simulación del juego Pac-Man, aplicando algoritmos
 * --------------------------
 */
#include <Windows.h>
#include <iostream>
#include "EasyBMP.cpp"

void DrwImage(std::string imagePath, HDC* console) {

   BMP image;
   image.ReadFromFile(imagePath.c_str());
   Rescale(image,'p',60);
   //image.SetBitDepth(32);
   for (int y = 0; y < image.TellHeight(); y++)
   {
       for (int x = 0; x < image.TellWidth(); x++)
       {
          int RED = image.GetPixel(x, y).Red;
          int GREEN = image.GetPixel(x, y).Green;
          int BLUE = image.GetPixel(x, y).Blue;
          int ALPHA = image.GetPixel(x, y).Alpha;

          COLORREF COLOUR = RGB(RED, GREEN, BLUE);
          if (ALPHA == 0) {
            SetPixelV(*console, x+40, y+40, COLOUR);
          }
       }
       Sleep(10);
   }
}
