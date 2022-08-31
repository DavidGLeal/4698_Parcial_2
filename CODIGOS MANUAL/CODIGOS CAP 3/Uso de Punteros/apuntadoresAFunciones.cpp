/* el programa de ordenamiento por selección. El ejemplo  consiste de main (líneas 17 a 55) y las funciones ordenamiento Selección (líneas 59 a 76), intercambiar (líneas 80 a 85), ascendente (líneas 89 a 92) y descendente (líneas 96 a 99). La función ordenamiento Selección recibe un apuntador a una función (ya sea ascendente o descendente) como argumento, además del arreglo de enteros a ordenar y del tamaño del arreglo.*/
//#include "stdafx.h"
 // Programa de ordenamiento multipropósito que usa apuntadores a funciones.
 #include <iostream>
 using std::cout;
 using std::cin;
 using std::endl;
 #include <iomanip>
 using std::setw;
 // prototipos
 void ordenamientoSeleccion(int[], const int, bool(*)(int, int));
 void intercambiar(int * const, int * const);
 bool ascendente(int, int); // implementa el orden ascendente
 bool descendente(int, int); // implementa el orden descendente
 int main(){
	 const int tamanioArreglo = 10;
	 int orden; // 1 = ascendente, 2 = descendente
	 int contador; // subíndice del arreglo
	 int a[tamanioArreglo] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
	
	 cout << "Escriba 1 para orden ascendente,\n"
	 << "Escriba 2 para orden descendente: ";
	 cin >> orden;
	 cout << "\nElementos de datos en el orden original\n";
	 // imprime el arreglo original
	 for (contador = 0; contador < tamanioArreglo; contador++)
	 cout << setw(4) << a[contador];
	
	 // ordena el arreglo en forma ascendente; pasa la función ascendente
	 // como un argumento para especificar el orden ascendente
	 if (orden == 1)
	 {
	 ordenamientoSeleccion(a, tamanioArreglo, ascendente);
	 cout << "\nElementos de datos en orden ascendente\n";
	 } // fin de if
	
	 // ordena el arreglo en forma descendente; pasa la función descendente
	 // como argumento para especificar el orden en forma descendente
	 else
	 {
	 ordenamientoSeleccion(a, tamanioArreglo, descendente);
	 cout << "\nElementos de datos en orden descendente\n";
	 } // fin de la parte del if...else correspondiente al else
	 // imprime el arreglo ordenado
	 for (contador = 0; contador < tamanioArreglo; contador++)
	 cout << setw(4) << a[contador];
	 cout << endl;
	 system("pause");
	 return 0; // indica que terminó correctamente
 } // fin de main
	 // ordenamiento por selección multipropósito; el parámetro compara es
	 // un apuntador a la función de comparación que determina el tipo de orden
	 void ordenamientoSeleccion(int trabajo[], const int tamanio,
	 bool(*compara)(int, int))
	 {
	 int menorOMayor; // índice del elemento más pequeño (o grande)
	
	 // itera a través de tamanio - 1 elements
	 for (int i = 0; i < tamanio - 1; i++)
	{
	 menorOMayor = i; // primer índice para el vector remanente
	
	 // itera para encontrar el índice del elemento más pequeño (o más grande)
	for (int index = i + 1; index < tamanio; index++)
	 if (!(*compara)(trabajo[menorOMayor], trabajo[index]))
		 menorOMayor = index;
		
		 intercambiar(&trabajo[menorOMayor], &trabajo[i]);
		 } // fin de if
	 } // fin de la función ordenamientoSeleccion
 
	  // intercambia los valores en las ubicaciones de memoria
	  // a las que apuntan elemento1Ptr y elemento2Ptr1
	  void intercambiar(int * const elemento1Ptr, int * const elemento2Ptr)
	  {
	  int contenido = *elemento1Ptr;
	  * elemento1Ptr = *elemento2Ptr;
	  * elemento2Ptr = contenido;
	 } // fin de la función intercambiar

	 // determina si el elemento a es menor que
	 // el elemento b para un orden ascendente
	bool ascendente(int a, int b)
	{
		 return a < b; // devuelve true si a es menor que b
	} // fin de la función ascendente
		 // determina si el elemento a es mayor que
		 // el elemento b para un orden descendente
	bool descendente(int a, int b)
	 {
		return a > b; // devuelve true si a es mayor que b
	 } // fin de la función descendente
