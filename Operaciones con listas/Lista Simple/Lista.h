/*UFA-ESPE
* Deber 5
* Autores: Iza Christopher- Rea Denise
* Fecha de creación 25/05/2022
* Fecha de modificación 30/05/2022
* Grupo 20
* github del grupo @dnrea@espe.edu.ec @cdiza5@espe.edu.ec
*/
#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		Nodo *primero;
		Nodo *actual;
		bool ListaVacia(){
			return (this->primero==NULL);
		}
	public:
		 
		Lista();
		~Lista();
		virtual	void insertarCabeza(int);
		virtual void insertarCola(int);
		virtual void mostrarCola();
		virtual void mostrarCabeza();
		virtual void recorrido(Nodo*);
		virtual void buscar();
		virtual void eliminarCabeza();
		virtual void eliminarCola();
		virtual int sizeLista();
		virtual int ingresoDatosEnteros();
		virtual void insertarColaEnteros();
		virtual void insertarCabezaEnteros();
		
	};
	                    