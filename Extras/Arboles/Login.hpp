/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file Login.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage operations of tree class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-19
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LOGIN_HPP
#define LOGIN_HPP

class MenuGUI;
class Login {
    private:

    static MenuGUI menuLogin;
    /**
     * @brief Selects the option of the menu
     * 
     * @param selectedOption 
     * @return true 
     * @return false 
     */
    static bool switchOption(int selectedOption);

    /**
     * @brief Gives acces to the login sub-menu
     * 
     */
    static void loginMenu();

    /**
     * @brief Gives access to the signup sub-menu
     * 
     */
    static void signUpMenu();

    public:

    /**
     * @brief Launches the menu
     * 
     */
    static void start();
};



#endif