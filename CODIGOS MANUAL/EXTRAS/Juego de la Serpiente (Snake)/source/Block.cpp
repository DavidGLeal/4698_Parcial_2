#include "Block.hpp"

Block::Block(const Position& _position) : Entity{178, _position, Color::yellow} {};

void Block::operator=(const Block& block) {
    setPosition(block.position);
}