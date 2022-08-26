/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file FileManager.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage files and save information of Tree class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.2
 * @date 2022-07-12
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include <string>

class Tree;
class Node;

class FileManager {
    private:
        static bool isBackupEnabled;
        static const std::string TXT_FILE_NAME;

        static std::string generateBackupFileName();

        /**
         * @brief write all information of Tree object in an specified file
         * 
         * @param root 
         * @param file 
         */
        static void writeTreeOnFile(Node *&root, std::ofstream &file);

        /**
         * @brief Save all data of tree in a txt file
         * 
         * @param tree 
         */
        static bool saveTreeBackup(Tree &tree);

    public:

        /**
         * @brief Save all data of tree in a txt file replaced all old information
         * 
         * @param tree 
         */
        static bool saveTree(Tree &tree);

        /**
         * @brief Read all data of most recent txt file and loading in a Tree object
         * 
         * @return Tree 
         */
        static Tree loadTreeInformation();

        /**
         * @brief Replace all information with data of backup file
         * 
         * @param fileName this name would have this format yymmdd-hhmmss.txt
         * @return true 
         * @return false 
         */
        static bool loadBackup(const std::string &fileName);

        /**
         * @brief Enable Backup option (generate txt files with date and time in his file name)
         * 
         */
        static void enableBackup();

        /**
         * @brief Disable Backup option
         * 
         */
        static void disableBackup();
};

#endif