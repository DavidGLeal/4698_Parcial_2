#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include "Empleado.cpp"

using namespace std;

int main()
{
    int opcion, c, i;
    bool repetir = true;
    Empleado *cab = NULL;
    Empleado obj;

    do
    {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Crear nodo inicial" << endl;
        cout << "2. Insertar empleados" << endl;
        cout << "3. Programadores en c++" << endl;
        cout << "4. Sueldo mayor a $500" << endl;
        cout << "5. Motrar suma de sueldos empleados" << endl;
        cout << "6. Borrar todo" << endl;
        cout << "7. Imprimir" << endl;
        cout << "8. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cab = obj.insertar_nodo_inicial();
            break;

        case 2:
            cout << "IDENTIFICACION: ";
            cin >> c;
            obj.insertar_nodos_circular(*&cab, c);
            break;

        case 3:
            cout << "En la empresa hay " << obj.progenc(cab) << " programador(es) de  c++";
            getch();
            break;

        case 4:
            obj.empleadosmayora(cab);
            break;

        case 5:
            obj.sumanomina(cab);
            break;

        case 6:
            cout << "Inserte identificacion: ";
            cin >> i;
            obj.eliminar_nodo_circ(*&cab, i);
            break;

        case 7:
            obj.imprime_lista_circ(cab);
            break;

        case 8:
            repetir = false;
            break;
        }
    } while (repetir);

    return 0;
}
