/**
 * @file Time.hpp
 * @brief class that calculates time and current date
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TIME_HPP
#define TIME_HPP

#include <ctime>
#include <string>

class Time {
    private:

    public:
        /**
         * @brief 
         * 
         * @return short 
         */
        static short currentDay();

        /**
         * @brief 
         * 
         * @return short 
         */
        static short currentMonth();

        /**
         * @brief 
         * 
         * @return short 
         */
        static short currentYear();

        /**
         * @brief 
         * 
         * @return short 
         */
        static short currentHour();

        /**
         * @brief 
         * 
         * @return short 
         */
        static short currentMinut();

        /**
         * @brief 
         * 
         * @return short 
         */
        static short currentSecond();

        /**
         * @brief 
         * 
         * @return short 
         */
        static std::string currentDate();

        /**
         * @brief 
         * 
         * @return short 
         */
        static std::string currentTime();
};

#endif