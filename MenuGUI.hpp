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

#ifndef MENU_GUI_HPP
#define MENU_GUI_HPP

#include <windows.h>
#include <string>

class MenuGUI {
    private:
        COORD menuPosition{4, 4};
        COORD arrowPosition{static_cast<SHORT>(this->menuPosition.X - 2), this->menuPosition.Y};
        const std::string *options{nullptr};
        std::string title{};
        size_t sizeOfArrayOptions{};
        size_t activeOption{1};

        void printOptions();
        void printArrow();
        void setNextOption();
        void setPreviousOption();
        bool switchOption(int keyPressed);

    public:
        MenuGUI() = default;
        void setTitleMenu(const std::string &newTitleOfMenu);
        void setListOptions(const std::string newListOptions[], size_t newSizeOfArrayOptions);
        void setPositionOfMenu(const COORD &newPositionOfMenu);
        int print();
};

#endif
