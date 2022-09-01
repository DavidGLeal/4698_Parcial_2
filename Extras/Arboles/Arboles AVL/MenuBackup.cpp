#include "MenuBackup.hpp"
#include "MenuGUI.hpp"
#include "FileManager.hpp"
#include "Tree.hpp"
#include "Input.hpp"
#include <iostream>

MenuGUI MenuBackup::menuGraphic;

bool MenuBackup::switchOption(int optionSelected, Tree &tree) {
    switch (optionSelected) {
        case 1:
            recoverBackup(tree);
            break;

        case 2:
            enableBackupGeneration();
            break;

        case 3:
            disableBackupGeneration();
            break;

        case 4:
            return true;
            break;
    }

    return false;
}

void MenuBackup::recoverBackup(Tree &tree) {
    system("cls");
    std::cout << "Listado de backups\n";
    system(" dir Backup_???????????????.txt");

    printf("Ingrese el a%co del backup: ", 164);
    int yearBackup{Input::unsignedIntegerNumber(4, 4)};

    std::cout << "Ingrese el mes del backup: ";
    int monthBackup{Input::unsignedIntegerNumber(1, 2)};

    std::cout << "Ingrese el dia del backup: ";
    int dayBackup{Input::unsignedIntegerNumber(1, 2)};

    std::cout << "Ingrese la hora del backup: ";
    int hourBackup{Input::unsignedIntegerNumber(1, 2)};

    std::cout << "Ingrese el minuto del backup: ";
    int minutBackup{Input::unsignedIntegerNumber(1, 2)};

    std::cout << "Ingrese el segundo del backup: ";
    int secondsBackup{Input::unsignedIntegerNumber(1, 2)};

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

    std::cout << ( isBackupRecovered ? "Backup recuperado" : "Backup no encontrado");

    system("pause > nul");
}

void MenuBackup::enableBackupGeneration() {
    FileManager::enableBackup();
    std::cout << "Backup activado";
    system("pause > nul");
}

void MenuBackup::disableBackupGeneration() {
    FileManager::disableBackup();
    std::cout << "Backup desactivado";
    system("pause > nul");
}

std::string MenuBackup::generateBackupFileName(int year, int month, int day, int hour, int minuts, int seconds) {
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

    const size_t AMOUNT_OPTIONS{4};
    menuGraphic.setListOptions(
        new std::string[AMOUNT_OPTIONS] {
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