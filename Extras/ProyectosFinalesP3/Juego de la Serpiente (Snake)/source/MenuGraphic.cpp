#include "MenuGraphic.hpp"
#include <conio.h>
#include <iostream>

void MenuGraphic::deleteOptions() {
    if (options != nullptr) {
        delete[] options;
        options = nullptr;
    }
}

void MenuGraphic::renderOption(const short option, const Color color) const {
    printf("\033[%d;%dH\033[2K\033[38;5;%dm%s\033[0m", position.getY() + option, position.getX(), static_cast<unsigned short>(color), options[option - 1].c_str());
}

void MenuGraphic::renderSelectedOption(const short option) const {
    if (option - 2 >= 0)
        renderOption(option - 1, unselectedOption);
    else
        renderOption(size, unselectedOption);

    renderOption(option, selectedOption);

    if (option < size)
        renderOption(option + 1, unselectedOption);
    else
        renderOption(1, unselectedOption);
}

void MenuGraphic::renderScreen() {
    printf("\033[%d;%dH\033[2K\033[38;5;%dm%s\033[0m", position.getY(), position.getX(), static_cast<unsigned short>(titleColor), title.c_str());
    renderOption(1, selectedOption);
    for (short i{2}; i <= size; ++i) {
        renderOption(i, unselectedOption);
    }
}

MenuGraphic::MenuGraphic(const std::string& _title, const Color color) : title{_title}, titleColor{color} {}

void MenuGraphic::setPosition(const Position& _position) {
    position = _position;
}

void MenuGraphic::setOptions(std::initializer_list<std::string> _options) {
    deleteOptions();

    size = _options.size();

    if (size > 0)
        options = new std::string[size]{};

    short i{};
    for (const auto& option : _options) {
        options[i] = option;
        ++i;
    }

}

void MenuGraphic::setOptions(const ArrayList<std::string>& _options) {
    deleteOptions();
    size = _options.size();

    if (size > 0)
        options = new std::string[size]{};

    short i{};
    for (const auto& option : _options) {
        options[i] = option;
        ++i;
    }
}

void MenuGraphic::setUnselectedOptionColor(const Color color) {
    unselectedOption = color;
}

void MenuGraphic::setSelectedOptionColor(const Color color) {
    selectedOption = color;
}

short MenuGraphic::render() {
    printf("\033[?25l\033[2J");
    renderScreen();
    const unsigned short enterKey{13};
    const unsigned short upKey{328};
    const unsigned short downKey{336};
    short currentOption{1};
    unsigned short keyPressed{};
    bool hasPressedEnter{ false };

    while (!hasPressedEnter) {
        while (!_kbhit()) {}

        keyPressed = _getch();
        hasPressedEnter = keyPressed == enterKey;

        if (keyPressed == 0 || keyPressed == 224)
            keyPressed = 256 + _getch();

        switch (keyPressed) {
            case upKey:
                --currentOption;

                if (currentOption < 1)
                    currentOption = size;

                break;

            case downKey:
                ++currentOption;

                if (currentOption > size)
                    currentOption = 1;

                break;
        }

        renderSelectedOption(currentOption);
    }

    printf("\033[?25h");

    return currentOption;
}

MenuGraphic::~MenuGraphic() {
    deleteOptions();
}