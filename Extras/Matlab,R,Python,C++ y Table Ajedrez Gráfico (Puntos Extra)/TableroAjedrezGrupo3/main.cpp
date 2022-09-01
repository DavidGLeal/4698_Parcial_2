/*
	Universidad de las Fuerzas Armadas "ESPE"
	Deber tablero de ajedrez.
	Arias Sebastián, Escobar David, Portilla Diego, Valdiviezo Darwin, Yánez Michelle
	Fecha de creación: 05/08/2022
	Fecha de modificación: 07/08/2022
	Grupo 8
	https://github.com/EscobarDavid/Grupo3P
*/

#include "Header.h"
#include "CTabla.h"
#include "CTabla.cpp"
#include "CPieza.h"
#include "CPieza.cpp"
#include "CPieza_Hijas.h"
#include "CPieza_Hijas.cpp"




CTabla tablero;


int main() {
    cout << "\t\t\t\tBienvenido al juego del ajedrez" << endl;
    cout << "La parte posterior del tablero corresponde a las piezas Negras y la parte inferior a las Blancas" << endl;
    tablero.imprimirTabla();
    return 0;
  
}