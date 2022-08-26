#include "FileManager.hpp"
#include <ctime>
#include <fstream>
#include "Tree.hpp"
#include "Node.hpp"

bool FileManager::isBackupEnabled{true};
const std::string FileManager::TXT_FILE_NAME{"TreeData.txt"};

std::string FileManager::generateBackupFileName() {
    time_t timeMark{time(NULL)};
    tm *dateAndTimeInfo = std::localtime(&timeMark);

    std::string DATE {
        std::to_string(dateAndTimeInfo->tm_year + 1900) +
        std::to_string(dateAndTimeInfo->tm_mon + 1) +
        std::to_string(dateAndTimeInfo->tm_mday)
    };

    std::string HOUR {
        std::to_string(dateAndTimeInfo->tm_hour) +
        std::to_string(dateAndTimeInfo->tm_min) +
        std::to_string(dateAndTimeInfo->tm_sec)
    };  

    return std::string{"Backup_" + DATE + '-' + HOUR + ".txt"};
}

void FileManager::writeTreeOnFile(Node *&root, std::ofstream &file) {
    if (root != nullptr) {
        file << root->getValue() << ' ';
        writeTreeOnFile(root->getLeftNode(), file);
        writeTreeOnFile(root->getRightNode(), file);
    }
}

bool FileManager::saveTreeBackup(Tree &tree) {
    std::ofstream file(generateBackupFileName());

    if (file.fail())
        return false;

    writeTreeOnFile(tree.getRoot(), file);

    file.close();

    return true;
}

bool FileManager::saveTree(Tree &tree) {
    std::ofstream file(TXT_FILE_NAME);

    if (file.fail())
        return false;

    writeTreeOnFile(tree.getRoot(), file);

    file.close();

    if (isBackupEnabled)
        return saveTreeBackup(tree);

    return true;
}

Tree FileManager::loadTreeInformation() {
    Tree treeFromFile;

    std::ifstream file(TXT_FILE_NAME);

    if (file.fail())
        throw "File not found exception";

    while (!file.eof()) {
        int value{};
        file >> value;

        if (!file.eof())
            treeFromFile.add(value);
    }

    file.close();

    return treeFromFile;
}

bool FileManager::loadBackup(const std::string &fileName) {
    std::ifstream fileBackup(fileName + ".txt");

    if (fileBackup.fail())
        return false;

    std::ofstream fileData(TXT_FILE_NAME);

    if (fileData.fail())
        return false;

    while (!fileBackup.eof()) {
        int value{};
        fileBackup >> value;

        if (!fileBackup.eof())
            fileData << value << ' ';
    }

    fileBackup.close();
    fileData.close();

    return true;
}

void FileManager::enableBackup() { isBackupEnabled = true; }

void FileManager::disableBackup() { isBackupEnabled = false; }