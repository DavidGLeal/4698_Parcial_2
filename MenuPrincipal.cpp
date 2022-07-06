#include "MenuPrincipal.hpp"
#include "MenuImprimir.cpp"
#include "Input.cpp"
#include <iostream>

MenuPrincipal menu;
int main()
{
    menu.start();
    return 0;
}

void MenuPrincipal::start() {
    this->arbol.setArbol(this->raiz);
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menu.start());
    }
}

bool MenuPrincipal::determinarOpcion(int opcionSeleccionada) {
    MenuImprimir menuImprimir;
    switch (opcionSeleccionada) {
        case 1:
            agregar();
            break;

        case 2:
            eliminar();
            break;

        case 3:
            buscar();
            break;

        case 4:
            this->arbol.setArbol(this->raiz); // Es necesario refactorizar al árbol con su nodo raíz.
            menuImprimir.start(arbol);
            break;

        case 5:
            return true;
            break;
    }

    return false;
}

void MenuPrincipal::agregar() {
    
    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 2));

    std::cout << "Ingrese un numero entero a guardar en el arbol: ";
    int valor = Input::integerNumber(1, 4);

    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 3));
    this->arbol.insertarNodo(this->raiz, valor);

    system("pause");
}

void MenuPrincipal::eliminar() {
    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 2));
    
    std::cout << "Ingrese un numero entero a eliminar del arbol: ";
    int valor = Input::integerNumber(1, 4);

    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 3));
    this->arbol.eliminarNodo(this->raiz, valor);

    system("pause");
}

void MenuPrincipal::buscar() {
    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 2));

    std::cout << "Ingrese un numero entero a buscar en el arbol: ";
    int valor = Input::integerNumber(1, 4);

    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 3));
    this->arbol.buscar(this->raiz, valor);

    system("pause");
}