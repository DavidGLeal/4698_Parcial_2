/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file MenuSignup.hpp
 * @author Grupo 1 y 20
 * @brief Class that manages the login submenu
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-19
 * Date last modification: 2022-07-19
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MENUSIGNUP_HPP
#define MENUSIGNUP_HPP
#include <string>
class MenuGUI;
class MenuSignup {
    private:
    static std::string name;
    static std::string lastname;
    static std::string id;
    static std::string password;

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