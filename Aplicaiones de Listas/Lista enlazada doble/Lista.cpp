#pragma once 
#include <iostream>
#include <stdio.h>
#include "Lista.h"
#include "Nodo.h"
#include "Nodo.cpp"

using namespace std;


Lista::Lista() {
    this->primero = NULL;
    this->ultimo = NULL;
} 
bool Lista :: listavacia(){
    if(this->primero == NULL){
        return true;
    }
    return false;
}
void Lista :: insertarporcabeza(int dato){
     Nodo* nuevo = new Nodo(dato, NULL, NULL);
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        nuevo->setSiguiente(this->primero);
        this->primero = nuevo;
    }
   
}
void Lista :: insertarporcola(int dato){
    Nodo* nuevo = new Nodo(dato, NULL,NULL);
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->ultimo->setSiguiente(nuevo);
        this->ultimo = nuevo;
    }
    
}
void Lista :: insertarporposicion(int dato, int posicion){
    if(this->primero != NULL){
    Nodo* nuevo = new Nodo(dato, NULL, NULL);
    if(posicion == 1){
        nuevo->setSiguiente(this->primero);
        this->primero->setAnterior(nuevo);
        this->primero = nuevo;
    }else{
        Nodo* aux = this->primero;
        for(int i = 1; i < posicion - 1; i++){
            aux = aux->getSiguiente();
        }
        nuevo->setSiguiente(aux->getSiguiente());
        aux->getSiguiente()->setAnterior(nuevo);
        aux->setSiguiente(nuevo);
        nuevo->setAnterior(aux);
    }
    if(this->ultimo == NULL){
        this->ultimo = nuevo;
    }
    }else{
        cout << "La lista esta vacia" << endl;
    }
}
void Lista :: eliminarporcabeza(){
    if(this->primero != NULL){
        cout << "El dato " << this->primero->getDato() << " se elimino de la lista" << endl;
        Nodo* actual = this->primero;
        this->primero = this->primero->getSiguiente();
        actual->setSiguiente(NULL);
        delete actual;
    }else{
        cout << "La lista esta vacia" << endl;
    }
}
void Lista :: eliminarporcola(){
    if(this->primero != NULL){
            if(this->primero->getSiguiente() == NULL){
                cout << "El dato " << this->primero->getDato() << " se elimino de la lista" << endl;
                delete this->primero;
                this->primero = NULL;
                this->ultimo = NULL;
            }else{
                Nodo* actual = this->primero;
                while(actual->getSiguiente()->getSiguiente() != NULL){
                    actual = actual->getSiguiente();
                }
                cout << "El dato " << actual->getSiguiente()->getDato() << " se elimino de la lista" << endl;
                delete actual->getSiguiente();
                actual->setSiguiente(NULL);
                this->ultimo = actual;
            }
        }else{
            cout << "La lista esta vacia" << endl;
        }
}
void Lista :: buscar(int dato){
    if(this->primero != NULL){
        Nodo* actual = this->primero;
        while(actual != NULL){
            if(actual->getDato() == dato){
                cout << "El dato " << dato << " si se encuentra en la lista" << endl;
                return;
            }
            actual = actual->getSiguiente();
        }
        cout << "El dato " << dato << " no se encuentra en la lista" << endl;
    }else{
        cout << "La lista esta vacia" << endl;
    }
}
void Lista :: imprimir(){
    if(this->primero != NULL){
        Nodo* actual = this->primero;
        while(actual != NULL){
            cout << actual->getDato() << "->";
            actual = actual->getSiguiente();

        }
        cout <<"NULL"<<endl;
    }else{
        cout << "La lista esta vacia" << endl;
    }
}
void Lista :: eliminarporposicion(int posicion){
    if(this->primero != NULL){
        if(posicion == 1){
            cout << "El dato " << this->primero->getDato() << " se elimino de la lista" << endl;
            Nodo* actual = this->primero;
            this->primero = this->primero->getSiguiente();
            actual->setSiguiente(NULL);
            delete actual;
        }else{
            Nodo* aux = this->primero;
            for(int i = 1; i < posicion - 1; i++){
                aux = aux->getSiguiente();
            }
            cout << "El dato " << aux->getSiguiente()->getDato() << " se elimino de la lista" << endl;
            aux->setSiguiente(aux->getSiguiente()->getSiguiente());
            aux->getSiguiente()->setAnterior(aux);
        }
    }else{
        cout << "La lista esta vacia" << endl;
    }
}



