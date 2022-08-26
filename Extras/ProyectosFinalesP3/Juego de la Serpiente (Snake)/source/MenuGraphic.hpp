/**
 * @file MenuGraphic.hpp
 * @brief Class that generates graphic options menus
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MENU_GRAPHIC_HPP
#define MENU_GRAPHIC_HPP

#include <string>
#include <initializer_list>
#include "Color.hpp"
#include "Position.hpp"
#include "ArrayList.hpp"

class MenuGraphic {
    private:
        std::string title{};
        std::string* options{};
        short size{};
        Position position{};
        Color titleColor{ Color::red };
        Color unselectedOption{ Color::gray };
        Color selectedOption{ Color::white };

        /**
         * @brief Clean the list of options
         * 
         */
        void deleteOptions();

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
        void renderScreen();

    public:
        /**
         * @brief Construct a new Menu Graphic object
         * 
         * @param _title 
         * @param color 
         */
        MenuGraphic(const std::string& _title, const Color color);

        /**
         * @brief Set the Position object
         * 
         * @param _position 
         */
        void setPosition(const Position& _position);

        /**
         * @brief Set the Options object
         * 
         * @param _options 
         */
        void setOptions(std::initializer_list<std::string> _options);

        /**
         * @brief Set the Options object
         * 
         * @param _options 
         */
        void setOptions(const ArrayList<std::string>& _options);

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
        short render();

        /**
         * @brief Destroy the Menu Graphic object
         * 
         */
        ~MenuGraphic();
};

#endif