#include "MenuPrincipal.hpp"
#include "Input.cpp"
#include "HandleConsole.cpp"
#include <iostream>

void MenuPrincipal::start() {
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menu.start());
    }
}

bool MenuPrincipal::determinarOpcion(int opcionSeleccionada) {
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
    std::cout << "\n\nValor : " << valor;
    system("pause");
}

void MenuPrincipal::eliminar() {
    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 2));
    std::cout << "Ingrese un numero entero a eliminar del arbol: ";
    int valor = Input::integerNumber(1, 4);
    std::cout << "\n\nValor : " << valor;
    system("pause");
    
}

void MenuPrincipal::buscar() {
    HandleConsole::setCursorPosition(this->ubicacion.X, (this->ubicacion.Y + this->cantidadDeOpciones + 2));
    std::cout << "Ingrese un numero entero a buscar en el arbol: ";
    int valor = Input::integerNumber(1, 4);
    std::cout << "\n\nValor : " << valor;
    system("pause");
}

// Arbol &MenuPrincipal::getArbol() {
//     return this->arbol;
// }