#pragma once 
#include <iostream>
#include <stdio.h>
#include "Nodo.h"
#include "Nodo.cpp"
#include "Lista.h"
#include "Lista.cpp"
#include <string>

using namespace std;
Lista* lista = new Lista();
Nodo* nodo = new Nodo();
int dato;
void validarinsertarporcabeza();
void validarinsertarporcola();
void validarinsertarporposicion();
void validarbusqueda();
void validarEliminarporPosicion();

bool isNumber(string opcion){
    for(int i = 0; i < opcion.length(); i++){
        if(opcion[i] < '0' || opcion[i] > '9'){
            return false;
        }
    }
    return true;
}

void menu(){
    string opcion;
    string posicion;
do{
    cout << "LISTAS DOBLEMENTE ENLAZADAS" << endl;
    cout << "1. Insertar por cabeza" << endl;
    cout << "2. Insertar por cola" << endl;
    cout << "3. Insertar entre" << endl;
    cout << "4. Imprimir" << endl;
    cout << "5. Buscar" << endl;
    cout << "6. Eliminar por cabeza" << endl;
    cout << "7. Eliminar por cola" << endl;
    cout << "8. Eliminar entre" << endl;
    cout << "9. Salir" << endl;
    cin >> opcion;

    if(isNumber(opcion)){
        int opcionInt = stoi(opcion);
        switch(opcionInt){
            case 1:
                validarinsertarporcabeza();
                system("pause");
                break;
            case 2:
                validarinsertarporcola();
                system("pause");
                break;
            case 3:
                
                validarinsertarporposicion();
                system("pause");
                break;
            case 4:
                lista->imprimir();
                system("pause");
                break;
            case 5:
                validarbusqueda();
                system("pause");
                break;
            case 6:
                lista->eliminarporcabeza();
                cout<<"Dato eliminado"<<endl;
                system("pause");
                break;
            case 7:
                lista->eliminarporcola();
                cout<<"Dato eliminado"<<endl;
                system("pause");
                break;
            case 8:
                validarEliminarporPosicion();
                system("pause");
                break;
            case 9:
                cout << "Saliendo..." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
                break;
        }
    }else{
        cout << "Opcion invalida" << endl;
    }
    system("cls");
}while(opcion != "9");
    
}
void validarinsertarporcabeza(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->insertarporcabeza(dato);
        cout << "Dato insertado" << endl;
    }else{

       validarinsertarporcabeza();                 
    }
}
void validarinsertarporcola(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->insertarporcola(dato);
        cout<<"Dato insertado"<<endl;
    }else{

       validarinsertarporcola();                 
    }
}
void validarinsertarporposicion(){
    string dato1;
    string posicion;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        cout << "Ingrese la posicion: " << endl;
        cin >> posicion;
        if(isNumber(posicion)){
            lista->insertarporposicion(dato, stoi(posicion));
            cout << "Dato insertado" << endl;
        }else{
            validarinsertarporposicion();
        }
    }else{

       validarinsertarporposicion();                 
    }
}
void validarbusqueda(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->buscar(dato);

    }else{

       validarbusqueda();                 
    }
}
void validarEliminarporPosicion(){
    string posicion;
    cout << "Ingrese la posicion: " << endl;
    cin >> posicion;
    if(isNumber(posicion)){
        lista->eliminarporposicion(stoi(posicion));
        cout<<"Dato eliminado"<<endl;
    }else{
        validarEliminarporPosicion();
    }
}
