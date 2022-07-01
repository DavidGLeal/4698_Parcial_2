#define _CRT_NONSTDC_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_DEPRECATE 1

#include <iostream>
#include <ctime>
#include "0Vector.h"
#include "1IngresoDatos.h"
#include "OrdenamientoSectores.h"

int main()
{
	srand(time(0));

    Vector vector;
	IngresoDatos ingreso;
    int total_fragmentos;
    
	do {
		std::cout << "ingrese el total de fragmentos (1-100): ";
		total_fragmentos = ingreso.funcionPrincipalEnteros();
		std::cout << std::endl;
	} while (total_fragmentos < 1 || total_fragmentos > 100);

	OrdenamientoSectores ordenamiento(total_fragmentos);
	ordenamiento.rellenar(100, 0, 100);
	ordenamiento.ordenamiento_zambrano_cristopher();
}
