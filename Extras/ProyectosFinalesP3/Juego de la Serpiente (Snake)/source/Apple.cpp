#include "Apple.hpp"

Apple::Apple(const Position& _position) : Entity{254, _position, Color::red} {}

void Apple::spawn(const Position& newPosition) {
    setPosition(newPosition);
    render();
}