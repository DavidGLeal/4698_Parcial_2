#include "Mezcla.cpp"
#include <iostream>

using namespace std;
int main()
{
    FILE *fichero;
    Mezcla *mezcla= new Mezcla();

   fichero = fopen("mezcla.txt", "r+");
   cout<<"Fichero desordenado\n"<<endl;
   mezcla->Mostrar(fichero);
   cout<<"Ordenando fichero\n"<<endl;
   mezcla->Mezcla_(fichero);
   cout<<"Fichero ordenado\n"<<endl;
   mezcla->Mostrar(fichero);
   fclose(fichero);
   return 0;
}
