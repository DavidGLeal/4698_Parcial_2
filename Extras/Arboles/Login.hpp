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