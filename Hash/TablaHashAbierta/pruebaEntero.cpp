<<<<<<< Updated upstream:TablaHashAbierta/pruebaEntero.cpp
=======
/*
Autores: Johan Romo, Cristhopher Villamarín.
Fecha de creacion: 16/07/2022
Fecha de modificacion: 19/07/2022
Grupo 11
Github del grupo: jaromo3@espe.edu.ec, cavillamarin9@espe.edu.ec
*/

#include <iostream>
>>>>>>> Stashed changes:TablaHashAbierta/pruebas.cpp
#include "Hash.cpp"

#include <iostream>
using namespace std;

int main(){
    Hash nuevo;
    nuevo.insertarElemento(2);
    nuevo.insertarElemento(4);
    nuevo.insertarElemento(8);
    nuevo.insertarElemento(10);
    nuevo.insertarElemento(3);

    cout<<"Imprimido :3\n";
    nuevo.mostrarHash();
    nuevo.buscarElemento(4);
    nuevo.eliminarElemento(10);
    nuevo.mostrarHash();
    nuevo.insertarElemento(20);
    nuevo.mostrarHash();

}

