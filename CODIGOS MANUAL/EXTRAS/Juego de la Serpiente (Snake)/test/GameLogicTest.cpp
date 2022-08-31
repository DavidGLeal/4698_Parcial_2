#include "..\source\GameLogic.hpp"
#include "..\source\GameInformation.hpp"
#include <iostream>
#include <windows.h>

/* void renderScenary() {
    GameLogic game{};
    game.renderScenary(1);
    system("pause > nul");

    game.renderScenary(2);
    system("pause > nul");
    
    game.renderScenary(3);
} */

/* void snakeMovement() {
    GameLogic game{};
    game.renderScenary(1);

    short score{};
    bool snakeMoved{true};
    while (score < 5 && snakeMoved) {
        snakeMoved = game.moveSnake();
        if (snakeMoved) {
            score = game.verifyIfSnakeAte();
        }
        Sleep(200);
    }
} */

/* void levelUp() {
    GameLogic game{};

    short score{};
    short scoreForNextLevel{30};
    short level{2};
    bool gameOver{ false };
    bool gameComplete { false };

    game.renderScenary(level);

    while (!gameOver && !gameComplete) {
        gameOver = !(game.moveSnake());

        if (!gameOver)
            score = game.verifyIfSnakeAte();

        if (score >= scoreForNextLevel) {
            ++level;
            gameComplete = level > GameInformation::levels;

            if (!gameComplete)
                game.renderScenary(level);
        }

        Sleep(100);
    }
} */

void levelUp() {
    bool gameOver{ false };
    bool gameCompleted{ false };

    GameLogic logic{};

    logic.renderScenary();
    while (!gameOver && !gameCompleted) {
        logic.moveSnake();
        
        gameOver = logic.snakeHasCollided();

        if (logic.hasLevelCompleted())
            gameCompleted = !logic.renderNextLevel();

    }
}

int main() {
    // renderScenary();
    // snakeMovement();
    levelUp();
    system("pause > nul");
}