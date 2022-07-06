#include "MenuImprimir.hpp"

void MenuImprimir::start(Arbol *_arbol) {
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menu.start(), _arbol);
    }
}

bool MenuImprimir::determinarOpcion(int opcionSeleccionada, Arbol *_arbol) {
    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 2));
    switch (opcionSeleccionada) {
        case 1:
            impresionPreOrden(_arbol);
            break;

        case 2:
            impresionInOrden(_arbol);
            break;

        case 3:
            impresionPosOrden(_arbol);
            break;

        case 4:
            impresionAmplitud(_arbol);
            break;

        case 5:
            return true;
            break;
    }
    system("pause");
    return false;
}

void MenuImprimir::impresionPreOrden(Arbol *_arbol) {
    arbol->preOrden(arbol->getArbol());
}

void MenuImprimir::impresionInOrden(Arbol *_arbol) {
    arbol->inOrden(arbol->getArbol());
}

void MenuImprimir::impresionPosOrden(Arbol *_arbol) {
    arbol->postOrden(arbol->getArbol());
}

void MenuImprimir::impresionAmplitud(Arbol *_arbol) {
    arbol->recorridoNivel(arbol->getArbol());
}
