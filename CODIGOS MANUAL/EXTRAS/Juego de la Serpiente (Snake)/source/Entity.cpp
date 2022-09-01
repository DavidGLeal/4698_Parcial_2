#include "Entity.hpp"
#include <iostream>

Entity::Entity(const unsigned char _sprite, const Position& _position, Color _color) : sprite{_sprite}, position{_position}, spriteColor{_color} {}

void Entity::setPosition(const Position& newPosition) {
    position = newPosition;
}

void Entity::render() const {
    printf("\033[?25l\033[%d;%dH\033[38;5;%dm%c\033[0m", position.getY(), position.getX(), static_cast<short>(spriteColor), sprite);
}

bool Entity::isToTheLeftOf(const Entity& entity) const {
    return position.isToTheLeftOf(entity.position);
}

bool Entity::isToTheRightOf(const Entity& entity) const {
    return position.isToTheRightOf(entity.position);
}

bool Entity::isAboveOf(const Entity& entity) const {
    return position.isAboveOf(entity.position);
}

bool Entity::isBelowOf(const Entity& entity) const {
    return position.isBelowOf(entity.position);
}

bool Entity::isInTheSamePositionOf(const Entity& entity) const {
    return position == entity.position;
}

bool Entity::isInTheSamePosition(const Position& _position) const {
    return position == _position;
}