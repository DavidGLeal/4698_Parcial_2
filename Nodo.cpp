/*
	*Universidad de las Fuerzas Armadas "ESPE"
        *Enunciado del problema:
	*Realizar un pograma de manejo de árboles binarios con todas sus funciones.
        *Autores:
	*Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 04-07-2022
	*Fecha de modificacion:
        * 08-07-2022
        *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Parcial_2
*/

#include "Nodo.h"

/**
 * Establece el valor del nodo.
 * 
 * @param _dato El valor que se almacenará en el nodo.
 */
void Nodo::setValor(int _dato)
{
    valor = _dato;
}

/**
 * 
 * @param _izquierda El nodo que se establecerá como el hijo izquierdo del nodo actual.
 */
void Nodo::setIzquierda(Nodo *_izquierda)
{
    izquierda = _izquierda;
}

/**
 * 
 * @param _derecha El nodo que se establecerá como el nodo derecho.
 */
void Nodo::setDerecha(Nodo *_derecha)
{
    derecha = _derecha;
}

/**
 * Devuelve el valor del nodo.
 * 
 * @return El valor del nodo.
 */
int Nodo::getValor()
{
    return valor;
}

/**
 * Devuelve el nodo izquierdo.
 * 
 * @return Un puntero al nodo izquierdo.
 */
Nodo*& Nodo::getIzquierda()
{
    return izquierda;
}

/**
 * Devuelve el nodo derecho.
 * 
 * @return Una referencia al nodo derecho.
 */
Nodo*& Nodo::getDerecha()
{
    return derecha;
}
