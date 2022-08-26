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
