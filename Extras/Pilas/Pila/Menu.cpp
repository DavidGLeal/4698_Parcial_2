/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    #Grupo 7
				Brandon Raul Masacela - 	 brmasacela@espe.edu.ec
				Juan Francisco Reyes -       jfreyes4@espe.edu.ec
	FECHA DE CREACION:        14-06-2022 	
	FECHA DE MODIFICACION:    14-06-2022
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Pila.cpp"
#include "Nodo.cpp"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;

void menu_principal();
int menu(int n);

void color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void menu_principal(){
    Pila obj;
    void *p = NULL;
	int opcion;
    bool flag = true;
	int num = 5;
    int dato;
	do{
		opcion = menu(num);
		switch(opcion){
			case 1:
				system("cls");
                cout<<"Valor a introducir a la pila => ";cin>>dato;
                p = obj.insertarpila(p, dato);
                cout<<"\n";
                system("pause");
				break;
			case 2:
				system("cls");
                p = obj.eliminar(p);
				break;
			case 3:
				system("cls");
                cout<<"Elementos almacenados en la pila\n";
                obj.mostrar(p);
				break;
            case 4:
                system("cls");
                obj.calcularPorcentaje(p);
				break;
            case 5:
				flag = false;
				break;
		}
	}while(flag);
}

int menu(int n){
	int Set[] = {7,7,7,7,7,7,7};
    int opcSelec = 1;
    char tecla;
	bool flag = true;
	do{
		system("cls");
        gotoxy(17,1);
        color(Set[0]);
        cout<<"PILAS";
    
        gotoxy(8,2);
        color(Set[1]);
		cout<<"====================";

		gotoxy(1,4);
        color(Set[2]);
        cout<<"1) Introducir un elemento a la pila";

        gotoxy(1,5);
        color(Set[3]);
        cout<<"2) Eliminar un elemento de la pila";

        gotoxy(1,6);
        color(Set[4]);
        cout<<"3) Mostrar todo el contenido de la pila";

        gotoxy(1,7);
        color(Set[5]);
        cout<<"4) Calcular el procentaje de numeros pares";

        gotoxy(1,8);
        color(Set[6]);
        cout<<"5) Salir";

		do{
			tecla = _getch();
		}while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);
		switch(tecla){
			case TECLA_ARRIBA:
				opcSelec--;
				if(opcSelec < 1){
					opcSelec = n;
				}
				break;
			case TECLA_ABAJO:
				opcSelec++;
				if(opcSelec > n){
					opcSelec = 1;
				}
				break;
			case ENTER:
				flag = false;
				break;
		}
		Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;
        if(opcSelec == 1)
        {
            Set[2] = 12;
        }
        if(opcSelec == 2)
        {
            Set[3] = 12;
        }
        if(opcSelec == 3)
        {
            Set[4] = 12;
        }
        if(opcSelec == 4)
        {
            Set[5] = 12;
        }
        if(opcSelec == 5)
        {
            Set[6] = 12;
        }
	}while(flag);
	return opcSelec;
}
