#include <iostream>

class Nodo
{
private:
    int valor;
    Nodo *siguiente;
    Nodo *previo;
public:

    Nodo();
    Nodo(int,Nodo*);

    int getValor();
    Nodo* getSiguiente();
    Nodo* getPrevio();

    void setSiguiente(Nodo*);
    void setPrevio(Nodo*);
    void setValor(int);
};

