/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 11
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
*/
#include "ListaStr.h"

ListaStr::ListaStr(){
	this->cabeza=NULL;
	this->actual=NULL;
}

ListaStr::~ListaStr(){

}

NodoStr* ListaStr::getActual(){
	return this->actual;
} 

NodoStr* ListaStr::getCabeza(){
	return this->cabeza;
} 

int ListaStr::getNumNodos() {
	return this->numNodos;
}

void ListaStr::setCabeza(NodoStr* cabeza){
	this->cabeza =cabeza;
} 

void ListaStr::setActual(NodoStr* actual){
	this->actual =actual;
} 

void ListaStr::setNumNodos(int numNodos){
	this->numNodos=numNodos;
}

bool ListaStr::ListaVacia(){
	return (this->cabeza==NULL);	
}

void ListaStr::agregarCabeza(string valor){
	NodoStr *nuevoNodo= new NodoStr(valor);
	NodoStr *temp=this->cabeza;
	
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

void ListaStr::agregarCola(string valor){
	NodoStr *nuevoNodo= new NodoStr(valor);
	NodoStr *temp=cabeza;
	
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


void ListaStr::imprimirLista() {

	if(ListaVacia()){
		cout<<"-- \n\t";
	}
	else{
		NodoStr *temp=this->cabeza;
		while(temp){
			temp->imprimirNodo();
			if(temp->getSiguiente()) cout<<" => ";
				temp=temp->getSiguiente(); 			
		}
	}
	cout<<endl;
}


void ListaStr::borrarCola(){
	if(ListaVacia()){
		cout<<"\tLa lista esta vacia "<<endl;
	}
	else{
		NodoStr *temp=this->cabeza;
		NodoStr *ultimo= new NodoStr();

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
	cout<<"\n\tEliminado correctamente\n";
	}
}

void ListaStr::borrarCabeza() {
	if(ListaVacia()){
		cout<<"\n\tNo hay elementos en la lista"<<endl;
	}else{
		NodoStr *temp=cabeza->getSiguiente();
		delete cabeza;
		setCabeza(temp); 
		cout<<"\n\tEliminado correctamente.\n";
	}
}

bool ListaStr::buscar(string valor){
	bool encontrado=false;
 	NodoStr *temp = cabeza;
 	int aux=1;
 	int aux2=0;
	
 	while(temp){
		if(strcmp(temp->getValor().c_str(),valor.c_str())==0){
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

int ListaStr::buscarPosicion(string valor){
 	NodoStr *temp = cabeza;
 	int aux=1;

	
 	while(temp){
		if(strcmp(temp->getValor().c_str(),valor.c_str())==0){
			break;
		}
 		temp=temp->getSiguiente();
 		aux++;
 	}
	return aux;
}

void ListaStr::borrarEnPosicion(string _valor){
	int pos=buscarPosicion(_valor);
	NodoStr *tempsig=cabeza;
	NodoStr *tempNodo=cabeza;	
	
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
