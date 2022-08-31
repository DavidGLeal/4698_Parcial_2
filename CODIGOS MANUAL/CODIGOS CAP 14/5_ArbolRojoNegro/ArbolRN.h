#include "Nodo.h"

// La clase ArbolRN implementa las operaciones del árbol
class ArbolRN
{
private:
    NodoPtr raiz;
    NodoPtr TNULL;
 
    // inicializa los nodos con valores apropiados
    // todos los punteros están apuntando al puntero null
    void inicializarNodoNull(NodoPtr nodo, NodoPtr padre)
    {
        nodo->dato = 0;
        nodo->padre = padre;
        nodo->izquierdo = nullptr;
        nodo->derecho = nullptr;
        nodo->color = 0;
    }
 
    void preOrdenAuxiliar(NodoPtr nodo)
    {
        if (nodo != TNULL)
        {
            cout << nodo->dato << " ";
            preOrdenAuxiliar(nodo->izquierdo);
            preOrdenAuxiliar(nodo->derecho);
        }
    }
 
    void inOrdenAuxiliar(NodoPtr nodo)
    {
        if (nodo != TNULL)
        {
            inOrdenAuxiliar(nodo->izquierdo);
            cout << nodo->dato << " ";
            inOrdenAuxiliar(nodo->derecho);
        }
    }
 
    void postOrdenAuxiliar(NodoPtr nodo)
    {
        if (nodo != TNULL)
        {
            postOrdenAuxiliar(nodo->izquierdo);
            postOrdenAuxiliar(nodo->derecho);
            cout << nodo->dato << " ";
        }
    }
 
    NodoPtr buscarArbolAuxiliar(NodoPtr nodo, int valor)
    {
        if (nodo == TNULL || valor == nodo->dato)
        {
            return nodo;
        }
 
        if (valor < nodo->dato)
        {
            return buscarArbolAuxiliar(nodo->izquierdo, valor);
        }
        return buscarArbolAuxiliar(nodo->derecho, valor);
    }
 
    // arreglar el arbol modificado por la eliminacion
    void arreglarEliminacion(NodoPtr x)
    {
        NodoPtr s;
        while (x != raiz && x->color == 0)
        {
            if (x == x->padre->izquierdo)
            {
                s = x->padre->derecho;
                if (s->color == 1)
                {
                    // case 3.1
                    s->color = 0;
                    x->padre->color = 1;
                    rotarIzquierdo(x->padre);
                    s = x->padre->derecho;
                }
 
                if (s->izquierdo->color == 0 && s->derecho->color == 0)
                {
                    // caso 3.2
                    s->color = 1;
                    x = x->padre;
                }
                else
                {
                    if (s->derecho->color == 0)
                    {
                        // caso 3.3
                        s->izquierdo->color = 0;
                        s->color = 1;
                        rotarDerecho(s);
                        s = x->padre->derecho;
                    }
 
                    // caso 3.4
                    s->color = x->padre->color;
                    x->padre->color = 0;
                    s->derecho->color = 0;
                    rotarIzquierdo(x->padre);
                    x = raiz;
                }
            }
            else
            {
                s = x->padre->izquierdo;
                if (s->color == 1)
                {
                    // caso 3.1
                    s->color = 0;
                    x->padre->color = 1;
                    rotarDerecho(x->padre);
                    s = x->padre->izquierdo;
                }
 
                if (s->derecho->color == 0 && s->derecho->color == 0)
                {
                    // caso 3.2
                    s->color = 1;
                    x = x->padre;
                }
                else
                {
                    if (s->izquierdo->color == 0)
                    {
                        // caso 3.3
                        s->derecho->color = 0;
                        s->color = 1;
                        rotarIzquierdo(s);
                        s = x->padre->izquierdo;
                    }
 
                    // caso 3.4
                    s->color = x->padre->color;
                    x->padre->color = 0;
                    s->izquierdo->color = 0;
                    rotarDerecho(x->padre);
                    x = raiz;
                }
            }
        }
        x->color = 0;
    }
 
