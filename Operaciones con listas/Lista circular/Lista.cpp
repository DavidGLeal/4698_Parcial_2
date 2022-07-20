/*UFA-ESPE
* Deber 5
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 25/05/2022
* Fecha de modificación 30/05/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Lista.h"
#include "Nodo.cpp"
Lista::Lista(){
	this->primero=NULL;
	this->actual=NULL;
}

//Ingreso por cola
void Lista::insertar(int _valor){

	Nodo *nuevo=new Nodo(_valor);
    if(ListaVacia()){
        this->primero=nuevo;
    }
    else{
        this->actual->setSiguiente(nuevo); 
    }
    this->actual = nuevo;
    actual->setSiguiente(primero);
}


// Impresion principio a fin
void Lista::mostrar(){
    if (this->ListaVacia()){
        cout<<"La lista esta vacia"<<endl;}
    else{
	    Nodo *tmp=this->primero;
		do{
			cout<<tmp->getValor()<<"-->";
			tmp=tmp->getSiguiente();
		}while(tmp != primero);
		cout<<tmp->getValor()<<"-->Inicio";		
    }		
}	

//Busqueda	
void Lista::buscar(){
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
void Lista::eliminar()
{
    Nodo* aux;
    int eliminar=0;
    bool ext = false;
    if(ListaVacia())
    {
        cout<<" La lista esta vacia, por lo tanto no se puede realizar esta accion" << endl;
    }
    else
    {
		cout<<"Digite el numero que desea eliminar"<<endl;
    	eliminar=ingresoDatosEnteros();
		
        Nodo* aux = new Nodo(eliminar);
        Nodo* tmp = this->primero; 
		do{
            if(tmp->getSiguiente()->getValor() == aux->getValor()){
                tmp->setSiguiente(tmp->getSiguiente()->getSiguiente());
                cout<<"Se ha eliminado el valor ingresado;";
                ext = true;
                break;
            }
        tmp = tmp->getSiguiente();        
        }while( tmp != primero);
        }
        if (ext == false){
            cout<<"El numero no esta en la lista: "<<endl;
        }   
    }
			

int Lista::ingresoDatosEnteros(){	
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

void Lista::insertarColaEnteros(){
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
	this->insertar(atoi(dato)); 
	cout<<"\n";	
	
	}
	 
}
	
