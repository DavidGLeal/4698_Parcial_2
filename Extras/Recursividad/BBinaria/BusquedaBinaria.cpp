#include "BusquedaBinaria.h"
#include <iostream>

using namespace std;

void leerArray(int n,int x[]){
    for(int i=0;i<n;i++)
    {
        cout<<"Elemento "<<i+1<<": ";
        cin>>x[i];
    }
}

void Listado(int n,int x[]){
    cout<<"Los elementos son: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i+1<<": "<<x[i]<<endl;
    }
}

void Burbuja(int n,int x[]){
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(x[j-1]>x[j])
            {
                temp = x[j-1];
                x[j-1] = x[j];
                x[j] = temp;
            }
        }
    }
}

int bBinaria(int n,int x[],int t){
    int mitad,izq,der;
    izq=0;der=n-1;
    while(izq<=der)
    {
        mitad = (izq+der)/2;
        if(t>x[mitad])izq = mitad+1;
        else if(t<x[mitad]) der = mitad-1;
        else return mitad;
    }
    return -1;
}

