#include "Player.h"

Player::Player(sf::Vector2f size, Coordinate position) : size_(size), position_(position) {
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(position_.getX() * 18, position_.getY() * 18);
    shape_.setSize(size_);
}

void Player::draw(sf::RenderWindow* window) {
    window->draw(shape_);
}

void Player::move(int shiftx, int shifty) {
    int x = position_.getX() + shiftx;
    int y = position_.getY() + shifty;

    setPosition(Coordinate(x, y));
}

void Player::setPosition(Coordinate position) {
    position_ = position;
    shape_.setPosition(position_.getX() * 18, position_.getY() * 18);
}

void Player::setSize(sf::Vector2f size) {
    size_ = size;
    shape_.setSize(size_);
}

Coordinate Player::getPosition()
{
    return position_;
}

sf::Vector2f Player::getSize()
{
    return size_;
}

sf::RectangleShape& Player::getShape()
{
    return shape_;
}
