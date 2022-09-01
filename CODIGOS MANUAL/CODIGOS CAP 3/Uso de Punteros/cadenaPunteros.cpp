#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
char cadena[80] = "Un ejemplo de cadena.";
char * puntero_cadena = cadena;
int main(){
	printf("Cadenas de caracteres.\n\n");
	printf("Espacio reservado para cadena          : %d\n", sizeof(cadena));
	printf("Espacio ocupado dentro de cadena       : %d\n", strlen(cadena));
	printf("La dirección de cadena es              : %u\n", atoi(cadena));
	printf("El valor de puntero_cadena es          : %u\n", atoi(puntero_cadena));	printf("El contenido de cadena es              : %s\n", cadena);
	printf("La cadena que señala puntero_cadena es : %s\n", puntero_cadena);
	printf("El cuarto elemento es                  : %c\n", *(cadena + 3));
	printf("El cuarto elemento es                  : %c\n", *(puntero_cadena + 3));
	printf("El cuarto elemento es                  : %c\n", cadena[3]);
	printf("El cuarto elemento es                  : %c\n", puntero_cadena[3]);
	printf("La cadena contiene                     : %s\n", cadena);
	printf("La cadena contiene                     : ");
	while (*puntero_cadena) printf("%c", *puntero_cadena++);
	printf("\n");
	printf("La cadena contiene                     : ");
	for (int i = 0; i<strlen(cadena); i++) printf("%c", cadena[i]);
	printf("\n");
	puntero_cadena = cadena; /* Esencial! */
	printf("La cadena contiene                     : ");
	for (int i = 0; i<strlen(cadena); i++) printf("%c", *(puntero_cadena + i));
	printf("\n");
	printf("\n\nTerminación normal de programa.\n");
	system("pause>null");
	return 0;
	}
