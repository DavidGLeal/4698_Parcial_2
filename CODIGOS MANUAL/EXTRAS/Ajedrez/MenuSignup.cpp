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

#include "MenuSignup.hpp"
#include "MenuGUI.hpp"
#include "ConsoleDataInput.hpp"
#include "ValidateUser.hpp"
#include "IdVerificator.hpp"
#include <string.h>
#include <iostream>
const short MINIMUM_CHARACTERS{1};
const short MAXIMUM_CHARACTERS{15};
const short MAXIMUM_CHAR_IDS{10};

MenuGUI MenuSignup::innerMenuSignup;
std::string MenuSignup::name;
std::string MenuSignup::lastname;
std::string MenuSignup::id;
std::string MenuSignup::password;

bool MenuSignup::switchOption(int selectedOption){
    switch (selectedOption) {
        case 1:
            registerName();
            break;
        case 2:
            registerLastName();
            break;
        case 3:
            registerPassword();
            break;
        case 4:
            registerID();
            break;
        case 5:
            createAccount();
        case 6:
            return true;
            break;
    }

    std::cout << std::endl;
    system("pause");
    return false;
}

void MenuSignup::registerName(){
    std::cout << "Ingresa su Nombre: ";
    ConsoleDataInput input;
    name = std::string{input.word(MINIMUM_CHARACTERS,MAXIMUM_CHARACTERS,31,13)};
}

void MenuSignup::registerLastName(){ 
    std::cout << "Ingresa su Apellido: ";
    ConsoleDataInput input;
    lastname = std::string{input.word(MINIMUM_CHARACTERS,MAXIMUM_CHARACTERS,33,13)};
}

void MenuSignup::registerPassword(){
    std::cout << "Ingresa su Clave: ";
    ConsoleDataInput input;
    password = std::string{input.alphanumeric(MINIMUM_CHARACTERS,MAXIMUM_CHARACTERS,33,13)};
}
void MenuSignup::registerID(){
    std::cout << "Ingresa su Cedula: ";
    ConsoleDataInput input;
    id = std::string{input.digits(MAXIMUM_CHAR_IDS,MAXIMUM_CHAR_IDS,33,13)};
}
void MenuSignup::createAccount(){
    if(IdVerificator::isValid(id)){
        if(!ValidateUser::validate_UserName(id)){
        ValidateUser::Register_Data(name,lastname,id,password);
        }else{
            std::cout<<"El usuario ya esta registrado";
        }
    }else{
        std::cout<<"La cedula es incorrecta";
    }
}

void MenuSignup::start() {
    innerMenuSignup.setTitleMenu("MENU REGISTRO");

    const size_t AMOUNT_OPTIONS{6};
    innerMenuSignup.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Ingresar Nombre",
            "Ingresar Apellido",
            "Ingresar Clave",
            "Ingresar Cedula",
            "Crear Cuenta",
            "Regresar"
        },
        AMOUNT_OPTIONS
    );

    innerMenuSignup.setPositionOfMenu({12, 5});

    bool exit{false};
    while (!exit) {
        exit = switchOption(innerMenuSignup.print());
    }
}
