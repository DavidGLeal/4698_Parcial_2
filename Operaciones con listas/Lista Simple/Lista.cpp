/*UFA-ESPE
 * Deber 5
 * Autores: Iza Christopher- Rea Denise
 * Fecha de creación 25/05/2022
 * Fecha de modificación 30/05/2022
 * Grupo 20
 * github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Lista.h"
#include "Nodo.cpp"
Lista::Lista()
{
	this->primero = NULL;
	this->actual = NULL;
}
// Ingreso por cabeza
void Lista::insertarCabeza(int _valor)
{
	Nodo *nuevo = new Nodo(_valor);
	if (ListaVacia())
	{
		this->primero = nuevo;
		this->actual = nuevo;
	}
	else
	{
		nuevo->setSiguiente(primero);
		this->primero = nuevo;
	}
}
// Ingreso por cola
void Lista::insertarCola(int _valor)
{
	Nodo *nuevo = new Nodo(_valor);
	if (ListaVacia())
	{
		this->primero = nuevo;
	}
	else
	{
		this->actual->setSiguiente(nuevo);
	}
	this->actual = nuevo;
}
// Impresion principio a fin
void Lista::mostrarCabeza()
{
	if (this->ListaVacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		Nodo *tmp = this->primero;
		while (tmp)
		{
			cout << tmp->getValor() << "-->";
			tmp = tmp->getSiguiente();
		}
		cout << "NULL\n";
	}
}

// Recorrido hasta el final
void Lista::recorrido(Nodo *nodo)
{
	if (nodo == NULL)
	{
		return;
	}
	recorrido(nodo->getSiguiente());
	cout << "<--" << nodo->getValor();
}
// Impresion de final a principio
void Lista::mostrarCola()
{
	if (this->ListaVacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		cout << "NULL";
		this->recorrido(this->primero);
		cout << "\n";
	}
}
// Busqueda
void Lista::buscar()
{
	int valor_b, count = 0;
	bool ext = false;
	if (this->ListaVacia())
	{
		cout << "La lista esta vacia, no se puede buscar" << endl;
	}
	else
	{
		cout << "Ingrese su valor a buscar" << endl;
		cin >> valor_b;
		Nodo *num = new Nodo(valor_b);
		Nodo *tmp = primero;

		while (tmp->getSiguiente())
		{
			if (tmp->getValor() == num->getValor())
			{
				cout << "El numero esta en la posicion: " << count + 1 << endl;
				ext = true;
				break;
			}
			tmp = tmp->getSiguiente();
			count++;
		}

		if (ext == false)
		{
			cout << "El numero no esta en la lista: " << endl;
		}
	}
}

// Eliminar por la cabeza
void Lista::eliminarCabeza()
{
	Nodo *aux;
	int eliminar = 0;

	if (ListaVacia())
	{
		cout << " La lista esta vacia, por lo tanto no se puede realizar esta accion" << endl;
	}
	else
	{
		cout << "Digite el numero de valores a suprimir por Cabeza" << endl;
		cout << " Recuerde que su lista contiene " << sizeLista() << " elementos  " << endl;
		eliminar = ingresoDatosEnteros();
		if (eliminar <= sizeLista())
		{
			if (eliminar == sizeLista())
			{
				primero = nullptr;
				cout << "\n Lista eliminada con exito \n";
			}
			else
			{
				for (int i = 0; i < eliminar; i++)
				{
					aux = this->primero;
					this->primero = this->primero->getSiguiente();
					aux->setSiguiente(NULL);
					delete aux;
				}
				cout << "\n Elementos eliminados con exito \n";
			}
		}
		else
		{
			cout << "No se puede eliminar " << eliminar << " elementos de " << sizeLista() << endl;
		}
	}
}

// Eliminar por Cola
void Lista::eliminarCola()
{
	int eliminar = 0;
	int i = 0;
	Nodo *aux = this->primero;
	Nodo *aux2;
	if (ListaVacia())
	{
		cout << "Los sentimos, su lista esta vacia, no se puede realizar esta accion" << endl;
	}
	else
	{
		cout << "\n Digite el numero de valores a suprimir por Cola" << endl;
		cout << " Recuerde que su lista contiene " << sizeLista() << " elementos  " << endl;
		cin>>eliminar;
		if (eliminar <= sizeLista())
		{
			while (aux->getSiguiente())
			{
				aux2 = aux;
				aux = aux->getSiguiente();
			}

			if (eliminar == 1 && sizeLista() == 1)
			{
				this->primero = this->primero->getSiguiente();
				delete aux;
				cout << "Su lista ahora esta vacia \n"
					 << endl;
			}
			else if (eliminar == sizeLista())
			{
				primero = NULL;
				cout << "Su lista ha sido eliminada\n " << endl;
			}
			else
			{
				do
				{
					aux2->setSiguiente(nullptr);
					delete aux;
					aux = primero;
					aux2 = nullptr;
					while (aux->getSiguiente())
					{
						aux2 = aux;
						aux = aux->getSiguiente();
					}
					i++;
				} while (i != eliminar);
				cout << "\n Elementos eliminados con exito\n ";
			}
		}
		else
		{
			cout << "No se puede eliminar " << eliminar << " elementos de " << sizeLista() << endl;
		}
	}
}
// obtener el tamaño de la Lista
int Lista::sizeLista()
{
	Nodo *aux = this->primero;
	int c = 0;
	while (aux != nullptr)
	{
		c++;
		aux = aux->getSiguiente();
	}
	return c;
}
int Lista::ingresoDatosEnteros()
{
	char *dato = new char[10], c;
	int i = 0;
	printf("Ingrese su valor: ");
	while ((c = getch()) != 13)
	{
		if (c >= '0' && c <= '9')
		{
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8 || c == 127)
		{
			printf("\b \b");
			dato[i--] = 0;
		}
	}
	dato[i] = '\0';
	cout << "\n ";
	return atoi(dato);
}

void Lista::insertarColaEnteros()
{
	char c;
	while (c != 47)
	{
		int i = 0;
		char *dato = new char[10], C;
		printf("Ingrese un valor o '/' detener: ");
		while ((c = getch()) != 13)
		{
			if (c >= '0' && c <= '9')
			{
				printf("%c", c);
				dato[i++] = c;
			}
			else if (c == 8 || c == 127)
			{
				printf("\b \b");
				dato[i--] = 0;
			}
			else if (c == 47)
			{
				printf("/", c);
				return;
			}
		}
		dato[i] = '\0';
		this->insertarCola(atoi(dato));
		cout << "\n";
	}
}

void Lista::insertarCabezaEnteros()
{
	char c;
	while (c != 47)
	{
		int i = 0;
		char *dato = new char[10];
		printf("Ingrese un valor o '/' detener: ");
		while ((c = getch()) != 13)
		{
			if (c >= '0' && c <= '9')
			{
				printf("%c", c);
				dato[i++] = c;
			}
			else if (c == 8 || c == 127)
			{
				printf("\b \b");
				dato[i--] = 0;
			}
			else if (c == 47)
			{
				printf("/", c);
				return;
			}
		}
		dato[i] = '\0';
		this->insertarCabeza(atoi(dato));
		cout << "\n";
	}
}

Lista::~Lista()
{
	while (primero)
	{
		delete primero;
		primero = primero->getSiguiente();
	}
}
