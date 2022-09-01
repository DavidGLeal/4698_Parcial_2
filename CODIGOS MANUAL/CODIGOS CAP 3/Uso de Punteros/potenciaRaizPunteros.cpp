/*
Escribir un programa que utilice una función que devuelva el mayor, el menor y la media de los valores de un array de números. (Utilizar punteros).
*/
/*Declaración de librerías*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	float *vec[20];
	float pot[10];
	float sq[10];
	for (int i = 0; i < 10; i++) {
		pot[i] = pow(i,2);
		sq[i] = pow(i,0.5) ;
	}
	for (int i = 0; i < 10; i++) {
		vec[i] = &pot[i];
		vec[i + 10] = &sq[i];
	}
	cout << "Potencia\n";
	for (int i = 0; i < 10; i++) {
		cout << *vec[i]<<"  ";
	}
	cout << "\nRaiz\n";
	for (int i = 1; i < 10; i++) {
		cout << *vec[i+10]<<"  ";
	}
	system("pause>NULL");
      return 0;
	  }
