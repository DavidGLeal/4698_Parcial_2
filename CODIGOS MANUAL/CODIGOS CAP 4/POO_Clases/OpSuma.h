#include <iostream>
#include "Suma.h"

//INTERFACE de extension.h
//PADRE

class OpSuma{
	
	public:
		
		/*VIRTUAL es el metodo abstracto 
	
		Se quita el =0 cuando cuando no queremos que TODO sea abstracto (parametrizar)
		
		Se pone el =0 cuando para implementar el VIRTUAL PURA, abstracta (sin parametros)*/
		virtual float sumar(Suma);
		virtual float resta(Suma);
		//friend class Suma; No es necesario friend class porque ya estamos utilizando objeto Suma
		
};

/*Declarado afuera porque cuando se hace el include la friend class se vuelve global
friend class Suma;*/
