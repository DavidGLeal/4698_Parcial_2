#include "Cola.h"
int main() {
    Cola c1;
    int op;
    do {
        cout << "     MENU DE OPCIONES    ";
        cout << "\n   Elija una opcion: ";
        cout << "\n1: Enqueue";
        cout << "\n2: Dequeue";
        cout << "\n3: Mostar";
        cout << "\n0: Salir";
        cout << "\n";
        cin >> op;
        cout << "\n";
        switch (op) {
        case 1:
            int num;
            cout << "Ingresar el valor: ";
            cin >> num;
            c1.enqueue(num);
            system("cls");
            break;
        case 2:
            c1.dequeue();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            c1.mostar();
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
