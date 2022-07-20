/*UFA-ESPE
* Deber 6
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 01/06/2022
* Fecha de modificación 02/06/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "ListaDoble.h"
#include "Nodo.cpp"

ListaDoble::ListaDoble(){
	this->primero=NULL;
	this->actual=NULL;
}
//Ingreso por cabeza
void ListaDoble::insertarCabeza(int _valor){
	Nodo *nuevo=new Nodo(_valor);
	nuevo->setPrevio(NULL);
		if(ListaVacia()){
			nuevo->setSiguiente(NULL);
			this->primero=nuevo;
			this->actual = nuevo;
		}
		else{
			nuevo->setSiguiente(primero);
			primero->setPrevio(nuevo);
        	this->primero = nuevo;
		}				
}
//Ingreso por cola
void ListaDoble::insertarCola(int _valor){
	Nodo *nuevo=new Nodo(_valor);
	nuevo->setSiguiente(NULL);
			if(ListaVacia()){
				nuevo->setPrevio(NULL);
				this->primero=nuevo;
				this->actual = nuevo;
			}
			else{
				this->actual->setSiguiente(nuevo);
				nuevo->setPrevio(actual);
			}
			this->actual=nuevo;
}

//Insertar entre
void ListaDoble::insertarEntre( )
{
	this->mostrarCabeza(0);
	/* Crear un nodo nuevo */
	int index,valor,count=1;
	//nuevo = (ListaDoble)malloc(sizeof(Nodo));
	Nodo *tmp2 = primero;
	cout<<"	Indice	"<<"	Valor \n";
	while(tmp2){
				cout<<"	"<<count<<"	"<<"	"<<tmp2->getValor()<<"\n";
				tmp2=tmp2->getSiguiente();
				count++;
			}
	cout<< "\nIngrese indice"<<endl;
	index = this->ingresoDatosEnteros();

	cout<< "\nIngrese el valor a insertar"<<endl;
	valor = this->ingresoDatosEnteros();

	Nodo *nuevo = new Nodo(valor);
	Nodo *tmp =primero;
	if(index>sizeLista()){
		cout<<"Ingrese un indice valido"<<endl;
	}
	else{
		for(int i=1;i<index;i++){
			tmp = tmp->getSiguiente();
		}
		nuevo->setSiguiente(tmp->getSiguiente());
		tmp->getSiguiente()->setPrevio(nuevo);
		tmp->setSiguiente(nuevo);
		nuevo->setPrevio(tmp);
	}
}
//Eliminar entre
void ListaDoble::eliminarEntre( ){
this->mostrarCabeza(0);		
	/* Crear un nodo nuevo */
	int index,count =0;
		Nodo *tmp2 = primero;
	cout<<"	Indice	"<<"	Valor \n";
	while(tmp2){
				cout<<"	"<<count<<"	"<<"	"<<tmp2->getValor()<<"\n";
				tmp2=tmp2->getSiguiente();
				count++;
			}
	//nuevo = (ListaDoble)malloc(sizeof(Nodo));
	cout<< "\nIngrese indice"<<endl;
	index = this->ingresoDatosEnteros();
	Nodo *tmp = primero;
	if(index>sizeLista()){
		cout<<"Ingrese un indice valido"<<endl;
	}
	else{
		for(int i=1;i<index;i++){
			tmp = tmp->getSiguiente();
		}
		tmp->getSiguiente()->setPrevio(tmp->getPrevio());
		tmp->getPrevio()->setSiguiente(tmp->getSiguiente());
		tmp->setSiguiente(NULL);
		tmp->setPrevio(NULL);
		delete tmp;
	}
}

// Impresion principio a fin
void ListaDoble::mostrarCabeza(int orden){
	if (this->ListaVacia()){
		cout<<"La lista esta vacia"<<endl;
	}
	else{
		Nodo *tmp=this->primero;
		if(orden ==0){ //0 cabeza
			while(tmp){
				cout<<tmp->getValor()<<"-->";
				tmp=tmp->getSiguiente();
			}
			cout<<"NULL\n";
		}
		else{ //1 cola
			while(tmp->getSiguiente()){
				tmp = tmp->getSiguiente();
			}
			cout<<"NULL";
			while(tmp){
				cout<<tmp->getValor()<<"<--";
				tmp=tmp->getPrevio();
			}
		}
	}	
}	
//Busqueda	
void ListaDoble::buscar(){
    int valor_b,count=0;
	bool ext =false;
	if(this->ListaVacia()){
		cout<<"La lista esta vacia, no se puede buscar"<<endl;
	}
	else{
	valor_b = this->ingresoDatosEnteros();
	Nodo* num = new Nodo(valor_b);
	Nodo* tmp = primero;	
    while (tmp->getSiguiente()){
		if (tmp->getValor() == num->getValor()){
            cout << "El numero esta en la posicion: "<<count+1<<endl;
			ext  = true;
            break;
        }
		tmp = tmp->getSiguiente();
		count++;
	}
	if (ext == false){
		cout<<"El numero no esta en la lista: "<<endl;
	}
}
}

