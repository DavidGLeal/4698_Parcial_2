/**
 * @file Apple.hpp
 * @brief Object to be the snake's food
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef APPLE_HPP
#define APPLE_HPP

#include "Entity.hpp"
#include "SpawnSystem.hpp"

class Apple : public Entity, public SpawnSystem {
    public:

        /**
         * @brief Construct a new Apple object
         * 
         * @param _position 
         */
        Apple(const Position& _position = Position{});

        /**
         * @brief Set a new position and render the object
         * 
         * @param newPosition 
         */
        void spawn(const Position& newPosition) override;
};

#endif