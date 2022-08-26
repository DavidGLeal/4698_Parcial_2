#include "Login.hpp"
#include "Input.hpp"
#include "UsersTextFileManager.hpp"
#include "MenuGraphic.hpp"
#include "GameManager.hpp"
#include <conio.h>

std::string Login::userName{};

bool Login::signUp() {
    const short x{15};
    const short y{10};
    bool tryAgain { true };
    bool userSaved { false };

    while (!userSaved && tryAgain) {
        printf("\033[%d;%dH\033[s\033[2KIngrese el nombre de usuario: ", y, x);
        std::string user { Input::word(1, 10) };
        printf("\033[u\033[2KIngrese la clave de usuario: ");
        std::string password { Input::password(5, 10) };

        if (!UsersTextFileManager::isNewUser(user)) {
            const unsigned char enterKey{13};
            printf("\033[u\033[2KUsuario ya existe, intertar otra vez? Si [ENTER], No [ESC]");
            tryAgain = getch() == enterKey;
        } else {
            userSaved = UsersTextFileManager::saveUser(user, password);
        }
    }

    return userSaved;
}

bool Login::signIn() {
    const short x{15};
    const short y{10};
    bool userFound{ false };
    bool tryAgain { true };

    while (!userFound && tryAgain) {
        printf("\033[%d;%dH\033[s\033[2KIngrese el nombre de usuario: ", y, x);
        std::string user { Input::word(1, 10) };
        printf("\033[u\033[2KIngrese la clave de usuario: ");
        std::string password { Input::password(5, 10) };

        userFound = UsersTextFileManager::findUser(user, password);

        if (!userFound) {
            const unsigned char enterKey{13};
            printf("\033[u\033[2KUsuario no existe, intertar otra vez? Si [ENTER], No [ESC]");
            tryAgain = getch() == enterKey;
        } else {
            userName = user;
        }
    }

    return userFound;
}

short Login::renderMenu() {
    MenuGraphic menuLogin{ "Inicio de sesion", Color::red };

    menuLogin.setPosition(Position{20, 5});
    menuLogin.setOptions(
        {
            " Iniciar sesion",
            "  Registrarse",
            "     Salir"
        }
    );
    menuLogin.setUnselectedOptionColor(Color::gray);
    menuLogin.setSelectedOptionColor(Color::yellow);

    return menuLogin.render();
}

void Login::render() {
    bool exit { false };
    GameManager snakeGame{};

    while (!exit) {
        switch (renderMenu()) {
            case 1:
                if (signIn())
                    snakeGame.start(userName);

                break;
            case 2:
                signUp();
                break;
            default:
                exit = true;
                break;
        }
    }
}