#include "Cola.h"

Cola::Cola(){
    this->cabeza=NULL;
	this->cola=NULL;
}

Nodo* Cola::getCabeza(){
	return this->cabeza;
} 

Nodo* Cola::getCola(){
    Nodo *temp=cabeza;
    while(temp->getSiguiente() !=NULL){
			temp=temp->getSiguiente() ;
		}
		
	return temp;
} 

void Cola::setCabeza(Nodo* cabeza){
	this->cabeza =cabeza;
} 

void Cola::setCola(Nodo* cola){
	this->cola =cola;
} 

bool Cola::colaVacia(){
    return(this->cabeza==NULL);
}


void Cola::push(int _dato){//ingresan por cola
    Nodo *nuevoNodo= new Nodo(_dato);
    Nodo *temp=cola;

    if(colaVacia()){
        this->cabeza= nuevoNodo;
    }
    else{
        getCola()->setSiguiente(nuevoNodo);
	}
}

void Cola::pop(){//salen por cabeza
    Nodo *temp=this->cabeza;

    if(cabeza == cola){
        cabeza = NULL;
        cola = NULL;
    }
    else{
        Nodo *temp=cabeza->getSiguiente();
		delete cabeza;
		setCabeza(temp); 
		cout<<"\nNodo eliminado correctamente";

    }

}

void Cola::mostrarCola() {

	if(colaVacia()){
		cout<<"\tLa lista esta vacia "<<endl;
	}
	else{
		Nodo *temp=this->getCola();
		Nodo *ultimo= new Nodo();
		cout<<endl<<endl;

			while (temp!=this->cabeza)
			{
				ultimo=temp;
				cout<<"|\t"<<temp->getDato()<<"\t|";
				cout<<"\n-----------------\n";
				temp=this->cabeza;
				while(temp->getSiguiente() !=ultimo){
				temp=temp->getSiguiente();	
				}
			}
			cout<<"|\t"<<temp->getDato()<<"\t|";
				cout<<"\n-----------------\n";
	}
	cout<<endl<<endl;
}

int Cola::obtenerMayor(){
	int mayor=0;
	int pos=1;
	int encontrado=0;
	if(colaVacia()){
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

