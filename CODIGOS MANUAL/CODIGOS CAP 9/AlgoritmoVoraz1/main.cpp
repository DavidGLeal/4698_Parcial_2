#include <math.h>
#include <string.h>
#include <iostream>
#include "dijkstra.cpp"

using namespace std;

int destino, origem, vertices = 0;
int custo, *custos = NULL;

void menu(void)
{
    cout << "Implementacion del Algoritmo de Dijasktra\n";
    cout << "\n1. Añadir un Grafo";
    cout << "\n2. Determinar el menor camino de los grafos";
    cout << "\n3. Sair del programa";
    cout << endl;
    cout << "Escoga una opcion: ";
}

int main()
{
    dijkstra obj;
    string opcion;
    do
    {
        menu();
        cin >> opcion;
        if (opcion == "1")
        {
            obj.add();
        }
        else if (opcion == "2" && (vertices > 0))
        {
            obj.buscar();
        }
    } while (opcion != "3");
    cout << "\nHasta la proxima...\n\n";
    delete (custos);
    exit(0);
}
