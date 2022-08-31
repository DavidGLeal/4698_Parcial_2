#include "..\source\GameLevel.hpp"
#include <iostream>

void renderLevel1() {
    ArrayList<Block> blocks{};
    GameLevel::renderLevel(1, blocks);
}

void renderLevel2() {
    ArrayList<Block> blocks{};
    GameLevel::renderLevel(2, blocks);
}

void renderLevel3() {
    ArrayList<Block> blocks{};
    GameLevel::renderLevel(3, blocks);
}

int main() {
    system("cls");
    renderLevel1();

    GameLevel::renderScore(20);
    system("pause > nul");

    GameLevel::renderScore(20);
    system("pause > nul");

    renderLevel2();
    system("pause > nul");

    GameLevel::renderScore(2);
    system("pause > nul");

    renderLevel3();
    system("pause > nul");

    GameLevel::renderScore(100);
    system("pause > nul");
    
    return 0;
}