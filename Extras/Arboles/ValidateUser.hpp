/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file ValidateUser.hpp
 * @author Grupo 1 y 20
 * @brief Class that manage operations of tree class
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-19
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ValidateUser
{
public:
    /**
     * @brief Validate users duplicated
     * 
     * @return true 
     * @return false 
     */
    static bool validate_UserName(string);

    /**
     * @brief Validate the user and password to the login
     * 
     * @return true 
     * @return false 
     */
    static bool validate_Login(string, string);

    /**
     * @brief Update de Register Data with the new account
     * 
     */
    static void Register_Data(string,string,string,string);
};