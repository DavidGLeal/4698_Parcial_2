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