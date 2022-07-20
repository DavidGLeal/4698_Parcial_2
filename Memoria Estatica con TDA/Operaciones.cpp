#include "Operaciones.h"
#include "Vector.cpp"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////
// Nombre:       Operaciones::Operaciones(Vector& vec)
// Propósito:    Implementacion de Operaciones::Operaciones()
// Parametros:
// - vec
// Return:     
////////////////////////////////////////////////////////////////////////
Operaciones::Operaciones(Vector& vec){
	this->v=vec;
}
////////////////////////////////////////////////////////////////////////
// Nombre:       Operaciones::encerar()
// Propósito:    Implementacion de Operaciones::encerar()
// Parametros:
// Return:     
////////////////////////////////////////////////////////////////////////
void Operaciones::encerar(){
	int vec[10];
	for(int i=0;i<10;i++){
		vec[i]=0;
	}
	this->v.setVect(vec);
}
////////////////////////////////////////////////////////////////////////
// Nombre:       Operaciones::ingresar()
// Propósito:    Implementacion de Operaciones::ingresar()
// Parametros:
// Return:     
////////////////////////////////////////////////////////////////////////
void Operaciones::ingresar(){
	int vec[10];
	for(int i=0;i<10;i++){
		vec[i]=rand()%11;
	}
	this->v.setVect(vec);
}
////////////////////////////////////////////////////////////////////////
// Nombre:       Operaciones::procesar()
// Propósito:    Implementacion de Operaciones::procesar()
// Parametros:
// Return:     promedio
////////////////////////////////////////////////////////////////////////
float Operaciones::procesar(){
	float promedio=0.0;
	for(int i=0;i<10;i++){
		promedio+=v.getVect()[i];
	}
	return promedio/10;
}
////////////////////////////////////////////////////////////////////////
// Nombre:       Operaciones::imprimir()
// Propósito:    Implementacion de Operaciones::imprimir()
// Parametros:
// Return:     
////////////////////////////////////////////////////////////////////////
void Operaciones::imprimir(){
	std::cout<<"\nVector=\{";
	for(int i=0;i<10;i++){
		std::cout<< v.getVect()[i]<<" ";
	}
	std::cout<<"\}";
}
////////////////////////////////////////////////////////////////////////
// Nombre:       Vector Operaciones::getVec()
// Propósito:    Implementacion de Vector Operaciones::getVec()
// Parametros:
// Return:     
////////////////////////////////////////////////////////////////////////
Vector Operaciones::getVec()
{
	return v;
}