    void trasplantarArbol(NodoPtr u, NodoPtr v)
    {
        if (u->padre == nullptr)
        {
            raiz = v;
        }
        else if (u == u->padre->izquierdo)
        {
            u->padre->izquierdo = v;
        }
        else
        {
            u->padre->derecho = v;
        }
        v->padre = u->padre;
    }
 
    void borrarNodoAuxiliar(NodoPtr nodo, int valor)
    {
        // encontrar el nodo que contiene el valor
        NodoPtr z = TNULL;
        NodoPtr x, y;
        while (nodo != TNULL)
        {
            if (nodo->dato == valor)
            {
                z = nodo;
            }
 
            if (nodo->dato <= valor)
            {
                nodo = nodo->derecho;
            }
            else
            {
                nodo = nodo->izquierdo;
            }
        }
 
        if (z == TNULL)
        {
            cout << "No se pudo hallar ese valor en el arbol" << endl;
            return;
        }
 
        y = z;
        int y_original_color = y->color;
        if (z->izquierdo == TNULL)
        {
            x = z->derecho;
            trasplantarArbol(z, z->derecho);
        }
        else if (z->derecho == TNULL)
        {
            x = z->izquierdo;
            trasplantarArbol(z, z->izquierdo);
        }
        else
        {
            y = hallarMinimo(z->derecho);
            y_original_color = y->color;
            x = y->derecho;
            if (y->padre == z)
            {
                x->padre = y;
            }
            else
            {
                trasplantarArbol(y, y->derecho);
                y->derecho = z->derecho;
                y->derecho->padre = y;
            }
 
            trasplantarArbol(z, y);
            y->izquierdo = z->izquierdo;
            y->izquierdo->padre = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0)
        {
            arreglarEliminacion(x);
        }
    }
 
    // arreglar el árbol rojo-negro
    void arreglarInsercion(NodoPtr k)
    {
        NodoPtr u;
        while (k->padre->color == 1)
        {
            if (k->padre == k->padre->padre->derecho)
            {
                u = k->padre->padre->izquierdo; // tío
                if (u->color == 1)
                {
                    // caso 3.1
                    u->color = 0;
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    k = k->padre->padre;
                }
                else
                {
                    if (k == k->padre->izquierdo)
                    {
                        // caso 3.2.2
                        k = k->padre;
                        rotarDerecho(k);
                    }
                    // caso 3.2.1
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    rotarIzquierdo(k->padre->padre);
                }
            }
            else
            {
                u = k->padre->padre->derecho; // tío
 
                if (u->color == 1)
                {
                    // caso 3.1
                    u->color = 0;
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    k = k->padre->padre;
                }
                else
                {
                    if (k == k->padre->derecho)
                    {
                        // caso 3.2.2
                        k = k->padre;
                        rotarIzquierdo(k);
                    }
                    // caso 3.2.1
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    rotarDerecho(k->padre->padre);
                }
            }
            if (k == raiz)
            {
                break;
            }
        }
        raiz->color = 0;
    }
 
    void auxiliarImprimir(NodoPtr raiz, string indent, bool last)
    {
        if (raiz != TNULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "     ";
            }
            else
            {
                cout << "L----";
                indent += "|    ";
            }
 
            string sColor = raiz->color ? "ROJO" : "NEGRO";
            cout << raiz->dato << "(" << sColor << ")" << endl;
            auxiliarImprimir(raiz->izquierdo, indent, false);
            auxiliarImprimir(raiz->derecho, indent, true);
        }
        // cout<<raiz->izquierdo->dato<<endl;
    }
 
