#pragma once 
#include <iostream>
#include <stdio.h>
#include "Lista.h"

using namespace std;


Lista::Lista() {
    this->primero = NULL;
    this->ultimo =  NULL;
}
void Lista::insertar(int dato) {
    Nodo* nuevo = new Nodo(dato, NULL);
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->ultimo->setSiguiente(nuevo);
        this->ultimo = nuevo;
    }
}
void Lista::buscar(int dato) {
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
void Lista::modificar(int dato) {
    if(this->primero != NULL){
        Nodo* actual = this->primero;
        while(actual != NULL){
            if(actual->getDato() == dato){
                cout << "Ingrese el nuevo dato: " << endl;
                int nuevoDato;
                cin >> nuevoDato;
                actual->setDato(nuevoDato);
                return;
            }
            actual = actual->getSiguiente();
        }
        cout << "El dato " << dato << " no se encuentra en la lista" << endl;
    }else{
        cout << "La lista esta vacia" << endl;
    } 
}

void Lista::eliminarporCabeza(){
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
    void Lista::eliminarUltimo(){
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
void Lista::ordenar() {
    if(this->primero == NULL){
        cout << "La lista esta vacia" << endl;
        return;
    }
    Nodo* actual = this->primero;
    Nodo* anterior = NULL;
    while(actual != NULL){
        Nodo* siguiente = actual->getSiguiente();
        while(siguiente != NULL){
            if(actual->getDato() > siguiente->getDato()){
                int aux = actual->getDato();
                actual->setDato(siguiente->getDato());
                siguiente->setDato(aux);
            }
            siguiente = siguiente->getSiguiente();
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
}
void Lista::insertarporcola(int dato) {
    Nodo* nuevo = new Nodo(dato, NULL);
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->ultimo->setSiguiente(nuevo);
        this->ultimo = nuevo;
    }
}
void Lista ::insertarporcabeza(int dato) {
    Nodo* nuevo = new Nodo(dato, NULL);
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        nuevo->setSiguiente(this->primero);
        this->primero = nuevo;
    }
}
void Lista::imprimirporcabeza() {
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
void Lista::imprimir() {
    if(this->primero != NULL){
    Nodo* actual = this->ultimo;
    while(actual != NULL){
        cout << actual->getDato() << "->";
        actual = actual->getSiguiente();
    }
    cout <<"NULL"<<endl;
    }else{
        cout << "La lista esta vacia" << endl;
    }
}