/**
 * @file Position.hpp
 * @brief Class used to place an object in a position on the screen
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef POSITION_HPP
#define POSITION_HPP

#include "Movement.hpp"

class Position {
    private:
        short x{};
        short y{};

        /**
         * @brief Copy all attributes of another position object
         * 
         * @param position 
         */
        void copy(const Position& position);

    public:
        /**
         * @brief Construct a new Position object
         * 
         * @param _x 
         * @param _y 
         */
        Position(short _x = 0, short _y = 0);

        /**
         * @brief Construct a new Position object
         * 
         * @param position 
         */
        Position(const Position& position);

        /**
         * @brief Get x coordinate
         * 
         * @return short 
         */
        short getX() const;

        /**
         * @brief Get y coordinate
         * 
         * @return short 
         */
        short getY() const;

        /**
         * @brief Modified the x or y coordinate in a specified direction
         * 
         * @param direction 
         * @param positions 
         */
        void move(const Movement direction, const short positions = 1);

        /**
         * @brief Verify the relative position with another position object
         * 
         * @param _position 
         * @return true 
         * @return false 
         */
        bool isToTheLeftOf(const Position& _position) const;

        /**
         * @brief Verify the relative position with another position object
         * 
         * @param _position 
         * @return true 
         * @return false 
         */
        bool isToTheRightOf(const Position& _position) const;

        /**
         * @brief Verify the relative position with another position object
         * 
         * @param _position 
         * @return true 
         * @return false 
         */
        bool isAboveOf(const Position& _position) const;

        /**
         * @brief Verify the relative position with another position object
         * 
         * @param _position 
         * @return true 
         * @return false 
         */
        bool isBelowOf(const Position& _position) const;

        /**
         * @brief 
         * 
         * @param position 
         */
        void operator=(const Position& position);

        /**
         * @brief A position is equal an another if x and y coodinates are equals
         * 
         * @param positionA 
         * @param positionB 
         * @return true 
         * @return false 
         */
        friend bool operator==(const Position& positionA, const Position& positionB);

        /**
         * @brief 
         * 
         * @param positionA 
         * @param positionB 
         * @return true 
         * @return false 
         */
        friend bool operator!=(const Position& positionA, const Position& positionB);
};

#endif