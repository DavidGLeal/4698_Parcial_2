#include <iostream>
#include "CCadena.h"
using namespace std;
 
template<class TIPO> class lista;
 
template<class TIPO>
class nodo {
   public:
    nodo(TIPO v, nodo<TIPO> *sig = NULL) {
       valor = v;
       siguiente = sig;
    }
 
   private:
    TIPO valor;
    nodo<TIPO> *siguiente;
 
   friend class lista<TIPO>;
};
 
template<class TIPO>
class lista {
   public:
    lista() { actual = NULL; }
    ~lista();
 
    void Insertar(TIPO v);
    void Borrar(TIPO v);
    bool ListaVacia() { return actual == NULL; }
    void Mostrar();
    void Siguiente();
    bool Actual() { return actual != NULL; }
    TIPO ValorActual() { return actual->valor; }
 
   private:
    nodo<TIPO> *actual;
};
 
template<class TIPO>
lista<TIPO>::~lista() {
   nodo<TIPO> *Nodo;
 
   // Mientras la lista tenga más de un nodo
   while(actual->siguiente != actual) {
      // Borrar el nodo siguiente al apuntado por lista
      Nodo = actual->siguiente;
      actual->siguiente = Nodo->siguiente;
      delete Nodo;
   }
   // Y borrar el último nodo
   delete actual;
   actual = NULL;
}
 
template<class TIPO>
void lista<TIPO>::Insertar(TIPO v) {
   nodo<TIPO> *Nodo;
 
   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo<TIPO>(v);
 
   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}
 
template<class TIPO>
void lista<TIPO>::Borrar(TIPO v) {
   nodo<TIPO> *Nodo;
 
   Nodo = actual;
 
   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if(actual->siguiente->valor != v) actual = actual->siguiente;
   } while(actual->siguiente->valor != v && actual != Nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(actual == actual->siguiente) {
         // Borrar toda la lista
         delete actual;
         actual = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         Nodo = actual->siguiente;
         actual->siguiente = Nodo->siguiente;
         delete Nodo;
      }
   }
}
 
template<class TIPO>
void lista<TIPO>::Mostrar() {
   nodo<TIPO> *Nodo = actual;
 
   do {
      cout << Nodo->valor << "-> ";
      Nodo = Nodo->siguiente;
   } while(Nodo != actual);
 
   cout << endl;
}
 
template<class TIPO>
void lista<TIPO>::Siguiente() {
   if(actual) actual = actual->siguiente;
}
