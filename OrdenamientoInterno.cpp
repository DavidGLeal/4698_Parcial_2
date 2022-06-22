#include "OrdenamientoInterno.h"

void OrdenamientoInterno::ordenarIntercambio(Vector<int> &arreglo){
    for (int i{}; i < arreglo.size(); i++) {
        for (int j = 0; j < arreglo.size() - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) {
                int aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }
}

void OrdenamientoInterno::ordenarBurbuja(){
	
}

void OrdenamientoInterno::ordenarQuicksort(){
	
}

void OrdenamientoInterno::ordenarShellSort(){
	
}

void OrdenamientoInterno::ordenarDistribucion(){
	
}

void OrdenamientoInterno::ordenarRadix(){
	
}
