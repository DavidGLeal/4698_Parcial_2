/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERÍA DE SOFTWARE             
	AUTORES:
        Dylan Hernández
        Andrés Almeida
	Juan Reyes
        Brandon Masacela
        GRUPO: 3
   FECHA DE CREACION:        Lunes, 22 de agosto de 2022 07:25 p.m. 	
   FECHA DE MODIFICACION:     Miercoles, 24 de agosto de 2022 01:52 a.m.
 * --------------------------
 * Planteamiento: Elaborar simulación del juego Pac-Man, aplicando algoritmos
 * --------------------------
 */
#include <direct.h>
#include <time.h>
#include <windows.h>
#include <string>
#include "Backup.h"

std::string direccionBackup = "C://Tercer Nivel//Estructura de Datos y Algoritmos//Programas//0822_ProyectoP3_Pacman//Backup";

Backup::Backup()
{
	mkdir(direccionBackup.c_str());
}
void Backup::generarBackup(string nombreArchivo)
{
	char fecha[25];
	time_t current_time;
	current_time = time(NULL);
	ctime(&current_time);
	strcpy(fecha, ctime(&current_time));
	std::string nombre = direccionBackup + "//";
	for (int i = 0; i < 20; i++)
	{
		if (fecha[i] != 32 && fecha[i] != '\0')
		{
			if (fecha[i] == 58)
			{
				nombre += "-";
			}
			else
			{
				nombre += fecha[i];
			}
		}
	}
	nombre += ".txt";
	string palabra;
	ifstream fin;
	ofstream fout;
	fin.open(nombreArchivo + ".txt");
	fout.open(nombre);
	while (fin >> palabra)
	{
		fout << palabra<<endl;
		cout << palabra<<endl;
	}
	fin.close();
	fout.close();
	cout << "\n Backup Completo....";
}
vector<string> Backup::obtenerNombres()
{
	vector<string> nombres;
	string buscar_path = direccionBackup + "//*.*";
	WIN32_FIND_DATAA fd;
	HANDLE hFind = FindFirstFileA(buscar_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				nombres.push_back((const char *)fd.cFileName);
			}
		} while (FindNextFileA(hFind, &fd));
		FindClose(hFind);
	}
	return nombres;
}
void Backup::obtenerArchivos()
{
	vector<string> nombres;
	nombres = obtenerNombres();
	cout << endl;
	cout << "ARCHIVOS GUARDADOS " << endl;
	cout << "Fecha     Hora " << endl;
	for (int i = 0; i < nombres.size(); i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 8; j++)
			cout << nombres[i][j];
		cout << " | ";
		for (int k = 8; k < 16; k++)
		{
			if (nombres[i][k] == 45)
				cout << ":";
			else
				cout << nombres[i][k];
		}
		cout << endl;
	}
}
void Backup::recuperarArchivo(string nombreRecuperar, string nombreNuevo)
{
	ifstream fin;
	ofstream fout;
	fin.open(direccionBackup + "//" + nombreRecuperar, ios::in);
	fout.open(nombreNuevo + ".txt", ios::out);
	string palabra;
	while (fin >> palabra)
	{
		cout << palabra<<endl;
		fout << palabra<<endl;
	}
	fin.close();
	fout.close();
	cout << "\n Archivo recuperado con exito....";
}
