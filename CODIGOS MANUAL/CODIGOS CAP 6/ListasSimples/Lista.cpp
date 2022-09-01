#include "Lista.h"

Lista::Lista()
{
	this->actual = NULL;
	this->inicio = NULL;
}

Lista::~Lista()
{
	delete actual;
	delete inicio;
}

Nodo* Lista::getInicio()
{
	return this->inicio;
}

void Lista::setInicio(Nodo* newInicio)
{
	this->inicio = newInicio;
}

Nodo* Lista::getActual(void)
{
	return this->actual;
}

void Lista::setActual(Nodo* newActual)
{
	this->actual = newActual;
}

bool Lista::listaVacia(void)
{
	return (this->inicio == NULL);
}

void Lista::agregarInicio(int v)
{
	Nodo* nuevo = new Nodo();
	nuevo->setDato(v);

	if (listaVacia()) {
		setInicio(nuevo);
	}
	else {
		nuevo->setSiguiente(inicio);
		setInicio(nuevo);
	}
}

void Lista::agregarFinal(int v)
{
	Nodo* nuevo = new Nodo();
	nuevo->setDato(v);
	if (listaVacia()) {
		setInicio(nuevo);
	}
	else {
		Nodo* aux = getInicio();
		while (aux->getSiguiente() != NULL)
			aux = aux->getSiguiente();
		aux->setSiguiente(nuevo);
	}
}

void Lista::imprimirInicio(void)
{
	for (Nodo* aux = inicio; aux != NULL; aux = aux->getSiguiente()) {
		cout << aux->getDato() << "--> ";
	}
	cout << "NULL\n";
}

void Lista::eliminarElemento(void)
{
	int val;
	if (inicio) {
		cout << "Ingrese el valor a eliminar: ";
		cin >> val;
		cout << "\n";
		Nodo* aux = inicio;
		Nodo* pre = new Nodo();
		while (aux) {
			if (aux->getDato() == val && inicio == aux) {
				eliminarInicio();
				break;
			}
			else if (aux->getDato() == val && aux->getSiguiente() == nullptr) {
				eliminarFinal();
				break;
			}
			else if (aux->getDato() == val && aux->getSiguiente() != nullptr) {
				pre->setSiguiente(aux->getSiguiente());
				aux->setSiguiente(NULL);
				delete aux;
				break;
			}
			else {
				pre = aux;
				aux = aux->getSiguiente();
			}
		}
	}
	else {
		cout << "\nLista Vacia\n";
	}
	cout << "\n";
}

void Lista::eliminarInicio() {
	Nodo* aux = inicio;
	inicio = inicio->getSiguiente();
	aux->setSiguiente(nullptr);
	delete aux;
}
void Lista::eliminarFinal() {
	if (inicio) {
		Nodo* aux = inicio;
		Nodo* pre = nullptr;
		while (aux->getSiguiente()) {
			pre = aux;
			aux = aux->getSiguiente();
		}
		if (aux == inicio) {
			inicio = inicio->getSiguiente();
			delete aux;
		}
		else {
			pre->setSiguiente(nullptr);
			delete aux;
		}
	}
	else {
		cout << "La lista esta vacia. \n";
	}

}

void Lista::buscarLista(void)
{
	int val;
	cout << "Ingrese el valor a Buscar: ";
	cin >> val;
	int aux1 = 0;
	Nodo* num = new Nodo(val, NULL);
	Nodo* tmp = this->inicio;
	while (tmp) {
		if (tmp->getDato() == num->getDato()) {
			aux1++;
		}
		tmp = tmp->getSiguiente();
	}
	if (aux1 == 0) {
		cout << "\nEl elemento no existe\n";
	}
	else {
		Nodo* aux = inicio;
		while (aux != NULL && aux->getDato() != val) {
			aux = aux->getSiguiente();
		}
		cout << "Existe el elemeto: " << aux->getDato() << " \n";
		cout << "La direccion del elemento buscado: " << aux << " \n";
	}
}

