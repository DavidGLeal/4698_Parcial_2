#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "time.h"
#define MAX 4
using namespace std;
void ingresomat(int mat[][MAX]) {
	int num;
	srand(time(NULL));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			num = 1+ rand() % (20-1);
			mat[i][j] = num;
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}

int simetrica(int mat[][MAX]) {
	int cont = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (*(*(mat+i)+j) == *(*(mat + j) + i)) {
				cont++;
			}
		}
	}
		return cont;
}

int main(){
	int mat[MAX][MAX],cont;
	char op;
	do {
		//op = NULL;
		ingresomat(mat);
		cont=simetrica(mat);
		
if (cont == MAX*MAX)
			cout << "es simetrica" << endl;
		else
			cout << "no es simetrica" << endl;
		cout << "desea otra matriz" << endl;
		cin >> op;
	} while (op != 'n');
	system("pause");

	return 0;
}
