#include<iostream>
#include "Sort.h"
 
using namespace std;
 
void Sort::mostrar(int *array, int tam) {
 
   for(int i = 1; i<=tam; i++)
      cout << array[i] << " ";
   cout << endl;
}
 
int Sort::obtenerMaximo(int array[], int tam) {
   int max = array[1];
 
   for(int i = 2; i<=tam; i++) {
      if(array[i] > max)
         max = array[i];
 
   }
 
   return max;
 
}
 
void Sort::countSort(int *array, int tam) {
   int *output =  new int(tam+1);
 
   int max = obtenerMaximo(array, tam);
   int *count = new int(max+1);      
 
   for(int i = 0; i<=max; i++)
      count[i] = 0;      
 
   for(int i = 1; i <=tam; i++)
      count[array[i]]++;      
 
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];    
 
   for(int i = tam; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1;  
   }
 
   for(int i = 1; i<=tam; i++) {
      array[i] = output[i];  
   }
 
}
