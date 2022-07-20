#include <iostream>
#include "ListaCircularSimple.h"
using namespace std;
int main()
{
	ListaCircularSimple* lc = new ListaCircularSimple();
	lc->insertarPrimero(100);
	lc->insertarPrimero(45);
	lc->insertarPrimero(12);
	lc->insertarPrimero(4);
	cout << "Insertando 4 nodos al principio:\n";
	lc->imprimir();
	lc->insertarUltimo(250);
	lc->insertarUltimo(7);
	cout << "Insertando 2 nuevos nodos al final:\n";
	lc->imprimir();
	cout << "Cantidad de nodos:" << lc->cantidad() << "\n";
	cout << "Borrando el primer nodo de la lista:\n";
	lc->borrar(1);
	lc->imprimir();
	cout << "Borrando el cuarto nodo de la lista:\n";
	lc->borrar(4);
	lc->imprimir();
	delete lc;
	system("pause");
}