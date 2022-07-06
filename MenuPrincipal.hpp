#ifndef MENU_PRINCIPAL_HPP
#define MENU_PRINCIPAL_HPP

#include "MenuGUI.cpp"
#include "Arbol.cpp"

class MenuPrincipal {
    private:
        Nodo *raiz{nullptr};
        Arbol arbol;
        const std::string titulo{"MENU PRINCIPAL"};
        static constexpr size_t cantidadDeOpciones{5};
        std::string opciones[cantidadDeOpciones]{
            "1. Agregar",
            "2. Eliminar",
            "3. Buscar",
            "4. Imprimir",
            "5. Salir"
        };
        COORD ubicacion{12, 5};
        MenuGUI menu = MenuGUI(titulo, opciones, cantidadDeOpciones, ubicacion);
        bool determinarOpcion(int opcionSeleccionada);
        void agregar();
        void eliminar();
        void buscar();

    public:
        void start();
};

#endif