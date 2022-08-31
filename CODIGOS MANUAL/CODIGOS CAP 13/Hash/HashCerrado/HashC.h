#include "NodoCircular.cpp"
#define NCASILLAS 29
 
class HashC
{
private:
	NodoCircular** tabla;
public:
	HashC();
	~HashC();
	void insertar(int valor);
	void eliminar(int valor);
	void imprimir();
	void buscar(int valor);
	int hash(int valor);
	int hash2(int);
};
