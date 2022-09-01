/**
 * @file Snake.hpp
 * @brief Snake class
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Entity.hpp"
#include "SpawnSystem.hpp"
#include "ArrayList.hpp"

class Snake : public Entity, public SpawnSystem {
    private:
        ArrayList<Position> body{};
        void updatePosition(Position oldPosition);
        void clear() const;
        void renderTail() const;

    public:
        /**
         * @brief Construct a new Snake object
         * 
         * @param _position 
         */
        Snake(const Position& _position = Position{});

        /**
         * @brief Get the Position object
         * 
         * @return const Position& 
         */
        const Position& getPosition() const;

        /**
         * @brief Change the position of snake and render the movement
         * 
         * @param direction 
         */
        void move(const Movement direction);

        /**
         * @brief Increment tail of snake
         * 
         */
        void eat();

        /**
         * @brief Verify if is in the same position of another position object
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        bool isInTheSamePosition(const Position& position) const override;

        /**
         * @brief Set a new position and render snake
         * 
         * @param newPosition 
         */
        void spawn(const Position& newPosition) override;

        /**
         * @brief Verify if is in the same position of another position object
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        Position relativePosition(const Movement direction) const;
};

#endif