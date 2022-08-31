#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define N 1
void salida(char*[], int*);
void entrada(char*[]);
int vocales(char*);
int main(){
	char *cad[N];
	int j, voc[N];
	entrada(cad);
	/* Cuenta de vocales por cada linea */
	for (j = 0; j<N; j++)
		voc[j] = vocales(*(cad)+j);
	salida(cad, voc);
	return 0;
}
void entrada(char * cd[]){
	char B[112];
	int j, tam;
	printf("\n\tEscribe %d lineas de texto\n", N);
	for (j = 0; j<N; j++)
	{
		gets(B);
		tam = (strlen(B) + 1)*sizeof(char);
		*(cd+j)= (char*)malloc(tam);
		strcpy((*(cd+j)), B);
	}
}
int vocales(char*c){
	int k, j;
	/* Cuenta vocales de la cadena c */
	for (j = k = 0; j<strlen(c); j++)
		switch (tolower(*(c + j)))
	{
		case 'a':;
		case 'e':;
		case 'i':;
		case 'o':;
		case 'u': k++;
	}
	return k;
}
void salida(char* cd[], int *v)
{
	int j;
	puts("\n\tSalida de las linea junto al numero de vocales");
		for (j = 0; j<N; j++)		{
			printf_s("%s : %2d\n", *(cd+j), *(v+j));
		}
        getch();
}
