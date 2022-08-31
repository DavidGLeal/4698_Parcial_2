#include <iostream>
#include "Hash.cpp"
using namespace std;
int main()
{
    Hash hash;
    hash.inicializar();
    int num;
    int nume;
    bool repetir = true;
    do {
        system("cls");
        cout << "\t<<<<<MENU DE OPCIONES>>>>>";
        cout << "\nElija una opcion: ";
        cout << "\n1: Ingresar ";
        cout << "\n2: Buscar ";
        cout << "\n3: Eliminar";
        cout << "\n4: Imprimir";
        cout << "\n0: Salir";
        cout << "\n";
        cin >> num;
 
        switch (num) {
        case 1:
            cout << "\nIngresar numeros a guardar: ";
            cin >> nume;
            hash.insertar(nume);
            system("pause");        
            system("cls");
            break;
        case 2:
            int val;
            cout << "\n Ingrese un valor a buscar:  \n";
            cin >> val;
            hash.busqueda(val);
            system("pause");
            system("cls");
            break;
        case 3:
            int val1;
            cout << "\n Ingrese un valor a eliminar:  \n";
            cin >> val1;
            hash.eliminar(val1);
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "\n Hash Impreso \n";
            hash.imprimir();
            system("pause");
            system("cls");
            break;
        case 0:
            repetir = false;
            cout << "\nHasta Luego";
            break;
        default:
            cout << "\nError no existe la opcion.\n";
            system("pause");
            system("cls");
            break;
        }
 
    } while (repetir);
    return 0;    
}
