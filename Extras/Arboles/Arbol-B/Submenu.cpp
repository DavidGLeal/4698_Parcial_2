
#include "Submenu.h"
#include <stdlib.h>
#include <stdio.h>
#include "Menu.cpp"
#include "Imagen.cpp"
#include "Backup.cpp"
#include "Generar.cpp"

using namespace std;
void Submenu::submenu(){
int opc=0;
	Imagen i;
   	Menu m1;
   	Backup b;
   	Complemento s;
   	Generar p;
    bool repite = true;
     // Título y las opciones del menú
   const char *titulo = "****  M E N U   P R I N C I P A L ****";
   const char *opciones[] = {"Programa Arboles B ", "Reporte en PDF", "Foto Pixelada", "Backup", "Recuperacion Backup", "C++ Doc", "Ayuda", "Regresar"};
   int n = 8 ; // Número de opciones
   
    do {
        
        opc = s.menu(titulo,opciones,n);
        system("cls");
        switch(opc) {
            case 1:{
             	m1.menuArbol();
				
       
                    system("pause>nul");
                break;
            }

            case 2:{
            	p.generarPDF("prueba.pdf");
                 cout<<"\nArchivo PDF generado correctamente\n";
                 system("pause>nul");
                break;
            }
                
            case 3:{
                i.Imagenes();
                 system("pause>nul");
                break;
            }
            case 4:{
            	b.generarBackup();
            	cout<<"\n\n--Backup realizado--\n\n";
                 system("pause");
                break;
            }
            case 5:{
            	string nombre;
            	cout << "\n\n\nIntroduzca el nombre: "; cin >> nombre;
            	b.recuperarBackup(nombre);
            	cout<<"\n\n\n\n--Backup recuperado--\n\n";
                 system("pause");
                break;
            }
              case 6:{
              	system("start chrome.exe&");
              	cout << "C++ docs abiertos" << endl;
              	system("pause");
                   break;
            }

            case 7:{
            	   
            	   system("arbol.chm");
                   break;
            }
            case 8:{
                   repite = false;
                   break;
            }
       }
        
    } while(repite);
}