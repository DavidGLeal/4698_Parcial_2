#include "Camino.h"

bool Camino::es_seguro(int v, bool graph[V][V], int path[], int pos)
{
    if (graph [path[pos - 1]][ v ] == 0)
        return false;
 
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}

bool Camino::ciclo_ham_util(bool graph[V][V],
                  int path[], int pos)
{
    
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
 
    for (int v = 1; v < V; v++)
    {
        if (es_seguro(v, graph, path, pos))
        {
            path[pos] = v;
 
            if (ciclo_ham_util (graph, path, pos + 1) == true)
                return true;
 
            path[pos] = -1;
        }
    }
    return false;
}
 
bool Camino::ciclo_ham(bool graph[V][V])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
        
    path[0] = 0;
    if (ciclo_ham_util(graph, path, 1) == false )
    {
        cout << "\nNo existe la solucion";
        return false;
    }
 
    imprimir_solucion(path);
    return true;
}

void Camino::imprimir_solucion(int path[])
{
    cout << "Existe Solucion:"
            " El siguiente es un ciclo Hamiltoniano \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << " ";
    cout << endl;
}
