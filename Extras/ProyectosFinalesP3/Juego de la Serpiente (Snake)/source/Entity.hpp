/**
 * @file Entity.hpp
 * @brief Father class that represent an renderizable object on console
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Position.hpp"
#include "Color.hpp"

class Entity {
    protected:
        const unsigned char sprite{};
        Position position{};
        Color spriteColor{};

        /**
         * @brief Set the Position object
         * 
         * @param newPosition 
         */
        void setPosition(const Position& newPosition);

    public:

        /**
         * @brief Construct a new Entity object
         * 
         * @param _sprite 
         * @param _position 
         * @param _color 
         */
        explicit Entity(const unsigned char _sprite, const Position& _position = Position{}, Color _color = Color::gray);

        /**
         * @brief Print the sprite on console
         * 
         */
        void render() const;

        /**
         * @brief Verify the relative position of entity
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool isToTheLeftOf(const Entity& entity) const;

        /**
         * @brief Verify the relative position of entity
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool isToTheRightOf(const Entity& entity) const;

        /**
         * @brief Verify the relative position of entity
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool isAboveOf(const Entity& entity) const;

        /**
         * @brief Verify the relative position of entity
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool isBelowOf(const Entity& entity) const;

        /**
         * @brief Verify the relative position of entity
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        bool isInTheSamePositionOf(const Entity& entity) const;

        /**
         * @brief Verify the relative position of another position
         * 
         * @param entity 
         * @return true 
         * @return false 
         */
        virtual bool isInTheSamePosition(const Position& _position) const;

        /**
         * @brief Destroy the Entity object
         * 
         */
        virtual ~Entity() = default;
};

#endif