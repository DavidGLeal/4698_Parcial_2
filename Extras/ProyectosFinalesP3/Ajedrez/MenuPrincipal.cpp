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
#include "MenuGUI.hpp"
#include "Input.hpp"
#include "GlobalVariables.hpp"
#include "PDFManager.hpp"
#include "ConsoleDataInput.hpp"
#include <iostream>
#include "Imagen.h"
#include "play.hpp"

MenuGUI MenuPrincipal::menuGraphic;


bool MenuPrincipal::switchOption(int optionSelected) {
    switch (optionSelected) {
        case 1:
            printTree();
            break;
        case 2:
            printImage();    
            break;
        case 3:
            generatePDF();
            break;
        case 4:
            openHelp();
            break;
        case 5:
            signOut();
            return true;
            break;
    }

    return false;
}

void MenuPrincipal::printTree() {
    system("cls");
    play p;
    p.start();
    system("pause > nul");
}


void MenuPrincipal::printImage() {
    Imagen image;
     system("cls");
    image.Imagenes();
    system("pause>nul");
    //GlobalVariables::printImageAvailable = true;
}

void MenuPrincipal::generatePDF() {
    PDFManager pd;
    pd.generatePDF();
}

void MenuPrincipal::openHelp() {
    system("start Ajedrez.chm");
    system("pause > nul");
}

void MenuPrincipal::signOut() {

}

void MenuPrincipal::start() {
    menuGraphic.setTitleMenu("MENU PRINCIPAL");

    const size_t AMOUNT_OPTIONS{5};
    menuGraphic.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Abrir Ajedrez",
            "Imprimir imagen",
            "Generar PDF",
            "Ayuda",
            "Cerrar sesion"
        },
        AMOUNT_OPTIONS
    );

    menuGraphic.setPositionOfMenu({12, 5});

    bool exit{false};

    while (!exit) {
        exit = switchOption(menuGraphic.print());
    }
}
