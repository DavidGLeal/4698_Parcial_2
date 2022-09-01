/**
 * @file Login.hpp
 * @brief Class in charge of managing user login and registration.
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>

class Login {
    private:
        static std::string userName;

        /**
         * @brief Insert information for sign up, the user entered must not exist
         * 
         * @return true 
         * @return false 
         */
        static bool signUp();

        /**
         * @brief Insert information for sign in, the user entered must exist
         * 
         * @return true 
         * @return false 
         */
        static bool signIn();

        /**
         * @brief Render login menu
         * 
         * @return short 
         */
        static short renderMenu();

    public:
        /**
         * @brief Switch the value return of login menu
         * 
         */
        static void render();
};

#endif