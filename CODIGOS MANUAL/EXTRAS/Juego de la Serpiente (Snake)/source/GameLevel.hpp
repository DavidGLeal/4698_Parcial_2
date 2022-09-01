/**
 * @file GameLevel.hpp
 * @brief Class in charge of rendering the levels
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include "ArrayList.hpp"
#include "Block.hpp"

class GameLevel {
    private:

        /**
         * @brief print walls on console
         * 
         */
        static void renderWalls();

    public:

        /**
         * @brief Render a specified level and charge blocks list
         * 
         * @param level Value between 1 and GameInformation::levels
         * @param blocks Object where the positions of all rendered blocks will be stored in the level
         */
        static void renderLevel(const short level, ArrayList<Block>& blocks);

        /**
         * @brief Render o update score on console
         * 
         */
        static void renderScore();
};

#endif