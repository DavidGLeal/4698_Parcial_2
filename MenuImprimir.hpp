#ifndef MENU_IMPRIMIR_HPP
#define MENU_IMPRIMIR_HPP

#include "Arbol.h"

class MenuImprimir {
    private:
        Arbol *arbol{nullptr};
        const std::string titulo{"MENU IMPRIMIR"};
        static constexpr size_t cantidadDeOpciones{5};
        std::string opciones[cantidadDeOpciones]{
            "1. Pre-Orden",
            "2. In-Orden",
            "3. Pos-Orden",
            "4. Amplitud",
            "5. Regresar"
        };
        COORD ubicacion{12, 5};
        MenuGUI menu = MenuGUI(titulo, opciones, cantidadDeOpciones, ubicacion);

        bool determinarOpcion(int opcionSeleccionada, Arbol *_arbol);
        void impresionPreOrden(Arbol *_arbol);
        void impresionInOrden(Arbol *_arbol);
        void impresionPosOrden(Arbol *_arbol);
        void impresionAmplitud(Arbol *_arbol);

    public:
        void start(Arbol *_arbol);
};

#endif