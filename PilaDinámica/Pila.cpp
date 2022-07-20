#include"Pila.h"
#include "Nodo.h"


/**
 * Pila::Pila() {
 * 	this->cabeza=NULL;
 * }
 */
Pila::Pila() {
	this->cabeza=NULL;
}

/**
 * Comprueba si la pila está vacía.
 * 
 * @return a boolean value.
 */
bool Pila::PilaVacia(){
	return (this->cabeza==NULL);	
}

/**
 * Devuelve la cabeza de la pila.
 * 
 * @return The head of the stack.
 */
Nodo* Pila::getCabeza(){
	return this->cabeza;
}


/**
 * 
 * 
 * @param cabeza Nodo*
 */
void Pila::setCabeza(Nodo* cabeza){
	this->cabeza =cabeza;
} 

/**
 * Añade un nuevo nodo a la parte superior de la pila.
 * 
 * @param valor El valor a insertar en la pila.
 */
void Pila::push(int valor){
	Nodo *nuevoNodo= new Nodo(valor);
	Nodo *temp=this->cabeza;
	
	if(PilaVacia ()){
		this->cabeza=nuevoNodo;
		cout<<"\n\tDato "<<valor<<" insertado correctamente\n";
	}
	else{
		nuevoNodo->setSiguiente(cabeza);
		cabeza=nuevoNodo;
		
		while(temp){
			temp=temp->getSiguiente();
		}
		cout<<"\n\tDato "<<valor<<" insertado correctamente\n";
	}
} 

/**
 * Elimina el primer elemento de la pila.
 */
void Pila::pop() {
	if(PilaVacia ()){
		cout<<"\n\tNo hay elementos en la pila\n"<<endl;
	}else{
		Nodo *temp=cabeza->getSiguiente();
		delete cabeza;
		setCabeza(temp); 
		cout<<"\n\tDato eliminado correctamente\n";
	}
}

/**
 * Si la pila está vacía, imprime un mensaje indicándolo. En caso contrario, imprime la pila.
 */
void Pila::mostrarPila() {

	if(PilaVacia()){
		cout<<"\tLa pila esta vacia\n"<<endl;
	}
	else{
		Nodo *temp=this->cabeza;
		while(temp){
			cout<<"\t|\t"<<temp->getDato()<<"\t|";
			cout<<"\n\t-----------------\n";
			if(!temp->getSiguiente());
				temp=temp->getSiguiente(); 			
		}
	}
	cout<<endl<<endl;
}

/**
 * Es una función que devuelve el mayor número de la pila
 * 
 * @return the value of the largest number in the stack.
 */
int Pila::obtenerMayor(){
	int mayor=0;
	int pos=1;
	int encontrado=0;
	if(PilaVacia()){
		cout<<"\tLa pila esta vacia\n"<<endl;
	}
	else{
		Nodo *temp=this->cabeza;
		mayor=temp->getDato();
		while(temp){
		
			if(temp->getDato() > mayor){
				mayor=temp->getDato();
				encontrado=pos;
				
			}
			temp=temp->getSiguiente(); 	
			pos ++;	
		}
	}
	cout<<"\tSe ha encontrado el numero mayor: "<<mayor<<" En la posicion: "<<encontrado<<endl;
	return mayor;
}
