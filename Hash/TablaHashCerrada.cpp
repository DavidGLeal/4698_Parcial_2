#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include <cstring>
#include "TablaHashCerrada.h"
//#include "TablaHash.h"
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
void TablaHashCerrada::eliminar(string cad){
	

    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    /*while (aux == nullptr)
    {
        pos++;
        aux = tabla[pos % NCASILLAS];
    }*/
    if(aux->getCadena() == cad){
        tabla[pos] = tabla[pos]->getSig();
        delete aux;
    }
    else
    {
    	while(tabla[pos]->getCadena()!=cad)
    	{
    		pos = hash2(pos);
		}
		aux = tabla[pos];
		tabla[pos] = tabla[pos]->getSig();
        delete aux;
	/*while (aux == nullptr)
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
        else cout << "No existe ese elemento. Verifique que está en la lista."<<endl;*/
        /*aux->setSig(aux->getSig()->getSig());
        delete aux->getSig();*/
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
/*
int TablaHashCerrada::quadraticProbing(string cad, int i){
    int suma =0;
    int indice =0;
    suma = hash(cad);
    indice = (suma + i*i) % NCASILLAS;
    return indice;

}*/
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
	/*int i = 0;
    bool ocupado = false;
    int indice = 0;
    while (ocupado == false)
    {
         indice = quadraticProbing(cad, i);
         NodoCircular *aux = tabla[indice];
        if (tabla[indice] == NULL)
        {
            tabla[indice] = new NodoCircular(cad);
            ocupado = true;
        }
        else
        {
            i++;
        }
    }*/
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
    /*int posiciones = clave + 1;
    if (posiciones >= NCASILLAS)
        posiciones -= NCASILLAS;

    bool haEncontradoValor{false};
    while (posiciones != clave && !haEncontradoValor) {
        if (this->tabla[posiciones] != nullptr)
            haEncontradoValor = this->tabla[posiciones]->getCadena().compare(valor) == 0;

        if (!haEncontradoValor)
            posiciones++;

        if (posiciones >= NCASILLAS)
            posiciones -= NCASILLAS;
    }

    return (haEncontradoValor) ? posiciones: ELEMENTO_NO_ENCONTRADO;*/
}

int TablaHashCerrada::hash(string cad){
    int suma = 0;
    for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
    }
    return suma % NCASILLAS;
}

/*int TablaHashCerrada::hashDoble(string cad){

    int p = [](string cad){
    	int suma = 0;
    	for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
	    }
	    return suma % NCASILLAS;
	}(cad);
    int indice = p;
    int t = [](string cad, int p){
    	int suma = 0;
	    int indice = 0;
	    suma = p;
	    indice = 7 -( suma % 7);
	    return indice;
	}(cad,p);
    while(tabla[indice] != NULL){
        indice = indice + t;
        if(indice>NCASILLAS){
        	indice = indice%NCASILLAS;
		}
    }
    	//cout<<indice<<endl;
    return indice;
}*/
/*void TablaHashCerrada::insertarDoble(string cad){
    int pos = hashDoble(cad);
    NodoCircular *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircular(cad);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircular(cad));
    }
}*/

//Sondeo Lineal
/*void TablaHashCerrada::insertarLineal(string cad)
{
    int i = 0;
    bool ocupado = false;
    int indice = 0;
    while (ocupado == false)
    {
         indice = hashF(cad, i);
         NodoCircular *aux = tabla[indice];
        if (tabla[indice] == NULL)
        {
            tabla[indice] = new NodoCircular(cad);
            ocupado = true;
        }
        else
        {
            i++;
        }
    }
}*/

/*int TablaHashCerrada::hashF(string cad, int i)
{
    int suma = 0;
    int indice = 0;
    suma = hash(cad);
    indice = (suma + i) % NCASILLAS; //Lineal
    return indice;
}*/


