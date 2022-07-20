#include <iostream>
#include "ColaCircular.cpp"
using namespace std;

int main() {
   int op,dato;
   //Creamos el objeto dela clase ColaCircular
   ColaCircular cola;
   cout<<"1) Insertar elemento a la cola"<<endl;
   cout<<"2) Eliminar elemento de la cola"<<endl;
   cout<<"3) Imprimir todos los elementos en cola"<<endl;
   cout<<"4) Salir"<<endl;
   do {
      cout<<"Digite una opcion : "<<endl;
      cin>>op;
      switch (op) {
         case 1: 
         	cout<<"Digite el dato a insertar : "<<endl;
      		cin>>dato;
		 	cola.insertar(dato); //Llamamos a la funcion insertar       	
         break;
         case 2: 
         	cola.eliminar(); //Llamamos a la funcion eliminar  
         break;
         case 3: 
         	cola.imprimir(); //Llamamos a la funcion imprimir  
         break;
         case 4: cout<<"Salio con exito"<<endl;
         break;
         default: cout<<"Opcion invalida"<<endl;
      }
   } while(op!=4);
   return 0;
}