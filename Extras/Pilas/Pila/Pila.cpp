/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    #Grupo 7
				Brandon Raul Masacela - 	 brmasacela@espe.edu.ec
				Juan Francisco Reyes -       jfreyes4@espe.edu.ec
	FECHA DE CREACION:        14-06-2022 	
	FECHA DE MODIFICACION:    14-06-2022
*/

#pragma once
#include "Pila.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Pila::Pila(){

}

void *Pila::insertarpila(void *p, int dato){
    Nodo *nuevo = new Nodo();
    nuevo->valor = dato;
    nuevo->siguiente = (Nodo *)p;
    p = nuevo;
    cout<<"\nSe agrego correctamente";
    return(p);
}

void Pila::mostrar(void *p){
    Nodo *ptemp;
    ptemp=(Nodo *)p;
    if (p==NULL)
        printf("\tPILA VACIA");
    else
     {  printf("\t");
        do
        { 
            cout<<ptemp->valor<<"->";
            ptemp = ptemp->siguiente;
        }while(ptemp!=NULL);
        cout<<"NULL";
     }
    cout<<"\n\tPresione una tecla para continuar...";
    getchar();
}

void *Pila::eliminar(void *p){
    Nodo *ptemp;
    if(p==NULL)
        printf("\tPILA VACIA\n");
    else
     { 
        ptemp=(Nodo*)p;
        cout<<"\tEliminado:"<<ptemp->valor;
       p = ptemp->siguiente;
       delete(ptemp);
     }
    
    cout<<"\n\tPresione una tecla para continuar...";
    getchar();
    return(p);
}

void Pila::calcularPorcentaje(void *p){
    int cont = 0;
    int porcetaje = 0;
    int size = 0;
    Nodo *ptemp;
    ptemp=(Nodo *)p;
    if (p==NULL)
        printf("\tPILA VACIA");
    else
     {  printf("\t");
        do
        {
            if(ptemp->valor % 2 == 0){
                cont++;
            } 
            ptemp = ptemp->siguiente;
            size++;
        }while(ptemp!=NULL);
        porcetaje = (cont * 100)/size;
        cout<<"\nEl porcentaje de numeros pares es "<<porcetaje<<" %";
     }
    cout<<"\n\tPresione una tecla para continuar...";
    getchar();
}
