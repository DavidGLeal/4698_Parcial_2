#include "ImprimirExterno.h"


void ImprimirExterno::abrir(fstream *f, char nom[], int tip){
	if (tip == 1)                          // LECTURA
    (*f).open(nom, ios::in);             //->
                                         // MODO TEXTO (Acceder a los datos) usarÃ© ">>"
  else if (tip == 2)                     // ESCRITURA SIN BORRAR
    (*f).open(nom, ios::out | ios::app); //->
                                         // MODO TEXTO (Colocar datos y no borrarÃ¡) usarÃ© "<<"
  else                                   // ESCRITURA y BORRAR
    (*f).open(nom, ios::out);            //->
  // MODO TEXTO (Colocar datos) usarÃ© "<<"
}

void ImprimirExterno::cerrar(fstream *f){
	(*f).close();	
}
void ImprimirExterno::imprimir(char nom[]){
	  fstream F;
  abrir(&F, nom, 1);
  int dato;
  F >> dato;
  while (!F.eof())
  {
    cout << dato << " ";
    F >> dato;
  }
  cerrar(&F);
	
}
