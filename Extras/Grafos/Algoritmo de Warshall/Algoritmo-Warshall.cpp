
#include "Warshall.h" 
#include <iostream>
using namespace std;

int main() {
  Warshall w;
  int graph[nV][nV] = {{0, 4, 8, INF ,INF},
                        {4, 0, 1, 2, INF},
                        {8, INF, 0, 4, 2},
                        {INF, 2, 4, 0, 7},
                        {INF, INF, 2, 7, 0}};
  system ("cls");
  
  cout << "********************* Algoritmo de Floyd-Warshall *********************" << endl;

  cout << "Matriz de adyacencia" << endl;
  w.printMatrix(graph);
  system ("pause");
  cout <<endl;
  cout << "Matriz resultante" << endl;    
  w.floydWarshall(graph);
}