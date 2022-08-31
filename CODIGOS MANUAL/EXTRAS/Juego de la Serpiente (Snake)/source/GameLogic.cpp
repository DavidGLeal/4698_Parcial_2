#include "GameLogic.hpp"
#include "GameInformation.hpp"
#include "GameLevel.hpp"
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <cmath>

Position GameLogic::generateRandomPosition() {
    short x{ static_cast<short>((GameInformation::leftWall + 1) + std::rand() % ((GameInformation::rightWall - 1) - (GameInformation::leftWall + 1) - 1)) };
    short y{ static_cast<short>((GameInformation::superiorWall + 1) + std::rand() % ((GameInformation::inferiorWall - 1) - (GameInformation::superiorWall + 1) - 1)) };

    return Position{x, y};
}

short GameLogic::calculateVelocityInMilliSeconds(const short velocity) {
    constexpr double minVelocity{1};
    constexpr double minTime{25};
    constexpr double maxTime{250};
    constexpr double slope { (minTime - maxTime) / (GameInformation::maxVelocity - minVelocity) };

    return (slope * (velocity - GameInformation::maxVelocity)) + minTime;
}

bool GameLogic::positionCollidesWithBlock(const Position& position) const {
    for (const auto& block : blocks) {
        if (block.isInTheSamePosition(position))
            return true;
    }

    return false;
}

bool GameLogic::positionCollidesWithSnake(const Position& position) const {
    return snake.isInTheSamePosition(position);
}

bool GameLogic::positionCollidesWithApple(const Position& position) const {
    return apple.isInTheSamePosition(position);
}

bool GameLogic::positionCollidesWithWall(const Position& position) const {
    return position.getX() == GameInformation::leftWall || position.getX() == GameInformation::rightWall || position.getY() == GameInformation::superiorWall || position.getY() == GameInformation::inferiorWall;
}

bool GameLogic::isAvailablePosition(const Position& position) const {
    return !positionCollidesWithBlock(position) && !positionCollidesWithSnake(position) && !positionCollidesWithWall(position) && position != lastPosition;
}

void GameLogic::spawnSnake() {
    Position renderingLocation{ generateRandomPosition() };
    
    while (positionCollidesWithBlock(renderingLocation) || positionCollidesWithApple(renderingLocation))
        renderingLocation = generateRandomPosition();

    snake.spawn(renderingLocation);
}

void GameLogic::spawnApple() {
    Position renderingLocation{ generateRandomPosition() };

    while (positionCollidesWithBlock(renderingLocation) || positionCollidesWithSnake(renderingLocation))
        renderingLocation = generateRandomPosition();

    apple.spawn(renderingLocation);
}

GameLogic::GameLogic() {
    std::srand(std::time(nullptr));
    GameInformation::score = 0;
}

void GameLogic::renderScenary() {
    GameLevel::renderLevel(GameInformation::level, blocks);
    spawnSnake();
    spawnApple();
    gameVelocity = calculateVelocityInMilliSeconds(GameInformation::velocity);
}

void GameLogic::verifyIfSnakeAte() {
    if (!snake.isInTheSamePositionOf(apple))
        return;

    snake.eat();
    spawnApple();
    ++GameInformation::score;
    GameLevel::renderScore();
}

void GameLogic::moveSnake() {
    bool isAvailableTheLeftPosition { isAvailablePosition(snake.relativePosition(Movement::left)) };
    bool isAvailableTheRightPosition { isAvailablePosition(snake.relativePosition(Movement::right)) };
    bool isAvailableTheAbovePosition { isAvailablePosition(snake.relativePosition(Movement::up)) };
    bool isAvailableTheBelowPosition { isAvailablePosition(snake.relativePosition(Movement::down)) };

    bool snakeMoved{ true };
    lastPosition = snake.getPosition();

    if (apple.isToTheLeftOf(snake) && isAvailableTheLeftPosition) {
        snake.move(Movement::left);

    } else if (apple.isToTheRightOf(snake) && isAvailableTheRightPosition) {
        snake.move(Movement::right);

    } else if (apple.isAboveOf(snake) && isAvailableTheAbovePosition) {
        snake.move(Movement::up);

    } else if (apple.isBelowOf(snake) && isAvailableTheBelowPosition) {
        snake.move(Movement::down);

    } else {
        snakeMoved = false;
    }

    if (!snakeMoved) {

        if (isAvailableTheLeftPosition)
            snake.move(Movement::left);

        else if (isAvailableTheRightPosition)
            snake.move(Movement::right);

        else if (isAvailableTheAbovePosition)
            snake.move(Movement::up);

        else if (isAvailableTheBelowPosition)
            snake.move(Movement::down);
        else
            snakeCanMove = false;
    }

    verifyIfSnakeAte();
    Sleep(gameVelocity);
}

bool GameLogic::snakeHasCollided() const {
    return !snakeCanMove;
}

bool GameLogic::hasLevelCompleted() const {
    return GameInformation::score >= GameInformation::scoreForNextLevel;
}

bool GameLogic::renderNextLevel() {
    ++GameInformation::level;

    bool gameCompleted{ GameInformation::level > GameInformation::levels };

    if (gameCompleted) {
        GameInformation::level = 1;
    } else {
        GameInformation::score = 0;
        GameLevel::renderLevel(GameInformation::level, blocks);
        spawnSnake();
        spawnApple();
    }

    return !gameCompleted;
}