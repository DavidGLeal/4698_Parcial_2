#include <iostream>
#include "suma.h"
#include "OpNumericas.h"

int main(int argc, char** argv) {
	
	//NombreClase  nombreObjeto (valores de retorno)
	Suma obj1(4,32);	
	cout<<"Numero 1: "<<obj1.getA()<<endl;
	cout<<"Numero 2: "<<obj1.getB()<<endl;
	
	OpNumericas n1(obj1);
	cout<<"\nLa suma es: "<<n1.sumar(obj1)<<endl;
	cout<<"La resta es: "<<n1.resta(obj1)<<endl;
	return 0;
}