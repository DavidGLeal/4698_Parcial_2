#include "Nodo.h"
class Pila : public Nodo
{
public:
	Pila();
	~Pila();
	Nodo* getInicio(void);
	void setInicio(Nodo* newInicio);
	Nodo* getActual(void);
	void setActual(Nodo* newActual);
	bool listaVacia(void);
	virtual void push(float);
	virtual void mostrar(void);
	virtual void pop(void);
protected:
private:
	Nodo* inicio;
	Nodo* actual;
};

