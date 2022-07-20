#include "Pila.h"

void Pila::crearPila(){
    this->pila=new int[10];
    this->ultimo=-1;
}

bool Pila::pilaVacia(){
    return(ultimo==-1);
}

void Pila::push(int _dato){
    
    pila[getUltimo()+1]=_dato;
    cout<<"\tDato "<<_dato<<" ingresado correctamente"<<endl;
    ultimo++;
   
}

void Pila::pop(){
    if(pilaVacia()){
        cout<<"\n\tLa pila esta vacia"<<endl;
    }
    else{

    pila[getUltimo()]=0;
    cout<<"\n\tDato eliminado correctamente"<<endl;
    ultimo--;
    }
}

void Pila::imprimir(){
    if(pilaVacia()){
        cout<<"\n\tLa pila esta vacia"<<endl;
    }
    else{
        for (int i = getUltimo(); i >= 0; i--)
        {
            cout<<"\t|\t"<<pila[i]<<"\t|";
			cout<<"\n\t-----------------\n";
        }
    }
}

int Pila::getUltimo(){
    return ultimo;
}
