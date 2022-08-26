#include "ArbolJuego.h"

//Contructor vacio
ArbolJuego::ArbolJuego(){
	this->raiz=NULL;
}

Nodo *ArbolJuego::getRaiz(){
	return this->raiz;
}

void ArbolJuego::setRaiz(Nodo *_raiz){
	this->raiz=_raiz;
}

void ArbolJuego::preOrdenA(Nodo *nodo){
	if(nodo != NULL){
		cout<<nodo->getValor()<<" ";
		preOrdenA(nodo->getIzquierda());
		preOrdenA(nodo->getDerecha());
	}
}

void ArbolJuego::inOrdenA(Nodo *nodo){
	if(nodo != NULL){
		inOrdenA(nodo->getIzquierda());
		cout<<nodo->getValor()<<" ";
		inOrdenA(nodo->getDerecha());
	}
}

void ArbolJuego::postOrdenA(Nodo *nodo){
	if(nodo != NULL){
		postOrdenA(nodo->getIzquierda());
		postOrdenA(nodo->getDerecha());
		cout<<nodo->getValor()<<" ";
	}
}

Nodo *ArbolJuego::buscarArbolAyuda(Nodo *nodo,int clave){
	if(nodo == NULL){	 
   	cout<<"No se encuentran datos en el arbol\n";
	}
	if(nodo == NULL || clave == nodo->getValor()){
		return nodo;
	}
	if (clave < nodo->getValor()){
		return buscarArbolAyuda(nodo->getIzquierda(),clave);		
	}
	return buscarArbolAyuda(nodo->getDerecha(),clave);
}

void ArbolJuego::eliminarNodoAyuda(Nodo *nodo, int clave){
	Nodo *x= NULL;
	Nodo *t,*s;
	while( nodo != NULL){
		if(nodo->getValor() == clave){
			x=nodo;
		}
		if(nodo->getValor() <= clave){
			nodo=nodo->getDerecha();
		}else{
			nodo=nodo->getIzquierda();
		}
	}
	if(x == NULL){
		cout<<"No se pudo encontrar la clave en el arbol"<<endl;
		return;
	}
	separar(x,s,t); //Separar en el arbol 
	if(s->getIzquierda()){
		s->getIzquierda()->getPadre()=NULL;
	}
	//CREO QUE VA A HABER ERROR AQUI
	raiz=unir(s->getIzquierda(),t);
	delete(s);
	s=NULL;	
}

void ArbolJuego::imprimirAyuda(Nodo* raiz, string ind, bool ultimo){
	if(raiz != NULL){
		cout<<ind;
		if(ultimo){
			cout<<"+----";
		    ind += "     ";	
		}else {
			cout<<"+----";
		    ind += "|    ";
			
		}
		cout<<raiz->getValor()<<endl;
		imprimirAyuda(raiz->getIzquierda(),ind,false);
		imprimirAyuda(raiz->getDerecha(),ind,true);
	}
}

//Rotar el nodo x a la izquierda
void ArbolJuego::RotarIzquierda(Nodo *x){
	Nodo *y=x->getDerecha();
	//x->getDerecha() = y->getIzquierda();
	x->setDerecha(y->getIzquierda());
	if(y->getIzquierda() != NULL){
		y->getIzquierda()->getPadre()=x;
	}
	//y->getPadre() = x->getPadre();
	y->setPadre(x->getPadre());
	if(x->getPadre() == NULL){
		this->raiz=y;
	}else if(x == x->getPadre()->getIzquierda()){
		x->getPadre()->getIzquierda()=y;		
	}else{
		x->getPadre()->getDerecha()=y;		
	}
	y->getIzquierda()=x;
	x->getPadre()=y;
}

//Rotar el nodo x a la derecha
void ArbolJuego::RotarDerecha(Nodo *x){
	Nodo *y=x->getIzquierda();
	x->setIzquierda(y->getDerecha());
	//x->getIzquierda() = y->getDerecha();
	if(y->getDerecha() != NULL){
		y->getDerecha()->getPadre()=x;
	}
	y->setPadre(x->getPadre());
	//y->getPadre()=x->getDerecha();
	if(x->getPadre() == NULL){
		this->raiz=y;
	}else if(x== x->getPadre()->getDerecha()){
		x->getPadre()->getDerecha()=y;
	}else {
		x->getPadre()->getIzquierda()=y;
	}
	y->getDerecha()=x;
	x->getPadre()=y;
}

