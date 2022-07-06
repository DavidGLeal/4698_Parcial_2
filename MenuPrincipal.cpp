#include "MenuPrincipal.hpp"
// #include "MenuImprimir.hpp"
#include "Input.hpp"
#include "HandleConsole.hpp"
#include <iostream>

bool MenuPrincipal::determinarOpcion(size_t opcionSeleccionada) {
    
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

    std::cout << "Ingrese un numero entero a guardar en: ";
    int valor = Input::integerNumber(1, 4);

    HandleConsole::setCursorPosition(ubicacion.X, (ubicacion.Y + cantidadDeOpciones + 3));

    system("pause");
}

void MenuPrincipal::eliminar() {
    
    std::cout << "Ingrese un numero entero a eliminar: ";
    int valor = Input::integerNumber(1, 4);

    HandleConsole::setCursorPosition(ubicacion.X, (ubicacion.Y + cantidadDeOpciones + 3));

    system("pause");
}

void MenuPrincipal::buscar() {

    std::cout << "Ingrese un numero entero a buscar en el arbol: ";
    int valor = Input::integerNumber(1, 4);

    HandleConsole::setCursorPosition(ubicacion.X, (ubicacion.Y + cantidadDeOpciones + 3));

    system("pause");
}

MenuPrincipal::MenuPrincipal() {
    this->menuPrincipal.setTitleMenu("MENU PRINCIPAL");
    this->menuPrincipal.setListOptions(
        new std::string[this->cantidadDeOpciones]{
            "Ingresar",
            "Eliminar",
            "Buscar",
            "Imprimir",
            "Salir"
        },
        this->cantidadDeOpciones
    );
    this->menuPrincipal.setPositionOfMenu(this->ubicacion);
}

void MenuPrincipal::start() {
    bool exit{false};
    while (!exit) {
        exit = determinarOpcion(this->menuPrincipal.print());
    }
}