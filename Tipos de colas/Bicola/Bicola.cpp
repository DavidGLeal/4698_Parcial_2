#include"Bicola.h"
//Constructor
Bicola::Bicola(){
	this->frente=NULL;
	this->final=NULL;
}
//Funcion para insertar al final de la bicola
void Bicola :: ponerFinal(int elemento)
{
	 Nodo* nuevo=new Nodo(); //Creamos un nuevo nodo
	 nuevo->setValor(elemento); //Asignamos el dato a nuestro nuevo nodo
	 //Verificamos si la bicola esta vacia
	 if (frente==NULL)
	 {
	 frente = nuevo;
	 }
	 else
	 {
	 //Insertamos el nuevo nodo al final	
	 final -> setSiguiente(nuevo);
	 }
	 final = nuevo;
	 cout<<"Elemento insertado.\n";
}


void Bicola :: ponerFrente(int elemento)
{
	 Nodo* nuevo=new Nodo();//Creamos un nuevo nodo
	 nuevo->setValor(elemento);//Asignamos el dato a nuestro nuevo nodo
	 //Verificamos si la bicola esta vacia
	 if (frente==NULL)
	 {
	 final = nuevo;
	 }
	 //Insertamos el nuevo nodo al inicio
	 nuevo->setSiguiente(frente);
	 frente = nuevo;
	 cout<<"Elemento insertado.\n";
}

int Bicola :: quitarFrente()
{
	//Verificamos si la bicola esta vacia
 	if (frente==NULL)
 	throw "Cola vacía, no se puede eliminar.\n";
 	//Creamos una variable auxiliar para almacenar nuestro valor a borrar
 	int aux = frente->getValor();
 	//Creamos un nodo auxiliar que almacenara nuestro frente actual
 	Nodo* a = frente;
 	//Asignamos el nuevo frente de la bicola
 	frente = frente->getSiguiente();
 	//Eliminamos el frente antiguo
	delete a;
 	return aux;; 
}

int Bicola :: quitarFinal()
{
	 int aux;
	 //Verificamos  si la cola esta vacia
	 if (frente!=NULL)
	 {
	 if (frente == final) // Bicola dispone de un solo nodo
	 {
	 //Llamamos a la  funcion quitarFrente
	  aux = quitarFrente();
	 }
	 else
	 {
	 //Creamos un nodo auxiliar que almacenara nuestro frente actual	
	 Nodo* a = frente;
	 //Nos desplazamos por la bicola hasta la posicion n-1
	 while (a->getSiguiente() != final)
	 a = a->getSiguiente();	 
	 //Almacenamos nuestro valor a borrar	 
	 aux = final->getValor();
	 //Asignamos nuestro nuevo final con el nodo que se encuentra en n-1
	 final = a;
	 //Eliminamos el nodo final 
	 delete a->getSiguiente();
	 }
	 }
	 else
	 cout<< "Bicola vacía\n";
 return aux;
}


void Bicola :: mostrarBicola()
{
	Nodo* nodo=frente;   
	cout<<"Elementos en cola\n"; 
	//Recorremos toda la bicola e imprimimos los valores
	while(nodo!=final){
		cout<<nodo->getValor()<<" ";
		nodo=nodo->getSiguiente();
	}  
	cout<<final->getValor();
}