#include <iostream>
#include "Grafo.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int E , origen, destino , peso , inicial;
	Grafo grafo;
    printf("Ingrese el numero de vertices y de nodos: ");
	scanf("%d %d" , &grafo.vertices , &E );
	int matriz[] = {1, 2, 15,
                    1, 3, 10,
                    2, 12, 30,
                    1, 18, 5,
                    1, 13, 15,
                    1, 7, 15,
                    7, 11, 50,
                    13, 8, 10,
                    17, 1, 40,
                    17, 3, 35,
                    16, 17, 20,
                    15, 16, 10,
                    10, 16, 50,
                    9, 15, 15,
                    14, 15, 15,
                    5, 6, 8,
                    11, 5, 10,
                    14, 4, 40,
                    13, 7, 5,
                    12, 10, 15,
                    8, 4, 5,
                    4, 11, 5,
                    7, 5, 20,
                    7, 6, 15,
                    6, 9, 10,
                    5, 14, 15,
                    9, 14, 10,
                    18, 13, 5,
                    18, 8, 5,
                    8, 5, 30};
    for(int i=0;i<E;i++){
        origen = matriz[i*3];
        destino = matriz[i*3+1];
        peso = matriz[i*3+2];
        grafo.matriz_adyacente[ origen ].push_back( Node( destino , peso ) ); 
    }
    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    grafo.bellmanFord( inicial );
    return 0;
}