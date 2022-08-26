/**
 * @file Marquee.hpp
 * @brief Infinite marquee printing class
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MARQUEE_HPP
#define MARQUEE_HPP

#include <string>

class Marquee {
    private:
        const short defaultVelocity{7};
        std::string message{};
        short limitLeft{};
        short limitRight{};
        short verticalPosition{};
        short velocity{};
        bool pause { false };
        bool over { false };

        /**
         * @brief Print complete message of marquee
         * 
         * @param x 
         */
        void renderMarquee(short x);

        /**
         * @brief Print substring of marquee message
         * 
         * @param substring 
         * @param x 
         */
        void renderMarquee(const std::string& substring, short x);

        /**
         * @brief Clean the first character of message print on console
         * 
         * @param x 
         */
        void clearMarquee(short x);

    public:

        /**
         * @brief Construct a new Marquee object
         * 
         * @param initialMessage message that print on the console
         * @param xLimitleft horizontal position from where start print marquee
         * @param xLimitRight horizontal position until where should print marquee
         */
        Marquee(const std::string& initialMessage, short xLimitleft, short xLimitRight);

        void setTitle(const std::string& title);

        /**
         * @brief Set the vertical position of the message, when the value is zero the marquee will be print at the top of the console, the maximum value is the same of the hight console
         * 
         * @param y : 0 - hight of console
         */
        void setVerticalPosition(short y);

        /**
         * @brief Set the velocity of print
         * 
         * @param velocity 0 - 10
         */
        void setVelocity(short velocity);

        /**
         * @brief Start the printing of marquee
         * 
         */
        void print();

        /**
         * @brief Pause the render of marquee
         * 
         */
        void pauseExecution();

        /**
         * @brief Resumes the printing of the marquee
         * 
         */
        void resumeExecution();

        void startExecution();

        void endExecution();
};

#endif