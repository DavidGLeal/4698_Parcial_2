/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
*/

#include "Hash.h"

Hash::Hash(){
    this->total_elementos = 3;
    this->listaP= new Lista[this->total_elementos];

    for (int i = 0; i < this->total_elementos; i++){
            listaP[i]=Lista();
    }
}

Hash::~Hash(){

}

void Hash::mensajito(){
    cout<<"Tabla Abierta";
}

void Hash::insertarElemento(int _valor){

    int key =getClave(_valor);
    listaP[key].agregarCabeza(_valor);

} 

int Hash::getClave(int _valor){
    return (_valor % this->total_elementos);
}

void Hash::mostrarHash(){
    
    for(int i = 0; i < this->total_elementos; i++){
        cout << "\t________ \n\t"; 
        cout << "|Clave " << i << "| ";    
        listaP[i].imprimirLista();

    }
}

bool Hash::buscarElemento(int _valor){
    bool encontrado=false;
    int key =getClave(_valor);

    cout<<"\n\tClave buscada: "<< key;
    if (listaP[key].buscar(_valor)){
        encontrado = true;
    }
    return encontrado;

}

void Hash::eliminarElemento(int _valor){
    int key = getClave(_valor);
    if (listaP[key].buscar(_valor)){
       listaP[key].borrarEnPosicion(_valor);
    }
    else{
        cout<<"\tEl dato no fué encontrado\n";
    }

}   

