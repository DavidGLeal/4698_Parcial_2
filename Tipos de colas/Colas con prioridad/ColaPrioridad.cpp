#include"ColaPrioridad.h"
//Constructor
ColaPrioridad::ColaPrioridad(){
	this->primero=NULL;
	this->ultimo=NULL;
}
//Funcion insertar
void ColaPrioridad::insertar(int dato,int prioridad){

     /* Encolamos el dato */
     encolar( dato,prioridad );
     
     /* Ordenamos por prioridad */
     ordenarPrioridad(); 	
}

//Funcion para ordenar los elementos por prioridad
void ColaPrioridad::ordenarPrioridad(){
     Nodo *aux1, *aux2;//Creacion de dos nodos auxiliares
     int priori;
     int dat;   
     aux1 = primero;//Asignamos a nuestro auxiliar el valor de primero
     //Ordenacion por el metodo burbuja
     while( aux1->getSiguiente() != NULL)
     {
            aux2 = aux1->getSiguiente();
            
            while( aux2 != NULL)
            {
                   if( aux1->getPrioridad() > aux2->getPrioridad() )
                   {
                       priori = aux1->getPrioridad();
                       dat = aux1->getValor();
                       
                       aux1->setPrioridad(aux2->getPrioridad()) ;
                       aux1->setValor(aux2->getValor());
                       
                       aux2->setPrioridad(priori) ;
                       aux2->setValor(dat);
                   }
                   
                   aux2 = aux2->getSiguiente();
            }
            
            aux1 = aux1->getSiguiente();
     }	
}
//Funcion encolar
void ColaPrioridad::encolar(int dato,int prioridad){
	//Creacion de un nuevo nodo con los datos recibidos
	 Nodo *aux = new Nodo(dato, prioridad);
    //Comprobamos si la cola esta vacia	
     if( primero == NULL)
         primero = aux;   // encola el primero elemento
     else
     	 //Asignamos nuestro nuevo nodo al nodo siguiente de nuestro ultimo nodo actual
         ultimo->setSiguiente(aux);
	 //Insertamos nuestro nuevo nodo al ultimo de la cola
     ultimo = aux;        // puntero que siempre apunta al ultimo elemento 	
}
//Funcion eliminar
int ColaPrioridad::eliminar(){
	if (primero==NULL)
 	throw "Cola vacía, no se puede eliminar.\n";
 	//Creamos una variable auxiliar para almacenar nuestro valor a borrar
 	int aux = primero->getValor();
 	//Creamos un nodo auxiliar que almacenara nuestro pimero actual
 	Nodo* a = primero;
 	//Asignamos el nuevo primero de la cola
 	primero = primero->getSiguiente();
 	//Eliminamos el primero antiguo
	delete a;
 	return aux;; 	
}
//Funcion mostrar elementos de la cola
void ColaPrioridad::mostrar(){
	 //Creamos un nodo auxiliar
     Nodo *aux;
     //Asignamos nuestro nuevo nodo el valor del primero
     aux = primero;
     //Imprimimos un encabezado para que se entienda la impresion de la cola
     cout << "   Dato  Prioridad " << endl;
     cout << " ------------------- " << endl;
     //Recorremos la cola desde el inicio e imprimimos sus datos y prioridad     
     while( aux != NULL )
     {
            cout<<"    "<< aux->getValor() << "     |   " << aux->getPrioridad() << endl;
            aux = aux->getSiguiente();
     }   	
}