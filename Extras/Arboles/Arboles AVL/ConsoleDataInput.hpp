/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file MenuBackup.hpp
 * @author Grupo 1 y 20
 * @brief Menu that manage backup files
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-13
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>
using namespace std;

class ConsoleDataInput{
    private: 
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD CursorPosition; 
    /**
    * @brief Sets the cursor to the x and y position of the screen
    * 
    * @param x 
    * @param y 
    */
    void gotoXY(int x, int y);
    public:
    /**
     * @brief Reads an integer value in the position x and y
     * 
     * @param x 
     * @param y 
     * @return int 
     */
     int integerInput(int x, int y);

    /**
     * @brief Reads a string in the position x and y
     * 
     * @param x 
     * @param y 
     * @return int 
     */
    string stringInput(int x, int y);

    /**
     * @brief Reads an alphanumeric value in the position x and y
     * 
     * @param x 
     * @param y 
     * @return int 
     */
    string alphanumericInput(int x, int y);


    int integerNumber(short minimumDigits, short maximumDigits,int x,int y);

    char *alphanumeric(short minimumCharacters, short maximumCharacters,int x,int y);

    char *word(short minimumCharacters, short maximumCharacters,int x, int y);

    char *digits(short minimumDigits, short maximumDigits,int x,int y);

};