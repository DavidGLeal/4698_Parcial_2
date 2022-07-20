<<<<<<< Updated upstream:TablaHashAbierta/pruebaEntero.cpp
=======
/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize hash abierto.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 15-07-2022
	*Fecha de modificacion:
        * 19-07-2022
    *GitHub del grupo:	
        https://github.com/DavidGLeal/4698_Parcial_2/tree/Codigos_proyecto/Hash/TablaHashAbierta
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

