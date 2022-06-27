#pragma once 
#include "2OrdenamientoInterno.h"
#include "0Vector.cpp"


/**
 * Devuelve el vector.
 * 
 * @return el vector
 */
Vector OrdenamientoInterno::getVector(){
	return this->vector;
}


/**
 * Establece el vector.
 * 
 * @param _vector
 */
void OrdenamientoInterno::setVector(Vector _vector){

    if (!this->vector.empty()) {
        this->vector.~Vector();
    }

    for (int i{}; i < _vector.size(); i++) {
        this->vector.push_back(_vector[i]);
    }
} 

/**
 * Es una función que ordena un vector de números enteros usando el algoritmo de intercambio
 */
void OrdenamientoInterno::ordenarIntercambio(){
    for (int i{}; i < this->vector.size(); i++) {
        for (int j = i; j < this->vector.size(); j++) {
            if (this->vector[i] > this->vector[j]) {
                auto aux = this->vector[i];
                *(this->vector.get(i)) = this->vector[j];
                *(this->vector.get(j)) = aux;
            }
        }
    }
}

/**
* Es una función que ordena un vector de números enteros usando el algoritmo de burbuja
*/
void OrdenamientoInterno::ordenarBurbuja(){ 
    //GRUPO 2 - ORDENAMIENTO BURBUJA
    int aux;
    int i, j;
    for (i = 0 ; i < vector.size() ; i++) {
        for (j = 0 ; j < vector.size() - 1 ; j++) {
            if (*(vector.get(j)) > *(vector.get(j + 1))) {
                aux = *(vector.get(j));
                *(vector.get(j)) = *(vector.get(j + 1));
                *(vector.get(j + 1)) = aux;
            }
        }
    }
}

/**
* Es una función que ordena un vector de enteros usando el algoritmo Quicksort
*/

void OrdenamientoInterno::ordenarQuicksort() {
	ordenarQuick(vector,0,vector.size() - 1); 
}

void OrdenamientoInterno::ordenarQuick(Vector &vector, size_t inicio, size_t fin) { 
    if (inicio >= fin)
        return;
    auto lim = dividir(vector, inicio, fin);
    ordenarQuick(vector, inicio, lim);
    ordenarQuick(vector, lim + 1, fin);
}

