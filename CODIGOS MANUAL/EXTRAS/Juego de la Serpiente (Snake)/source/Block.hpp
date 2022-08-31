/**
 * @file Block.hpp
 * @brief Object that will be an obstacle to the snake
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Entity.hpp"

class Block : public Entity {
    public:
        /**
         * @brief Construct a new Block object
         * 
         * @param _position 
         */
        Block(const Position& _position = Position{});

        /**
         * @brief Copy the position of other block object
         * 
         * @param block 
         */
        void operator=(const Block& block);
};

#endif