#include "HashC.h"
HashC::HashC()
{
	tabla = new NodoCircular * [NCASILLAS];
	for (int i = 0; i < NCASILLAS; i++) {
		tabla[i] = NULL;
	}
}
HashC::~HashC()
{
	for (int i = 0; i < NCASILLAS; i++) {
		NodoCircular* aux = tabla[i];
		aux = tabla[i];
		while (aux != NULL) {
			tabla[i] = tabla[i]->getSig();
			delete aux;
			aux = tabla[i];
		}
	}
	delete[] tabla;
}
void HashC::insertar(int valor)
{
	int pos = hash(valor);
	NodoCircular* aux = tabla[pos];
	if (tabla[pos] == NULL) {
		tabla[pos] = new NodoCircular(valor);
	}
	else {
		while (tabla[pos] != NULL) {
			pos = hash2(pos);
		}
		tabla[pos] = new NodoCircular(valor);
	}
}
void HashC::eliminar(int valor)
{
	int pos = hash(valor);
	NodoCircular* aux = tabla[pos];
	if (tabla[pos] == NULL) {
		cout << "Lista Vacia" << endl;
	}
	else {
		if (aux->getValor() == valor) {
			tabla[pos] = tabla[pos]->getSig();
			delete aux;
		}
		else {
			while (tabla[pos]->getValor() != valor) {
				pos = hash2(pos);
			}
			aux = tabla[pos];
			tabla[pos] = tabla[pos]->getSig();
			delete aux;
		}
	}
}
void HashC::imprimir()
{
	for (int i = 0; i < NCASILLAS; i++) {
		NodoCircular* aux = tabla[i];
		while (aux != NULL) {
			cout << "Posicion[" << i << "]: " << aux->getValor() << " ";
			aux = aux->getSig();
		}
		cout << endl;
	}
}
void HashC::buscar(int valor)
{
	const int ELEMENTO_NO_ENCONTRADO{ -1 };
	int clave{ hash(valor) };
	int retorno = clave;
	bool noEsta = false;
	if (tabla[clave] == NULL || tabla[clave]->getValor() != valor) {
		clave += hash2(valor);
		while (tabla[clave] == NULL || tabla[clave]->getValor() != valor || clave != retorno) {
			clave = hash2(valor);
			if (clave == retorno) {
				noEsta = true;
				break;
			}
		}
	}	
}
int HashC::hash(int valor)
{
	return valor % NCASILLAS;
}
int HashC::hash2(int pos)
{
	int i = 1;
	pos = (pos + i) % NCASILLAS;
	return pos;
}