int OrdenamientoInterno::dividir(Vector &vector, size_t inicio,size_t fin) {
    int pivote = *(vector.get(inicio));
    auto i = inicio + 1; //i=izquierda
    auto j = fin; //j=derecha

    while (true) {
        while (i< j && *(vector.get(j)) >= pivote) j--;
        while (i < j && *(vector.get(i)) < pivote) i++;

        if (i == j) break;

        int tmp = *(vector.get(i));
        *(vector.get(i)) = *(vector.get(j));
        *(vector.get(j)) = tmp;
    }

    if (*(vector.get(i)) >= pivote) return inicio;
    *(vector.get(inicio)) = *(vector.get(i));
    *(vector.get(i)) = pivote;
    return i;
}

    
/**
* Es una función que ordena un vector de enteros usando el algoritmo Shell Sort
*/
void OrdenamientoInterno::ordenarShellSort(){
   int j, incremento, aux; // incremento: Tamaño del bloque de separación de los elementos dentro del método Shell.
    incremento = vector.size() / 2; // De acuerdo al algoritmo original, el incremento se divide en 2 en cada iteración.
    while (incremento > 0)
    {
        for (int i = incremento; i < vector.size(); i++)
        {
            j = i - incremento; // j es un índice de secuenciamiento.
            while (j >= 0)
            {
                if (*(vector.get(j)) >= *(vector.get(j + incremento))) // Se comparan los elementos distales a un factor incremental de separación.
                {
                    aux = *(vector.get(j)); // Se intercambian los valores, logrando el ordenamiento.
                    *(vector.get(j)) = *(vector.get(j + incremento));
                    *(vector.get(j + incremento)) = aux;
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

/**
* Toma una matriz de números enteros y los ordena en orden ascendente con el algoritmo de distribucion
*/
void OrdenamientoInterno::ordenarDistribucion(){

	//GRUPO 16 - ORDENAMIENTO COUNTING SORT
	int max = vector[1];
	int salida[vector.size()+1];  	
	for(int i = 2; i<=vector.size(); i++) 
	{
      		if(vector[i] > max)
        	max = vector[i];
   	}

   	int aux1[max+1];     
   	for(int i = 0; i<=max; i++)
   	{
   	    aux1[i] = 0;
   	}

  	 for(int i = 1; i <=vector.size(); i++)
   	{
   		aux1[vector[i]]++; 
  	}

   	for(int i = 1; i<=max; i++)
    {
   		aux1[i] += aux1[i-1]; 
   	} 

  	for(int i = vector.size(); i>=1; i--) {

      	salida[aux1[vector[i]]] = vector[i];
      	aux1[vector[i]] -= 1; 
 	}

   	for(int i = 1; i<=vector.size(); i++) {
      	vector[i] = salida[i]; 
  	}
    
}

/**
 * Toma un vector de números enteros y los ordena usando el algoritmo bucket
*/
void OrdenamientoInterno::ordenarBucket(){
    
	int c = vector.size();
	int col=10,cnt=0,k=0,d=1,l=0;
	Vector ordenado;
	int **matriz = new int*[c];
	
	for(int z =0;z<c;z++)
	{
		matriz[z] = new int[col];
	}
	
	int max= *vector.get(0);
	for(int a=1;a<c;a++)
    {
        if(*vector.get(a)>max)
            max=*vector.get(a);
    }
    while(max>0)
    {
        cnt++;
        max=max/10;
    }
	int *j = new int[c];
	for(int m=0;m<cnt;m++)
    {
        for(int i=0;i<col;i++)
        {    
			j[i]=0;
		}
        for(int y=0;y<c;y++)
        {
            k=(vector[y]/d)%10;
            matriz[k][j[k]]=*vector.get(y);
            j[k]++;
        }
        
        for(int a=0;a<c;a++)
        {
        	for(int r=0;r<j[a];r++)
        	{
        		
        		for(int o=r;o<j[a];o++)
        		{
        		 if(matriz[a][r]>matriz[a][o])
        			{
        				int aux = matriz[a][r];
        			 matriz[a][r] = matriz[a][o];
        				matriz[a][o] = aux;					 					 				        				
					}				        			
				}        		
			}
		}
        
    	l=0;
        for(int b=0;b<c;b++)
        {
            for(k=0;k<j[b];k++)
            {
            	int aux =matriz[b][k];
                ordenado.push_back(matriz[b][k]);
                l++;
            }
        }
        
        d*=10;
    }

    setVector(ordenado);
}

/**
 * La función toma un vector de números enteros y los ordena usando el algoritmo de clasificación radix
 * 
 */
void OrdenamientoInterno::ordenarRadix(){

    auto maximo = [&] (){
	int mx = *(vector.get(0)); 
    	for (int i = 1; i < vector.size(); i++) 
        if (*(vector.get(i)) > mx) 
        mx = *(vector.get(i)); 
    	return mx;
	};
	
    int m = maximo(); 

    auto Sort = [&] (int exp){	
	    Vector salida,contador; 
	    for (int i = 0; i < 10; i++){	        	
	        contador.push_back(0);
	    }
	    for (int i = 0; i < vector.size(); i++){	        	
	        salida.push_back(0);
	    } 		  
	    for (int i = 0; i < vector.size(); i++){		
	        *(contador.get((*(vector.get(i)) / exp) % 10))=*(contador.get((*(vector.get(i)) / exp) % 10))+1;
            }		  
	    for (int i = 1; i < 10; i++) {		    	
		*(contador.get(i)) += *(contador.get(i-1)); 
	    }
	    for (int i = vector.size()-1; i >= 0; i--) {
		*(salida.get(*(contador.get((*(vector.get(i))/exp)%10))-1))=*(vector.get(i)) ;				
		*(contador.get((*(vector.get(i)) / exp) % 10))=*(contador.get((*(vector.get(i)) / exp) % 10))-1;		
            }   
	    for (int i = 0; i < vector.size(); i++){
		*(vector.get(i)) = *(salida.get(i)); 
	    }	        
    };
    
    for (int exp = 1; m / exp > 0; exp *= 10) 
        Sort(exp); 
} 

void OrdenamientoInterno::imprimirInterno(){
    imprimir(vector);
    cout<<"\n";
}
