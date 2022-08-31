/**
 * @file GameManager.hpp
 * @brief Class in charge of managing the video game's options
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <string>
#include "Marquee.hpp"

class GameManager {
    private:
        Marquee marquee{" ", 10, 60};

        /**
         * @brief Render the main menu and return the option selected
         * 
         * @return short 
         */
        short renderMainMenu();

        /**
         * @brief Render settings menu and modify values
         * 
         */
        void renderSettingsMenu();

        /**
         * @brief Start the snake algorithm
         * 
         * @param user 
         */
        void startGame(const std::string& user);

    public:
        /**
         * @brief Construct a new Game Manager object
         * 
         */
        GameManager();

        /**
         * @brief 
         * 
         * @param user 
         */
        void start(const std::string& user);
};

#endif