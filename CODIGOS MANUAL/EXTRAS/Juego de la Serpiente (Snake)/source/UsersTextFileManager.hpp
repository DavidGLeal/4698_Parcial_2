/**
 * @file UsersTextFileManager.hpp
 * @brief Class that handles the saving of user information in text files
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef USERS_TEXT_FILE_MANAGER_HPP
#define USERS_TEXT_FILE_MANAGER_HPP

#include <string>

class UsersTextFileManager {
    private:
        static inline const std::string usersFileName { "Users.txt" };

    public:
        /**
         * @brief Print information of user in the text file
         * 
         * @param user 
         * @param password 
         * @return true 
         * @return false 
         */
        static bool saveUser(const std::string& user, const std::string& password);

        /**
         * @brief Find an user in the text file
         * 
         * @param userToFind 
         * @param passwordToFind 
         * @return true 
         * @return false 
         */
        static bool findUser(const std::string& userToFind, const std::string& passwordToFind);

        /**
         * @brief Verify that not exist an user with the same nam
         * 
         * @param user 
         * @return true 
         * @return false 
         */
        static bool isNewUser(const std::string& user);
};

#endif