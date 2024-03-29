#include "Input.hpp"
#include <iostream>
#include <conio.h>

int Input::unsignedIntegerNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 10)
        throw "DigitsOutOfBoundsException";

    const char enterKey{13};
    const char backSpaceKey{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != enterKey || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (std::isdigit((keyPressed)) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == backSpaceKey && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

double Input::unsignedRealNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 15)
        throw "DigitsOutOfBoundsException";


    const char enterKey{13};
    const char backSpaceKey{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    while ((keyPressed = getch()) != enterKey || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == backSpaceKey && iterator != numbers) {
            printf("\b \b");

            iterator--;

            if (*iterator == '.') {
                hasEnteredADot = false;
            } else {
                digitsAmount--;
            }

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

int Input::integerNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 10)
        throw "DigitsOutOfBoundsException";

    const char enterKey{13};
    const char backSpaceKey{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != enterKey || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == backSpaceKey && iterator != numbers) {
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

double Input::realNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 15)
        throw "DigitsOutOfBoundsException";

    const char enterKey{13};
    const char backSpaceKey{8};

    char *numbers = new char[maximumDigits + 3]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    
    while ((keyPressed = getch()) != enterKey || *numbers == '\0' || digitsAmount < minimumDigits) {

        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == backSpaceKey && iterator != numbers) {
            printf("\b \b");

            iterator--;
            
            if (*iterator == '.') {
                hasEnteredADot = false;
            } else if (*iterator != '-') {
                digitsAmount--;
            }


            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

std::string Input::word(short minimumCharacters, short maximumCharacters) {
    const char enterKey{13};
    const char backSpaceKey{8};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != enterKey || *string == '\0' || sizeOfString < minimumCharacters) {

        if (std::isalpha(keyPressed) && sizeOfString < maximumCharacters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == backSpaceKey && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

std::string Input::digits(short minimumDigits, short maximumDigits) {
    const char enterKey{13};
    const char backSpaceKey{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != enterKey || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == backSpaceKey && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return numbers;
}

std::string Input::alphabetic(short minimumLetters, short maximumLetters) {
    const char enterKey{13};
    const char backSpaceKey{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumLetters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != enterKey || *string == '\0' || sizeOfString < minimumLetters) {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumLetters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalpha(keyPressed) && sizeOfString < maximumLetters) {

            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == backSpaceKey && iterator != string) {
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

std::string Input::alphanumeric(short minimumCharacters, short maximumCharacters) {
    const char enterKey{13};
    const char backSpaceKey{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != enterKey || *string == '\0' || sizeOfString < minimumCharacters) {

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

        } else if (keyPressed == backSpaceKey && iterator != string) {
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

std::string Input::password(short minimumCharacters, short maximumCharacters) {
    const char enterKey{13};
    const char backSpaceKey{8};

    char* string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char* iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != enterKey || *string == '\0' || sizeOfString < minimumCharacters) {

        if (std::isalnum(keyPressed) && sizeOfString < maximumCharacters) {

            printf("*");

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == backSpaceKey && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}