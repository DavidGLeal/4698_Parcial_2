#include "Position.hpp"

void Position::copy(const Position& position) {
    x = position.x;
    y = position.y;
}

Position::Position(short _x, short _y) : x{static_cast<short>(_x + 1)}, y{static_cast<short>(_y + 1)} {}

Position::Position(const Position& position) {
    copy(position);
}

short Position::getX() const {
    return x;
}

short Position::getY() const {
    return y;
}

void Position::move(const Movement direction, const short positions) {
    switch(direction) {
        case Movement::up:
            y -= positions;
            break;
        case Movement::down:
            y += positions;
            break;
        case Movement::left:
            x -= positions;
            break;
        case Movement::right:
            x += positions;
            break;
        default:
            break;
    }
}

bool Position::isToTheLeftOf(const Position& position) const {
    return x < position.x;
}

bool Position::isToTheRightOf(const Position& position) const {
    return x > position.x;
}

bool Position::isAboveOf(const Position& position) const {
    return y < position.y;
}

bool Position::isBelowOf(const Position& position) const {
    return y > position.y;
}

void Position::operator=(const Position& position) {
    copy(position);
}

bool operator==(const Position& positionA, const Position& positionB) {
    return positionA.x == positionB.x && positionA.y == positionB.y;
}

bool operator!=(const Position& positionA, const Position& positionB) {
    return !(positionA == positionB);
}