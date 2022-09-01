// ListaSimple.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Lista.h"

int main() {
	Lista listaDeNumeros;
	Lista listaMCM;
	int op;
	do {
		cout << "		MENU DE OPCIONES	";
		cout << "\n	Elija una opcion: ";
		cout << "\n1: Ingresar valor a la lista por cola";
		cout << "\n2: Ingresar valor a la lista por cabeza";
		cout << "\n3: Imprimir por la Cola";
		cout << "\n4: Buscar";
		cout << "\n5: Eliminar";
		cout << "\n0: Salir";
		cout << "\n";
		cin >> op;
		cout << "\n";
		switch (op) {
		case 1:
			int num;
			cout << "Ingresar numeros a guardar: ";
			cin >> num;
			listaDeNumeros.agregarFinal(num);
			system("cls");
			break;
		case 2:
			int num2;
			cout << "Ingresar numeros a guardar: ";
			cin >> num2;
			listaDeNumeros.agregarInicio(num2);
			system("cls");
			break;
		case 3:
			cout << "Lista Impresa:\n";
			listaDeNumeros.imprimirInicio();
			system("pause");
			system("cls");
			break;
		case 4:
			listaDeNumeros.buscarLista();
			system("pause");
			system("cls");
			break;
		case 5:
			listaDeNumeros.eliminarElemento();
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

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
