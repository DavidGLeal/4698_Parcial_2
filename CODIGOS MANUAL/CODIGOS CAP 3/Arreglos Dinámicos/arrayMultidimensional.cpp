#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include <conio.h>
int main () {
	int **p;
	int n, m, i;
	do {
		printf ("\n Número de filas: "); scanf ("%d", &n);
	} while (n <= 0);
	p = (int**) malloc (n*sizeof (int*));
	for (i = 0; i < n; i++){
		int j;
		printf ("Número de elementos de fila %d ", i + 1);
		scanf ("&d", &m);
		p[i] = (int*) malloc (m*sizeof(int));
		for (j = 0; i < m; j++) {
			scanf ("%d", &p[i][j]);
		}
	}
	getch();
}
