#include "Burbuja.h"
void Burbuja::mostrar(int *array, int tam)
{
 for (int i = 1; i <= tam; i++)
    cout << array[i] << " ";
  cout << endl;
}
void Burbuja::realizarOrdenamiento(int *arr, int tam)
{
  int aux;
  for (int i = 1; i <= tam; i++)
  {
    for (int j = 1; j <= tam - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
      }
    }
  }
  mostrar(arr,tam);
}
 
void Burbuja::ingresarDatos(){
  int n = 0;
  cout << "Ingresa el numero de elementos: ";
  cin >> n;
  int *arr = new int(n+1);
  cout << "Ingrese elementos:" << endl;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  cout << "Arreglo antes de ordenar: ";
  mostrar(arr,n);
  realizarOrdenamiento(arr,n);
}

Burbuja::Burbuja()
{
  
}