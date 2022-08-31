#include "OpNumericas.h"

//Constructor
OpNumericas::OpNumericas(Suma _s1){
	this->s1 = _s1;
}

//Metodo Adicional
float OpSuma::sumar(Suma s1){
	
	return s1.getA()+s1.getB();
}

float OpSuma::resta(Suma s1){
	
	return s1.getA()-s1.getB();
}