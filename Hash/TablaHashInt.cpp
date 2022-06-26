#pragma once 
#include <iostream>
#include "TablaHashInt.h"
#include "NodoEntero.h"
#include "NodoEntero.cpp"

using namespace std;

TablaCerradaEnteros :: TablaCerradaEnteros(){
    tabla = new NodoCircularEntero*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}
TablaCerradaEnteros :: ~TablaCerradaEnteros(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircularEntero *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;
}
void TablaCerradaEnteros::insertar(int valor){
    int pos = hash(valor);
    NodoCircularEntero *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircularEntero(valor);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircularEntero(valor));
    }
}
void TablaCerradaEnteros::eliminar(int valor){
    int pos = hash(valor);
    NodoCircularEntero *aux = tabla[pos];
    if(aux->getValor() == valor){
        tabla[pos] = tabla[pos]->getSig();
        delete aux;
    }
    else{
        while(aux->getSig()->getValor() != valor){
            aux = aux->getSig();
        }
        aux->setSig(aux->getSig()->getSig());
        delete aux->getSig();
    }
}
void TablaCerradaEnteros::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircularEntero *aux = tabla[i];
        while(aux != NULL){
            cout << aux->getValor() << " ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}
int TablaCerradaEnteros::hash(int valor){
    return valor % NCASILLAS;
}

int TablaCerradaEnteros::hash2(int valor)
{
    int i = valor % NCASILLAS;
    int veces = 0;
    
    if(tabla[i]==NULL)
    {
    	return i;
	}
	else
	{
		function<int()> hash2 = [&]()->int
		{
			try
			{
				do{
					int dob = 7 - valor%7;
		
					i+=dob;
		
					if(i>28)
					{
						i=NCASILLAS-i;
					}
					veces++;
				}while(tabla[i]!=NULL & veces <NCASILLAS);
			
				if(veces==NCASILLAS)
				{
					throw (veces);
				}
			
				return i;
			}catch(int lleno)
			{
				cout<<"La lista esta llena."<<endl;
				system("pause");
				return -1;
			}
		};
		
		return hash2();
	}
}    
