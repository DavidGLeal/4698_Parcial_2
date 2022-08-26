#include <iostream>
#include "BusquedaBinaria.cpp"

using namespace std;

int main()
{
    int n,x[MAX],t,pos;
    cout<<"Nro de elementos: ";cin>>n;
    leerArray(n,x);
    Burbuja(n,x);
    Listado(n,x);
    cout<<"Elemento a buscar: ";cin>>t;
    pos = bBinaria(n,x,t);
    if(pos==-1) cout<<"No se encuentra"<<endl;
    else cout<<"Lo encontre en la posicion: "<<pos<<endl;
    
    return 0;
}