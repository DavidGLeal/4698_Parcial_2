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
#ifndef MENULOGIN_HPP
#define MENULOGIN_HPP
#include <string>
using namespace std;
class MenuGUI;
class MenuLogin {
    private:

    static string id;
    static string password;

    static MenuGUI innerMenuLogin;
    /**
     * @brief Selects the option of the menu
     * 
     * @param selectedOption 
     * @return true 
     * @return false 
     */
    static bool switchOption(int selectedOption);

    /**
     * @brief Enters and verifies the username of the user
     * 
     */
    static void enterUser();

    /**
     * @brief Enters and verifies the password of the user
     * 
     */
    static void enterPassword();
    /**
     * @brief If user is verified,main menu deploys
     * 
     */
    static void enterMainMenu();
    public:

    /**
     * @brief Launches the menu 
     * 
     */
    static void start();
};

#endif