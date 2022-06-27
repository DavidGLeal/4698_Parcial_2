#include "4Busqueda.h"


void busquedaBinaria(){
    int numeros[10];//arreglo a usar
    int inf,sup,mitad,dato,i;
    char band='F';//bandera sirve para comprobar si existe o no el elemento
    for(int i=0;i<10;i++){
        cout<<"Ingrese el elemento:"<<endl;
        cin>>numeros[i];
    }
    cout<<"El numero a encontrar: ";
    cin>>dato;//numero a buscar
    //Algoritmo de la Busqueda Binaria
    inf=0; //limite inferior del arreglo
    sup=10; // limite superior del arreglo
    i=0;
    while((inf<=sup)&&(i<10)){
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
    //Enviar mensaje si se encontro o no el dato.
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

