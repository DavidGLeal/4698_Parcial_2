#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <vector>

using namespace std;
#define MAX 105  
#define Node pair< int , int > 
#define INF 1<<30 

class Grafo
{
	public:
		int nodo_previo[ MAX ];  
		int distancia_entre_nodos[ MAX ];      
		int vertices;  
		vector< Node > matriz_adyacente[ MAX ]; 
		
		void inicializar();
		void impresion( int destino );
		bool relajacion( int actual , int adyacente , int peso );
		void bellmanFord( int inicial );
		
};

#endif