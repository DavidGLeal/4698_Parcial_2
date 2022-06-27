#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <windows.h>
#include <stdlib.h>
#include "TablaHashCerrada.cpp"
#include "TablaCerradaEnteros.cpp"
#include "TablaSondeoCuadraticoInt.cpp"
#include "TablaSondeoLinealInt.cpp"
#include "TablaHashDobleInt.cpp"
#include "TablaHashDobleText.cpp"
#include "TablaSondeoCuadraticoText.cpp"
#include "TablaSondeoLinealText.cpp"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13
using namespace std;
TablaSondeoCuadraticoInt  TablaSC;
TablaSondeoLinealInt TablaSL;
TablaHashDobleInt TablaHD;
TablaSondeoCuadraticoText TablaCT;
TablaHashDobleText TablaDT;
TablaSondeoLinealText TablaLT;

int menu(const char *titulo, const char *opciones[], int n);

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string IngresoString()
{
	
	char *dato=new char[30],c;
	int i=0;
	while((c=_getch())!=13){
		if((c>=65&& c<=90)||(c>=97&&c<=122)){
			printf("%c",c);
			dato[i++]=c;}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
			i--;
		}
	}
	dato[i]='\0';
	return dato;
}

int ingresar_Datosenteros()
{
	char* dato = new char[10], c;
	int i = 0;
	printf("Seleccione una opcion: ");
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8 || c == 127) {
			printf("\b \b");
			dato[i--] = 0;
		}
	}
	dato[i] = '\0';
	return atoi(dato);
}

void MenuIngresoLineal(){
   bool repite = true;
   int opcion, longitud;   
   string op;
   string cadena;
   char *cad;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Insertar lineal (numeros)", "Insertar lineal(texto)","Eliminar (numeros)","Eliminar (texto)","Buscar (numero)","Buscar (texto)","Retornar"};
   int n = 7;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				do{
					int valor = ingresar_Datosenteros();
					TablaSL.insertar(valor);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
				TablaSL.imprimir();
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
				do{
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaLT.insertar(cadena);
					cout << "\n¿Desea ingresar otra? (s/n)"<<endl;
					cin >> op;
				}while(op == "s");
					cout <<"\nTabla hash cerrada"<< endl;
					TablaLT.imprimir();
				system ("pause");
				break;
			}		
			case 3:{
				system("cls");
				do{
				int valor = ingresar_Datosenteros();
				TablaSL.eliminar(valor);
				cout << "\n¿Desea eliminar otra? (s/n)" << endl;
				cin >> op;
				}while(op == "s");
				TablaSL.imprimir();
				system ("pause");
				break;
			}
			case 4:{
				system("cls");
				do{
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaLT.eliminar(cadena);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
					cout <<"\nTabla hash cerrada"<< endl;
					TablaLT.imprimir();
				system ("pause");
				break;
			}		
			case 5:{
				system("cls");
					int valor = ingresar_Datosenteros();
					TablaSL.buscar(valor);
				system ("pause");
				break;
			}	
			case 6:{
				system("cls");
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaLT.buscar(cadena);
				system ("pause");
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

void MenuIngresoCuadratico(){
   bool repite = true;
   int opcion, longitud;   
   string op;
   string cadena;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Insertar Cuadratico (numeros)", "Insertar Cuadratico(texto)","Eliminar (numeros)","Eliminar (texto)","Buscar (numero)","Buscar (texto)","Retornar"};
   int n = 7;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				do{
					int valor = ingresar_Datosenteros();
					TablaSC.insertar(valor);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
				TablaSC.imprimir();
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
				do{
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaCT.insertar(cadena); //METODO INSERTAR CUADRATICO
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
					cout <<"\nTabla hash cerrada"<< endl;
					TablaCT.imprimir();
				system ("pause");
				break;
			}		
			case 3:{
				system("cls");
				do{
				int valor = ingresar_Datosenteros();
				TablaSC.eliminar(valor);
				cout << "\n¿Desea eliminar otra? (s/n)" << endl;
				cin >> op;
				}while(op == "s");
				TablaSC.imprimir();
				system ("pause");
				break;
			}
			case 4:{
				system("cls");
				do{
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaCT.eliminar(cadena);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
					cout <<"\nTabla hash cerrada"<< endl;
					TablaCT.imprimir();
				system ("pause");
				break;
			}	
			case 5:{
				system("cls");
					int valor = ingresar_Datosenteros();
					TablaSC.buscar(valor);
				system ("pause");
				break;
			}	
			case 6:{
				system("cls");
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaCT.buscar(cadena);
				system ("pause");
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

void MenuIngresoDoble(){
   bool repite = true;
   int opcion, longitud;   
   string op;
   string cadena;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Insertar Doble (numeros)", "Insertar Doble (texto)","Eliminar (numeros)","Eliminar (texto)","Buscar (numero)","Buscar (texto)","Retornar"};
   int n = 7;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				do{
					int valor = ingresar_Datosenteros();
					TablaHD.insertar(valor);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
				TablaHD.imprimir();
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
				do{
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaDT.insertar(cadena);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
					cout <<"\nTabla hash cerrada"<< endl;
					TablaDT.imprimir();
				system ("pause");
				break;
			}		
			case 3:{
				system("cls");
				do{
				int valor = ingresar_Datosenteros();
				TablaHD.eliminar(valor);
				cout << "\n¿Desea eliminar otra? (s/n)" << endl;
				cin >> op;
				}while(op == "s");
				TablaHD.imprimir();
				system ("pause");
				break;
			}
			case 4:{
				system("cls");
				do{
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaDT.eliminar(cadena);
					cout << "\n¿Desea ingresar otra? (s/n)" << endl;
					cin >> op;
				}while(op == "s");
					cout <<"\nTabla hash cerrada"<< endl;
					TablaDT.imprimir();
				system ("pause");
				break;
			}						
			case 5:{
				system("cls");
					int valor = ingresar_Datosenteros();
					TablaHD.buscar(valor);
				system ("pause");
				break;
			}	
			case 6:{
				system("cls");
					cout << "> Ingrese la letra o palabra: ";
					cadena=IngresoString();
					TablaDT.buscar(cadena);
				system ("pause");
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

	bool repite = true;
	int opcion;   
   
    const char *titulo = "HASH CERRADO";
    const char *opciones[] = {"Sondeo Lineal", "Sondeo Cuadratico","Doble Hash","Salir del programa"};
    int n =4;  
 
    do {
        opcion = menu(titulo, opciones, n); 	
		switch(opcion){
			case 1:{
				system("cls");
				MenuIngresoLineal();
				break;
			}
			case 2:{
				system("cls");
				MenuIngresoCuadratico();
				break;
			}		
			case 3:{
				system("cls");
				MenuIngresoDoble();
				break;
			}		
			case 4:{
				cout<<endl;
				printf("\n\n\n");
				cout<<"Saliendo del programa..."<<endl;
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
