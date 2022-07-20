#include "HashStr.h"

HashStr::HashStr(){
    this->total_elementos = 3;
    this->listaP= new ListaStr[this->total_elementos];

    for (int i = 0; i < this->total_elementos; i++){
            listaP[i]=ListaStr();
    }
}

HashStr::~HashStr(){

}

void HashStr::mensajito(){
    cout<<"Holii x2";
}

void HashStr::insertarElemento(string _valor){

    int key =getClave(_valor);
    listaP[key].agregarCabeza(_valor);

} 

int HashStr::getClave(string _valor){
    int suma = 0;
    for(int i = 0; i < _valor.length(); i++){
        suma += _valor[i];
    }
    return suma % this->total_elementos;
}

void HashStr::mostrarHash(){
    
    for(int i = 0; i < this->total_elementos; i++){
        cout << "\t________ \n\t"; 
        cout << "|Clave " << i << "| ";    
        listaP[i].imprimirLista();

    }
}

bool HashStr::buscarElemento(string _valor){
    bool encontrado=false;
    int key =getClave(_valor);

    cout<<"\n\tClave buscada: "<< key;
    if (listaP[key].buscar(_valor)){
        encontrado = true;
    }
    return encontrado;

}

void HashStr::eliminarElemento(string _valor){
    int key = getClave(_valor);
    if (listaP[key].buscar(_valor)){
       listaP[key].borrarEnPosicion(_valor);
    }
    else{
        cout<<"\tEl dato no fué encontrado\n";
    }

}   

