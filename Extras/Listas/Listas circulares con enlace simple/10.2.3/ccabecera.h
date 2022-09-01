#include <iostream>
#include "CCadena.h"
using namespace std;

int main() {
   lista<int> iLista;
   lista<float> fLista;
   lista<double> dLista;
   lista<char> cLista;
   lista<Cadena> sLista;

   // Prueba con <int>
   iLista.Insertar(20);
   iLista.Insertar(10);
   iLista.Insertar(40);
   iLista.Insertar(30);
   iLista.Insertar(60);

   iLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   iLista.Borrar(10);
   iLista.Borrar(30);

   iLista.Mostrar();

   // Prueba con <float>
   fLista.Insertar(20.01);
   fLista.Insertar(10.02);
   fLista.Insertar(40.03);
   fLista.Insertar(30.04);
   fLista.Insertar(60.05);

   fLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   fLista.Borrar(10.02);
   fLista.Borrar(30.04);

   fLista.Mostrar();

   // Prueba con <double>
   dLista.Insertar(0.0020);
   dLista.Insertar(0.0010);
   dLista.Insertar(0.0040);
   dLista.Insertar(0.0030);
   dLista.Insertar(0.0060);

   dLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   dLista.Borrar(0.0010);
   dLista.Borrar(0.0030);

   dLista.Mostrar();

   // Prueba con <char>
   cLista.Insertar('x');
   cLista.Insertar('y');
   cLista.Insertar('a');
   cLista.Insertar('b');
   cLista.Insertar('m');

   cLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   cLista.Borrar('y');
   cLista.Borrar('b');

   cLista.Mostrar();

   // Prueba con <Cadena>
   sLista.Insertar("Hola");
   sLista.Insertar("somos");
   sLista.Insertar("programadores");
   sLista.Insertar("buenos");
   sLista.Insertar("!!!!");

   sLista.Mostrar();

   cout << "Lista de elementos:" << endl;
   sLista.Borrar("somos");
   sLista.Borrar("buenos");

   sLista.Mostrar();

   cin.get();
   return 0;
}
