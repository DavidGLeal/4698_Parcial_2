#include "GameManager.hpp"
#include "GameLogic.hpp"
#include "ScoreTextFileManager.hpp"
#include "GameInformation.hpp"
#include "MenuGraphic.hpp"
#include "SettingsMenu.hpp"
#include "PrintBitMap.hpp"
#include "PDFGenerator.hpp"
#include <thread>
#include <chrono>

short GameManager::renderMainMenu() {
    MenuGraphic menu { "  Snake Game", Color::green };
    menu.setOptions(
        {
            " Iniciar juego",
            "Configuraciones",
            "    Backups",
            "    Grafico",
            "      PDF",
            "     Ayuda",
            "     Salir"
        }
    );
    menu.setSelectedOptionColor(Color::red);
    menu.setUnselectedOptionColor(Color::blue);
    menu.setPosition(Position{20, 5});

    return menu.render();
}

void GameManager::renderSettingsMenu() {
    SettingsMenu settings { Position{ 10, 5 } };
    settings.setTitleColor(Color::red);
    settings.setSelectedOptionColor(Color::green);
    settings.setUnselectedOptionColor(Color::yellow);
    settings.render();
}

void GameManager::startGame(const std::string& user) {
    bool gameOver{ false };
    bool gameCompleted{ false };

    GameLogic logic{};
    ScoreTextFileManager::saveUser(user);
    logic.renderScenary();
    while (!gameOver && !gameCompleted) {
        logic.moveSnake();
        
        gameOver = logic.snakeHasCollided();

        if (logic.hasLevelCompleted()) {
            ScoreTextFileManager::saveScore();
            gameCompleted = !logic.renderNextLevel();
        }

        if (gameOver)
            ScoreTextFileManager::saveScore();
    }

    ScoreTextFileManager::insertEndOfLine();
    ScoreTextFileManager::saveBackup();
    printf("\033[2J");
}

GameManager::GameManager() {
    marquee.setVerticalPosition(2);
}

void GameManager::start(const std::string& user) {
    const std::string title{"SNAKE GAME - " + user};
    marquee.setTitle(title);
    marquee.startExecution();
    
    bool exit{ false };
    
    std::thread worker(&Marquee::print, &marquee);
    worker.detach();

    while (!exit) {
        switch (renderMainMenu()) {
            case 1:
                startGame(user);
                break;
            
            case 2:
                renderSettingsMenu();
                break;

            case 3:
                ScoreTextFileManager::recoverBackup();
                break;

            case 4:
                marquee.pauseExecution();
                PrintBitmap::printImage("imagen.bmp");
                marquee.resumeExecution();
                break;

            case 5:
                marquee.pauseExecution();
                printf("\033[20;1H");
                PDFGenerator::generate(user);
                marquee.resumeExecution();
                break;

            case 6:
                system("start help.chm");
                break;

            default:
                exit = true;
                break;
        }
    }

    marquee.endExecution();
}