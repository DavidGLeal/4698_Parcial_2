#include <iostream>
#include "Nodo.cpp"
using namespace::std;


int main(){
	
	int opcion_menu = 0;
	Nodo n1;
	do
	{
        system("cls");
		cout << "\n|-------------------------------------|";
		cout << "\n|             LISTA SIMPLE            |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 4. Eliminar      |";
		cout << "\n| 2. Buscar        | 5. Desplegar     |";
		cout << "\n| 3. Modificar     | 6. Salir         |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
            n1.insertarNodo();
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
			n1.buscarNodo();
			break;
		case 3:
			cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
			n1.modificarNodo();
			break;
		case 4:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			n1.eliminarNodo();
			break;
		case 5: 
			cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
			n1.desplegarLista();
			break;
		case 6:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 6);
	
	
	return 0;
}

