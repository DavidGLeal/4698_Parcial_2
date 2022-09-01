#include <conio.h>
#include <iostream>
#define MAX 50
#include "Bsecuencial.h"
 
using namespace std;
 
void Bsecuencial::leearray(int n, int a[])
{
	char val[MAX];
	int d;
	for (int i = 0; i < n; i++) {
		cout << "\n\t" << i + 1 << ". ";
		char* mensaje2 = (char*)"Ingrese el elemento: ";
		strcpy(val, ingresoInt(mensaje2));
		d = (int)atof(val);
		a[i] = d;
	}
}
 
int Bsecuencial::buscarsecuencial(int n, int a[], int b)
{
	for (int i = 0; i < n; i++) {
		if (b == a[i]) {
			return 1;
		}
	}
	return 0;
}
 
char* Bsecuencial::ingresoInt(char* msj)
{
	char* dato = new char[10], c;
	int i = 0;
	cout << msj;
	while ((c = getch()) != 13) {
		if ((c >= '0' && c <= '9')) {
			cout << c;
			dato[i++] = c;
		}
		else if (c == 8 || c == 127) {
			cout << "\b \b";
			dato[i--] = 0;
		}
	}
	dato[i] = '\0';
	return dato;
}
