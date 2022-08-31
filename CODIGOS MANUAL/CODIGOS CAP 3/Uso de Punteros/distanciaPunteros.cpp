#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int vector[10],*p, *q;
	p = vector; /* Equivale a p = &vector[0]; */
	q = &vector[4]; /* apuntamos al 5º elemento */
	cout <<"El resultado de la distancia de ambos punteros en esta operacion es:" <<q - p << endl;
	system("pause>null");
}
