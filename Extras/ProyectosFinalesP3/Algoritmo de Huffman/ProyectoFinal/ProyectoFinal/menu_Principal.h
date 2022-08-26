#pragma once

#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <limits>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <ctime>
#include <thread>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "HuffmanTree.h"
#include "TransformUtils.h"
#include "BinaryFileHelper.h"
#include "menu.h"
#include "menu_option.h"
#include "registro.h"
#include <direct.h>
#define MAX 10005 
#define Nodo pair< int , int > 
#define INF 1<<30 



struct cmp {
	bool operator() (const Nodo& a, const Nodo& b) {
		return false;
	}
};
vector< Nodo > ady[MAX];
int distancia[MAX];
bool visitado[MAX];
priority_queue< Nodo, vector<Nodo>, cmp > Q;
int V = 18;
int previo[MAX];


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
void corto(int inicial);
void init();
void minimizacion(int actual, int adyacente, int peso);
void print(int destino);




void menuPrincipal() {
	std::string test = " E S T R U C T U R A  D E  D A T O S  H U F F M A N  I N G E N I E R I A  S O F T W A R E  E S P E   ";
	std::thread t2(marquee, test);
	t2.detach();
	registro();
	Menu m("\n\n\t===[PROYECTO FINAL]===");

	m.add_option(MenuOption(" |\t1._COMPRIMIR ARCHIVO              |", [&](MenuOptionArguments args) {
		system("cls");

		std::cout << "SE COMPRIMIRA EL TXT " << endl;
		try
		{
			const auto input = "Blancanieves.txt";
			const auto output = "BlancanievesCompression.bin";

			ifstream file(input);
			if (!file.is_open()) throw exception("Exception:No se puede abrir el archivo.");

			stringstream stream;
			stream << file.rdbuf();
			file.close();

			const auto file_content = stream.str();
			const auto file_size = BinaryFileHelper::get_file_size(input);
			std::cout << "Antes de la compresion : " << file_size << " bytes" << endl;

			HuffmanTree huffman_tree(file_content);
			const auto encoded = huffman_tree.encode(file_content);
			const auto bytes = TransformUtils::transformar_string_to_bytes(encoded);

			BinaryFileHelper::write(output, bytes);
			const auto after_size = BinaryFileHelper::get_file_size(output);
			const auto delta = file_size - after_size;

			std::cout << "Despues de la compresion : " << after_size << " bytes" << endl;
			std::cout << "Tiempo de ejecicion: (" << static_cast<double>(delta) / file_size << ")" << endl;

			const auto output_data = BinaryFileHelper::read(output);
		}
		catch (exception& e)
		{
			std::cout << e.what() << endl;
		}
		cin.get();
		return 0;


		}));

	m.add_option(MenuOption(" |\t2._DESCOMPRIMIR ARCHIVO           |", [&](MenuOptionArguments args) {
		system("cls");
		std::cout << "SE DESCOMPRIMIRA EL ARCHIVO " << endl;
		try
		{
			const auto input = "Blancanieves.txt";
			const auto output = "BlancanievesCompression.bin";
			ifstream file(input);
			if (!file.is_open()) throw exception("Exception:No se puede abrir el archivo.");
			stringstream stream;
			stream << file.rdbuf();
			file.close();
			const auto file_content = stream.str();
			HuffmanTree huffman_tree(file_content);
			const auto encoded = huffman_tree.encode(file_content);
			const auto bytes = TransformUtils::transformar_string_to_bytes(encoded);
			const auto output_data = BinaryFileHelper::read(output);
			std::cout << huffman_tree.decode(output_data);
			return 0;
		}
		catch (exception& e)
		{
			std::cout << "NO SE ENCUENTRA NINGUN ARCHIVO COMPRIMIDO" << endl;
		}


		}));
	m.add_option(MenuOption(" |\t3._GRAFO UNIVERSIDAD              |", [&](MenuOptionArguments args) {
		system("cls");
		int a;
		int opc;
		int inicio, fin, t;
		float tiempoS;
		int repite;
		bool continuar = true;
		int E = 30, origen, destino, peso, inicial;

		cout <<endl<<endl<<"\tBienvenido al programa de Grafos para hallar la distancia mas corta de un nodo o vertice al otro. " << endl;
		int matriz[] = { 1, 2 ,15,
					  1,3,10,
				   2, 12 ,30,
				   1 ,18 ,5,
				   1 ,13 ,15,
				   1 ,7 ,15,
				   7 ,11 ,50,
				   13 ,8 ,10,
				   17 ,1 ,40,
				   17 ,3 ,35,
				   16 ,17 ,20,
				   15 ,16 ,10,
				   10 ,16 ,50,
				   9 ,15 ,15,
				   14 ,15 ,15,
				   5 ,6 ,8,
				   11 ,5 ,10,
				   14 ,4 ,40,
				   13 ,7 ,5,
				   12 ,10, 15,
				   8 ,4, 5,
				   4 ,11, 5,
				   7 ,5 ,20,
				   7 ,6 ,15,
				   6 ,9 ,10,
				   5 ,14 ,15,
				   9 ,14 ,10,
				   18 ,13 ,5,
				   18 ,8 ,5,
				   8 ,5 ,30 };

		for (int i = 0; i < E; i++) {
			origen = matriz[i * 3];
			destino = matriz[i * 3 + 1];
			peso = matriz[i * 3 + 2];
			ady[origen].push_back(Nodo(destino, peso));

		}

		cout << endl << endl;
		cout << "\t\t .----------------------------------." << endl;
		cout << "\t\t | Nodo|          Sitio             |" << endl;
		cout << "\t\t .----------------------------------." << endl;
		cout << "\t\t |  1  |  Entrada/Garita            |" << endl;
		cout << "\t\t |  2  |  Policlinico               |" << endl;
		cout << "\t\t |  3  |  Residencias               |" << endl;
		cout << "\t\t |  4  |  Laboratorio de Fisica     |" << endl;
		cout << "\t\t |  5  |  Edificio. Bloque C        |" << endl;
		cout << "\t\t |  6  |  Edif.Central / Bloque A, B|" << endl;
		cout << "\t\t |  7  |  Edificio Administrativo   |" << endl;
		cout << "\t\t |  8  |  Idiomas                   |" << endl;
		cout << "\t\t |  9  |  Edificio.Innovativa       |" << endl;
		cout << "\t\t | 10  |  Lab.Ing.Mecanica          |" << endl;
		cout << "\t\t | 11  |  Edif.Posgrados/Bloque G.H |" << endl;
		cout << "\t\t | 12  |  Lab.Ing.Electronica       |" << endl; 
		cout << "\t\t | 13  |  Biblioteca                |" << endl; 
		cout << "\t\t | 14  |  Areas Verdes/canchas      |" << endl;
		cout << "\t\t | 15  |  Estadio                   |" << endl;
		cout << "\t\t | 16  |  Centro de Investigacion   |" << endl;
		cout << "\t\t | 17  |  Coliseo                   |" << endl;
		cout << "\t\t .----------------------------------." << endl;


		cout <<endl<< "\tINGRESE EL VERTICE INICIAL : ";
		cin >> inicial;
		while (inicial <=0 || inicial > 17){
			cout << "\tERROR: EL VERTICE INICIAL NO EXISTE" << endl;
			cout << "\tINGRESE EL VERTICE INICIAL : ";
			cin >> inicial;
		}
		inicio = clock();
		corto(inicial);
		system("ESPEGRAFO.jpeg");
		fin = clock();
		t = fin - inicio;
		tiempoS = ((float)t) / CLOCKS_PER_SEC;
		cout << "El tiempo transcurrido fue: " << tiempoS << endl;

		return 0;

		}));
	m.add_option(MenuOption(" |\t4._IMAGEN DEL GRUPO               |", [&](MenuOptionArguments args) {
		system("cls");
		system("gestorProyecto.exe");
		return 0;

		}));
	m.add_option(MenuOption(" |\t5._C++ DOCS                    |", [&](MenuOptionArguments args) {

		system("index.html");
		cout << "Por Favor espere los c++ docs se abrirar de inmediato" << endl;

		}));

	m.add_option(MenuOption(" |\t6._AYUDA                       |", [&](MenuOptionArguments args) {

		system("Manual_Usuario.htm");
		cout << "Por Favor espere el manual se abrira de inmediato" << endl;

		}));

	m.add_option(MenuOption(" |\t7._SALIR                       |", [&](MenuOptionArguments args) {

		system("cls");
		std::cout << "\n\nSalio con exito del programa..." << std::endl;
		m.stop();
		}, false));
	m.display();

}


