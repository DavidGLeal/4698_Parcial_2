#pragma once 
/*
* @flie archivo.h
* @author Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos - Estructura de Datos
* @date 19/7/2022
* @brief Archivo de cabecera para la clase archivo.h
* @version 1.0
* 
*@copyright Copyright (c) 2022,Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos 
*@license MIT License
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream archivo;

char name[100];
char *pass = new char[100];
char nameaux[100];
char passaux[100];
char aux_pass[100];

/**
 * @brief El metodo insert() permite insertar un nuevo usuario en el archivo
 *
 * @param name
 * @param pass
 */
void insert(char *name, char *pass) {
	archivo.open("usuarios.txt", ios::app);
	//validate
	if (archivo.fail()) {
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	archivo << "\nName: " << name << " " << "Password: " << pass << endl;
	archivo.close();
}

/**
 * @brief El metodo readfile() permite leer el archivo y validar si el usuario existe
 *
 * @param name
 * @param pass
 * @return true
 * @return false
 */
bool readfile(char *name, char *pass) {
	ifstream archivo;
	archivo.open("usuarios.txt", ios::in);
	if (archivo.fail()) {
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	string line;
	//comprobar si el usuario y la contrase�a son correctos
	while (getline(archivo, line)) {
		if (line.find(name) != string::npos && line.find(pass) != string::npos) {
			return true;
		}
	}
	archivo.close();
	return false;
}
