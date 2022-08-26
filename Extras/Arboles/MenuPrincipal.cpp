#include "MenuPrincipal.hpp"
#include "MenuGUI.hpp"
#include "MenuBackup.hpp"
#include "Tree.hpp"
#include "Input.hpp"
#include "PrintTree.hpp"
#include "PrintBitMap.hpp"
#include "FileManager.hpp"
#include "PDFManager.hpp"
#include "ConsoleDataInput.hpp"
#include <iostream>

MenuGUI MenuPrincipal::menuGraphic;
Tree MenuPrincipal::binaryAVLTree;

bool MenuPrincipal::switchOption(int optionSelected) {
    switch (optionSelected) {
        case 1:
            insertValue();
            break;
        case 2:
            deleteValue();
            break;
        case 3:
            searchValue();
            break;
        case 4:
            printTree();
            break;
        case 5:
            startMenuBackup();
            break;
        case 6:
            printImage();
            break;
        case 7:
            generatePDF();
            break;
        case 8:
            openHelp();
            break;
        case 9:
            signOut();
            return true;
            break;
    }

    return false;
}

void MenuPrincipal::insertValue() {
    std::cout << "Ingresa valor entero a guardar: ";
    //binaryAVLTree.add(Input::integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS));
    int dato;
    ConsoleDataInput console;
    dato = console.integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS,45,16);
    binaryAVLTree.add(dato);

    if (FileManager::saveTree(binaryAVLTree))
        std::cout << "\nArbol guardado en txt con exito\n";
    else
        std::cout << "\nInformacion de arbol no guardada en txt\n";

    system("pause > nul");
}

void MenuPrincipal::deleteValue() {
    std::cout << "Ingresa valor entero a eliminar: ";
    //binaryAVLTree.remove(Input::integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS));
    
    int dato;
    ConsoleDataInput console;
    dato = console.integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS,45,16);
    binaryAVLTree.remove(dato);

    if (FileManager::saveTree(binaryAVLTree))
        std::cout << "\nArbol guardado en txt con exito\n";
    else
        std::cout << "\nInformacion de arbol no guardada en txt\n";

    system("pause > nul");
}

void MenuPrincipal::searchValue() {
    std::cout << "Ingresa valor entero a buscar: ";
    int dato;
    ConsoleDataInput console;
    dato = console.integerNumber(MINIMUM_DIGITS, MAXIMUM_DIGITS,45,16);

    std::cout << (binaryAVLTree.search(dato) ? "Valor encontrado" : "Valor no encontrado");
    system("pause > nul");
}

void MenuPrincipal::printTree() {
    system("cls");
    PrintTree::printGraphic(binaryAVLTree);
    system("pause > nul");
}

void MenuPrincipal::startMenuBackup() {
    MenuBackup::start(binaryAVLTree);
}

void MenuPrincipal::printImage() {
    const std::string BITMAP_FILE_NAME{"imagen.bmp"};
    PrintBitmap::printImage(BITMAP_FILE_NAME);
}

void MenuPrincipal::generatePDF() {
    PDFManager::generatePDF(binaryAVLTree);
}

void MenuPrincipal::openHelp() {
    system("start help.chm");
    system("pause > nul");
}

void MenuPrincipal::signOut() {

}

void MenuPrincipal::start() {
    menuGraphic.setTitleMenu("MENU PRINCIPAL");

    const size_t AMOUNT_OPTIONS{9};
    menuGraphic.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Insertar valor",
            "Eliminar valor",
            "Buscar valor",
            "Imprimir arbol",
            "Backup",
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
