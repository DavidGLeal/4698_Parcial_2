/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
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









