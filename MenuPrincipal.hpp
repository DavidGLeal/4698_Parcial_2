#ifndef MENU_PRINCIPAL_HPP
#define MENU_PRINCIPAL_HPP

#include "MenuGUI.hpp"

class MenuPrincipal {
    private:
        const COORD ubicacion{12, 5};
        const size_t cantidadDeOpciones{5};
        MenuGUI menuPrincipal;

        bool determinarOpcion(size_t opcionSeleccionada);
        void agregar();
        void eliminar();
        void buscar();

    public:
        MenuPrincipal();
        void start();
};

#endif