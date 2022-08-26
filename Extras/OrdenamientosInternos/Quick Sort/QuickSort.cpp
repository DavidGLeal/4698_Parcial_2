#include <iostream>
#include "QuickSort.h"
using namespace std;


void QuickSort::quicksort(double A[20],int primero,int ultimo)
{
    int central,i,j;
    double pivote;
    central=(primero+ultimo)/2;
    pivote=A[central];
    i=primero;
    j=ultimo;
    do
        {
            while(A[i]<pivote) i++;
            while(A[j]>pivote) j--;
            if(i<=j)
            {
                double temp;
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
                i++;
                j--;
            }
        }
    
    while(i<=j);
    if(primero<j)
        quicksort(A,primero,j); 
    if(i<ultimo)
        quicksort(A,i,ultimo); 
}
void QuickSort::escribir(double A[20], int n)
{
    int i;
    cout<<endl<<"Arreglo ordenado por QuickSort: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"\t"<<A[i]<<setw(5);
    }
    cout<<endl<<endl;
    
}