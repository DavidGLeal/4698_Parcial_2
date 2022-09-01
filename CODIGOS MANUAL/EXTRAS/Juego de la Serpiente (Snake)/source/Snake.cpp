#include "Snake.hpp"
#include <iostream>

void Snake::updatePosition(Position oldPosition) {
    for (auto& positions : body) {
        Position auxiliar{ positions };
        positions = oldPosition;
        oldPosition = auxiliar;
    }
}

void Snake::eat() {
    if (!body.isEmpty())
        body.addLast(body[body.size() - 1]);
    else
        body.addLast(position);
}

void Snake::clear() const {
    const unsigned char blankSpace{32};
    
    if (body.isEmpty())
        printf("\033[%d;%dH%c\033[0m", position.getY(), position.getX(), blankSpace);
    else
        printf("\033[%d;%dH%c\033[0m", body[body.size() - 1].getY(), body[body.size() - 1].getX(), blankSpace);
}

void Snake::renderTail() const {
    if (!body.isEmpty())
        printf("\033[%d;%dH\033[38;5;%dm%c\033[0m", body[body.size() - 1].getY(), body[body.size() - 1].getX(), static_cast<unsigned short>(spriteColor), sprite);
}

Snake::Snake(const Position& _position) : Entity{219, _position, Color::green}, body(10, 10) {}

const Position& Snake::getPosition() const {
    return position;
}

void Snake::move(const Movement direction) {
    clear();

    Position oldPosition { position };

    position.move(direction);

    render();
    updatePosition(oldPosition);
    renderTail();
}

bool Snake::isInTheSamePosition(const Position& _position) const {
    if (_position == position)
        return true;

    for (const auto& part : body) {
        if (_position == part)
            return true;
    }

    return false;
}

void Snake::spawn(const Position& newPosition) {
    body.clear();
    setPosition(newPosition);
    render();
}

Position Snake::relativePosition(const Movement direction) const {
    Position newPosition { position };

    switch(direction) {
        case Movement::left:
            newPosition.move(Movement::left);
            break;

        case Movement::right:
            newPosition.move(Movement::right);
            break;

        case Movement::up:
            newPosition.move(Movement::up);
            break;

        case Movement::down:
            newPosition.move(Movement::down);
            break;

        default:
            break;
    }

    return newPosition;
}