#include "Hash.h"
using namespace std;
void Hash::inicializar()
{
	int i;
	for (i = 0; i < size; i++) {
		cadena[i] = NULL;
	}
}
void Hash::insertar(int valor)
{
	//Se crea un nuevo nodo
	Nodo *newNode = new Nodo(valor, nullptr);
	valor=newNode->getDatos();
	newNode->setSiguiente(NULL);
	//Se calcula la clave Hash
	int key = valor % size;
	//Se revisa si la cadena[key] está vacía
	if (cadena[key] == NULL){
		cadena[key]=newNode;
	}	
	//Colisión
	else {
		//Se añade el nodo al final de la cadena[key]
		Nodo *temp = cadena[key];
		while (temp->getSiguiente()) {
			temp = temp->getSiguiente();
		}
		temp->setSiguiente(newNode);
	}
}
void Hash::imprimir()
{
	int i;
	for (i = 0; i < size; i++) {
		Nodo *temp = cadena[i];
		printf("cadena[%d]-->", i);
		while (temp) 
		{
			printf("%d -->", temp->getDatos());
			temp = temp->getSiguiente();
		}
		printf("NULL\n");
	}
}
void Hash::busqueda(int valor)
{
	int key = valor % size;
	Nodo *temp = cadena[key];
	while (temp) {
		if (temp->getDatos() == valor) {
			printf("Valor encontrado: %d \n", temp->getDatos());
			temp = temp->getSiguiente();
		}else{
			printf("Valor no encontrado: %d\n",valor);
		}
	}
}
void Hash::eliminar(int num)
{
	int hash = HashFunc(num);
	while (cadena[hash] != NULL) {
		if (cadena[hash]->getDatos() == num)
			break;
		hash = HashFunc(hash + 1);
	}
		if (cadena[hash] == NULL) {
			printf("No se encontro ningun elemnto en la clave: %d\n", num);
			return;
		}
		else {
			delete cadena[hash];
		}
	printf("Elemento Eliminado \n");
}
int Hash::HashFunc(int key)
{
	return key % size;
}
