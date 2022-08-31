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

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <thread>
#include <vector>
#include <windows.h>

using namespace std;

#include "Grafico.cpp"
#include "ImprimirFotoConsola.cpp"
#include "Login.cpp"
#include "MenuGrafico.cpp"
#include "Usuario.h"
#include "Backup.cpp"
#include "Iniciar.cpp"
#include "pdf.cpp"

#define VALORX 4
#define VALORY 4
#define ANCHO 100
#define ALTO 20

int opcionMain = 0;
int opcionSesion = 0;
int opcionAdmin = 0;

Backup obj;
Login *login;
IngresarDatos *ing = new IngresarDatos();
Usuario usuario;
vector<Usuario> usuarios;
vector<string> backups;

Grafico graficoPacman;
Iniciar juegoPacman;
fstream reporte;
ostringstream out;

MENU menuSesion;
MENU menuPrincipal;
MENU menuAdmin;
PDF p;

std::string texto = "Saludos, Damas y Caballeros. PAC-MAN | Saludos, Damas y Caballeros. Enfoque Algoritmico PAC-MAN | ";

void Registrar()
{
	Rectangulo(VALORX, VALORY, ANCHO, ALTO, "*");
	Escribir(12, 4, "*** Registro ***\n");
	usuario = usuario.crearUsuario(20, 9);
	if (usuario.buscarUsuario(usuarios, usuario.cedula))
	{
		Limpiar();
		Escribir(20, 20, "Ya tenemos una cuenta con esos datos. Inicia Sesion desde el menu!");
		usuarios.pop_back();
	}
	else
	{
		Limpiar();
		Escribir(20, 20, "Registro exitoso - Presiona cualquier tecla para continuar!");
		usuarios.push_back(usuario);
	}
	_getch();
	Limpiar();
	opcionMain = 0;
}

void reportePDF()
{
	out << "reporte" << ".pdf";

	string nombreArc = out.str();

	cout << "-----------------------------------------" << "\n";
	cout << "Creando archivo: [" << nombreArc << "]"       << "\n";
	cout << "-----------------------------------------" << "\n";

	p.setFont(PDF::HELVETICA_BOLD_OBLIQUE, 14);
	string s = "Reporte de Usuario";
	//p.setFillColor(0,255,255);
	p.showTextXY(s,110,762);
	p.setFont(PDF::TIMES_ITALIC, 12);

	reporte.open("reporte.txt", ios::in);
	string palabraActual;
	int lineas = 0;
	while(reporte >> palabraActual)
	{
		p.showTextXY(palabraActual,50,747 - 13*lineas);
		lineas++;
	}
	reporte.close();

	string errMsg;

	if(!p.writeToFile(nombreArc, errMsg))
	{
		cout << errMsg << endl;
	}
	else
	{
		cout << "(Se ha creado el PDF)" << endl;
		//system(("start " + nombreArc).c_str());
	}
}

