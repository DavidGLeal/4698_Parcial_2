#pragma warning (disable: 4996)
#include <iostream>
#include "Operaciones.h"
#include <conio.h>
int main(int argc, char** argv) {
	std::cout<<"Taller Memoria Estatica Vectores"<<std::endl;
	Operaciones op;
	op.encerar();
	op.ingresar();
	std::cout<<"Promedio: "<<op.procesar();
	op.imprimir();
	getch();
	return 0;
}
