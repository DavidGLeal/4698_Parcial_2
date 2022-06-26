#include "4Busqueda.h"


void Busqueda::busquedaBinaria(){
	int numeros[] = {1,2,3,4,5,6,7,8,9,10};
	int inf,sup,mitad,dato,i;
	char band='F';
	dato = 1;
	
	//Algoritmo de la Busqueda Binaria
	inf=0;
	sup=5;
	i=0;
	while((inf<=sup)&&(i<5)){
		mitad = (inf+sup)/2;
		if(numeros[mitad] == dato){
			band='V';
			break;
		}
		if(numeros[mitad]>dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if(numeros[mitad]<dato){
			inf = mitad;
			mitad = (inf+sup)/2;
		}
		i++;
	}
	if(band == 'V'){
		cout<<"El numero se encontro en la pos: "<<mitad<<endl;
	}
	else{
		cout<<"El numero NO se encontro";
	}
	
}

void Busqueda::busquedaSecuencial(){
		int numeros[] = {1,2,3,4,5,6,7,8,9,10}; //array a usar
	bool encontrado=false; //bandera
    int i=0,numeroBusqueda;
    cout<<"Ingresa el valor a buscar: ";
	cin>>numeroBusqueda;     //numero a buscar en el array
    while (i<10 && encontrado==false){
        if(*(numeros+i)==numeroBusqueda){
            encontrado=true; //cambia a verdadero la bandera si ha encontrado el elemento
        }
        i++;
    }
    if (encontrado==true){ //verificamos el estado de la bandera
        cout<<"El numero "<<numeroBusqueda<<" si se encuentra en el arreglo\n"<<"en la posicion "<<i<<endl;
    }else{
        cout<<"El numero "<<numeroBusqueda<<" no esta en la lista \n"<<endl;
    }    
}

