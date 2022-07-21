#include <cstddef>
#include <iostream>
#include "nodo.h"
using namespace std;
 
//Clase cola
class cola{
	public:
	    nodo *delante;
	    nodo *atras;
};

//metodo de insertar a la cola
void Insertar(cola &q, int valor ){
     nodo *aux = new nodo();
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
 
//Eliminar de la cola
int Eliminar(cola &q ){
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
 
//Imprimir toda la cola
void Imprimir(cola q ){
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}

//Imprimir solo los que sean mayores que 50
void Imprimir50(cola q ){
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
		 if((aux->nro)>50){
			cout<<"   "<< aux->nro ;
		 }
        aux = aux->sgte;
     }    
}