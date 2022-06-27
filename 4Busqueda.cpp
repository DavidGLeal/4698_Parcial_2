#include "4Busqueda.h"

void Busqueda::setVector(Vector &_vector){
    this->vector = _vector;
}

void  Busqueda::vaciarVector(){
    vector.vaciar();
}

void  Busqueda::setDato(int a){
    this->dato = a;
}


void Busqueda::busquedaBinaria(){

    int inf,sup,mitad,dato,i;
    char band='F';//bandera sirve para comprobar si existe o no el elemento


    //Algoritmo de la Busqueda Binaria
    inf=0; //limite inferior del arreglo
    sup=10; // limite superior del arreglo
    i=0;
    while((inf<=sup)&&(i<10)){
        mitad = (inf+sup)/2;
        if(vector[mitad] == dato){
            band='V';
            break;
        }
        if(vector[mitad]>dato){
            sup = mitad;
            mitad = (inf+sup)/2;
        }
        if(vector[mitad]<dato){
            inf = mitad;
            mitad = (inf+sup)/2;
        }
        i++;
    }
    //Enviar mensaje si se encontro o no el dato.
    if(band == 'V'){
        cout<<"El numero se encontro en la pos: "<<mitad<<endl;
    }
    else{
        cout<<"El numero NO se encontro";
    }

}

void Busqueda::busquedaSecuencial(){

	bool encontrado=false; //bandera
    int i=0;

    while (i<10 && encontrado==false){
        if(vector[i]==dato){
            encontrado=true; //cambia a verdadero la bandera si ha encontrado el elemento
        }
        i++;
    }
    if (encontrado==true){ //verificamos el estado de la bandera
        cout<<"El numero "<< dato <<" si se encuentra en el arreglo\n"<<"en la posicion "<<i<<endl;
    }else{
        cout<<"El numero "<<dato <<" no esta en la lista \n"<<endl;
    }    
}