//Splaying
void ArbolJuego::juego(Nodo *x){
	while(x->getPadre()){
		if(!x->getPadre()->getPadre()){
			if(x==x->getPadre()->getIzquierda()){
				//Rotacion ZIG 
				RotarDerecha(x->getPadre());
			}else{
				//Rotacion ZAG 
				RotarIzquierda(x->getPadre());
			}
		}else if(x == x->getPadre()->getIzquierda() && x->getPadre() == x->getPadre()->getPadre()->getIzquierda()){
			//ROTACION ZIG-ZIG
			RotarDerecha(x->getPadre()->getPadre());
			RotarDerecha(x->getPadre());			
		}else if(x==x->getPadre()->getDerecha() && x->getPadre() == x->getPadre()->getPadre()->getDerecha()){
			//ROTACION ZAG-ZAG
			RotarIzquierda(x->getPadre()->getPadre());
			RotarIzquierda(x->getPadre());
		}else if( x == x->getPadre()->getDerecha() && x->getPadre() == x->getPadre()->getPadre()->getIzquierda()) {
			//ROTACION ZIG-ZAG
			RotarIzquierda(x->getPadre());
			RotarDerecha(x->getPadre());			
		}else{
			//ROTACION ZAG-ZIG
			RotarDerecha(x->getPadre());
			RotarIzquierda(x->getPadre());
		}		
	}

}

// une dos arboles s y t
Nodo *ArbolJuego::unir(Nodo *s, Nodo *t){
	if(!s){
		return t;
	}
	if(!t){
		return s;
	}
	Nodo *x= maximo(s);
	juego(x);
	x->getDerecha()=t;
	t->getPadre()=x;
	return x;
}

// divide el arbol en s y t
void ArbolJuego::separar(Nodo *&x,Nodo *&s,Nodo *&t){
	juego(x);
	if(x->getDerecha()){
		t=x->getDerecha();
		t->getPadre()=NULL;
	}else{
		t=NULL;
	}
	s=x;
	s->getDerecha()=NULL;
	x=NULL;
}

// Recorrido pre-orden
// Nodo-> Izquierda-> Derecha
void ArbolJuego::preorden(){
	preOrdenA(this->raiz);
}

//Recorrido In-Orden
//Izquierda-> Nodo-> Derecha
void ArbolJuego::inorden(){
	inOrdenA(this->raiz);
}

//Recorrido Post-Orden
//Izquierda->Derecha->Nodo
void ArbolJuego::postorden(){
	postOrdenA(this->raiz);
}

// busca en el arbol la clave k
// y devolver el nodo correspondiente
Nodo *ArbolJuego::buscarArbol(int k){

	Nodo *x=buscarArbolAyuda(this->raiz,k);
	if(x){
		juego(x);
	}
	return x;
}

//Busca el nodo con la minima clave
Nodo *ArbolJuego::minimo(Nodo* nodo){
	while(nodo->getIzquierda() != NULL){
		nodo=nodo->getIzquierda();
	}
	return nodo;
}

//Busca el nodo con la maxima clave
Nodo *ArbolJuego::maximo(Nodo* nodo){
	while(nodo->getDerecha() != NULL){
		nodo=nodo->getDerecha();
	}
	return nodo;
}

//Busca el sucesor del nodo dado
Nodo *ArbolJuego::sucesor(Nodo* x){
	// si el subarbol derecho no es nulo,
	// el sucesor es el nodo mas a la izquierda en el
	// subarbol derecho
	if(x->getDerecha() != NULL){
		return minimo(x->getDerecha());
	}
	
	// de lo contrario, es el ancestro mas bajo de x cuyo
	// el hijo izquierdo tambien es un ancestro de x.
	Nodo *y= x->getPadre();
	while(y != NULL && x== y->getDerecha()){
		x=y;
		y=y->getPadre();
	}
	return y;
}

//Buscar Predecesor del nodo dado
Nodo *ArbolJuego::predecesor(Nodo* x){
	// si el subarbol izquierdo no es nulo,
	// el predecesor es el nodo mas a la derecha en el
	// subarbol izquierdo
	if(x->getIzquierda() != NULL){
		return maximo(x->getIzquierda());		
	}
	
	Nodo *y=x->getPadre();
	while (y != nullptr && x == y->getIzquierda()) {
			x = y;
			y = y->getPadre();
	}
	return y;
}

//Insertar clave en el arbol en la posicion mas apropiada
void ArbolJuego::insertar(int clave){
	//Normal insertar BST
	Nodo *nodo= new Nodo;
	nodo->getPadre()=NULL;
	nodo->getIzquierda()=NULL;
	nodo->getDerecha()=NULL;
	nodo->setValor(clave);
	Nodo *y= NULL;
	Nodo *x=this->raiz;
	
	while (x != nullptr) {
		y = x;
		if (nodo->getValor() < x->getValor()) {
			x = x->getIzquierda();
		} else {
			x = x->getDerecha();
		}
	
	}
	
	//y es padre de x
	nodo->getPadre()=y;
	if(y==NULL){
		raiz=nodo;
	}else if(nodo->getValor() < y->getValor()){
		y->getIzquierda()=nodo;
	}else{
		y->getDerecha()=nodo;
	}
	
	//Splay del nodo
	juego(nodo);
	cout<<"Insertado Correctamente"<<endl;
}

//Eliminar el nodo del arbol
void ArbolJuego::eliminarNodo(int dato){
	eliminarNodoAyuda(this->raiz,dato);
}

//Imprimir la estructura del arbol
void ArbolJuego::imprimirBonito(){
	imprimirAyuda(this->raiz,"",true);
}