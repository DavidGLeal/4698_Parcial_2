#include "Time.hpp"


short Time::currentDay() {
    std::time_t timeMark { time(nullptr) };
    std::tm* timer { std::localtime( &timeMark )};
    return timer->tm_mday;
}

short Time::currentMonth() {
    std::time_t timeMark { time(nullptr) };
    std::tm* timer { std::localtime( &timeMark )};
    return timer->tm_mon + 1;
}

short Time::currentYear() {
    std::time_t timeMark { time(nullptr) };
    std::tm* timer { std::localtime( &timeMark )};
    return timer->tm_year + 1900;
}

short Time::currentHour() {
    std::time_t timeMark { time(nullptr) };
    std::tm* timer { std::localtime( &timeMark )};
    return timer->tm_hour;
}

short Time::currentMinut() {
    std::time_t timeMark { time(nullptr) };
    std::tm* timer { std::localtime( &timeMark )};
    return timer->tm_min;
}

short Time::currentSecond() {
    std::time_t timeMark { time(nullptr) };
    std::tm* timer { std::localtime( &timeMark )};
    return timer->tm_sec;
}

std::string Time::currentDate() {
    return std::string {
        std::to_string(currentYear()) + "-" +
        std::to_string(currentMonth()) + "-" +
        std::to_string(currentDay())
    };
}

std::string Time::currentTime() {
    return std::string {
        std::to_string(currentHour()) + "-" +
        std::to_string(currentMinut()) + "-" +
        std::to_string(currentSecond())
    };
}