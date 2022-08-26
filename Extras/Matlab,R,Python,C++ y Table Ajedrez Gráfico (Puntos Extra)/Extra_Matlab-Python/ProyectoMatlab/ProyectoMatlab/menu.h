#pragma once
#include <iostream>
#include "Matlab.h"
#include "menu.h"

using namespace std;

class menu{
    public:
    void menuPrincipal();
    bool isNumber(string);
    Matlab m;
};

void menu::menuPrincipal(){
    string opcion;

    system("cls");

    do{
        cout << "Bienvenido al sistema de graficas"<< endl;
        cout << "1. Notacion BigO en Matlab" << endl;
        cout << "2. Notacion BigO en Python " << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if(isNumber(opcion)){
            int opcion1 = atoi(opcion.c_str());
            switch(opcion1){
                case 1:
                    system("cls");
                    cout << "Notacion BigO en Matlab" << endl;
                    m.procesoMatlab();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "Notacion BigO en Python" << endl;
                    system("BigO.exe");
                    break;
                case 3:
                    cout << "Saliendo del programa" << endl;
                    system("pause");
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
        }else{
            cout << "Opcion no valida" << endl;
        }
        system("cls");
    }while(opcion != "3");
}
   

bool menu::isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }

    }
    
    return true;
}

