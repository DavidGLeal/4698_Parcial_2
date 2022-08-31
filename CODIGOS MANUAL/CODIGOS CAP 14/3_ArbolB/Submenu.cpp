#include "Submenu.h"
#include <stdlib.h>
#include <stdio.h>
#include "Menu.cpp"

using namespace std;
void Submenu::submenu(){
int opc=0;
   	Menu m1;
   	Complemento s;
    bool repite = true;
     // Título y las opciones del menú
   const char *titulo = "****  M E N U   P R I N C I P A L ****";
   const char *opciones[] = {"Programa Arboles B","Salir"};
   int n = 2; // Número de opciones
   
    do {
        
        opc = s.menu(titulo,opciones,n);
        system("cls");
        switch(opc) {
            case 1:{
             	m1.menuArbol();
                    system("pause>nul");
                break;
            }
            
            case 2:
				repite = false;
				break;
             
       }
        
    } while(repite);
}
