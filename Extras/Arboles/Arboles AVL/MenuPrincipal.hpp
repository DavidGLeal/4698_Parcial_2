/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file MenuPrincipal.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage operations of tree class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-14
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MENU_PRINCIPAL_HPP
#define MENU_PRINCIPAL_HPP

class MenuGUI;
class Tree;

class MenuPrincipal {
    private:
        static MenuGUI menuGraphic;
        static Tree binaryAVLTree;
        static constexpr short MINIMUM_DIGITS{1};
        static constexpr short MAXIMUM_DIGITS{4};

        /**
         * @brief Choose action to realiza
         * 
         * @param optionSelected 
         * @return true 
         * @return false 
         */
        static bool switchOption(int optionSelected);

        /**
         * @brief insert a new value in tree object
         * 
         */
        static void insertValue();

        /**
         * @brief delete a specified value in tree object
         * 
         */
        static void deleteValue();

        /**
         * @brief verify if exist a specified value in tree object
         * 
         */
        static void searchValue();

        /**
         * @brief print tree in graphic mode
         * 
         */
        static void printTree();

        /**
         * @brief Change to submenu
         * 
         */
        static void startMenuBackup();

        /**
         * @brief Print a image pyxel by pyxel on console
         * 
         */
        static void printImage();

        /**
         * @brief Generate a report on pdf with information of tree object
         * 
         */
        static void generatePDF();

        /**
         * @brief Open a help file
         * 
         */
        static void openHelp();

        /**
         * @brief Return to login screen and close session of user
         * 
         */
        static void signOut();

    public:

        /**
         * @brief Start algorithm of this menu
         * 
         */
        static void start();
};

#endif