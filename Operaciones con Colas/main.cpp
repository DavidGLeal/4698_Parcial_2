/*
	Universidad de las Fuerzas Armadas "ESPE"
	Colas con m�todos de insertar, eliminar, e imprimir valores mayores de 50
	Ram�rez Erick, Y�nez Michelle
	Fecha de creaci�n: 13/06/2022
	Fecha de modificaci�n: 14/06/2022
	Grupo 9
	https://github.com/ErickRamirezO/Trabajos-Grupo-9
*/

#include "Colas.h"
#include <iostream>
using namespace std;

int main() {
  cola Cola;
  cout << "Colas\n" << endl;
  Insertar(Cola, 55);
  Insertar(Cola, 67);
  Insertar(Cola, 23);
  Insertar(Cola, 14);
  Insertar(Cola, 67);
  Insertar(Cola, 55);
  Insertar(Cola, 78);
  Insertar(Cola, 90);
  cout << "\nImprimir todos los valores" << endl;
  Imprimir(Cola);
  cout << "\nImprimir mayores de 50" << endl;
  Imprimir50(Cola);

  return 0;
}
