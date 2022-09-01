#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10005 //maximo numero de v?rtices
#define Node pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //

class Grafo
{
	public:
		struct comparador {
			bool operator() ( const Node &a , const Node &b ) {
   				return a.second > b.second;
			}
		};
		
		vector< Node > matriz_adyacente[ MAX ];
		int distancia_entre_nodos[ MAX ];
		bool nodo_visitado[ MAX ];
		priority_queue< Node , vector<Node> , comparador > Q;
		int vertices;
		int nodo_previo[ MAX ];
		void inicializacion();
		void relajacion( int actual , int adyacente , int peso );
		void impresion( int destino );
		void algoritmo_dijkstra( int inicial );
		
};

#endif