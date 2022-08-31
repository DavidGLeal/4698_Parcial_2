// Requerimientos:
// ID tipo string
// Nombre tipo string
// Nota 1, 2 ,3 tipo float
// promedio tipo float
// buscar por medio del id
// agregar en cualquier posicion
// Librerias
#include "Nodo.cpp"
#include <iostream>
using namespace std;
// Función principal main()
int main()
{
    // Variables locales de la funcion main()
    char id[5];
    char nom[20];
    float n1, n2, n3;
    char opc;
    int opcion, posicion;
    int numeroNodos = 0;

    Nodo n; // Declaro una referencia n de tipo Nodo
    typedef Nodo *lista;
    typedef Nodo *ultimo;
    lista lis = NULL;
    ultimo ulis = NULL;
    do
    {
        system("cls");
        cout << "\t\t\tListas Circulares Simples\n\n";
        cout << "1.- Agregar" << endl;
        cout << "2.- Mostrar" << endl;
        cout << "3.- Insertar en posicion N" << endl;
        cout << "4.- Eliminar" << endl;
        cout << "0.- Salir" << endl;
        cout << "\nIngrese una opcion valida: ";
        opcion = _getch();

        switch (opcion)
        {

        case '1': // Agregar
            do
            {
                system("cls");
                cout << "*** Agregar datos ***\n\n";
                cout << "\nIngrese ID: ";
                cin >> id;
                cout << "\nIngrese el nombre: ";
                cin >> nom;
                do
                {
                    cout << "\nIngrese Nota 1: ";
                    cin >> n1;
                } while (n1 > 20 || n1 < 0);
                do
                {

                    cout << "\nIngrese Nota 2: ";
                    cin >> n2;
                } while (n2 > 20 || n2 < 0);
                do
                {
                    cout << "\nIngrese Nota 3: ";
                    cin >> n3;
                } while (n3 > 20 || n3 < 0);
                n.insertar(lis, ulis, id, nom, n1, n2, n3, numeroNodos);
                cout << "Desea ingresar otro nodo?: s/n: ";
                opc = _getch();
            } while (opc == 's' || opc == 'S');
            break;
        case '2': // Mostrar
            system("cls");
            cout << "*** Mostrar Lista ***\n\n";
            cout << "Pos.\tID\tNombre\tNota1\tNota2\tNota3\tPromedio\n\n";
            n.mostrar(lis);
            system("PAUSE");
            break;
        case '3': // Insertar en posicion N
            system("cls");
            cout << "*** Insertar en posicion N ***\n\n";
            cout << "\nNumero de Nodos: " << numeroNodos;
            cout << endl;
            n.mostrar(lis);
            cout << "\nIngrese la posicion en donde desea agregar el nuevo dato: ";
            cin >> posicion;

            if (posicion > numeroNodos)
            {
                printf("\t\t------------------------------");
                printf("\n\t\tPosicion Erronea!!!");
                printf("\n\t\t------------------------------\n");
                system("PAUSE");
            }
            else
            {
                do
                {
                    cout << "\nIngrese ID: ";
                    cin >> id;
                    cout << "\nIngrese el nombre: ";
                    cin >> nom;
                    do
                    {
                        cout << "\nIngrese Nota 1: ";
                        cin >> n1;
                    } while (n1 > 20 || n1 < 0);
                    do
                    {

                        cout << "\nIngrese Nota 2: ";
                        cin >> n2;
                    } while (n2 > 20 || n2 < 0);
                    do
                    {
                        cout << "\nIngrese Nota 3: ";
                        cin >> n3;
                    } while (n3 > 20 || n3 < 0);
                    n.agregarCPosicion(lis, ulis, posicion, nom, id, n1, n2, n3, numeroNodos);
                    cout << "Desea ingresar otro nodo?: s/n: ";
                    opc = _getch();
                } while (opc == 's' || opc == 'S');
            }
            system("PAUSE");
            break;
        case '4':
            system("cls");
            cout << "*** Eliminar ***\n"
                 << endl;
            n.eliminar(lis);
            cout << "Dato eliminado" << endl;
            system("PAUSE");
            break;
        case '0':
            system("cls");
            cout << "Salir" << endl;
            system("PAUSE");
            exit(0);
            break;

        } // Fin switch()
    } while (opcion != '1' || opcion != '2' || opcion != '3' || opcion != '4' || opcion != '0');

} // Fin programa
