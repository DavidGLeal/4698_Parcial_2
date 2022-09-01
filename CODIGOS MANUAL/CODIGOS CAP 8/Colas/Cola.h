#include "Nodo.h"
class Cola : public Nodo
{
public:
	Cola();
	~Cola();
	Nodo* getInicio(void);
	void setInicio(Nodo* newInicio);
	Nodo* getActual(void);
	void setActual(Nodo* newActual);
	bool listaVacia(void);
	virtual void enqueue(int);
	virtual void dequeue();
	virtual void mostar(void);
protected:
private:
	Nodo* inicio;
	Nodo* actual;
};
