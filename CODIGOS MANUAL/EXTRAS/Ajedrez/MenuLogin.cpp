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
#include "MenuPrincipal.hpp"
#include "MenuLogin.hpp"
#include "MenuGUI.hpp"
#include "ConsoleDataInput.hpp"
#include "ValidateUser.hpp"
#include <string.h>
#include <iostream>
MenuGUI MenuLogin::innerMenuLogin;
const short MINIMUM_CHARACTERS{1};
const short MAXIMUM_CHARACTERS{15};
const short MAXIMUM_CHAR_IDS{10};

std::string MenuLogin::id;
std::string MenuLogin::password;

bool MenuLogin::switchOption(int selectedOption){
    switch (selectedOption) {
        case 1:
            enterUser();
            break;
        case 2:
            enterPassword();
            break;
        case 3:
            enterMainMenu();
        case 4:
            return true;
            break;
    }

    std::cout << std::endl;
    system("pause");
    return false;
}

void MenuLogin::enterUser(){
    std::cout << "Ingresa su usuario: ";
    ConsoleDataInput input;
    id = std::string{input.digits(MAXIMUM_CHAR_IDS,MAXIMUM_CHAR_IDS,31,11)};
}

void MenuLogin::enterPassword(){ 
    std::cout << "Ingresa su clave: ";
    ConsoleDataInput input;
    password = std::string{input.alphanumeric_password(MINIMUM_CHARACTERS,MAXIMUM_CHARACTERS,30,11)};
}

void MenuLogin::enterMainMenu(){

    if((ValidateUser::validate_Login(id,password))){
        MenuPrincipal::start();
    }else{
        std::cout<<"Usuario o clave incorrecto";
    }
    
}
void MenuLogin::start() {
    innerMenuLogin.setTitleMenu("INICIAR SESION");

    const size_t AMOUNT_OPTIONS{4};
    innerMenuLogin.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Ingresar Usuario",
            "Ingresar Clave",
            "Iniciar Sesion",
            "Regresar"
        },
        AMOUNT_OPTIONS
    );

    innerMenuLogin.setPositionOfMenu({12, 5});

    bool exit{false};
    while (!exit) {
        exit = switchOption(innerMenuLogin.print());
    }
}
