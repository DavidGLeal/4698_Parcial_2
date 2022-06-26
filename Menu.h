
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <windows.h>
#include <stdlib.h>
#include "IngresoDatos.h"

#include "MetodosExternos.cpp"
#include "Win.h"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13
int validar_arreglo(char arreglo[]);
using namespace std;
int menu(const char *titulo, const char *opciones[], int n);

//!VIS DE EXTERNO

	MetodoExterno *directa = new MetodoExterno("OrdenamientoDirecto.txt");
	MetodoExterno *natural = new MetodoExterno("OrdenamientoNatural.txt");



int ingresoD(){

	IngresoDatos *i = new IngresoDatos();
	cout << "\n";
	int num = i->funcionPrincipalEnteros("Ingrese sus numeros: ");

	return num;
}


int* ingresar(){

	int *arreglo = new int[10];
	
	int cont{0};

	cout<<"\n";
	//cout << "contador " <<cont <<endl;

	
	for (int i = 0; i< 10; i++){

		int num{ingresoD()};

		if(num == -10101010){
			i = 10;
		}else{
			arreglo[i] = num;
			++cont;
		}
	}

	for (int i = 0; i< cont; i++){
		cout<< arreglo[i] << " ";
	}

	cout<<"\n";
	system("pause");
	
	return arreglo;
}


void ingresarExternos(string nom1, string nom2){

	directa->setN(0);
	for (int i = 0; i< 10; i++){

		int num{ingresoD()};

		if(num == -10101010){
			i = 10;
		}else{

			natural->insertar2(num, nom1);
			directa->insertar(num, nom2);
		}
	}

}

int IngresarDatos(){
	//char arreglo[10]={};
	char *arreglo=new char[10];
	int N{0};
	int arreglovalido{0};

	do
   	{
       printf("INGRESA UN arreglo ENTERO: ");
       scanf("%s",arreglo);
       N=validar_arreglo(arreglo);

   	}while(N==0);

   	arreglovalido=atoi(arreglo);
   	printf("\nEL arreglo ES: %i",arreglovalido);

   	getch();
   	return 1;
}

int validar_arreglo(char* arreglo)
{
    int i;
    for(i=0; i<strlen(arreglo); i++)
    {
        if(!(isdigit(arreglo[i])))
        {
            printf("\nINGRESA SOLO arregloS\n");
            getch();
            return 0;
        }
    }
    return 1;
}


void MenuMetExt(){
	//Operaciones op1;
	bool repite = true;
	int opcion;   
 

   const char *titulo = "Metodos Externos";
   const char *opciones[] = {"Ingresar  Datos","Ordenar por Directa","Ordenar por Natural", "Regresar al menu principal"};
   int n = 4;  

   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				directa->limpiar("OrdenamientoDirecto.txt");
				natural->limpiar("OrdenamientoNatural.txt");
				ingresarExternos("OrdenamientoNatural.txt","OrdenamientoDirecto.txt");
				cout<< "\n~~~ Datos ingresados con exito ~~~"<<endl;
				system("pause");

				break;
			}
			case 2:{
				system("cls");

				if(directa->hayDatos("OrdenamientoDirecto.txt")){
					directa->ordenarPorDirecta();
					cout<< "\n~~~ Datos ordenados con exito ~~~"<<endl;
					cout<<"\n";
					directa->imprimir("OrdenamientoDirecto.txt");
					cout<<"\n";
					system("pause");
				}else{
					cout<< "\n~~~ Datos vacios. Ingrese antes de ordenar ~~~"<<endl;
					system("pause");
				}

				break;
			}
			case 3:{
				system("cls");

				if(natural->hayDatos("OrdenamientoNatural.txt")){
					natural->ordenarPorNatural();
					cout<< "\n~~~ Datos ordenados con exito ~~~"<<endl;
					cout<<"\n";
					natural->imprimir("OrdenamientoNatural.txt");
					cout<<"\n";
					system("pause");
				}else{
					cout<< "\n~~~ Datos vacios. Ingrese antes de ordenar ~~~"<<endl;
					system("pause");
				}

				break;
			}					
			case 4:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuBusquedas(){
	//Operaciones op1;
	bool repite = true;
	int opcion;   
 
   
   const char *titulo = "Busquedas";
   const char *opciones[] = {"Busqueda Binaria", "Busqueda Secuencial", "Regresar al menu principal"};
   int n = 3;  
 
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:
				system("cls");

				break;
			case 2:
				system("cls");

				break;	
			case 3:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void SubmenuDistribucion(){
	//Operaciones op1;
	bool repite = true;
	int opcion;   
 
   
   const char *titulo = "Ordenamientos de Distribucion";
   const char *opciones[] = {"Ordenar por CountingSort", "Ordenar por BucketSort","Volver atras"};
   int n = 3;  
 
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				int *arreglo = ingresar();
				break;
			}		
			case 2:{
				system("cls");
				IngresarDatos();
				break;
			}					
			case 3:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuOrdenamientos(){
	//Operaciones op1;
	bool repite = true;
	int opcion;   
 
   
   const char *titulo = "Ordenamientos";
   const char *opciones[] = {"Ordenar por Intercambio", "Ordenar por Burbuja", "Ordenar por Quicksort", "Ordenar por ShellSort","Ordenar por Distribucion","Ordenar por Radix","Regresar al menu principal"};
   int n = 7;  
 
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				IngresarDatos();
				break;
			}		
			case 2:{
				system("cls");
				IngresarDatos();
				break;
			}				
			case 3:{
				system("cls");
				IngresarDatos();
				break;
			}
			case 4:{
				system("cls");
				IngresarDatos();
				break;
			}
			case 5:{
				system("cls");
				SubmenuDistribucion();
				break;
			}
			case 6:{
				system("cls");
				IngresarDatos();
				break;
			}	
			case 7:{
				system("cls");
				cout<<endl;
				cout<<"Regresando..."<<endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuPrincipal(){

	system("mode con: cols=50 lines=23");
	bool repite = true;
	int opcion;   
 
   
   const char *titulo = "Menu principal";
   const char *opciones[] = {"Metodos de Ordenamiento", "Metodos de Busqueda","Metodos Externos","Salir del programa"};
   int n =4;  
 
   do {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion){
			case 1:{
				system("cls");
				MenuOrdenamientos();
				break;
			}
			case 2:{
				system("cls");
				MenuBusquedas();
				break;
			}		
			case 3:{
				system("cls");
				MenuMetExt();
				break;
			}		
			case 4:{
				cout<<endl;
				printf("\n\n\n");
				cout<<"Cerrando el programa..."<<endl;
				repite=false;
				break;
			}										
	}
	printf("\n\n\n");
	system("pause");
	}while(repite);
}

int menu(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  
 
   int tecla;
 
   bool repite = true; 
 
   do {
      system("cls");
      //system("Color 8B");
      gotoxy(5, 3 + opcionSeleccionada); cout << "->" << endl;
 
      
      gotoxy(15, 2); cout << titulo;
 
      
      for (int i = 0; i < n; ++i) {
         gotoxy(10, 4 + i); cout <<"["<< i + 1 << "] | " << opciones[i];
      }
 
      
 
      do {
         tecla = getch();
         
      } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != TECLA_ENTER);
 
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
 
         case TECLA_ENTER:
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}

