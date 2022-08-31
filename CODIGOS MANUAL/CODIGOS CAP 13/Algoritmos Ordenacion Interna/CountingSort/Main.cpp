#include<iostream>
#include "Sort.cpp"
 
using namespace std;
 
int main() {
    Sort sort;
   int n;
   cout << "Ingresa el numero de elementos: ";
   cin >> n;
   int *arr = new int(n+1);   
   cout << "Ingrese elementos:" << endl;
   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }
 
   cout << "Arreglo antes de ordenar: ";
   sort.mostrar(arr, n);
   sort.countSort(arr, n);
   cout << "Arreglo luego de ordenar: ";
   sort.mostrar(arr, n);
}
 
