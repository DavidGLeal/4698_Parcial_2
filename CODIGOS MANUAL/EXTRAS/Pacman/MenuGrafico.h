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

#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>

void Limpiar();								  // funcion para limpiar pantalla
void GotoXY(int x, int y);					  // funcion para posicionar el cursor
void Escribir(const char *txt);				  // Funcion para imprimir en pantalla
void Escribir(int x, int y, const char *txt); // funcion para imprimir en pantalla con coordenadas
void ColorTexto(int color);					  // definir color del texto
void Replica(const char c, int can);
void ReplicaH(int x, int y, const char *c, int can);
void ReplicaV(int x, int y, const char *c, int can);
void Rectangulo(int x, int y, int w, int h, const char *c); // dibuja un rectangulo
void PonerColorA(int color, int colorf);
void PonerColorA(int color, int colorf);
void PonerColorB(int color, int colorf);

class Opcion
{
public:
	int id;
	char name[128];
};

class MENU
{
public:
	MENU();
	virtual ~MENU();
	void Poner_Color(int color, int colorb);
	void Poner_Espacio(int s);
	void Agregar_Items(const char *txt, int index);
	int Dibujar(int x, int y);
private:
	int COLOR, COLORB, ESPACIO;
	int con;
	Opcion Opcion[10];
	int OPC_SEL;
};
