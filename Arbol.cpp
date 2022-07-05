#include "Arbol.h"

/**
 * Establece el valor de la variable privada arbol al valor del parámetro _arbol.
 * 
 * @param _arbol El nodo raíz del árbol.
 */
void Arbol::setArbol(Nodo *_arbol)
{
    arbol = _arbol;
}

/**
 * Devuelve la raíz del árbol.
 * 
 * @return El nodo raíz del árbol.
 */
Nodo *Arbol::getArbol()
{
    return arbol;
}

/**
 * Crea un nuevo nodo con el valor del parámetro.
 * 
 * @param dato El valor del nodo
 * 
 * @return Un puntero a un objeto Nodo.
 */
Nodo *Arbol::crearNodo(int dato)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 * 
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodo(Nodo *&arbol, int dato)
{
    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout<<"Dato ingresado correctamente...\n";
    }
    else
    {
        int raiz = arbol->getValor();
        if (dato < raiz)
        {
            insertarNodo(arbol->getIzquierda(), dato);
            cout<<"Dato ingresado correctamente...\n";
        }
        else
        {
            insertarNodo(arbol->getDerecha(), dato);
            cout<<"Dato ingresado correctamente...\n";
        }
    }
}

//Función mostrar 👍
void Arbol::mostrar(Nodo *arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrar(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "  ";
        }
        cout << arbol->getValor() << endl;
        mostrar(arbol->getIzquierda(), contador + 1);
    }
}

//Función que calcula el peso de un árbol binario
int Arbol::peso(Nodo *arbol)
{
    if (arbol == NULL)
        return 0;
    else
        return 1 + peso(arbol->getIzquierda()) + peso(arbol->getDerecha());
}

//Función que calcula la altura (por niveles + 1) de un árbol binario
int Arbol::altura(Nodo *aux)
{
	 if (aux == NULL)
	    return 0;
	 if (aux->getIzquierda() == NULL && aux ->getDerecha() == NULL) 
	    return 1;
	 return max (altura (aux->getIzquierda()), altura (aux->getDerecha())) + 1; 
}

//Funciónes que determinan si un árbol es perfecto o no
//Esta función se complementa con la función "simetias"
bool Arbol::simetria(Nodo* X, Nodo* Y){
    if (X == NULL && Y == NULL) {
        return true;
    }
    return (X != NULL && Y != NULL) &&
        simetria(X->getIzquierda(), Y->getDerecha()) &&
        simetria(X->getDerecha(), Y->getIzquierda());
}

//Función que compara los sub - árboles obtenidos en la 
//función "simetria"
bool Arbol::simetrias(Nodo* aux){
    if (aux == NULL) {
        return true;
    }
 
    return simetria(aux->getIzquierda(), aux->getDerecha());
}

//RECORRIDO EN PREORDEN
/**
 * *|CURSOR_MARCADOR|*
 * 
 * @param arbol es la raiz del arbol
 * 
 * @return el valor del nodo.
 */
void Arbol::preOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
        cout<<"No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        cout<<arbol->getValor()<<"-";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}
void Arbol::buscar(Nodo* arbol, int dato){	
if(arbol == NULL){	 
   cout<<"No se encuentran datos en el arbol\n";
}
else if(arbol->getValor() == dato){
	cout<<arbol->getValor()<<"\t "<<"Dato encontrado correctamente...\n";
}
else if(dato < arbol->getValor()){
buscar(arbol->getIzquierda(), dato);
}
else{
buscar(arbol->getDerecha(), dato);
}
}

<<<<<<< HEAD

/**
 * Imprime el árbol en orden posterior.
 * 
 * @param arbol El nodo raíz del árbol.
 * 
 * @return el valor del nodo.
 */
void Arbol::postOrden(Nodo *arbol){
	
	 if (arbol == NULL)
    {
        return;
        cout<<"No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
		cout<<arbol->getValor()<<"->";
    }
} 


=======
>>>>>>> 43921ee9ed286a3d641a34c157eddc7e5593c36b
