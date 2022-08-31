/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca de Veintemilla
				Kevin Vargas 
                Cristopher Iza
                Denisse Rea
					
	FECHA DE CREACION:        20-05-2022 	
	FECHA DE MODIFICACION:    24-05-2022
	Grupo #6
*/
#include "MenuGUI.hpp"
#include "HandleConsole.hpp"
#include <conio.h>
#include <iostream>

MenuGUI::MenuGUI(const std::string &title, const std::string arrayOptions[], size_t amountOptions, const COORD &positionXY) {
    setTitleMenu(title);
    setListOptions(arrayOptions, amountOptions);
    setPositionOfMenu(positionXY);
}

void MenuGUI::printOptions() {
    system("cls");
    HandleConsole::setCursorVisibilitie(false);
    HandleConsole::setCursorPosition(this->menuPosition.X + 1, this->menuPosition.Y);
    std::cout << title;
    for (size_t option{1}; option <= sizeOfArrayOptions; option++) {
        HandleConsole::setCursorPosition(this->menuPosition.X, (this->menuPosition.Y + option));
        std::cout << ' ' << options[option - 1];
    }
}

void MenuGUI::printArrow() {
    for (size_t option{1}; option <= sizeOfArrayOptions; option++) {
        HandleConsole::setCursorPosition(arrowPosition.X, (this->arrowPosition.Y + option));
        std::cout << ((option == this->activeOption) ? "->" : "  ");
    }
}

void MenuGUI::setNextOption() {
    this->activeOption++;

    if (this->activeOption > this->sizeOfArrayOptions)
        this->activeOption = 1;
}

void MenuGUI::setPreviousOption() {
    this->activeOption--;

    if (this->activeOption <= 0)
        this->activeOption = this->sizeOfArrayOptions;
}


bool MenuGUI::switchOption(int keyPressed) {
    const short UP_KEY{72};
    const short DOWN_KEY{80};
    const short ENTER_KEY{13};

    switch (keyPressed) {
        case UP_KEY:
            setPreviousOption();
            break;
        case DOWN_KEY:
            setNextOption();
            break;
        case ENTER_KEY:
            return true;
    }

    return false;
}

void MenuGUI::setTitleMenu(const std::string &newTitleOfMenu) {
    this->title = newTitleOfMenu;
}

void MenuGUI::setListOptions(const std::string newListOptions[], size_t newSizeOfArrayOptions) {
    this->options = newListOptions;
    this->sizeOfArrayOptions = newSizeOfArrayOptions;
}

void MenuGUI::setPositionOfMenu(const COORD &newPositionOfMenu) {
    this->menuPosition.X = newPositionOfMenu.X;
    this->menuPosition.Y = newPositionOfMenu.Y;
    this->arrowPosition.X = this->menuPosition.X - 2;
    this->arrowPosition.Y = this->menuPosition.Y;
}

int MenuGUI::print() {
    printOptions();

    bool exit{false};
    do {
        printArrow();
        while (!kbhit()) {}
        exit = switchOption(getch());
    } while (!exit);

    HandleConsole::setCursorVisibilitie(true);
    HandleConsole::setCursorPosition(this->menuPosition.X, (this->menuPosition.Y + this->sizeOfArrayOptions + 2));
    return this->activeOption;
}
