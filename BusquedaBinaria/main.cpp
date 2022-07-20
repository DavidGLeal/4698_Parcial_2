/*Universidad de las Fuerzas Armadas ESPE
  Enunciado: Dado el siguiente problema utilizando proceso racional resolver el siguiente problema 
  Autores: 
  Adriana Diaz
  Johanna Pila
  Fecha de creación: 17/07/2022
  Fecha de modificación: 17/07/2022
  Github: https://github.com/AdrianaDiazB/Grupo3-EstructuraDeDatos-4698/tree/main/Evidencia%20Grupo%2014/PARCIAL%20I/Deber%201
*/
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
    else cout<<"Lo encontre en la posicion: "<<pos+1<<endl;
    
    return 0;
}