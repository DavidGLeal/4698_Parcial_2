/*UFA-ESPE
* Deber 6
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 01/06/2022
* Fecha de modificación 02/06/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
class ListaDoble{
	private:
		Nodo *primero;
		Nodo *actual;
		bool ListaVacia(){
			return (this->primero==NULL);
		}
	public:
		ListaDoble();
		~ListaDoble();
		virtual	void insertarCabeza(int);
		virtual void insertarCola(int);
		virtual void insertarEntre();
		virtual void buscar();
		virtual void mostrarCabeza(int);
		virtual void eliminarCabeza();
		virtual void eliminarCola();
		virtual void eliminarEntre();
		virtual int ingresoDatosEnteros();
		virtual void insertarColaEnteros();
		virtual void insertarCabezaEnteros();
		virtual int sizeLista();
	};
	                    