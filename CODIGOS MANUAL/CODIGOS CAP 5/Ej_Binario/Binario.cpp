#include <cstring>
#include "binario.h"

using namespace std;

//Recursion
void decimalBinario(int val, char *cad){ //1. parametrizacion
   
   if(val>=1){ //2. Caso base con parametros
      decimalBinario(val/2, cad);//3. llamada a recursion
      //strcpy(*cad,itoa((val%2),*cad,10));//4. Se copia en la cadena
      /*el itoa tiene 3 parametros
        1. Valor
        2. donde lo vamos a copiar (es de tipo char)
        3. la base*/
      itoa(val%2, cad+strlen(cad), 10);
      strcat(cad,"\0"); //Finaliza la cadena 
   }
};
