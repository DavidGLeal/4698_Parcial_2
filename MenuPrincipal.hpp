/*
	*Universidad de las Fuerzas Armadas "ESPE"
        *Enunciado del problema:
	*Realizar un pograma de manejo de árboles binarios con todas sus funciones.
        *Autores:
	*Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 04-07-2022
	*Fecha de modificacion:
        * 08-07-2022
        *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Parcial_2
*/

#ifndef MENU_PRINCIPAL_HPP
#define MENU_PRINCIPAL_HPP

#include "MenuGUI.cpp"
#include "Arbol.cpp"

class MenuPrincipal {
    private:
        const COORD ubicacion{12, 5};
        const size_t cantidadDeOpciones{5};
        MenuGUI menuPrincipal;
        Arbol arbol;
        Nodo *raiz{nullptr};

        bool determinarOpcion(size_t opcionSeleccionada);
        void agregar();
        void eliminar();
        void buscar();

    public:
        MenuPrincipal();
        void start();
};

#endif
