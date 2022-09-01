#include "Nodo.cpp"
#define size 7
class Hash
{
private:
	Nodo* cadena[size];
public:
	void inicializar();
	void insertar(int valor);
	void imprimir();
	void busqueda(int valor);
	void eliminar(int num);
	int HashFunc(int key);
};
