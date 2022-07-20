/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 10
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
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

