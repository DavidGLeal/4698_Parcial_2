#pragma once 
#include "OrdenamientoInterno.h"
#include "vector.h"
#include "vector.cpp"

Vector v ;
Vector vShell;

Vector OrdenamientoInterno::getVector(){
	return this->vector;
}

void OrdenamientoInterno::setVector(Vector _vector){
	this->vector = _vector;
} 

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

void OrdenamientoInterno::ordenarQuicksort(Vector &v, int inicio, int fin){

        int i=inicio;
        int j=fin;
        int pivote=*(v.get((inicio+fin)/2));
        while(i<=j){
            while(*(v.get(i))<pivote)
                i++;
            while(*(v.get(j))>pivote)
                j--;
            if(i<=j){
                int aux=*(v.get(i));
                *(v.get(i))=*(v.get(j));
                *(v.get(j))=aux;
                i++;
                j--;
            }
        }
        if(inicio<j)
            ordenarQuicksort(v,inicio,j);
        if(i<fin)
            ordenarQuicksort(v,i,fin);

        for (int i = 0; i < v.size(); i++) {
            cout << *(v.get(i)) << " ";
        }
        cout << endl;
    
    
}
  
/*void OrdenamientoInterno::ordenarQuicksort(Vector arreglo, int izq, int der) {
       
        int pivot = arreglo[(izq + der) / 2]; //pivote 
        int i = izq;
        int j = der;

        while (izq <= der) {

            while (arreglo[izq] < pivot){
                izq++;
            }

            while (arreglo[der] > pivot){
                der--;
            }

            if (izq <= der) {
                int aux = arreglo[izq];
                arreglo[izq] = arreglo[der];
                arreglo[der] = aux;
                ++izq;
                --der;
            }
        }

        if (izq < j)
            ordenarQuicksort(arreglo, izq, j);

        if (i < der)
            ordenarQuicksort(arreglo, i, der);

        //imprimir vector ordenado por quicksort 

        for (int i = 0; i < arreglo.size(); i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;

        
    }
*/


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
	//GRUPO 16 - ORDENAMIENTO COUNTING SORT
	/*Vector arreglo;
	int max = arreglo[1];
	int salida[arreglo.size()+1];  	
	for(int i = 2; i<=arreglo.size(); i++) 
	{
      		if(arreglo[i] > max)
        	max = arreglo[i];
   	}
   	int aux1[max+1];     
   	for(int i = 0; i<=max; i++)
   	{
   	aux1[i] = 0;
   	}
  	 for(int i = 1; i <=arreglo.size(); i++)
   	{
   		aux1[arreglo[i]]++; 
  	 }
   	for(int i = 1; i<=max; i++)
  	 {
   		aux1[i] += aux1[i-1]; 
   	} 
  	 for(int i = arreglo.size(); i>=1; i--) {
      	salida[aux1[arreglo[i]]] = arreglo[i];
      	aux1[arreglo[i]] -= 1; 
 	  }
   	for(int i = 1; i<=arreglo.size(); i++) {
      	arreglo[i] = salida[i]; 
  	 }
     */
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
