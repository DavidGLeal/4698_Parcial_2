/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file ConsoleDataInput.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage operations of tree class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-19
 * Date last modification: 2022-07-19
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>
using namespace std;

class ConsoleDataInput{
    public:
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD CursorPosition; 
    /**
    * @brief Sets the cursor to the x and y position of the screen
    * 
    * @param x 
    * @param y 
    */
    void gotoXY(int x, int y);
    
    /**
     * @brief Allows entering a interger number within a specific position of the console
     * 
     * @param minimumDigits 
     * @param maximumDigits 
     * @param x 
     * @param y 
     * @return int 
     */
    int integerNumber(short minimumDigits, short maximumDigits,int x,int y);

    /**
     * @brief Allows entering an alphanumeric characters within a specific position of the console
     * 
     * @param minimumCharacters 
     * @param maximumCharacters 
     * @param x 
     * @param y 
     * @return char* 
     */
    char *alphanumeric(short minimumCharacters, short maximumCharacters,int x,int y);

    /**
     * @brief Allows entering a string of characters within a specific position of the console
     * 
     * @param minimumCharacters 
     * @param maximumCharacters 
     * @param x 
     * @param y 
     * @return char* 
     */
    char *word(short minimumCharacters, short maximumCharacters,int x, int y);

    /**
     * @brief Allows entering digits characters within a specific position of the console
     * 
     * @param minimumDigits 
     * @param maximumDigits 
     * @param x 
     * @param y 
     * @return char* 
     */
    char *digits(short minimumDigits, short maximumDigits,int x,int y);

    /**
     * @brief Allows to enter a password with the print of ***
     * 
     * @param minimumCharacters 
     * @param maximumCharacters 
     * @param x 
     * @param y 
     * @return char* 
     */
    char *alphanumeric_password(short minimumCharacters, short maximumCharacters,int x,int y);
    /**
     * @brief Allows to enter a unsigned integer taking into account the position of the console
     * 
     * @param minimumDigits 
     * @param maximumDigits 
     * @param x 
     * @param y 
     * @return int 
     */
    int unsignedIntegerNumber(short minimumDigits, short maximumDigits,int x, int y);

};