/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file HandleConsole.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage properties of console
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-13
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    public:
        /**
         * @brief Set the Cursor Position object
         * 
         * @param x coordinate
         * @param y coordinate
         */
        static void setCursorPosition(SHORT x, SHORT y);

        /**
         * @brief Set the Cursor Visibilitie object
         * 
         * @param isEnabled 
         */
        static void setCursorVisibilitie(bool isEnabled);
};

#endif