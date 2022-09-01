#include <conio.h>
#include <iostream>
#include <cstring>
#include "Bsecuencial.cpp"
#define MAX 50
 
using namespace std;
 
int main() {
	Bsecuencial busqueda;
	int x[MAX], elem, n;
	char val[MAX];
	system("cls");
	cout << "\tBUSQUEDA SECUENCIAL" << endl;
	char* mensaje2 = (char*)"\nIngrese el numero de valores a ingresar: ";
	strcpy(val, busqueda.ingresoInt(mensaje2));
	n = (int)atof(val);
	busqueda.leearray(n, x);
	cout << "\n\nIngrese elemento a buscar: ";
	cin >> elem;
	if (busqueda.buscarsecuencial(n, x, elem) == 1) {
		cout << "\n\t <<Elemento encontrado>>" << endl;
	}
	else {
		cout << "\n\t <<Elemento NO encontrado>>" << endl;
	}
}
