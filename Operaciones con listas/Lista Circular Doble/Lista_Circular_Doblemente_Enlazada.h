#include "Nodo.cpp"

class Lista_Circular_Doblemente_Enlazada
{
private:
    Nodo *cabeza;
    Nodo *actual;

    bool ListaVacia(){
        return (this->cabeza==nullptr);
    }
public:
    Lista_Circular_Doblemente_Enlazada();
    ~Lista_Circular_Doblemente_Enlazada();

    void Insertar(int);
    void Eliminar(int);
    void Buscar(int);
    void Mostrar();
    void InsertarPorCola(Nodo**, int);
    void InsertarPorCabeza(Nodo**, int);
    void InsertarDespues(Nodo**, int,int);
};
