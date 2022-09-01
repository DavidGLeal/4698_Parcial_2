/**
 * @file ScoreTextFileManager.hpp
 * @brief File management class with the score obtained in each run
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SCORE_TEXT_FILE_MANAGER
#define SCORE_TEXT_FILE_MANAGER

#include <string>

class ScoreTextFileManager {
    private:
        static const std::string backupsRegisterFileName;

    public:
        static const std::string scoreFileName;

        /**
         * @brief Print the user name in the text file
         * 
         * @param user 
         * @return true 
         * @return false 
         */
        static bool saveUser(const std::string& user);

        /**
         * @brief Print score in the text file
         * 
         * @return true 
         * @return false 
         */
        static bool saveScore();

        /**
         * @brief Copy all information of main score file
         * 
         * @return true 
         * @return false 
         */
        static bool saveBackup();

        /**
         * @brief Insert and end of line in the main score file
         * 
         * @return true 
         * @return false 
         */
        static bool insertEndOfLine();

        /**
         * @brief Replace all information of main score file with the backup file selected
         * 
         * @return true 
         * @return false 
         */
        static bool recoverBackup();
};

#endif