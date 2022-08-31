#include "Nodo.h"

class Lista
{
public:
	Lista();
	~Lista();
	Nodo* getInicio(void);
	void setInicio(Nodo* newInicio);
	Nodo* getActual(void);
	void setActual(Nodo* newActual);
	bool listaVacia(void);
	virtual void agregarInicio(int);
	virtual void agregarFinal(int);
	virtual void imprimirInicio(void);
	virtual void eliminarElemento(void);
	virtual void eliminarInicio(void);
	virtual void eliminarFinal(void);
	virtual void buscarLista(void);
protected:
private:
	Nodo* inicio;
	Nodo* actual;


};
