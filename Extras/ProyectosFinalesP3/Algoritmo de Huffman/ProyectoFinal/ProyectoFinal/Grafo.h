#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10005 
#define Nodo pair< int , int >
#define INF 1<<30 

class Grafo
{
public:
	vector < Nodo > ady[MAX];
	int distancia[MAX];
	bool visitado[MAX];
	int V = 18;
	int previo[MAX];
	void minimizacion(int actual, int adyacente, int peso);
	void print(int destino);
	void corto(int inicial);
	void init();

};

#endif