#include"ColaCircular.h"
using namespace std;
//Constructor
ColaCircular::ColaCircular(){
	this->colaC=new int[5];//Crea el array de 5 elementos(el tamaño del array puede variar dependiendo la necesidad del programador)
	//Inicializamos primero y ultimo en -1
	this->inicio=-1;
	this->ultimo=-1;
	//Inicializamos el tamaño del arreglo con el número de elementos máximos del array
	this->tamanio=5;
}
//Metodo insertar
void ColaCircular::insertar(int dato) {
   //Comprobamos si la cola esta llena			
   if ((inicio == 0 && ultimo == tamanio-1) || (inicio == ultimo+1)) {
      cout<<"Cola llena \n";
      return;
   }
   //Si nuestro marcador inicio es -1 asignamos a inicio y ultimo 0
   if (inicio == -1) {
      inicio = 0;
      ultimo = 0;
   } else {
      if (ultimo == tamanio - 1)
      ultimo = 0;
      else
      ultimo++;//Incrementamos ultimo en 1
   }
   *(colaC+ultimo) = dato ;
}
//Metodo eliminar
void ColaCircular::eliminar(){
  //Comprobamos si la cola esta vacia	
   if (inicio == -1) {
      cout<<"Cola vacia\n";
      return ;
   }
   cout<<"Elemento eliminado de la cola : "<<*(colaC+inicio)<<endl;
	//Si nuestros marcadores son iguales les asignamos el valor de -1
   if (inicio == ultimo) {
      inicio = -1;
      ultimo = -1;
   } else {
      if (inicio == tamanio - 1)
      inicio = 0;
      else
      inicio++;//Incrementamos ultimo en 1
   }
}
void ColaCircular::imprimir(){
   //Creamos variables auxiliares para recorrer la cola
   int f = inicio, r = ultimo;
   //Comprobamos si la cola esta vacia	
   if (inicio == -1) {
      cout<<"Cola vacia"<<endl;
      return;
   }
   cout<<"Elementos en cola :\n";
   //Cuando inicio sea menor o igual ultimo imprimimos el valor de la posicion inicio
   if (f <= r) {
      while (f <= r){
         cout<<*(colaC+f)<<" ";
         f++;//incrementamos nuestra vaiable auxiliar f en 1
      }
   } else {
   	  //Recorremos toda la cola	
      while (f <= tamanio - 1) {
         cout<<*(colaC+f)<<" ";
         f++;
      }
      f = 0;//Asignamos 0 a f
      while (f <= r) {
         cout<<*(colaC+f)<<" ";
         f++;
      }
   }
   cout<<endl;
}