void init() {
	for (int i = 0; i <= V; ++i) {
		distancia[i] = INF;
		visitado[i] = false;
		previo[i] = -1;
	}
}


void minimizacion(int actual, int adyacente, int peso) {
	if (distancia[actual] + peso < distancia[adyacente]) {
		distancia[adyacente] = distancia[actual] + peso;
		previo[adyacente] = actual;
		Q.push(Nodo(adyacente, distancia[adyacente]));
	}
}


void print(int destino) {
	if (previo[destino] != -1)
		print(previo[destino]);
	printf("%d ", destino);
}

void corto(int inicial) {
	init();
	Q.push(Nodo(inicial, 0));
	distancia[inicial] = 0;
	int actual, adyacente, peso;
	while (!Q.empty()) {
		actual = Q.top().first;
		Q.pop();
		if (visitado[actual]) continue;
		visitado[actual] = true;

		for (int i = 0; i < ady[actual].size(); ++i) {
			adyacente = ady[actual][i].first;
			peso = ady[actual][i].second;
			if (!visitado[adyacente]) {
				minimizacion(actual, adyacente, peso);
			}
		}
	}


	printf("\tDistancias mas cortas iniciando en vertice %d\n", inicial);
	for (int i = 1; i <= V; ++i) {
		printf("\tVertice %d , distancia mas corta = %d\n", i, distancia[i]);
	}

	puts("\tPara hallar el camino mas corto del vertice de origen al vertice destino,");
	printf("\tINGRESE EL VERTICE DESTINO: ");
	int destino;
	cin >> destino;
	while (destino <= 0 || destino > 17) {
		cout << "\tERROR: EL VERTICE DE DESTINO NO EXISTE" << endl;
		cout << "\tINGRESE EL VERTICE DESTINO : ";
		cin >> destino;
	}

	print(destino);
	printf("\n");
}












