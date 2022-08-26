#include "Grafo.h"

using namespace std;

void Grafo::minimizacion(int actual, int adyacente, int peso) {
    if (distancia[actual] + peso < distancia[adyacente]) {
        distancia[adyacente] = distancia[actual] + peso;
        previo[adyacente] = actual;
    }
}

void Grafo::print(int destino) {
    if (previo[destino] != -1)
        print(previo[destino]);
    printf("%d ", destino);
}

void Grafo::corto(int inicial) {
    init();
    distancia[inicial] = 0;
    int actual=0, adyacente=0, peso=0;
    
        if (visitado[actual]) 
        visitado[actual] = true;

        for (int i = 0; i < ady[actual].size(); ++i) {
            adyacente = ady[actual][i].first;
            peso = ady[actual][i].second;
            if (!visitado[adyacente]) {
                minimizacion(actual, adyacente, peso);
            }
        }



    printf("\tDistancias mas cortas iniciando en vertice %d\n", inicial);
    for (int i = 1; i <= V; ++i) {
        printf("\tVertice %d , distancia mas corta = %d\n", i, distancia[i]);
    }

    puts("\tPara hallar el camino mas corto del vertice de origen al vertice destino,");
    printf("\tIngrese el vertice destino: ");
    int destino;
    cin>>destino;
    print(destino);
    printf("\n");
}

void Grafo::init() {
    for (int i = 0; i <= V; ++i) {
        distancia[i] = INF;
        visitado[i] = false;
        previo[i] = -1;
    }
}
