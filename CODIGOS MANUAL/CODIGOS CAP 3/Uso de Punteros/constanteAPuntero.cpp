#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void imprimeChars(const char *); // prototipo
int main(){
	char cFrase[] = "Esta es una prueba de punteros a constantes,gracias!";
	imprimeChars(cFrase);
	system("pause>null");}
void imprimeChars(const char *ptrStr){
	for (; *ptrStr != '\0'; ptrStr++) //Sin inicialización
		std::cout << *ptrStr;}
