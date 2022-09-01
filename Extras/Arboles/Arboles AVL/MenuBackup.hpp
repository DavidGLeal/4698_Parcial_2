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

#ifndef MENU_BACKUP_HPP
#define MENU_BACKUP_HPP

#include <string>

class MenuGUI;
class Tree;

class MenuBackup {
    private:
        static MenuGUI menuGraphic;

        /**
         * @brief verify that action realize
         * 
         * @param optionSelected 
         * @return true if exit option is select
         * @return false if exit option isn't select
         */
        static bool switchOption(int optionSelected, Tree &tree);

        /**
         * @brief Replace file that contain information of tree object with a backup file
         * 
         */
        static void recoverBackup(Tree &tree);

        /**
         * @brief Enable backup files generation
         * 
         */
        static void enableBackupGeneration();

        /**
         * @brief Disable backup files generation
         * 
         */
        static void disableBackupGeneration();

        /**
         * @brief Generate a backup file name for use in file manger class
         * 
         * @param year 
         * @param month 
         * @param day 
         * @return std::string 
         */
        static std::string generateBackupFileName(int year, int month, int day, int hour, int minuts, int seconds);

    public:

        /**
         * @brief Start algorithm of this menu
         * 
         */
        static void start(Tree &tree);
};

#endif