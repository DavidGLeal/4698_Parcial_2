#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include <cstring>
#include "TablaHashCerrada.h"
#define NCASILLAS 29

using namespace std;

TablaHashCerrada::TablaHashCerrada(){
    tabla = new NodoCircular*[NCASILLAS];
    for(int i = 0; i < NCASILLAS; i++){
        tabla[i] = NULL;
    }
}
TablaHashCerrada::~TablaHashCerrada(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircular *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete aux;
            aux = tabla[i];
        }
    }
    delete[] tabla;
}
void TablaHashCerrada::eliminar(string cad)
{
    int buscar = 0;
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    while (aux == nullptr && buscar < 30)
    {
        pos++;
        aux = tabla[pos % NCASILLAS];
        buscar++;
        if (buscar>=30)
        {
            cout << "Tabla vacia" <<endl;
            break;
        }
    }
    if (aux != nullptr)
    {
       if (aux->getCadena() == cad && buscar < 30)
        {
            tabla[pos] = tabla[pos]->getSig();
            delete aux;
        }
        else if (buscar > 30)
        {
            cout << "Tabla Vacia" <<endl;
        }
        else
        {
            while (aux == nullptr)
            {
                pos++;
                aux = tabla[pos % NCASILLAS];
            }	    
            if (aux->getSig() != nullptr)
            {
                while (aux->getSig()->getCadena() != cad)
                {
                    aux = aux->getSig();
                }
            }
            else cout << "\nNo existe ese elemento. Verifique que está en la lista."<<endl;
            /*while(tabla[pos]->getCadena()!=cad)
            {
                pos = hash2(pos);
            }
            aux = tabla[pos];
            tabla[pos] = tabla[pos]->getSig();*/
            //delete aux;
            /*aux->setSig(aux->getSig()->getSig());
            delete aux->getSig();*/
        }
    }
}


void TablaHashCerrada::imprimir(){
    for(int i = 0; i < NCASILLAS; i++){
        NodoCircular *aux = tabla[i];
        int pos = i;
        aux = tabla[i];
        while(aux != NULL){
            cout << pos<<"<-"<<aux->getCadena() <<" ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}

void TablaHashCerrada::insertar(string cad)
{
    int pos = hash(cad);
    
    if(tabla[pos]==NULL)
    {
    	tabla[pos] = new NodoCircular(cad);
	}
    else
    {
    	while(tabla[pos]!=NULL)
    	{
    		pos=hash2(pos);
		}
		tabla[pos] = new NodoCircular(cad);
	}
}

void TablaHashCerrada::buscar(std::string cad) {
    const int ELEMENTO_NO_ENCONTRADO{-1};
    int clave{hash(cad)};

	int retorno = clave;
	bool noEsta = false;
	
    if (this->tabla[clave]->getCadena().compare(cad) == 0)
    {    
		cout<<this->tabla[clave]->getCadena()<<endl;
        cout<<"\nEncontrado en la posicion: "<<clave;
	}
	else
	{
		clave = hash2(clave);
		while(this->tabla[clave]->getCadena().compare(cad)!=0 && retorno!=clave)
		{
			clave = hash2(clave);
		}
		if(clave==retorno)
		{
			noEsta=true;
		}
		
		if(!noEsta)
		{
			cout<<this->tabla[clave]->getCadena()<<endl;
        	cout<<"\nEncontrado en la posicion "<<clave<<endl;
		}
		else
		{
			cout<<"\nEl elemento no se encuentra en la lista\n"<<endl;
		}
	}
}

int TablaHashCerrada::hash(string cad){
    int suma = 0;
    for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
    }
    return suma % NCASILLAS;
}


