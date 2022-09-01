#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

class dijkstra
{
public:
    dijkstra(/* args */);
    int destino;
    int origen;
    int vertices = 0;
    int custo;
    int *custos = NULL;
    void metododijkstra(int vertices, int origen, int destino, int *costos);
    void add(void);
    void buscar(void);
    ~dijkstra();
};
