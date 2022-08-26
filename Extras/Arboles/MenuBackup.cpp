#include "MenuBackup.hpp"
#include "MenuGUI.hpp"
#include "FileManager.hpp"
#include "ConsoleDataInput.hpp"
#include "Tree.hpp"
#include "Input.hpp"
#include <iostream>

MenuGUI MenuBackup::menuGraphic;

bool MenuBackup::switchOption(int optionSelected, Tree &tree) {
    switch (optionSelected) {
        case 1:
            viewBackupList();
            break;

        case 2:
            recoverBackup(tree);
            break;

        case 3:
            enableBackupGeneration();
            break;

        case 4:
            disableBackupGeneration();
            break;

        case 5:
            return true;
            break;
    }

    return false;
}

void MenuBackup::viewBackupList() {
    system("cls");
    std::cout << "\n\n\nListado de backups\n";
    system(" dir Backup_???????????????.txt");
    system("pause > nul");
}

void MenuBackup::recoverBackup(Tree &tree) {
    system("cls");
    ConsoleDataInput input;
    input.gotoXY(12,5);

    printf("Ingrese el a%co del backup: ", 164);
    int yearBackup{input.unsignedIntegerNumber(4, 4,39,5)};
    input.gotoXY(12,6);
    std::cout << "Ingrese el mes del backup: ";
    int monthBackup{input.unsignedIntegerNumber(1, 2,39,6)};
    input.gotoXY(12,7);
    std::cout << "Ingrese el dia del backup: ";
    int dayBackup{input.unsignedIntegerNumber(1, 2,39,7)};
    input.gotoXY(12,8);
    std::cout << "Ingrese la hora del backup: ";
    int hourBackup{input.unsignedIntegerNumber(1, 2,40,8)};
    input.gotoXY(12,9);
    std::cout << "Ingrese el minuto del backup: ";
    int minutBackup{input.unsignedIntegerNumber(1, 2,42,9)};
    input.gotoXY(12,10);
    std::cout << "Ingrese el segundo del backup: ";
    int secondsBackup{input.unsignedIntegerNumber(1, 2,43,10)};

    bool isBackupRecovered = FileManager::loadBackup(generateBackupFileName(
            yearBackup,
            monthBackup,
            dayBackup,
            hourBackup,
            minutBackup,
            secondsBackup
        )
    );

    if (isBackupRecovered)
        tree = FileManager::loadTreeInformation();
    input.gotoXY(1,18);
    std::cout << ( isBackupRecovered ? "Backup recuperado" : "Backup no encontrado");

    system("pause > nul");
}

void MenuBackup::enableBackupGeneration() {
    ConsoleDataInput input;
    input.gotoXY(1,15);
    FileManager::enableBackup();
    std::cout << "Backup activado";
    system("pause > nul");
}

void MenuBackup::disableBackupGeneration() {
    ConsoleDataInput input;
    input.gotoXY(1,15);
    FileManager::disableBackup();
    std::cout << "Backup desactivado";
    system("pause > nul");
}

std::string MenuBackup::generateBackupFileName(int year, int month, int day, int hour, int minuts, int seconds) {
    ConsoleDataInput input;
    input.gotoXY(1,18);
    return std::string{"Backup_" +
                       std::to_string(year) +
                       std::to_string(month) +
                       std::to_string(day) +
                       "-" +
                       std::to_string(hour) +
                       std::to_string(minuts) +
                       std::to_string(seconds)};
}

void MenuBackup::start(Tree &tree) {
    menuGraphic.setTitleMenu("MENU BACKUP");

    const size_t AMOUNT_OPTIONS{5};
    menuGraphic.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
            "Mostrar listado de backups",
            "Recuperar backup",
            "Activar generacion backup",
            "Desactivar generacion de backup",
            "Regresar"
        },
        AMOUNT_OPTIONS
    );

    menuGraphic.setPositionOfMenu({12, 5});

    bool exit{false};
    while (!exit) {
        exit = switchOption(menuGraphic.print(), tree);
    }
}