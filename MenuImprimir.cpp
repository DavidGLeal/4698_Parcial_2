#include "MenuImprimir.hpp"

void MenuImprimir::start(Arbol &_arbol) {
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menu.start(), &_arbol);
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
    cout << "\n" <<endl;
    system("pause");
    return false;
}

void MenuImprimir::impresionPreOrden(Arbol *&_arbol) { // Para los métodos, es necesario recibir los punteros por referencia.
    _arbol->preOrden(_arbol->getArbol());
}

void MenuImprimir::impresionInOrden(Arbol *&_arbol) {
    _arbol->inOrden(_arbol->getArbol());
}

void MenuImprimir::impresionPosOrden(Arbol *&_arbol) {
    _arbol->postOrden(_arbol->getArbol());
}

void MenuImprimir::impresionAmplitud(Arbol *&_arbol) {
    _arbol->recorridoNivel(_arbol->getArbol());
}
