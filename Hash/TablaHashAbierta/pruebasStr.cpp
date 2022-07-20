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

#include "HashStr.cpp"

#include <iostream>
using namespace std;

int main(){

    HashStr nuevo;
    cout<<"Holiss";
    nuevo.mensajito();
    nuevo.insertarElemento("ESPE");
    nuevo.insertarElemento("LOLA");
    nuevo.insertarElemento("HOLI");
    nuevo.insertarElemento("ALOL");
    nuevo.insertarElemento("EPSE");

    cout<<"Imprimido :3\n";
    nuevo.mostrarHash();
    nuevo.buscarElemento("ESPE");
    nuevo.eliminarElemento("EPSE");
    nuevo.mostrarHash();
    cout<<"Imprimido :3\n";
    nuevo.insertarElemento("LAAL");
    nuevo.mostrarHash();

}
