#include <iostream>   
#include "Radix.cpp"   
using namespace std;   
int main()   
{   
int n, i;   
Radix ordenar;   
cout<<"Ingrese la dimension del arreglo: ";   
cin>>n;   
int *arr = new int(n);   
for(i = 0; i < n; i++)   
{   
cout<<"Arreglo["<<i+1<<"]=";   
cin>>arr[i];   
}   
ordenar.radixsort(arr, n);   
cout<<"Elementos ordenados por metodo Radix Sort "<<endl;   
for (i = 0; i < n; i++)   
cout<<"\t"<<arr[i];   
}  
