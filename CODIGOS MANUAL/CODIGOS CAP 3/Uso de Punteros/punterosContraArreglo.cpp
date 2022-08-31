#include <stdio.h>
#include <stdlib.h>
int libros(const char cadena[]);
int main(){
	static char cadena[] = "Universidad De Las Fuerzas Armadas";
	printf("La cantidad de libros en la biblioteca de la %s es %d escritos.\n", cadena, libros(cadena));
	system("pause>null");
	return 0;
}
int libros(const char cadena[]){
	int cantidad = 0; 
	while (cadena[cantidad] != '\O'){
		cantidad++;
	}
	return cantidad;
}
