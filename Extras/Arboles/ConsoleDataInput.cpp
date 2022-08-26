/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file MenuBackup.hpp
 * @author Grupo 1 y 20
 * @brief Menu that manage backup files
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-13
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include "ConsoleDataInput.hpp"

void ConsoleDataInput::gotoXY(int x,int y){
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

int ConsoleDataInput::integerNumber(short minimumDigits, short maximumDigits,int x, int y) {
    if (minimumDigits <= 0 || maximumDigits >= 10)
        throw "DigitsOutOfBoundsException";

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        gotoXY(x+digitsAmount,y);
        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            
            if (*iterator != '-')
                digitsAmount--;

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

char *ConsoleDataInput::alphanumeric(short minimumCharacters, short maximumCharacters,int x, int y) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {
        gotoXY(x+sizeOfString,y);
        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumCharacters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalnum(keyPressed) && sizeOfString < maximumCharacters) {

            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    // Limpiando espacios en blanco despues del ultimo caracter alfabetico
    if (*(iterator - 1) == SPACE_KEY) {
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

char *ConsoleDataInput::word(short minimumCharacters, short maximumCharacters, int x, int y) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {
        gotoXY(x+sizeOfString,y);
        if (std::isalpha(keyPressed) && sizeOfString < maximumCharacters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}


char *ConsoleDataInput::digits(short minimumDigits, short maximumDigits,int x,int y) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        gotoXY(x+digitsAmount,y);
        if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return numbers;
}

char *ConsoleDataInput::alphanumeric_password(short minimumCharacters, short maximumCharacters,int x, int y) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {
        gotoXY(x+sizeOfString,y);
        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumCharacters) {
            printf("*", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalnum(keyPressed) && sizeOfString < maximumCharacters) {

            printf("*", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    // Limpiando espacios en blanco despues del ultimo caracter alfabetico
    if (*(iterator - 1) == SPACE_KEY) {
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

int ConsoleDataInput::unsignedIntegerNumber(short minimumDigits, short maximumDigits,int x,int y) {
    if (minimumDigits <= 0 || maximumDigits >= 10)
        throw "DigitsOutOfBoundsException";

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        gotoXY(x+digitsAmount,y);
        if (std::isdigit((keyPressed)) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}