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









