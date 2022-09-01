#pragma once
/**
 * @file registro.h
 * @author Arias, Escobar,Portilla,Valdiviezo,Yanez
 * @brief cabecera del registro
 * @version 0.1
 * @date 2022-08-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include "archivo.h"
#include <string>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "menu_option.h"

using namespace std;

/**
 * @brief method registration of the user
 *
 */
void registration() {
	int v = 0;
	system("cls");
	fflush(stdin);
	std::cout << "\tRegistrarse" << endl;
	fflush(stdin);
	std::cout << "\nNombre: ";
	cin >> name;
	//system("pause");
	fflush(stdin);
	std::cout << "Contrasenia: ";
	for (int i = 0; i < 60; i++) {
		v = _getch();
		if ((v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
			aux_pass[i] = v;
			std::cout << "*";
		}
		else if (v == 13) {
			aux_pass[i] = '\0';
			break;
		}
	}
	pass = aux_pass;

	//cin.getline(pass, 100, '\n');
	fflush(stdin);
	insert(name, pass);

}
/**
 * @brief method to login
 *
 */
void login() {
	do {
		system("cls");
		std::cout << "\n\tLOG IN" << endl;
		fflush(stdin);
		std::cout << "\nNombre: ";
		cin >> nameaux;
		fflush(stdin);
		std::cout << "Contrasenia: ";
		for (int i = 0; i < 60; i++) {
			int v = _getch();
			if ((v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
				passaux[i] = v;
				std::cout << "*";
			}
			else if (v == 13) {
				passaux[i] = '\0';
				break;
			}
		}
		fflush(stdin);
		if (strcmp(nameaux, name) == 0 && strcmp(passaux, pass) == 0) {
			std::cout << "\n\tBienvenido " << name << endl;
			break;
		}
		else if (readfile(nameaux, passaux)) {
			std::cout << "\n\tBienvenido " << nameaux << endl;
			system("pause");
			break;
		}
		else {
			std::cout << "\n\tError en nombre o contrasenia" << endl;
			system("pause");
		}
		system("pause");
	} while (true);
}
/**
 * @brief method registro
 *
 */
void registro() {
	int option;
	char answer;
	Menu m("\nBIENVENIDO");
	m.add_option(MenuOption("1. Registrarse", [&](MenuOptionArguments args) {
		system("cls");
		registration();
		std::cout << "\nDesea iniciar sesion? (s/n): ";
		cin >> answer;
		if (answer == 's' || answer == 'S') {
			login();
			system("pause");
		}
		else {
			return;
		}
		m.stop();
		}));
	m.add_option(MenuOption("2. Ingresar", [&](MenuOptionArguments args) {
		system("cls");
		login();
		m.stop();
		return 0;
		}));

	m.add_option(MenuOption("3. Salir", [&](MenuOptionArguments args) {
		system("cls");
		cout << " " << endl;
		std::cout << "Salio con exito del programa..." << std::endl;
		exit(1);
		}, false));

	m.display();

}

