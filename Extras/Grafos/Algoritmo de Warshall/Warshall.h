#pragma once 
#include <iostream>
#define nV 5
#define INF 999 

using namespace std;

class Warshall
{
public:
    void printMatrix(int matrix[][nV]);
    void floydWarshall(int graph[][nV]);
};

void Warshall::printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void Warshall::floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    // Agregando vértices individualmente
    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) // si la suma de los pesos es menor que el peso actual
                    matrix[i][j] = matrix[i][k] + matrix[k][j]; // actualizamos el peso
            }
        }
    }
    printMatrix(matrix);
}