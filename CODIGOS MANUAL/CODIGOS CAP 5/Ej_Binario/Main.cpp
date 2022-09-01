/*Universidad de las Fuerzas Armadas ESPE
  Enunciado: Dado el siguiente problema utilizando proceso racional resolver el siguiente problema 
  Autores: 
  Adriana Diaz
  Johanna Pila
  Fecha de creación: 18/05/2022
  Fecha de modificación: 23/05/2022
  Github: https://github.com/AdrianaDiazB/Grupo3-EstructuraDeDatos-4698/tree/main/Evidencia%20Grupo%2014/PARCIAL%20I/Deber%201
*/

#include <string.h>
#include <iostream>
#include <iomanip>
#include "binario.cpp" 

using namespace std;
void decimalBinario(int, char[]);

int main(){

    char *cad=new char[10]; //memoria dinamica 
    cad[0]='\0';
    decimalBinario(124, cad);
    cout<<cad<<endl;
    return 0;
}
