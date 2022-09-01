/**
 * @file GameLogic.hpp
 * @brief Class in charge of serp motion logic
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include "Block.hpp"
#include "Apple.hpp"
#include "Snake.hpp"

class GameLogic {
    private:
        ArrayList<Block> blocks{};
        Apple apple{};
        Snake snake{};
        Position lastPosition{};
        bool snakeCanMove{ true };
        short gameVelocity{};

        /**
         * @brief Returns a random position with values between the walls of GameInformation
         * 
         * @return Position 
         */
        static Position generateRandomPosition();

        /**
         * @brief Transform a value of velocity through a linear function to millisecond value for use in Sleep function
         * 
         * @param velocity 
         * @return short 
         */
        static short calculateVelocityInMilliSeconds(const short velocity);

        /**
         * @brief Verify if a position collide with some block of blocks list
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        bool positionCollidesWithBlock(const Position& position) const;

        /**
         * @brief Verify if a position collide with some part of snake
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        bool positionCollidesWithSnake(const Position& position) const;

        /**
         * @brief Verify if a position collide with apple
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        bool positionCollidesWithApple(const Position& position) const;

        /**
         * @brief Verify if a position collide with some wall
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        bool positionCollidesWithWall(const Position& position) const;

        /**
         * @brief Verify that a position doesn't collide with apple, snake, block or wall
         * 
         * @param position 
         * @return true 
         * @return false 
         */
        bool isAvailablePosition(const Position& position) const;

        /**
         * @brief Place the apple in a new random position
         * 
         */
        void spawnApple();

        /**
         * @brief Place the snake in a new random position
         * 
         */
        void spawnSnake();

        /**
         * @brief Verify if head snake is in the same position of apple
         * 
         */
        void verifyIfSnakeAte();

    public:
        /**
         * @brief Construct a new Game Logic object
         * 
         */
        GameLogic();

        /**
         * @brief Render walls and score information
         * 
         */
        void renderScenary();

        /**
         * @brief Algorithm that decides the shortest or most available path by which the snake will reach the apple
         * 
         */
        void moveSnake();

        /**
         * @brief Checks all possible collisions
         * 
         * @return true 
         * @return false 
         */
        bool snakeHasCollided() const;

        /**
         * @brief Verifies if the score has reached the defined maximum
         * 
         * @return true 
         * @return false 
         */
        bool hasLevelCompleted() const;

        /**
         * @brief Render the next level, if level is the last return false
         * 
         * @return true 
         * @return false 
         */
        bool renderNextLevel();
};

#endif