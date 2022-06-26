#pragma once 
#include "2OrdenamientoInterno.h"
#include "0Vector.cpp"

Vector v ;
Vector vShell;

Vector OrdenamientoInterno::getVector(){
	return this->vector;
}

void OrdenamientoInterno::setVector(Vector _vector){
    if (!this->vector.empty()) {
        this->vector.~Vector();
    }

    for (int i{}; i < _vector.size(); i++) {
        this->vector.push_back(_vector[i]);
    }
} 

Vector &OrdenamientoInterno::ordenarIntercambio(){
    for (int i{}; i < this->vector.size(); i++) {
        for (int j = i; j < this->vector.size(); j++) {
            if (this->vector[i] > this->vector[j]) {
                auto aux = this->vector[i];
                *(this->vector.get(i)) = this->vector[j];
                *(this->vector.get(j)) = aux;
            }
        }
    }

    return this->vector;
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

void OrdenamientoInterno::imprimirInterno() {
		for (int i = 0; i < v.size(); i++)
			//for (int i = 0; i < arreglo.size(); i++)
			cout << *(v.get(i)) << " ";
			//cout << *(v + i) << " ";
	}


void OrdenamientoInterno::ordenarBucket(){
    Vector arre = getVector();
	int c = arre.size();
	int col=10,cnt=0,k=0,d=1,l=0;
	//int *ordenado = new int[c];
	Vector ordenado;
	int **matriz = new int*[c];
	
	for(int z =0;z<c;z++)
	{
		matriz[z] = new int[col];
	}
	
	int max= *arre.get(0);
	for(int a=1;a<c;a++)
    {
        if(*arre.get(a)>max)
            max=*arre.get(a);
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
            k=(arre[y]/d)%10;
            matriz[k][j[k]]=*arre.get(y);
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
    
}

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
