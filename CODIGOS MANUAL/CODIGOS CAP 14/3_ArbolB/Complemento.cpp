#include "Complemento.h"
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#pragma once

Complemento::Complemento() {
	
}

void Complemento::gotoxy(int x,int y){
   HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

int Complemento::menu(const char *titulo, const char *opciones[], int n){
	 int opcionSeleccionada = 1;
   int tecla;
   bool repite = true;

   do {
      system("cls");
      gotoxy(5, 3 + opcionSeleccionada); cout << "==>";

      // Imprime el título
      gotoxy(15, 2); cout << titulo;

      // Imprime las opciones
      for (int i = 0; i < n; i++) {
         gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
      }

      do {
         tecla = _getch();
      } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

      switch (tecla) {
         case TECLA_ARRIBA:
            opcionSeleccionada--;

            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }
            break;

         case TECLA_ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }
            break;

         case ENTER:
            repite = false;
            break;
      }

   } while (repite);


   return opcionSeleccionada;
}
