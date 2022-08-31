#include <stdio.h>
#include <conio.h>
#include <stdlib.h> /* requerida para malloc y free funciones */
#include <iostream>

using namespace std;

int main() {

 	system("COLOR 0f");
 	int number;
 	int *ptr;
 	int i;

 	printf("\n\tCuantos numeros enteros desea invertir? \n\n\t\t\t");
 	scanf("%d", &number);

 	/* Creamos el espacio de memoria en forma dinámica */
 	ptr = (int *)malloc(number*sizeof(int));

 printf("\n\n\tConteo de numeros desde el numero ingresado hasta 0\n\n ");
 	if (ptr != NULL) {

 	for (i = 0; i<number; i++) {
 	 	*(ptr + i) = i;
 	}

 	for (i = number; i>0; i--) {
 	  printf("\t%d", *(ptr + (i - 1))); /*Imprimimos en orden inverso*/
 	}

  free(ptr); /* Liberamos la memoria reservada */

 getch();
}

else {
printf("\n\tLa reserva de memoria no suficiente memoria.\n");
return 1;
}
}
