#pragma once 
#include "OrdenamientoInterno.h"
#include "vector.h"
#include "vector.cpp"

Vector v ;
Vector <int> vShell;

void OrdenamientoInterno::ordenarIntercambio(){
    int aux;
    Vector arreglo;
    for (int i{}; i < arreglo.size(); i++) {
        for (int j = i; j < arreglo.size(); j++) {
            if (arreglo[i] > arreglo[j]) {
                auto aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}

void OrdenamientoInterno::ordenarBurbuja(){ 
    //GRUPO 2 - ORDENAMIENTO BURBUJA
    int aux;
    int i, j;
    for (i = 0 ; i < v.size() ; i++) {
        for (j = 0 ; j < v.size() - 1 ; j++) {
            if (*(v.get(j)) > *(v.get(j + 1))) {
                aux = *(v.get(j));
                *(v.get(j)) = *(v.get(j + 1));
                *(v.get(j + 1)) = aux;
            }
        }
    }
}

void OrdenamientoInterno::ordenarQuicksort() {
        int pivot = arreglo[(izq + der) / 2]; //pivote 
        int i = izq;
        int j = der;

        while (izq <= der) {

            while (arreglo[izq] < pivot) ++izq;

            while (arreglo[der] > pivot) --der;

            if (izq <= der) {
                std::swap(arreglo[izq], arreglo[der]);
                ++izq;
                --der;
            }
        }

        if (izq < j)
            ordenarQuicksort(arreglo, izq, j);

        if (i < der)
            ordenarQuicksort(arreglo, i, der);
            
}


void OrdenamientoInterno::ordenarShellSort(){
   int j, incremento, aux; // incremento: Tamaño del bloque de separación de los elementos dentro del método Shell.
    incremento = vShell.size() / 2; // De acuerdo al algoritmo original, el incremento se divide en 2 en cada iteración.
    while (incremento > 0)
    {
        for (int i = incremento; i < vShell.size(); i++)
        {
            j = i - incremento; // j es un índice de secuenciamiento.
            while (j >= 0)
            {
                if (*(vShell.get(j)) >= *(vShell.get(j + incremento))) // Se comparan los elementos distales a un factor incremental de separación.
                {
                    aux = *(vShell.get(j)); // Se intercambian los valores, logrando el ordenamiento.
                    *(vShell.get(j)) = *(vShell.get(j + incremento));
                    *(vShell.get(j + incremento)) = aux;
                }
                else
                {
                    j = 0; // Se retrocede el índice de secuenciamiento del vector.
                }
                j = j - incremento;
            }
        }
        incremento = incremento / 2; // Se divide el bloque de comparación en cada iteración.
    }
}

void OrdenamientoInterno::ordenarDistribucion(){
	
}

void OrdenamientoInterno::ordenarRadix(){
	
}


void OrdenamientoInterno::imprimirInterno() {
		for (int i = 0; i < v.size(); i++)
			//for (int i = 0; i < arreglo.size(); i++)
			cout << *(v.get(i)) << " ";
			//cout << *(v + i) << " ";
	}

/*void OrdenamientoInterno::imprimirInterno (int* vector, int tam) {
		for (int i = 0; i < tam; i++)
			cout << *(vector + i) << " ";
	}*/
void OrdenamientoInterno::ordenarBucket(){
    
}
