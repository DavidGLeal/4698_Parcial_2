#define N 4
#define M 2
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
void ingreso(float *);
void impresion(float *);
float proceso(float[N][M]);
int main(){
	float mat[N][M];
	float *p = &mat[0][0];
	ingreso(p);
	impresion(p);
	cout << "La suma de los productos entre columnas es: " << proceso(mat);

	system("pause");
	return 0;
}
void ingreso(float *matp){
	for (int i = 0; i<N*M; i++)
	{
		printf("Ingrese numero: ");
		scanf("%f", *(&matp) + i);
	}

}
void impresion(float *matp){
	for (int i = 0; i<N*M; i++)	{
		printf("%.2f    ", *(matp + i));
		if (i == N - 1)
			printf("\n");
	}
	printf("\n");
}
float proceso(float mat[N][M]){
	int i, b;
	float a = 0;
	cout << "Ingrese la columna a ser multiplicada: ";
	cin >> b;
	for (i = 0; i<N; i++){
		a = a + (mat[i][0] * mat[i][b]);
	}
	return a;
}
