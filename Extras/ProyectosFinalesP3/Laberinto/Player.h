#pragma once
#include <SFML/Graphics.hpp>
#include "Coordinate.h"

class Player {
public:
    Player(sf::Vector2f size, Coordinate position);
    void draw(sf::RenderWindow* window);
    void move(int shiftx, int shifty = 0);

    void setPosition(Coordinate position);
    void setSize(sf::Vector2f size);
    Coordinate getPosition();
    sf::Vector2f getSize();
    sf::RectangleShape& getShape();

private:
    sf::RectangleShape shape_;
    sf::Vector2f size_;
    Coordinate position_;
};

