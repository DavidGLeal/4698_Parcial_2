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

/**
 * Recorrido inOrden.
 * 
 * @param arbol Un puntero al nodo de la raíz.
 * 
 * @return Dato entero del nodo.
 */
void Arbol::inOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        cout<<"No se encuentran datos en el arbol"<<endl;
        cout<<"El arbol se encuentra vacio"<<endl;
        return;
    }
    else
    {
        inOrden(arbol->getIzquierda());
	cout<<arbol->getValor()<<"->";
        inOrden(arbol->getDerecha());
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
