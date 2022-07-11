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

#pragma once
#include "MenuImprimir.hpp"
#include "HandleConsole.cpp"

bool MenuImprimir::determinarOpcion(int opcionSeleccionada) {
    switch (opcionSeleccionada) {
        case 1:
            impresionPreOrden();
            break;

        case 2:
            impresionInOrden();
            break;

        case 3:
            impresionPosOrden();
            break;

        case 4:
            impresionAmplitud();
            break;

        case 5:
            impresionModoGrafico();
            break;

        case 6:
            return true;
            break;
    }

    std::cout << std::endl;
    system("pause");
    return false;
}

void MenuImprimir::impresionPreOrden() {
    std::cout << "Impresion PreOrden: ";
    this->arbolAImprimir.preOrden(this->arbolAImprimir.getArbol());
}

void MenuImprimir::impresionInOrden() {
    std::cout << "Impresion InOrden: ";
    this->arbolAImprimir.inOrden(this->arbolAImprimir.getArbol());
}

void MenuImprimir::impresionPosOrden() {
    std::cout << "Impresion PosOrden: ";
    this->arbolAImprimir.postOrden(this->arbolAImprimir.getArbol());
}

void MenuImprimir::impresionAmplitud() {
    std::cout << "Impresion Amplitud: ";
    this->arbolAImprimir.recorridoNivel(this->arbolAImprimir.getArbol());
}

void MenuImprimir::impresionModoGrafico() {
    std::cout << "Impresion Grafica:\n";
    this->arbolAImprimir.mostrar(this->arbolAImprimir.getArbol(), 0);
}

MenuImprimir::MenuImprimir(Arbol arbol) {
    this->arbolAImprimir = arbol;
    this->menuImprimir.setTitleMenu("MENU IMPRIMIR");
    this->menuImprimir.setListOptions(
        new std::string[this->cantidadDeOpciones]{
            "Pre-Orden",
            "In-Orden",
            "Post-Orden",
            "Amplitud",
            "Grafico",
            "Regresar"
        },
        this->cantidadDeOpciones
    );
    this->menuImprimir.setPositionOfMenu(this->ubicacion);
}

void MenuImprimir::start() {
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menuImprimir.print());
    }
}
