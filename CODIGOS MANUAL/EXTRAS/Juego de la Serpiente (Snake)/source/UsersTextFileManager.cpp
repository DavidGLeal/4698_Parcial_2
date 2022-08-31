#include "UsersTextFileManager.hpp"
#include <fstream>

bool UsersTextFileManager::saveUser(const std::string& user, const std::string& password) {
    std::ofstream usersFile { usersFileName, std::ios::app };

    if (usersFile.fail())
        return false;

    usersFile << user << ' ' << password << '\n';

    usersFile.close();

    return true;
}

bool UsersTextFileManager::findUser(const std::string& userToFind, const std::string& passwordToFind) {
    std::ifstream usersFile { usersFileName, std::ios::in };
    
    if (usersFile.fail())
        return false;

    bool userFound { false };
    std::string user{};
    std::string password{};

    while (!usersFile.eof() && !userFound) {
        usersFile >> user;
        usersFile >> password;
        userFound = user == userToFind && password == passwordToFind;
    }

    usersFile.close();

    return userFound;
}

bool UsersTextFileManager::isNewUser(const std::string& user) {
    std::ifstream usersFile { usersFileName, std::ios::in };

    if (usersFile.fail())
        return true;

    bool isNewUser { true };
    std::string userInFile{};
    std::string password{};

    while (!usersFile.eof() && isNewUser) {
        usersFile >> userInFile;
        usersFile >> password;

        isNewUser = userInFile != user;
    }

    usersFile.close();

    return isNewUser;
}