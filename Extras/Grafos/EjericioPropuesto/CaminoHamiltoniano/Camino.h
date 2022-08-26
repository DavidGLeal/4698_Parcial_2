#ifndef CAMINO_H
#define CAMINO_H

#include <bits/stdc++.h>
using namespace std;

#define V 5

class Camino
{
	public:
		void imprimir_solucion(int path[]);
		bool es_seguro(int v, bool graph[V][V], int path[], int pos);
		bool ciclo_ham_util(bool graph[V][V], int path[], int pos);
		bool ciclo_ham(bool graph[V][V]);
	protected:
};

#endif