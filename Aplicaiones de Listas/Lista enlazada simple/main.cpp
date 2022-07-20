/*Universidad de las Fuerzas Armadas ESPE
 Desarrollo de Aplicaciones de Software
 Estructura de Datos
 Ing. Fernando Solis
 Autores: Diego Portilla 
          Darwin Valdiviezo
*/

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Nodo.h"
#include "Nodo.cpp"
#include "Lista.h"
#include "Lista.cpp"


using namespace std;

bool isNumber(string);
void ingresar();
void ingresarporcola();
void validarBusqueda();
void validarModificacion();

int dato;
Lista* lista = new Lista();

int main(){
    
    string opcion;
    
    do{
        cout << "Ingrese una opcion: " << endl;
        cout << "1. Insertar por cabeza" << endl;
        cout << "2. Insertar por cola" << endl;
        cout << "3. Modificar" << endl;
        cout << "4. Buscar" << endl;
        cout << "5. Imprimir" << endl;
        cout << "6. Ordenar" << endl;
        cout << "7. Eliminar ultimo" << endl;
        cout << "8. Eliminar primero" << endl;
        cout << "9. Salir" << endl;
        cin >> opcion;
        if(isNumber(opcion)){
            int opcion1 = atoi(opcion.c_str());
            switch(opcion1){
                case 1:
                    ingresar();
                    system("pause");
                    break;
                case 2:
                    ingresarporcola();
                    system("pause");
                    break;
                case 3:
                    validarModificacion();
                    system("pause");
                    break;
                case 4:
                    validarBusqueda();
                    system("pause");
                    break;
                case 5:
                    cout<<"Imprimiendo lista por cabeza"<<endl;
                    lista->imprimirporcabeza();
                    cout<<"Imprimiendo lista por cola"<<endl;
                    lista->imprimir();
                    
                    system("pause");
                    break;
                case 6:
                    lista->ordenar();
                    system("pause");
                    break;
                case 7:
                    lista->eliminarUltimo();
                    lista->imprimirporcabeza();
                    system("pause");
                    break;
                case 8:
                    lista->eliminarporCabeza();
                    lista->imprimirporcabeza();
                    system("pause");
                    break;
                case 9:
                    cout << "Saliendo..." << endl;
                    system("pause");
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    system("pause");
                    break;
            }
        }else{
            cout << "Opcion no valida" << endl;
            system("pause");
        }
        system ("cls");
    }while(opcion != "9");
        
}




bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }

    }
    
    return true;
}
void ingresar(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->insertarporcabeza(dato);
    }else{

       ingresar();                 
    }

}
void ingresarporcola(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->insertarporcola(dato);
    }else{

       ingresarporcola();                 
    }

}
void validarBusqueda(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->buscar(dato);
    }else{

       validarBusqueda();                 
    }

}
void validarModificacion(){
    string dato1;
    cout << "Ingrese un dato: " << endl;
    cin >> dato1;
    if(isNumber(dato1)){
        dato = stoi(dato1);
        lista->modificar(dato);
    }else{

       validarModificacion();                 
    }

}
