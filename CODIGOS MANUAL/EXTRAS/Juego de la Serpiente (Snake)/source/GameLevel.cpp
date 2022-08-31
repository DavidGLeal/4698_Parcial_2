#include "GameLevel.hpp"
#include "GameInformation.hpp"
#include <iostream>

void GameLevel::renderWalls() {
    constexpr unsigned char leftWallSprite{186};
    constexpr unsigned char rightWallSprite{186};

    std::cout << "\033[?25l";

    for (short i{GameInformation::superiorWall + 1}; i <= GameInformation::inferiorWall; ++i) {
        printf("\033[%d;%dH%c", i, GameInformation::leftWall, leftWallSprite);
        printf("\033[%d;%dH%c", i, GameInformation::rightWall, rightWallSprite);
    }

    constexpr unsigned char superiorWallSprite{205};
    constexpr unsigned char inferiorWallSprite{205};
    
    for (short i{GameInformation::leftWall + 1}; i <= GameInformation::rightWall; ++i) {
        printf("\033[%d;%dH%c", GameInformation::superiorWall, i, superiorWallSprite);
        printf("\033[%d;%dH%c", GameInformation::inferiorWall, i, inferiorWallSprite);
    }

    constexpr unsigned char upperLeftCornerSprite{201};
    printf("\033[%d;%dH%c", GameInformation::superiorWall, GameInformation::leftWall, upperLeftCornerSprite);

    constexpr unsigned char upperRightCornerSprite{187};
    printf("\033[%d;%dH%c", GameInformation::superiorWall, GameInformation::rightWall, upperRightCornerSprite);

    constexpr unsigned char lowerLeftCornerSprite{200};
    printf("\033[%d;%dH%c", GameInformation::inferiorWall, GameInformation::leftWall, lowerLeftCornerSprite);

    constexpr unsigned char lowerRightCornerSprite{188};
    printf("\033[%d;%dH%c", GameInformation::inferiorWall, GameInformation::rightWall, lowerRightCornerSprite);
}

void GameLevel::renderLevel(const short level, ArrayList<Block>& blocks) {
    system("cls");
    blocks.clear();
    
    switch(level) {
        case 1:
            break;
        case 2:
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 5, GameInformation::superiorWall + 3 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 14, GameInformation::superiorWall + 3 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 5, GameInformation::superiorWall + 11 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 14, GameInformation::superiorWall + 11 } });
            break;
        case 3:
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 5, GameInformation::superiorWall + 3 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 14, GameInformation::superiorWall + 3 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 5, GameInformation::superiorWall + 7 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 14, GameInformation::superiorWall + 7 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 5, GameInformation::superiorWall + 11 } });
            blocks.addLast(Block{ Position{ GameInformation::leftWall + 14, GameInformation::superiorWall + 11 } });
            break;
        default:
            std::cout << "\nNivel no existe\n";
    }

    renderWalls();
    renderScore();
    
    for (const auto& block : blocks)
        block.render();
}

void GameLevel::renderScore() {
    printf("\033[?25l\033[%d;%dHScore: %03d", GameInformation::superiorWall - 2, GameInformation::leftWall, GameInformation::score);
}