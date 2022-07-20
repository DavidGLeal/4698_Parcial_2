#pragma once 
#include "Radix.h"

/**
 * Devuelve el vector.
 * 
 * @return el vector
 */
Vector& Radix::getVector(){
	return this->vector;
}

/**
 * Establece el vector.
 * 
 * @param _vector
 */
void Radix::setVector(Vector &_vector){
    this->vector = _vector;
} 

/**
 * Ordena el vector separando los números negativos de los positivos, luego ordena los
 * números negativos y números positivos por separado, y finalmente fusiona los dos vectores
 * 
 * @return El vector ordenado.
 */
void Radix::ordenarRadix(){

    int tam{vector.size()};
    Vector vN,vP; 
	//vN=vector negativos
	//vP=vector positivos
    
    for(int i=0; i<tam; i++){
        if(vector[i]<0)
        {
        	vN.push_back(abs(vector[i]));
		}else{
			vP.push_back(vector[i]);
		}
    }
    int auxNCount=0;
	//Para valores Negativos
    if(vN.size()!=0)
    {
    	auto maximoN = [&] (){
		int mxN = *(vN.get(0)); 
	    	for (int i = 1; i < vN.size(); i++) 
	        if (*(vN.get(i)) > mxN) 
	        mxN = *(vN.get(i)); 
	    	return mxN;
		};
		
	    int mN = maximoN(); 
	
	    auto SortN = [&] (int expN){	
		    Vector salidaN,contadorN; 
		    for (int i = 0; i < 10; i++){	        	
		        contadorN.push_back(0);
		    }
		    for (int i = 0; i < vN.size(); i++){	        	
		        salidaN.push_back(0);
		    } 		  
		    for (int i = 0; i < vN.size(); i++){		
		        *(contadorN.get((*(vN.get(i)) / expN) % 10))=*(contadorN.get((*(vN.get(i)) / expN) % 10))+1;
	        }		  
		    for (int i = 1; i < 10; i++) {		    	
				*(contadorN.get(i)) += *(contadorN.get(i-1)); 
		    }
		    for (int i = vN.size()-1; i >= 0; i--) {
				*(salidaN.get(*(contadorN.get((*(vN.get(i))/expN)%10))-1))=*(vN.get(i)) ;				
				*(contadorN.get((*(vN.get(i)) / expN) % 10))=*(contadorN.get((*(vN.get(i)) / expN) % 10))-1;		
	        }   
		    for (int i = vN.size()-1; i>=0; i--){
				*(vN.get(i)) = *(salidaN.get(i)); 
		    }	        
	    };
	    
	    for (int expN = 1; mN / expN > 0; expN *= 10) 
	        SortN(expN);
	}
	
	//Para valores positivos
	if(vP.size()!=0)
	{
		auto maximoP = [&] (){
			int mxP = *(vP.get(0)); 
	    	for (int i = 1; i < vP.size(); i++) 
	        if (*(vP.get(i)) > mxP) 
	        mxP = *(vP.get(i)); 
	    	return mxP;
		};
		
	    int mP = maximoP(); 
	
	    auto SortP = [&] (int expP){	
		    Vector salidaP,contadorP; 
		    for (int i = 0; i < 10; i++){	        	
		        contadorP.push_back(0);
		    }
		    for (int i = 0; i < vP.size(); i++){	        	
		        salidaP.push_back(0);
		    } 		  
		    for (int i = 0; i < vP.size(); i++){		
		        *(contadorP.get((*(vP.get(i)) / expP) % 10))=*(contadorP.get((*(vP.get(i)) / expP) % 10))+1;
	        }		  
		    for (int i = 1; i < 10; i++) {		    	
				*(contadorP.get(i)) += *(contadorP.get(i-1)); 
		    }
		    for (int i = vP.size()-1; i >= 0; i--) {
				*(salidaP.get(*(contadorP.get((*(vP.get(i))/expP)%10))-1))=*(vP.get(i)) ;				
				*(contadorP.get((*(vP.get(i)) / expP) % 10))=*(contadorP.get((*(vP.get(i)) / expP) % 10))-1;		
	        }   
		    for (int i = 0; i < vP.size(); i++){
				*(vP.get(i)) = *(salidaP.get(i)); 
		    }	        
	    };
	    
	    for (int expP = 1; mP / expP > 0; expP *= 10) 
	        SortP(expP);	
	}
	if(vN.size()!=0)
    {
		for (int i = vN.size()-1; i >=0; i--){
			*(vector.get(auxNCount)) = *(vN.get(i)); 
			vector[auxNCount]=-1*(vector[auxNCount]);
			auxNCount++;
		}
	}
	if(vP.size()!=0)
    {
		for (int i = 0; i < vP.size(); i++){
			*(vector.get(auxNCount)) = *(vP.get(i)); 
			auxNCount++;
		}
	}
} 

/**
 * Imprime el vector
 */
void Radix::imprimirInterno(){
    imprimir(vector);
    cout<<"\n";
}

/**
 * Imprime los elementos del vector.
 * 
 * @param vector El vector a imprimir.
 */
void Radix::imprimir(Vector &vector){
    for(int i = 0; i < vector.getElementos(); i++){
        cout << vector[i] << " ";
    }    
}