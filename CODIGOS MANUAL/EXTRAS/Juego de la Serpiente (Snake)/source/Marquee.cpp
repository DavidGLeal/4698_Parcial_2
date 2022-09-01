#include "Marquee.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <conio.h>
#include <windows.h>

void Marquee::renderMarquee(short x) {
    printf("\033[%d;%dH%s", verticalPosition, x, message.c_str());
}

void Marquee::renderMarquee(const std::string& substring, short x) {
    printf("\033[%d;%dH%s", verticalPosition, x, substring.c_str());
}

void Marquee::clearMarquee(short xActualPosition) {
    const unsigned char blankSpace{32};
    printf("\033[%d;%dH%c", verticalPosition, xActualPosition - 1, blankSpace);
}

Marquee::Marquee(const std::string& initialMessage, short xLimitleft, short xLimitRight) {
    message = initialMessage;
    limitLeft = xLimitleft;
    limitRight = xLimitRight;
    setVelocity(defaultVelocity);
}

void Marquee::setTitle(const std::string& title) {
    message = title;
}

void Marquee::setVerticalPosition(short y) {
    verticalPosition = y;
}

void Marquee::setVelocity(short newVelocity) {
    const short minimumTimeInMilliseconds{100};
    const short maximumTimeInMilliseconds{1000};
    const short minimumWaitTimeFoNextInstruction{minimumTimeInMilliseconds};
    const short maximumWaitTimeForNextInstruction{maximumTimeInMilliseconds};
    // Minimum value for newVelocity variable
    const short minimumSpeed{0};
    // Maximum value for newVelocity variable
    const short maximumSpeed{10};
    const short slope{(maximumWaitTimeForNextInstruction - minimumWaitTimeFoNextInstruction) / (minimumSpeed - maximumSpeed)};

    if (newVelocity < 0 || newVelocity > 10)
        newVelocity = defaultVelocity;

    velocity = slope * newVelocity + maximumWaitTimeForNextInstruction;
}

void Marquee::print() {

    printf("\033[?25l");

    // Print from last until first character of the message
    for (short i{static_cast<short>(message.length())}; i > 0; i--) {
        while (pause) {};
        printf("\033[%d;%dH%s", verticalPosition, limitLeft, std::string(message, i, static_cast<short>(message.length()) - i).c_str());
        Sleep(velocity);

        if (over)
            return;
    }

    short x{limitLeft};
    while (!over) {
        while (pause) {};

        if (x < limitRight - static_cast<short>(message.length())) {
            renderMarquee(x);

            clearMarquee(x);
        } else {

            clearMarquee(x);

            renderMarquee(std::string(message, 0, limitRight - x), x);

            renderMarquee(std::string(message, limitRight - x, static_cast<short>(message.length()) - (limitRight - x)), limitLeft);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(velocity));
        x++;

        if (x > limitRight)
            x = limitLeft;
    }

    printf("\033[?25h");
}

void Marquee::pauseExecution() {
    pause = true;
}

void Marquee::resumeExecution() {
    pause = false;
}

void Marquee::startExecution() {
    over = false;
}

void Marquee::endExecution() {
    over = true;
}