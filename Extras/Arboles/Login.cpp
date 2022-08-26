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

#include "Login.hpp"
#include "MenuGUI.hpp"
#include "MenuLogin.hpp"
#include "MenuSignup.hpp"

#include <iostream>

MenuGUI Login::menuLogin;

bool Login::switchOption(int selectedOption){
    switch (selectedOption) {
        case 1:
            loginMenu();
            break;
        case 2:
            signUpMenu();
            break;
        case 3:
            exit(1);
            break;
    }

    std::cout << std::endl;
    system("pause");
    return false;
}

void Login::loginMenu(){
    MenuLogin::start();
}

void Login::signUpMenu(){ 
    MenuSignup::start();
}

void Login::start() {
    menuLogin.setTitleMenu("Bienvenido");

    const size_t AMOUNT_OPTIONS{3};
    menuLogin.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Iniciar Sesion",
            "Crear Cuenta",
            "Salir"
        },
        AMOUNT_OPTIONS
    );

    menuLogin.setPositionOfMenu({12, 5});

    bool exit{false};
    while (!exit) {
        exit = switchOption(menuLogin.print());
    }
}