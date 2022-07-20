#ifndef NODOSTR_H
#define NODOSTR_H

#include <iostream>

using namespace std;

class NodoStr{
	private:
		NodoStr *siguiente;
		string valor;	
	
	public:
		NodoStr();
		NodoStr(string);
		~NodoStr();
		string getValor();
		NodoStr *getSiguiente();	
		void setValor(string);
		void setSiguiente(NodoStr *);

		void imprimirNodo();
		
};

#endif