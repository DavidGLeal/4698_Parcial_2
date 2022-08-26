/**
 * @file Node.hpp
 * @author Grupo 1 y Grupo 20
 * @brief Node class
 * @brief Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <thread>
#ifndef MARQUEE_HPP
#define MARQUEE_HPP
class Marquee{
    private:
    
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD CursorPosition; 
    /**
     * @brief Sets the cursor to the x and y position of the screen
     * 
     * @param x 
     * @param y 
     */
    void gotoXY(int x,int y);
    public:
    /**
     * @brief Displays continuous Marquee
     * 
     */
    void displayMarquee();
};

#endif