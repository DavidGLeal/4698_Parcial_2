#pragma once
#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "Player.h"

class MazeGame {
public:
    MazeGame();
    void initialize();

private:
    Maze* maze;
    Player* player;
    sf::RenderWindow* window;
    bool finished = false;
};

