#include "ScoreTextFileManager.hpp"
#include "GameInformation.hpp"
#include "Time.hpp"
#include "ArrayList.hpp"
#include "MenuGraphic.hpp"
#include <fstream>

const std::string ScoreTextFileManager::scoreFileName{ "score.txt" };
const std::string ScoreTextFileManager::backupsRegisterFileName { "BackupsRegister.txt" };

bool ScoreTextFileManager::saveUser(const std::string& user) {
    std::ofstream scoreFile { scoreFileName, std::ios::app };

    if (scoreFile.fail())
        return false;

    scoreFile << user << '\n';

    scoreFile.close();

    return true;
}

bool ScoreTextFileManager::saveScore() {
    std::ofstream scoreFile { scoreFileName, std::ios::app };

    if (scoreFile.fail())
        return false;
    
    if (GameInformation::score >= GameInformation::scoreForNextLevel)
        scoreFile << "Nivel " << GameInformation::level << " = Completado\t";
    else
        scoreFile << "Nivel " << GameInformation::level << " = " << GameInformation::score << '\t';

    scoreFile.close();

    return true;
}

bool ScoreTextFileManager::saveBackup() {
    std::ifstream scoreFile { scoreFileName, std::ios::in };

    if (scoreFile.fail())
        return false;

    std::string backupFileName { "Backup_" + Time::currentDate() + "_" + Time::currentTime() + ".txt" };
    std::ofstream newBackup { backupFileName, std::ios::out };

    if (newBackup.fail())
        return false;

    std::string line{};

    while (!scoreFile.eof()) {
        std::getline(scoreFile, line);
        newBackup << line;

        if (!line.empty())
            newBackup << '\n';
    }

    scoreFile.close();
    newBackup.close();

    std::ofstream backupsRegister { backupsRegisterFileName, std::ios::app };

    if (backupsRegister.fail())
        return false;

    backupsRegister << backupFileName << '\n';
    backupsRegister.close();

    return true;
}

bool ScoreTextFileManager::insertEndOfLine() {
    std::ofstream scoreFile { scoreFileName, std::ios::app };
    
    if (scoreFile.fail())
        return false;

    scoreFile << '\n';

    scoreFile.close();

    return true;
}

bool ScoreTextFileManager::recoverBackup() {
    std::ifstream backupsRegister { backupsRegisterFileName, std::ios::in };

    if (backupsRegister.fail())
        return false;

    ArrayList<std::string> backupsName{};

    std::string fileName{};
    while (!backupsRegister.eof()) {
        std::getline(backupsRegister, fileName);
        backupsName.addLast(fileName);
    }

    backupsRegister.close();

    MenuGraphic menuBackups { "Backups", Color::green };
    
    menuBackups.setOptions(backupsName);
    menuBackups.setUnselectedOptionColor(Color::white);
    menuBackups.setSelectedOptionColor(Color::red);
    menuBackups.setPosition(Position{15, 5});
    const short fileToRecover { menuBackups.render() };

    std::ifstream backupToRecover { backupsName[fileToRecover - 1], std::ios::in };

    if (backupToRecover.fail())
        return false;

    std::ofstream scoreFile { scoreFileName, std::ios::out };

    if (scoreFile.fail())
        return false;

    std::string line{};
    while (!backupToRecover.eof()) {
        std::getline(backupToRecover, line);
        scoreFile << line;

        if (!line.empty())
            scoreFile << '\n';
    }

    backupToRecover.close();
    scoreFile.close();

    return true;
}