void IniciarSesion()
{
	bool salirSesion = false;
	opcionSesion = 0;
	Limpiar();
	if (!usuarios.empty())
	{
		Rectangulo(VALORX, VALORY, ANCHO, ALTO, "*");
		Escribir(12, 4, "*** Inicio de Sesion ***\n");
		ing->setCoordenadas(20, 9);
		login = new Login(ing->ingresarDatosStringPermisivo("su usuario"),
						  ing->ingresarDatosOculto("su clave"));
		Limpiar();
		int posicion = usuario.recuperarUsuario(usuarios, login->getUsuario());
		if (login->validarLoginNormal(usuarios, posicion))
		{
			Limpiar();
			usuario = usuarios.at(posicion);
			menuSesion.Agregar_Items(" 1. Jugar ", 1);
			menuSesion.Agregar_Items(" 2. Salir ",2);
			menuSesion.Poner_Espacio(2);

			do
			{
				Limpiar();
				ColorTexto(10);

				if (opcionSesion == 0)
				{
					std::string titulo = "Bienvenida/o '" + usuarios.at(posicion).nombre + "'";
					std::string cta = "Lista/o? Comencemos!";
					PonerColorB(2, 19);
					Rectangulo(VALORX, VALORY, ANCHO, ALTO, "*");
					PonerColorA(2, 22);
					Escribir(22, 4, titulo.c_str());
					Escribir(22, 5, cta.c_str());
					opcionSesion = menuSesion.Dibujar(44, 8);
				}

				switch (opcionSesion)
				{
				case 1:
					Limpiar();
					juegoPacman.comenzarJuego();
					reporte.open("reporte.txt", ios::out);
					reporte << "=================================="<<endl;
					reporte << "Usuario: " << usuarios.at(posicion).usuario<<endl;
					reporte << "Puntaje: " << juegoPacman.jg.puntaje<<endl;
					reporte << "Vidas: " << juegoPacman.jg.vidas<<endl;
					reporte << "=================================="<<endl;
					reporte.close();
					cout << "Se ha generado su archivo .txt" <<endl;
					reportePDF();
					_getch();
					system("start reporte.txt");
					system("start reporte.pdf");
					Limpiar();
					opcionSesion = 0;
					break;
				case 2:
					Limpiar();
					obj.generarBackup("recuperacion");
					salirSesion = true;
				}
			} while (salirSesion == false);

			opcionMain = 0;
			Limpiar();
		}
		else
		{
			Limpiar();
			Escribir(20, 10, "Credenciales Incorrectas. Intente nuevamente.");
			_getch();
			Limpiar();
			opcionMain = 0;
		}
	}
	else
	{
		Limpiar();
		Escribir(15, 10, "Vaya! Parece ser que no tenemos usuarios registrados aun.");
		Escribir(15, 10, "Gustas Registrarte?.");
		_getch();
		Limpiar();
		opcionMain = 0;
	}
	Limpiar();
}

void Administrar()
{
	opcionAdmin = 0;
	Limpiar();
	bool salirAdmin = false;
	Rectangulo(VALORX, VALORY, ANCHO, ALTO, "*");
	Escribir(12, 4, "*** Administrar ***\n");
	ing->setCoordenadas(20, 9);
	login = new Login(ing->ingresarDatosStringPermisivo("su usuario"), ing->ingresarDatosOculto("su clave"));
	Limpiar();
	if (login->validarLoginAdmin(login))
	{
		string titulo = "Que gusto verte nuevamente! " + login->getUsuario();
		menuAdmin.Agregar_Items(" 1. Consultar Usuarios   ", 1);
		menuAdmin.Agregar_Items(" 2. Recuperar Sistema    ", 2);
		menuAdmin.Agregar_Items(" 3. Abrir Documentacion  ", 3);
		menuAdmin.Agregar_Items(" 4. Salir                ", 4);
		menuAdmin.Poner_Espacio(2);

		do
		{
			Limpiar();
			ColorTexto(10);

			if (opcionAdmin == 0)
			{
				PonerColorB(2, 19);
				Rectangulo(VALORX, VALORY, ANCHO, ALTO, "*");
				PonerColorA(2, 22);
				Escribir(12, 4, titulo.c_str());
				opcionAdmin = menuAdmin.Dibujar(16, 6);
			}

			switch (opcionAdmin)
			{
			case 1:
				Limpiar();
				if (!usuarios.empty())
				{
					cout <<endl<<endl;
					for (int i = 0; i < usuarios.size(); i++)
					{
						cout << "Nombre: " << usuarios.at(i).nombre << "Usuario: " << usuarios.at(i).usuario<<endl;
					}
				}
				else Escribir(22,10,"Lo sentimos, no hay usuarios registrados.");
				_getch();
				opcionAdmin = 0;
				break;
			case 2:
				Limpiar();
				backups = obj.obtenerNombres();
				obj.obtenerArchivos();
				int aux;
				cout << "Escoja el punto del sistema que quiera recuperar:" << endl;
				cin >> aux;
				--aux;
				//cout << "Escriba el nuevo nombre del archivo para guardar:" << endl;
				//cin >> nuevoArchivo;
				obj.recuperarArchivo(backups.at(aux), "recuperacion");
				juegoPacman.jg.recuperarPuntaje();
				opcionAdmin = 0;
				break;
			case 3:
				Limpiar();
				system("start html\\index.html");
				opcionAdmin = 0;
				break;
			case 4:
				Limpiar();
				opcionAdmin = 0;
				salirAdmin = true;
				break;
			}
		} while (salirAdmin == false);
	}
	else
	{
		Escribir(20, 20, "Estas seguro de que administras este lugar? Intenta nuevamente.");
		system("pause");
	}
	opcionMain = 0;
	Limpiar();
}

