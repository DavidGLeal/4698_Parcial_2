/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 10
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
*/
#include "NodoStr.h"
#include <cstring>
#include <cstdlib>

using namespace std;
NodoStr::NodoStr() {
	valor = "";
	siguiente=NULL;
}

NodoStr::NodoStr(string _valor){
	this->valor =_valor;
	this->siguiente =NULL;
}

NodoStr::~NodoStr(){

}

NodoStr* NodoStr::getSiguiente(){
	return this->siguiente;
}

void NodoStr::setSiguiente (NodoStr *_siguiente){
	this->siguiente=_siguiente;
}

string NodoStr::getValor() {
	return this->valor;
}

void NodoStr::setValor(string _valor){
	this->valor=_valor;
} 

void NodoStr::imprimirNodo(){
	cout<< this->valor;
}









