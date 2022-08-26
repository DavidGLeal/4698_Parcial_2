#include "Nodo.h"

class ArbolJuego{
	private:
		Nodo *raiz=NULL;
		void preOrdenA(Nodo *);
		void inOrdenA(Nodo *); 
		void postOrdenA(Nodo *);
		Nodo *buscarArbolAyuda(Nodo *, int);
		void eliminarNodoAyuda(Nodo *, int);
		void imprimirAyuda(Nodo *, string , bool);
		void RotarIzquierda(Nodo *);
		void RotarDerecha(Nodo *);
		void juego(Nodo *);
		Nodo *unir(Nodo *, Nodo *);
		void separar(Nodo *&, Nodo *&, Nodo *&);
		
	public:
		ArbolJuego();
		Nodo *getRaiz();
		void setRaiz(Nodo *);
		void preorden();
		void inorden();
		void postorden();
		Nodo *buscarArbol(int);
		Nodo *minimo(Nodo *);
		Nodo *maximo(Nodo *);
		Nodo *sucesor(Nodo *);
		Nodo *predecesor(Nodo *);
		void insertar(int);
		
		void eliminarNodo(int);
		void imprimirBonito();
		
};