public:
    ArbolRN()
    {
        TNULL = new Nodo;
        TNULL->color = 0;
        TNULL->izquierdo = nullptr;
        TNULL->derecho = nullptr;
        raiz = TNULL;
    }
 
    // Pre-Order traversal
    // nodo->izquierdo Subtree->derecho Subtree
    void preorden()
    {
        preOrdenAuxiliar(this->raiz);
    }
 
    void inorden()
    {
        inOrdenAuxiliar(this->raiz);
    }
 
    void postOrden()
    {
        postOrdenAuxiliar(this->raiz);
    }
 
    // buscar el valor v en el arbol
    NodoPtr buscarEnElArbol(int v)
    {
        return buscarArbolAuxiliar(this->raiz, v);
    }
 
    // encontrar el nodo con el valor mínimo
    NodoPtr hallarMinimo(NodoPtr nodo)
    {
        while (nodo->izquierdo != TNULL)
        {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }
 
    // encontrar el nodo con el valor máximo
    NodoPtr hallarMaximo(NodoPtr nodo)
    {
        while (nodo->derecho != TNULL)
        {
            nodo = nodo->derecho;
        }
        return nodo;
    }
 
    // encontrar sucesor del nodo
    NodoPtr hallarSucesor(NodoPtr x)
    {
        if (x->derecho != TNULL)
        {
            return hallarMinimo(x->derecho);
        }
 
        NodoPtr y = x->padre;
        while (y != TNULL && x == y->derecho)
        {
            x = y;
            y = y->padre;
        }
        return y;
    }
 
    // encontrar el predecesor del nodo
    NodoPtr encontrarPredecesor(NodoPtr x)
    {
        if (x->izquierdo != TNULL)
        {
            return hallarMaximo(x->izquierdo);
        }
 
        NodoPtr y = x->padre;
        while (y != TNULL && x == y->izquierdo)
        {
            x = y;
            y = y->padre;
        }
 
        return y;
    }
 
    // rotar el nodo x a la izquierda
    void rotarIzquierdo(NodoPtr x)
    {
        NodoPtr y = x->derecho;
        x->derecho = y->izquierdo;
        if (y->izquierdo != TNULL)
        {
            y->izquierdo->padre = x;
        }
        y->padre = x->padre;
        if (x->padre == nullptr)
        {
            this->raiz = y;
        }
        else if (x == x->padre->izquierdo)
        {
            x->padre->izquierdo = y;
        }
        else
        {
            x->padre->derecho = y;
        }
        y->izquierdo = x;
        x->padre = y;
    }
 
    // rotar al nodo x a la derecha
    void rotarDerecho(NodoPtr x)
    {
        NodoPtr y = x->izquierdo;
        x->izquierdo = y->derecho;
        if (y->derecho != TNULL)
        {
            y->derecho->padre = x;
        }
        y->padre = x->padre;
        if (x->padre == nullptr)
        {
            this->raiz = y;
        }
        else if (x == x->padre->derecho)
        {
            x->padre->derecho = y;
        }
        else
        {
            x->padre->izquierdo = y;
        }
        y->derecho = x;
        x->padre = y;
    }
 
    // insertar el valor al árbol en su posición apropiada
    // y arreglar el árbol
    void insert(int valor)
    {
        // Inserción de Búsqueda Binaria
        NodoPtr nodo = new Nodo;
        nodo->padre = nullptr;
        nodo->dato = valor;
        nodo->izquierdo = TNULL;
        nodo->derecho = TNULL;
        nodo->color = 1; // El nuevo nodo debe ser rojo
 
        NodoPtr y = nullptr;
        NodoPtr x = this->raiz;
 
        while (x != TNULL)
        {
            y = x;
            if (nodo->dato < x->dato)
            {
                x = x->izquierdo;
            }
            else
            {
                x = x->derecho;
            }
        }
 
        // y es padre de x
        nodo->padre = y;
        if (y == nullptr)
        {
            raiz = nodo;
        }
        else if (nodo->dato < y->dato)
        {
            y->izquierdo = nodo;
        }
        else
        {
            y->derecho = nodo;
        }
 
        // si el nuevo nodo es una raíz, simplemente retorne
        if (nodo->padre == nullptr)
        {
            nodo->color = 0;
            return;
        }
 
        // si el abuelo es nulo, retornar
        if (nodo->padre->padre == nullptr)
        {
            return;
        }
 
        // Arreglar el arbol
        arreglarInsercion(nodo);
    }
 
    NodoPtr getraiz()
    {
        return this->raiz;
    }
 
    // borrar el Nodo del Arbol
    void borrarNodo(int dato)
    {
        borrarNodoAuxiliar(this->raiz, dato);
    }
 
    // Imprimir en pantalla
    void imprimirCorregido()
    {
        if (raiz)
        {
            auxiliarImprimir(this->raiz, "", true);
        }
    }
};
