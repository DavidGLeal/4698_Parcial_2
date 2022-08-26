#include <iostream>
#include "Camino.h"



int main(int argc, char** argv) {
	Camino camino;
	/*
	(0)--(1)--(2)
 	|   /  \   |
 	|  /    \  | 
 	| /      \ |
	(3)-------(4)
	*/
	cout << "SOLUCION PRIMER CICLO" << endl;
	bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
    camino.ciclo_ham(graph1);
    
    /*
    (0)--(1)--(2)
	 |   / \   |
 	 |  /   \  | 
 	 | /     \ |
	(3)      (4)     
    */
    cout << "SOLUCION SEGUNDO CICLO" << endl;
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
    camino.ciclo_ham(graph2);
	return 0;
}