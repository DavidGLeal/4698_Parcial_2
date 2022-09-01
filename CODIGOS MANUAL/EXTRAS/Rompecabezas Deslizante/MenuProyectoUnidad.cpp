/*Universidad de las Fuerzas Armadas - ESPE
PROYECTO - Parcial 3: 
Por medio de un algoritmo de busqueda exhaustiva, ordenar una matriz de colores en función de sus códigos RGB.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 20/08/2022
FECHA DE MODIFICACIÓN: 23/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#include "MenuProyectoUnidad.h"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#define ESCAPE 27
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::menuCursor(const char* titulo, const char* opciones[], int n)
// Purpose:    Implementation of MenuProyectoUnidad::menuCursor()
// Parameters:
// - titulo
// - opciones[]
// - n
// Return:     int
////////////////////////////////////////////////////////////////////////

int MenuProyectoUnidad::menuCursor(const char* titulo, const char* opciones[], int n)
{
   	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;
	
	do
	{
		ocultarCursor();
		system("cls");
		
	    gotoxy(5, 3 + opcionSeleccionada); cout << "==>";
	    
	    //Imprime el título
	    gotoxy(15,2); cout << titulo;
	    
	    //Imprime las opciones
	    int i;
	    
	    for((i=0);(i<n);(i++))
	    {
	    	gotoxy(10, 4 + i); cout << i+1 << ") " << opciones[i];
		}
		
		do
		{
			tecla = getch();
		}
		while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);
		
		switch(tecla)
		{
			case TECLA_ARRIBA:
				opcionSeleccionada --;
				
				if (opcionSeleccionada < 1)
				{
					opcionSeleccionada = n;
				}
				
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada ++;
				
				if (opcionSeleccionada > n)
				{
					opcionSeleccionada = 1;
				}
				
				break;
				
			case ENTER:
				repite = false;
				break;
		}
    }
    while(repite);
	
	return opcionSeleccionada;
}


int MenuProyectoUnidad::menuCursorColor(const char* titulo, RGBcode* opciones, int n)
{
   	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;
	
	do
	{
		ocultarCursor();
		system("cls");
	    
	    //Imprime el título
	    gotoxy(30,4); cout << titulo;
		opciones[opcionSeleccionada-1].setX(400);
		opciones[opcionSeleccionada-1].setY(75); 
		opciones[opcionSeleccionada-1].mostrar();
		do
		{
			tecla = getch();
		}
		while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER && tecla !=ESCAPE);
		
		switch(tecla)
		{
			case TECLA_ARRIBA:
				opcionSeleccionada --;
				
				if (opcionSeleccionada < 1)
				{
					opcionSeleccionada = n;
				}
				
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada ++;
				
				if (opcionSeleccionada > n)
				{
					opcionSeleccionada = 1;
				}
				
				break;
				
			case ENTER:
				repite = false;
				break;
			case ESCAPE:
				return ESCAPE;
				break;
		}
    }
    while(repite);
	
	return opcionSeleccionada;
}

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::gotoxy(int x, int y)
// Purpose:    Implementation of MenuProyectoUnidad::gotoxy()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void MenuProyectoUnidad::gotoxy(int x, int y)
{
   	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::presentarMenu()
// Purpose:    Implementation of MenuProyectoUnidad::presentarMenu()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MenuProyectoUnidad::presentarMenu()
{
	Imagen i;
	HWND miConsola = GetConsoleWindow();
	ShowWindow(miConsola,SW_SHOWMAXIMIZED);
	RGBcode rojo(255,0,0),azul(0,0,255),verde(0,255,0);
	COLORREF color;
	FuncionesParaValidar objFunVal;
	const char *tituloColor = "ELIGE UN COLOR";
	const char *tituloGeneral = "MENU PROYECTO UNIDAD 3";
	const char *opcionesGeneral[] = {"Resolver Manualmente.", "Resolver Automaticamente","Imagen","Cdocs.",
	"Manual","Ayuda.","Salir."};
	const char *tituloPdf = "ELIGE UN COLOR";
	RGBcode opcionesColor[] = {rojo,azul, verde};		
	int opG=0,opC=0,nColor=3,nGeneral=7;
	do{
		ocultarCursor();
		opG=menuCursor(tituloGeneral,opcionesGeneral,nGeneral);
		switch(opG){
			case 1:{ //Resolver Manualmente
				do{	 
					opC=menuCursorColor(tituloColor,opcionesColor,nColor);
					switch(opC){
						case 1:{//rojo
							int dimen;
							char numchar[100];
							do
							{
								system("cls");
								std::cout<<"\n\n\n\n";
								strcpy(numchar,objFunVal.ingresarDatos("\nIngrese la dimension del cuadrado: "));
								dimen=atoi(numchar);	
							}while(dimen>5 || dimen<=1);
							Paleta rompecabezas(dimen);
							system("cls");
							rompecabezas.crearPaleta(2);
							rompecabezas.degradar(1);
							rompecabezas.clonar();
							rompecabezas.jugar();
							break;
						}
						case 2: {	//azul
							int dimen;
							char numchar[100];
							do
							{
								system("cls");
								std::cout<<"\n\n\n\n";
								strcpy(numchar,objFunVal.ingresarDatos("\nIngrese la dimension del cuadrado: "));
								dimen=atoi(numchar);	
							}while(dimen>5 || dimen<=1);
							Paleta rompecabezas(dimen);			
							system("cls");
							rompecabezas.crearPaleta(1);
							rompecabezas.degradar(3);
							rompecabezas.clonar();
							rompecabezas.jugar();
							break;
						}
						case 3://verde
						{
							int dimen;
							char numchar[100];
							do
							{
								system("cls");
								std::cout<<"\n\n\n\n";
								strcpy(numchar,objFunVal.ingresarDatos("\nIngrese la dimension del cuadrado: "));
								dimen=atoi(numchar);	
							}while(dimen>5 || dimen<=1);
							Paleta rompecabezas(dimen);
							system("cls");
							rompecabezas.crearPaleta(3);
							rompecabezas.degradar(2);
							rompecabezas.clonar();
							rompecabezas.jugar();
							break;					
						}
						default:
							{
								printf("\nRegresando al menu principal...\n");
								system("pause");
								break;
							}
						}			
					}while(opC!=ESCAPE);
				break;		
			}
			case 2:{ //Resolver Automáticante
			do{	 
					opC=menuCursorColor(tituloColor,opcionesColor,nColor);
					switch(opC){
						case 1:{//rojo
							int dimen;
							char numchar[100];
							do
							{
								system("cls");
								std::cout<<"\n\n\n\n";
								strcpy(numchar,objFunVal.ingresarDatos("\nIngrese la dimension del cuadrado: "));
								dimen=atoi(numchar);	
							}while(dimen>5 || dimen<=1);
							Paleta rompecabezas(dimen);
							system("cls");
							rompecabezas.crearPaleta(2);
							rompecabezas.degradar(1);
							rompecabezas.escribir(2);
							rompecabezas.clonar();
							rompecabezas.solucionar();
							break;
						}
						case 2: {	//azul
							int dimen;
							char numchar[100];
							do
							{
								system("cls");
								std::cout<<"\n\n\n\n";
								strcpy(numchar,objFunVal.ingresarDatos("\nIngrese la dimension del cuadrado: "));
								dimen=atoi(numchar);	
							}while(dimen>5 || dimen<=1);
							Paleta rompecabezas(dimen);			
							system("cls");
							rompecabezas.crearPaleta(1);
							rompecabezas.degradar(3);
							rompecabezas.escribir(1);
							rompecabezas.clonar();
							rompecabezas.solucionar();
							break;
						}
						case 3://verde
						{
							int dimen;
							char numchar[100];
							do
							{
								system("cls");
								std::cout<<"\n\n\n\n";
								strcpy(numchar,objFunVal.ingresarDatos("\nIngrese la dimension del cuadrado: "));
								dimen=atoi(numchar);	
							}while(dimen>5 || dimen<=1);
							Paleta rompecabezas(dimen);
							system("cls");
							rompecabezas.crearPaleta(3);
							rompecabezas.degradar(2);
							rompecabezas.escribir(3);
							rompecabezas.clonar();
							rompecabezas.solucionar();
							break;					
						}
						default:
							{
								printf("\nRegresando al menu principal...\n");
								system("pause");
								break;
							}
						}			
					}while(opC!=ESCAPE);
				break;		
			}
			case 3:{ //Imagen
				i.Imagenes();
				break;		
			}
			case 4:{ //Cdocs.
				system("start chrome.exe&");
              	cout << "C++ docs abiertos" << endl;
              	system("pause");
                   break;
				break;		
			}
			case 5:{ //Manual
				system("Manual_Puzzle.pdf");
				break;		
			}
			case 6:{ //Ayuda
				system("AyudaPuzzle.chm");
				break;		
			}
			case 7:{ //Salir
				system("cls");
				cout<<"\nGracias por usar nuestro programa."<<endl;
				exit(EXIT_SUCCESS);
				break;		
			}
		}
	}while(opG!=7);
}

void MenuProyectoUnidad::ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}