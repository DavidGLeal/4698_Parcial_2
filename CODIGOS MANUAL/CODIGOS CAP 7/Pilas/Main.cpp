#include "Pila.h"
int main() {
    Pila listaDeNumeros;
    int op;
    do {
        cout << "     MENU DE OPCIONES    ";
        cout << "\n   Elija una opcion: ";
        cout << "\n1: Push (Ingresar)";
        cout << "\n2: Imprimir";
        cout << "\n3: Pop(ELiminiar)";
        cout << "\n0: Salir";
        cout << "\n";
        cin >> op;
        cout << "\n";
        switch (op) {
        case 1:
            float num;
            cout << "Ingresar numeros a guardar: ";
            cin >> num;
            listaDeNumeros.push(num);
            system("cls");
            break;
        case 2:
            cout << "Imprimir:\n";
            listaDeNumeros.mostrar();
            system("pause");
            system("cls");
            break;
        case 4:
            break;
        case 3:
            listaDeNumeros.pop();
            listaDeNumeros.mostrar();
            system("pause");
            system("cls");
            break;
        default:
            cout << "Comando no valido.";
            system("pause");
            system("cls");
            break;
        case 0:
            break;
        }
    } while (op != 0);
    cout << "Gracias por usar el codigo :)";
    return 0;
}

