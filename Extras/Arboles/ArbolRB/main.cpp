/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
ESTRUCTURA DE DATOS
Integrantes: Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos
NRC: 4698
Tema: Arbol Rojo Negro - Proyecto Segundo Parcial

*/

#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <thread>
#include <string>
#include "ArbolR-N.h"
#include "ArbolR-N.cpp"
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "menu.h"
#include "menu.cpp"
#include "menu_option.h"
#include "menu_option.cpp"
#include "registro.h"
#include "Input.h"
#include "Input.cpp"
#include "metrics.h"
#include "metrics.cpp"
#include "pdf.h"
#include "pdf.cpp"
#include "Generar.h"
#include "Generar.cpp"



using namespace std;

void menu(ArbolRN RBTree);
void subMenu(ArbolRN RBTree);
void extrasMenu(ArbolRN RBTree);
void askForMenu(ArbolRN RBTree);
void insert(ArbolRN RBTree);
void remove(ArbolRN RBTree);
void search(ArbolRN RBTree);
void print(ArbolRN RBTree);
void preOrder(ArbolRN RBTree);
void inOrder(ArbolRN RBTree);
void postOrder(ArbolRN RBTree);
void converTxtToPdf();


//Marquesina
void marquee(std::string text) {
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

int main()
{
	std::string test = "E S T R U C T U R A  D E  D A T O S  G R U P O 2 Y 19  I N G E N I E R I A  S O F T W A R E  E S P E   ";
    std::thread t2(marquee, test);
    t2.detach();
	ArbolRN RBTree;
	//registro();
	menu(RBTree);
	return 0;
}













void askForMenu(ArbolRN RBTree)
{
	char ch = '\0';
	cin.ignore();
	cout << "\nDesea regresar al menu? S/N: ";
	cin.get(ch);
	while (ch != 'S' && ch != 's' && ch != 'N' && ch != 'n')
	{
		cout << "\nLo sentimos opcion invalida, intente de nuevo: ";
		cout << "\nDesea regresar al menu? S/N: ";
		cin.get(ch);
	}
	if (ch == 's' || ch == 'S')
		menu(RBTree);
	else if (ch == 'n' || ch == 'N')
		exit(0);
	cin.ignore();
}

void insert(ArbolRN RBTree)
{
	unsigned int size = 0;
	int val = 0;

	system("CLS");
	cout <<endl;
	cout << "============= [Insertando un Valor] ============\n\n";
	cout << "Ingrese el valor:\n";
		val = Input::integerNumber(1,9);
		RBTree.insert(val);

	system("CLS");
	cout <<endl;
	cout << "==========================================\n";
	cout << "\tLos valores han sido insertados!\n";
	cout << "==========================================\n\n";
	cout << "\033[1;31m" << "("<<val<<")"<< "\033[0m"<<endl;
	RBTree.print();
	cout<<"==========================================\n";
	cout<< "\tInformacion del arbol:\n";
	cout<<"==========================================\n";
	RBTree.informationTree();
	cout<<"==========================================\n";
	
	
	askForMenu(RBTree);
	fflush(stdin);
	
}


void remove(ArbolRN RBTree)
{
	int val = 0;

	system("CLS");
	cout <<endl;
	cout << "============= [Eliminando un valor] ============\n\n";
	cout << "Ingrese el valor a eliminar: ";
	cin >> val;
	system("CLS");
	cout << "=========================================\n";
	RBTree.remove(val);
	cout << "=========================================\n";
	RBTree.print();
}

void search(ArbolRN RBTree)
{
	int val = 0;

	system("CLS");
	cout <<endl;
	cout << "========== [BUSCAR UN VALOR] ==============\n\n";
	cout << "Ingrese el valor a buscar: ";
	cin >> val;
	system("CLS");
	cout << "=============================================\n";
	RBTree.search(val);
	cout << "=============================================\n";
	RBTree.print();
	cout << "=============================================\n";
}

void print(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "===========================================================\n";
	RBTree.print();
	cout << "===========================================================\n\n";
}

void preOrder(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "===================== [PreOrden]===========================\n";
	RBTree.preOrder();
	cout << "===========================================================\n\n";
}
void inOrder(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "===================== [InOrden]===========================\n";
	RBTree.inOrder();
	cout << "===========================================================\n\n";
}
void postOrder(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "===================== [PostOrden]===========================\n";
	RBTree.postOrder();
	cout << "===========================================================\n\n";
}

void menu(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
    cout<<endl;
    cout <<" "<<endl;
    Menu m("\n\n\t============= [Menu] ============");
    m.add_option(MenuOption("  |\t1. Ingresar un valor			    |", [&](MenuOptionArguments args) {
        system("cls");
		insert(RBTree);
        return 0;
	}));
    m.add_option(MenuOption("  |\t2. Eliminar un valor			    |", [&](MenuOptionArguments args) {
		system("cls");
		remove(RBTree);
		return 0;
	}));
    m.add_option(MenuOption("  |\t3. Buscar un valor			    |", [&](MenuOptionArguments args) {
		system("cls");
		search(RBTree);
		return 0;
	}));
    m.add_option(MenuOption("  |\t4. Imprimir Arbol    			    |", [&](MenuOptionArguments args) {
		system("cls");
		print(RBTree);
		return 0;
	}));
    m.add_option(MenuOption("  |\t5. Recorrido         			    |", [&](MenuOptionArguments args) {
        system("cls");
        subMenu(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  |\t6. Extras         			    |", [&](MenuOptionArguments args) {
        system("cls");
        extrasMenu(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  |\t7. Salir        			    |", [&](MenuOptionArguments args) {
		system("cls");
		std::cout << "\n\nSalio con exito del programa..." << std::endl;
		m.stop();
	}, false));
    m.display();
}
void subMenu(ArbolRN RBTree){
    cout<<endl;
    Menu m("\n\n    ============= [Recorrido] ============");
    m.add_option(MenuOption("  |\t1. PreOrden			    |", [&](MenuOptionArguments args) {
        system("cls");
        preOrder(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  |\t2. InOrden			    |", [&](MenuOptionArguments args) {
        system("cls");
        inOrder(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  |\t3. PostOrden			    |", [&](MenuOptionArguments args) {
        system("cls");
        postOrder(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  |\t4. Regresar			    |", [&](MenuOptionArguments args) {
        system("cls");
        cout << "\n\nRegresando..." << endl;
        system("pause");
        menu(RBTree);
        return 0;
    }));
    m.display();
}

void extrasMenu(ArbolRN RBTree){
    cout<<endl;
    Menu m("\n\n      ============= [Extras] ============");
    m.add_option(MenuOption("  |\t1. Guardar en Txt y Dat	            |", [&](MenuOptionArguments args) {
        system("cls");
        RBTree.saveTreeTxt();
		RBTree.saveTreeBin();
		RBTree.saveTxtData();
        cout << "\n\nGuardado con exito , los archivos se abriran enseguida , por favor espere" << endl;
		system("ArbolRN.txt");
		system("ArbolRN.dat");
        return 0;
    }));
    m.add_option(MenuOption("  |\t2. Guardar en Pdf		    |", [&](MenuOptionArguments args) {
		Generar p;
        system("cls");  
		p.generarPDF("ArbolRB.pdf");
		cout << "\n\nGuardado con exito , el archivo se abriran enseguida , por favor espere" << endl;
		system ("ArbolRB.pdf");
        return 0;
    }));
    m.add_option(MenuOption("  |\t3. Foto pixelada 		    |", [&](MenuOptionArguments args) {
        system("cls");
        system("Imagen.exe");
        return 0;
    }));
    m.add_option(MenuOption("  |\t4. Backup     			    |", [&](MenuOptionArguments args) {
        system("cls");
        cout << "\n\nBienvenido a Backup" << endl;
        //system("Backup.exe");
        return 0;
    }));
    m.add_option(MenuOption("  |\t5. Regresar	     		    |", [&](MenuOptionArguments args) {
        system("cls");
        cout << "\n\nRegresando..." << endl;
        system("pause");
        menu(RBTree);
        return 0;
    }));
    m.display();
}

