#include "Nodo.cpp"

class Arbol
{
private:
    Nodo *arbol = NULL;
public:
    void setArbol(Nodo *);
    Nodo *getArbol();
    Nodo *crearNodo(int);
    void insertarNodo(Nodo *&, int);
    void mostrar(Nodo *, int);
    void buscar(Nodo *, int);
    void preOrden(Nodo *);
    void inOrden(Nodo *);
    void postOrden(Nodo *);
};
