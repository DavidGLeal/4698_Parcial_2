#include<iostream>
#include<conio.h>
#include<iomanip>
#include "QuickSort.cpp"
using namespace std;
 
int main()
{
    int i,nro;
    QuickSort ordenar;
    double B[20];
   
    cout<<"Ingrese la dimension del arreglo: "<<endl;
    cin>>nro;
    for(i=0;i<nro;i++)
    {
        cout<<"Arreglo["<<i+1<<"]=";
        cin>>B[i];
    }
    ordenar.quicksort(B,0,nro-1);
    ordenar.escribir(B,nro);
    getch();
    return 0;
}
