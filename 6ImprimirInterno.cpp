#include "6ImprimirInterno.h"
#include "0Vector.cpp"

void ImprimirInterno::imprimir(Vector *vector){
    for(int i = 0; i < vectorelementos; i++){
        cout << arrayInterno[i] <<endl;
    }    
}