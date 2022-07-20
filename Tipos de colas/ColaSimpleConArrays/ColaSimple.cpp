#include"ColaSimple.h"
using namespace std;
//Constructor
ColaSimple::ColaSimple(){
	this->cola=new int[100];//Crea el array de 100 elementos(el tamaño del array puede variar dependiendo la necesidad del programador)
	//Inicializamos primero y ultimo en -1
	this->primero=-1;
	this->ultimo=-1;
	//Inicializamos el tamaño del arreglo con el número de elementos máximos del array
	this->tamanio=100;
}
//Metodo insertar
void ColaSimple::insertar(int dato) {
   //Comprobamos si la cola esta llena			
   if (ultimo == tamanio-1)
   cout<<"Cola llena"<<endl;
   else {
   	//Inserta el dato en el final de la cola
      if (primero == - 1)
      primero = 0;
      ultimo++;//aumenta la posicion de ultimo en 1
      *(cola+ultimo) = dato;
   }
}
//Metodo eliminar
void ColaSimple::eliminar(){
  //Comprobamos si la cola esta vacia	
   if (primero == - 1 || primero > ultimo) {
      cout<<"Cola vacia ";
      return ;
   } else {
   	//Eliminamos el primer dato insertado en la cola	
      cout<<"El dato eliminado de la cola es: "<< *(cola+primero) <<endl;
      primero++;//Aumenta la posicion de primero en 1
   }
}
void ColaSimple::imprimir(){
	//Comprobamos si la cola esta vacia	
	if (primero == - 1)
    cout<<"Cola Vacia"<<endl;
    else {
      cout<<"Elementos en cola : ";
      //Imprime los elementos del primero al ultimo
      for (int i = primero; i <= ultimo; i++)
      	cout<<*(cola+i)<<" ";//Recorre los elementos de la cola desde primero hasta ultimo
        cout<<endl;
    }
}

