/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash cerrado de enteros y strings .
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 24-06-2022
	*Fecha de modificacion:
        * 29-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/
#pragma once 
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "NodoEntero.h"
#define NCASILLAS 29

class TablaCerradaEnteros{
    protected:
        NodoCircularEntero **tabla;
    public:
        TablaCerradaEnteros();
        ~TablaCerradaEnteros();
        void insertar(int valor);
        void eliminar(int valor);
        void imprimir();
        void buscar(int valor);
        int hash(int valor);
        virtual int hash2(int valor)=0;
};