void MostrarFoto()
{
	HWND consola = GetConsoleWindow();
  	HDC gestor = GetDC(consola);
	DrwImage("C:\\Tercer Nivel\\Estructura de Datos y Algoritmos\\Programas\\0822_ProyectoP3_Pacman\\fotoConjunta.bmp",&gestor);
  	getchar();

	opcionMain = 0;
}

void MostrarAyuda()
{
	system("start AyudaPacMan.chm");
	opcionMain = 0;
}

void AcercaDe()
{
	Limpiar();
}

void MarquesinaX(std::string mensaje)
{
	HANDLE controlador = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO canvas;
	GetConsoleScreenBufferInfo(controlador, &canvas);
	int longitud;
	longitud = canvas.srWindow.Right - canvas.srWindow.Left + 1;

	while (true)
	{
		string temp = mensaje;
		mensaje.erase(0, 1);
		mensaje += temp[0];
		CHAR_INFO *buffer = (CHAR_INFO *)calloc(longitud, sizeof(CHAR_INFO));

		for (int i = 0; i < mensaje.length(); i++)
		{
			buffer[i].Char.AsciiChar = mensaje.at(i);
			buffer[i].Attributes = 100;
		}

		SMALL_RECT pos;
		pos.Left = (SHORT)10;
		pos.Top = (SHORT)0;
		pos.Right = (SHORT)mensaje.length() + 10;
		pos.Bottom = (SHORT)1;
		WriteConsoleOutputA(controlador, buffer, {pos.Right, pos.Bottom}, {0, 0}, &pos);
		free(buffer);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void mostrarMenu()
{
	opcionMain = 0;
	Limpiar();
	bool salirMain = false;

	menuPrincipal.Agregar_Items(" 1. Registrarse      ", 1);
	menuPrincipal.Agregar_Items(" 2. Iniciar Sesion   ", 2);
	menuPrincipal.Agregar_Items(" 3. Administrar      ", 3);
	menuPrincipal.Agregar_Items(" 4. Fotografia       ", 4);
	menuPrincipal.Agregar_Items(" 5. Ayuda            ", 5);
	menuPrincipal.Agregar_Items(" 6. Salir            ", 6);
	menuPrincipal.Poner_Espacio(2);

	do
	{
		ColorTexto(10);

		if (opcionMain == 0)
		{
			PonerColorB(2, 7);
			Rectangulo(VALORX, VALORY, ANCHO, ALTO, "*");
			PonerColorA(2, 15);
			Escribir(46, 4, " PAC-MAN ");
			Escribir(26, 5, " Un Enfoque Algoritmico para el Modo de Juego ");
			graficoPacman.SetRadio(40);
			graficoPacman.DibujarPacman(180,260,graficoPacman.AMARILLO,4);
			graficoPacman.DibujarPacman(840,260,graficoPacman.AMARILLO,4);
			Sleep(100);
			opcionMain = menuPrincipal.Dibujar(40, 8);
		}

		switch (opcionMain)
		{

		case 1:
			Limpiar();
			Registrar();
			break;

		case 2:
			Limpiar();
			IniciarSesion();
			break;

		case 3:
			Limpiar();
			Administrar();
			break;

		case 4:
			Limpiar();
			MostrarFoto();
			break;

		case 5:
			Limpiar();
			MostrarAyuda();
			break;
		case 6:
			Limpiar();
			AcercaDe();
			salirMain = true;
			break;
		}

	} while (salirMain == false);
}
int main(int argc, char *argv[])
{
	std::thread hiloSecundario(MarquesinaX, texto);
	hiloSecundario.detach();
	// system("cls");
	// cout << "\n";
	PlaySoundA((LPCSTR)"C:\\Tercer Nivel\\Estructura de Datos y Algoritmos\\Programas\\0822_ProyectoP3_Pacman\\pacManMusicaVolumenBajo.wav", NULL, SND_ASYNC);
	mostrarMenu();
	return 0;
}
