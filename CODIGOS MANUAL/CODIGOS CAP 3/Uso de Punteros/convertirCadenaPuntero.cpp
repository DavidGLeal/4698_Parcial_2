#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
char *p;
char CadenaTexto[81];
cout<<"Introduzca cadena a convertir : "<<endl;
cin>>CadenaTexto;
/*p apunta al primer carácter de la cadena */
p = &CadenaTexto[0]; /*equivale a p = CadenaTexto */
/*Repetir mientras *p no sea cero */
while (*p){
/*restar 32, constante de código ASCII */
if ((*p >= 'a') && (*p <= 'Z'))
*p++ = *p - 32;
else
p++;
}
puts("La cadena convertida es : " ) ;
puts(CadenaTexto);
puts("\nPulse intro (Enter) para continuar");
system("pause>null");
}
