#include "ArbolAVL.cpp"
int main()
{
    Nodo *raiz = nullptr;
    cout << "-----Arbol AVL-------" << endl;
    raiz = raiz->insertarNodo(raiz, 33);
    raiz = raiz->insertarNodo(raiz, 13);
    raiz = raiz->insertarNodo(raiz, 53);
    raiz = raiz->insertarNodo(raiz, 9);
    raiz = raiz->insertarNodo(raiz, 21);
    raiz = raiz->insertarNodo(raiz, 61);
    raiz = raiz->insertarNodo(raiz, 8);
    raiz = raiz->insertarNodo(raiz, 11);
    raiz->imprimirArbol(raiz, "", true);
    raiz = raiz->borrarNodo(raiz, 13);
    cout << "---------------------" << endl;
    cout << "Se ha borrado el 13: " << endl;
    raiz->imprimirArbol(raiz, "", true);
    return 0;
}