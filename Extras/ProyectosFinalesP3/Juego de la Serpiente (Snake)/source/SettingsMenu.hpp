/**
 * @file SettingsMenu.hpp
 * @brief class that modifies aspects of the game such as the initial level, score to pass the level and the speed of the snake
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SETTINGS_MENU_HPP
#define SETTINGS_MENU_HPP

#include "Position.hpp"
#include "Color.hpp"
#include "GameInformation.hpp"
#include <string>

class SettingsMenu {
    private:
        Position position{};
        std::string title{ "         Configuraciones" };
        static inline constexpr short size{4};
        const std::string options[size] {
            "Nivel inicial",
            "Puntaje necesario",
            "Velocidad",
            "             Regresar"
        };
        const short* values[size - 1] {
            &GameInformation::level,
            &GameInformation::scoreForNextLevel,
            &GameInformation::velocity
        };
        Color titleColor{ Color::red };
        Color selectedOption{ Color::blue };
        Color unselectedOption{ Color::green };

        /**
         * @brief 
         * 
         * @return short 
         */
        short maxStringSize() const;

        /**
         * @brief Render an option with a specified color
         * 
         * @param option 
         * @param color 
         */
        void renderOption(const short option, const Color color) const;

        /**
         * @brief Render the option selected with a selectedOptionColor and render after and before option with unselectedOptionColor
         * 
         * @param option 
         */
        void renderSelectedOption(const short option) const;

        /**
         * @brief Render all options
         * 
         */
        void renderScreen() const;

    public:
        /**
         * @brief Construct a new Settings Menu object
         * 
         * @param _position 
         */
        SettingsMenu(const Position& _position = Position{});

        /**
         * @brief Set the Title Color object
         * 
         * @param color 
         */
        void setTitleColor(const Color color);

        /**
         * @brief Set the Unselected Option Color object
         * 
         * @param color 
         */
        void setUnselectedOptionColor(const Color color);

        /**
         * @brief Set the Selected Option Color object
         * 
         * @param color 
         */
        void setSelectedOptionColor(const Color color);
        
        /**
         * @brief Start algorithm and return the selected option
         * 
         * @return short 
         */
        void render();
};

#endif