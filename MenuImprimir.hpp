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

#ifndef MENU_IMPRIMIR_HPP
#define MENU_IMPRIMIR_HPP
#include "MenuGUI.cpp"
#include "Arbol.cpp"

class MenuImprimir {
    private:
        Arbol arbolAImprimir;
        const size_t cantidadDeOpciones{6};
        COORD ubicacion{12, 5};
        MenuGUI menuImprimir;

        bool determinarOpcion(int opcionSeleccionada);
        void impresionPreOrden();
        void impresionInOrden();
        void impresionPosOrden();
        void impresionAmplitud();
        void impresionModoGrafico();

    public:
        MenuImprimir(Arbol arbol);
        void start();
};

#endif