//Eliminar por la cabeza
void ListaDoble::eliminarCabeza()
{
    Nodo* aux;
    int eliminar=0;
    
    if(ListaVacia()){
        cout<<" La lista esta vacia, por lo tanto no se puede realizar esta accion" << endl;
    }
    else{
		cout<<"Digite el numero de valores a suprimir por Cabeza"<<endl;
        cout <<" Recuerde que su lista contiene " <<sizeLista()<<" elementos  "<<endl;
    	//validar que ingrese solo números 
    	eliminar=ingresoDatosEnteros();
		if(eliminar<=sizeLista()){
			if(eliminar==sizeLista()){
				primero= nullptr;
                cout<< "\n Lista eliminada con exito \n";
			}
			else{
	        	for (int i=0; i<eliminar;i++){
	            aux= this-> primero;
	            this-> primero = this-> primero-> getSiguiente();
				this-> primero->setPrevio(NULL);
	            aux -> setSiguiente(NULL);
	            delete aux;
        		}
                cout<< "\n Elementos eliminados con exito \n";
			}
		}
		else{
			cout<< "No se puede eliminar "<< eliminar <<" elementos de "<<sizeLista()<<endl;
		}
    }
}	

//Eliminar por la cola
void ListaDoble::eliminarCola(){
    Nodo* aux = new Nodo();
    Nodo* tmp = new Nodo();
    cout<<this->actual->getValor()<<endl;
    int eliminar=0;
    
    if(ListaVacia()){
        cout<<" La lista esta vacia, por lo tanto no se puede realizar esta accion" << endl;
    }
    else{
		cout<<"Digite el numero de valores a suprimir por Cabeza"<<endl;
        cout <<" Recuerde que su lista contiene " <<sizeLista()<<" elementos  "<<endl;
    	//validar que ingrese solo números 
    	eliminar=ingresoDatosEnteros();
    	aux = this->primero;
		//Nodo* tmp = aux;
		if(eliminar<=sizeLista()){
			while(aux->getSiguiente()){
			tmp = aux;
			aux= aux->getSiguiente();
			}
			if(eliminar==sizeLista()){
				primero= nullptr;
                cout<< "\n Lista eliminada con exito \n";
			}
			else{
			for (int i=0; i<eliminar;i++){	
				aux->setPrevio(NULL);
	           	tmp->setSiguiente(NULL);
	            delete aux;
	            aux = tmp;
	            tmp = tmp->getPrevio();
        		}  
                cout<< "\n Elementos eliminados con exito \n";
			}
		}
		else{
			cout<< "No se puede eliminar "<< eliminar <<" elementos de "<<sizeLista()<<endl;
		}
    }
}
		
//obtener el tamaño de la Lista
int ListaDoble:: sizeLista()
{
    Nodo* aux = this-> primero;
        int c = 0;
        while (aux != nullptr){
            c++;
            aux = aux->getSiguiente();
        }
        return c;
    
}
int ListaDoble::ingresoDatosEnteros(){	
	char *dato=new char[10],c;
	int i=0;
	printf("Ingrese su valor: ");
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
    cout<<"\n ";
	return atoi(dato); 
}

void ListaDoble::insertarColaEnteros(){
		char c;
		while(c!=47){
		int i=0;
		char *dato=new char[10],C;
		printf("Ingrese un valor o '/' detener: ");
		while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
		else if(c==47){
			printf("/",c);
			return;
		}
	}
	dato[i]='\0';
	this->insertarCola(atoi(dato)); 
	cout<<"\n";	
	}
}
	
void ListaDoble::insertarCabezaEnteros(){
	char c;
	while(c!=47){
		int i=0;
		char *dato=new char[10];
		printf("Ingrese un valor o '/' detener: ");
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
		else if(c==47){
			printf("/",c);
			return;
		}
	}
	dato[i]='\0';
	this->insertarCabeza(atoi(dato)); 
	cout<<"\n";	
	
	} 
	
}
	ListaDoble::~ListaDoble() {	
		while(primero){
			delete primero;
			primero = primero->getSiguiente();
		}
	}

