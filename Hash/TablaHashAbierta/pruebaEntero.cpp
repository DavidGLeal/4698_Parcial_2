<<<<<<< Updated upstream:TablaHashAbierta/pruebaEntero.cpp
=======
/*
Autores: Shared Tinoco, Sebastian Torres.
Fecha de creacion: 26/06/2022
Fecha de modificacion: 29/06/2022
Grupo 10
Github del grupo: mstinoco@espe.edu.ec, sptorres1@espe.edu.ec
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

