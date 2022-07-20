/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
*/

#include "lista.h"

Lista::Lista(){
	this->cabeza=NULL;
	this->actual=NULL;
}

Lista::~Lista(){

}

Nodo* Lista::getActual(){
	return this->actual;
} 

Nodo* Lista::getCabeza(){
	return this->cabeza;
} 

int Lista::getNumNodos() {
	return this->numNodos;
}

void Lista::setCabeza(Nodo* cabeza){
	this->cabeza =cabeza;
} 

void Lista::setActual(Nodo* actual){
	this->actual =actual;
} 

void Lista::setNumNodos(int numNodos){
	this->numNodos=numNodos;
}

bool Lista::ListaVacia(){
	return (this->cabeza==NULL);	
}

void Lista::agregarCabeza(int valor){
	Nodo *nuevoNodo= new Nodo(valor);
	Nodo *temp=this->cabeza;
	
	if(ListaVacia()){
		this->cabeza=nuevoNodo;
	}
	else{
		nuevoNodo->setSiguiente(cabeza);
		cabeza=nuevoNodo;
		
		while(temp){
			temp=temp->getSiguiente();
		}
	}
	numNodos++;
} 

void Lista::agregarCola(int valor){
	Nodo *nuevoNodo= new Nodo(valor);
	Nodo *temp=cabeza;
	
	if(ListaVacia()){
		this->cabeza=nuevoNodo;
	}
	else{
		while(temp->getSiguiente() !=NULL){
			temp=temp->getSiguiente() ;
		}
		temp->setSiguiente(nuevoNodo);
	}
	numNodos++;
} 


void Lista::imprimirLista() {

	if(ListaVacia()){
		cout<<"-- \n";
	}
	else{
		Nodo *temp=this->cabeza;
		while(temp){
			temp->imprimirNodo();
			if(temp->getSiguiente()) cout<<" => ";
				temp=temp->getSiguiente(); 			
		}
	}
	cout<<endl;
}


void Lista::borrarCola(){
	if(ListaVacia()){
		cout<<"\tLa lista esta vacia "<<endl;
	}
	else{
		Nodo *temp=this->cabeza;
		Nodo *ultimo= new Nodo();

		while(temp->getSiguiente() !=NULL){
			temp=temp->getSiguiente() ;	
		}		
			ultimo=temp;
			delete ultimo;
			temp=this->cabeza;

			while(temp->getSiguiente() !=ultimo){
			temp=temp->getSiguiente() ;	
			}
			temp->setSiguiente(NULL);
	numNodos--;
	cout<<"\n\t Eliminado correctamente\n";
	}
}

void Lista::borrarCabeza() {
	if(ListaVacia()){
		cout<<"\n\tNo hay elementos en la lista"<<endl;
	}else{
		Nodo *temp=cabeza->getSiguiente();
		delete cabeza;
		setCabeza(temp); 
		cout<<"\n\t Eliminado correctamente.\n";
	}
}

bool Lista::buscar(int valor){
	bool encontrado=false;
 	Nodo *temp = cabeza;
 	int aux=1;
 	int aux2=0;
	
 	while(temp){
		if(temp->getValor()==valor){
			encontrado = true;
			cout<<" => El valor se encuentra en la posicion: "<<aux<<endl;
 			aux2++;
 		}
 		temp=temp->getSiguiente();
 		aux++;
 	}
 	if(aux2==0){
 		cout<<" => Valor no encontrado "<<endl;
 	}
 	cout<<endl<<endl;
	return encontrado;
}

int Lista::buscarPosicion(int valor){
 	Nodo *temp = cabeza;
 	int aux=1;

	
 	while(temp){
		if(temp->getValor()==valor){
			break;
		}
 		temp=temp->getSiguiente();
 		aux++;
 	}
	return aux;
}

void Lista::borrarEnPosicion(int _valor){
	int pos=buscarPosicion(_valor);
	Nodo *tempsig=cabeza;
	Nodo *tempNodo=cabeza;	
	
	if(ListaVacia()){
		cout<<"\tLa lista esta vacia"<<endl;
	}
	else{	

		if (pos==1){
			this->borrarCabeza();
		}
		else if (pos>numNodos+1)
		{
			cout<<"\tLa posicion excede el numero de nodos "<<endl;
		}
		else if (pos==numNodos)
		{
			this->borrarCola();
		}

		else{
			for (int i = 1; i < pos; i++)
			{
				tempsig=tempsig->getSiguiente(); //se almacena la posición siguiente en temp
			}
			tempNodo=tempsig;
			tempsig=tempsig->getSiguiente();
			
			delete tempNodo;
			cout<<"Nodo: "<<pos<<" eliminado correctamente.\n";	 			
		}		
	} 	
}
