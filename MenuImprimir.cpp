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

MenuImprimir::MenuImprimir(Arbol arbol) {
    this->arbolAImprimir = arbol;
    this->menuImprimir.setTitleMenu("MENU IMPRIMIR");
    this->menuImprimir.setListOptions(
        new std::string[this->cantidadDeOpciones]{
            "Pre-Orden",
            "In-Orden",
            "Post-Orden",
            "Amplitud",
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