#include "suma.h"

//Nombre Clase  metodo

//Constructores
Suma::Suma(float _a, float _b){
	this-> a=_a;
	this-> b= _b;
}

Suma::Suma(){
	this-> a=0;
	this-> b=0;
}

//Metodos Get
float Suma::getA(){
	return a;
}

float Suma::getB(){
	return b;
}

//Metodos Set
void Suma::setA(float _A){
	a = _A;
}

void Suma::setB(float _B){
	b = _B;
}
