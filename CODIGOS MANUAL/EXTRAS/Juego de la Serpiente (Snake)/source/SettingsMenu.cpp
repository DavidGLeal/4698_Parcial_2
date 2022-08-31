#include "SettingsMenu.hpp"
#include <iostream>
#include <conio.h>

short SettingsMenu::maxStringSize() const {
    std::size_t max{};

    for (short i{}; i < size - 1; ++i) {
        if (options[i].size() > max)
            max = options[i].size();
    }

    return max;
}

void SettingsMenu::renderOption(const short option, const Color color) const {
    if (option >= size)
        printf("\033[%d;%dH\033[2K\033[38;5;%dm%s\033[0m", position.getY() + option, position.getX(), static_cast<unsigned short>(color), options[option - 1].c_str());
    else {
        const short spacing{10};
        printf("\033[%d;%dH\033[2K\033[38;5;%dm%-*s<%03d>\033[0m", position.getY() + option, position.getX(), static_cast<unsigned short>(color), maxStringSize() + spacing, options[option - 1].c_str(), *(values[option - 1]));
    }
    
}

void SettingsMenu::renderSelectedOption(const short option) const {
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

void SettingsMenu::renderScreen() const {
    printf("\033[%d;%dH\033[2K\033[38;5;%dm%s\033[0m", position.getY(), position.getX(), static_cast<unsigned short>(titleColor), title.c_str());
    renderOption(1, selectedOption);
    for (short i{2}; i <= size; ++i) {
        renderOption(i, unselectedOption);
    }
}

SettingsMenu::SettingsMenu(const Position& _position) : position{_position} {}

void SettingsMenu::setTitleColor(const Color color) {
    titleColor = color;
}

void SettingsMenu::setUnselectedOptionColor(const Color color) {
    unselectedOption = color;
}

void SettingsMenu::setSelectedOptionColor(const Color color) {
    selectedOption = color;
}

void SettingsMenu::render() {
    printf("\033[?25l\033[2J");
    renderScreen();
    const unsigned short enterKey{13};
    const unsigned short upKey{328};
    const unsigned short downKey{336};
    const unsigned short leftKey{331};
    const unsigned short rightKey{333};
    short currentOption{1};
    unsigned short keyPressed{};
    bool hasPressedEnter{ false };

    while (!hasPressedEnter) {
        while (!_kbhit()) {}

        keyPressed = _getch();
        hasPressedEnter = keyPressed == enterKey && currentOption == size;

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

            case leftKey:
                switch(currentOption) {
                    case 1:
                        if (GameInformation::level > 1)
                            --GameInformation::level;
                            
                        break;
                    case 2:
                        if (GameInformation::scoreForNextLevel > 1)
                            --GameInformation::scoreForNextLevel;

                        break;

                    case 3:
                        if (GameInformation::velocity > 1)
                            --GameInformation::velocity;
                        break;
                    
                }
                break;

            case rightKey:
                switch(currentOption) {
                    case 1:
                        if (GameInformation::level < GameInformation::levels)
                            ++GameInformation::level;

                        break;

                    case 2:
                        if (GameInformation::scoreForNextLevel < GameInformation::maxScore)
                            ++GameInformation::scoreForNextLevel;

                        break;
                    
                    case 3:
                        if (GameInformation::velocity < GameInformation::maxVelocity)
                            ++GameInformation::velocity;
                        break;
                }
                break;

        }

        renderSelectedOption(currentOption);
    }

    printf("\033[?25h");
}