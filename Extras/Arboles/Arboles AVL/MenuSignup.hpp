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
#ifndef MENUSIGNUP_HPP
#define MENUSIGNUP_HPP
#include <string>
using namespace std;
class MenuGUI;
class MenuSignup {
    private:
    static string name;
    static string lastname;
    static string id;
    static string password;

    static MenuGUI innerMenuSignup;
    /**
     * @brief Selects the option of the menu
     * 
     * @param selectedOption 
     * @return true 
     * @return false 
     */
    static bool switchOption(int selectedOption);

    /**
     * @brief Registers the name of the user
     * 
     */
    static void registerName();
    
    /**
     * @brief Registers the lastname of the user
     * 
     */
    static void registerLastName();

    /**
     * @brief Registers the password of the user
     * 
     */
    static void registerPassword();

    /**
     * @brief Registers the ID of the user
     * 
     */
    static void registerID();

    /**
     * @brief Create account and save it on txt list
     * 
     */
    static void createAccount();

    public:

    /**
     * @brief Launches the menu
     * 
     */
    static void start();
};

#endif