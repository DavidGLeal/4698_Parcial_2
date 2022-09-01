#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
using namespace std;
int main(){
 	system("color 3f");
 	int filas1 = 0;
 	int columnas1 = 0;
 	int **x;

 	cout << " \n \n \t \t \t*** CUBO MAGICO *** \n \n";
 	cout << "ingrese el # del cubo:  ";
 	cin >> filas1;

 	columnas1 = filas1;

 	x = (int **)malloc(filas1*sizeof(int*));// Reserva de Memoria 
 	for (int i = 0; i<filas1; i++)
 	x[i] = (int*)malloc(columnas1*sizeof(int));

 	//Ingresar la matriz
 	for (int c = 0; c<filas1; c++){
 		printf("\n");
 		printf("FILA %d :\n", c + 1);
 	 	for (int f = 0; f<columnas1; f++){
 	 	    cout << "  Dato [" << c + 1 << "][" << f + 1 << "] : ";
 		    cin >> x[c][f];
 	 	}
 	}
//Imprimir la matriz
 	for (int i = 0; i<filas1; i++){
 		cout << "\n \t \t \t";
 		for (int j = 0; j<columnas1; j++)
 		   printf("\t%d", x[i][j]);
 	}
   getch();
}
