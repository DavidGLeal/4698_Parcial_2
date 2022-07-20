#include <iostream>

using namespace std;

class ListaCircularSimple {
private:
	class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo* ant;
	};

	Nodo* raiz;
public:
	ListaCircularSimple();
	~ListaCircularSimple();
	void insertarPrimero(int x);
	void insertarUltimo(int x);
	bool vacia();
	void imprimir();
	int cantidad();
	void borrar(int pos);
};

ListaCircularSimple::ListaCircularSimple()
{
	raiz = NULL;
}

ListaCircularSimple::~ListaCircularSimple()
{
	if (raiz != NULL) {
		Nodo* reco = raiz->sig;
		Nodo* bor;
		while (reco != raiz)
		{
			bor = reco;
			reco = reco->sig;
			delete bor;
		}
		delete raiz;
	}
}

void ListaCircularSimple::insertarPrimero(int x)
{
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	if (raiz == NULL)
	{
		nuevo->sig = nuevo;
		nuevo->ant = nuevo;
		raiz = nuevo;
	}
	else
	{
		Nodo* ultimo = raiz->ant;
		nuevo->sig = raiz;
		nuevo->ant = ultimo;
		raiz->ant = nuevo;
		ultimo->sig = nuevo;
		raiz = nuevo;
	}
}

void ListaCircularSimple::insertarUltimo(int x)
{
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	if (raiz == NULL)
	{
		nuevo->sig = nuevo;
		nuevo->ant = nuevo;
		raiz = nuevo;
	}
	else
	{
		Nodo* ultimo = raiz->ant;
		nuevo->sig = raiz;
		nuevo->ant = ultimo;
		raiz->ant = nuevo;
		ultimo->sig = nuevo;
	}
}

bool ListaCircularSimple::vacia()
{
	if (raiz == NULL)
		return true;
	else
		return false;
}

void ListaCircularSimple::imprimir()
{
	if (!vacia()) {
		Nodo* reco = raiz;
		do {
			cout << reco->info << "-";
			reco = reco->sig;
		} while (reco != raiz);
		cout << "\n";
	}
}

int ListaCircularSimple::cantidad()
{
	int cant = 0;
	if (!vacia())
	{
		Nodo* reco = raiz;
		do {
			cant++;
			reco = reco->sig;
		} while (reco != raiz);
	}
	return cant;
}

void ListaCircularSimple::borrar(int pos)
{
	if (pos <= cantidad())
	{
		if (pos == 1)
		{
			if (cantidad() == 1)
			{
				delete raiz;
				raiz = NULL;
			}
			else
			{
				Nodo* bor = raiz;
				Nodo* ultimo = raiz->ant;
				raiz = raiz->sig;
				ultimo->sig = raiz;
				raiz->ant = ultimo;
				delete bor;
			}
		}
		else {
			Nodo* reco = raiz;
			for (int f = 1; f <= pos - 1; f++)
				reco = reco->sig;
			Nodo* bor = reco;
			Nodo* anterior = reco->ant;
			reco = reco->sig;
			anterior->sig = reco;
			reco->ant = anterior;
			delete bor;
		}
	}
}



