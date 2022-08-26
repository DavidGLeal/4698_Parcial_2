#ifndef GAME_INFORMATION_HPP
#define GAME_INFORMATION_HPP

namespace GameInformation {
    inline constexpr short width{20};
    inline constexpr short hight{15};
    inline constexpr short leftWall{10};
    inline constexpr short rightWall{leftWall + width + 1};
    inline constexpr short superiorWall{5};
    inline constexpr short inferiorWall{superiorWall + hight + 1};
    inline constexpr short levels{3};
    inline constexpr short maxScore{100};
    inline constexpr short maxVelocity{5};
    inline short level{1};
    inline short scoreForNextLevel{30};
    inline short score{};
    inline short velocity{3};
}

#endif