#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define N 1
void salida(char*[], int*);
void entrada(char*[]);
int numeros(char*);
int main()
{
	char *cad[N];
	int j, num[N];
	entrada(cad);
	/* Cuenta el numero de numeros por cada linea */
	for (j = 0; j<N; j++)
		num[j] = numeros(*(cad)+j);
	salida(cad, num);
	return 0;
}
void entrada(char * cd[])
{
	char B[112];
	int j, tam;
	printf("\nEscribe %d lineas de texto\n", N);
	for (j = 0; j<N; j++)
	{
		gets(B);
		tam = (strlen(B) + 1)*sizeof(char);
		cd[j] = (char*)malloc(tam);
		strcpy((*(cd+j)), B);
	}
}
int numeros(char*c)
{
	int k, j;
	/* Cuenta numeros de la cadena c */
	for (j = k = 0; j<strlen(c); j++)
		switch (tolower(*(c + j)))
	{
		case '0':;
		case '1':;
		case '2':;
		case '3':;
		case '4':;
		case '5':;
		case '6':;
		case '7':;
		case '8':;
		case '9': k++;
	}
	return k;
}
void salida(char* cd[], int *v)
{
	int j;
	puts("\nSalida de las linea junto al numero de numeros");
		for (j = 0; j<N; j++)
		{
			printf_s("%s : %2d\n", *(cd+j), *(v+j));
		}
        getch();
}
	
