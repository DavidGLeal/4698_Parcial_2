#include "PrintBitMap.hpp"
#define _CRT_SECURE_NO_WARNINGS
#include "bitmap_image.hpp"
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

std::string PrintBitmap::charPixel(int intensity) noexcept {
    std::vector<std::string> map{"$", "@", "B", "%", "8", "&", "W", "M",  "#", "*", "o", "a", "h",  "k", "b", "d", "p",
                                 "q", "w", "m", "Z", "O", "0", "Q", "L",  "C", "J", "U", "Y", "X",  "z", "c", "v", "u",
                                 "n", "x", "r", "j", "f", "t", "/", "\\", "|", "(", ")", "1", "{",  "}", "[", "]", "?",
                                 "-", "_", "+", "~", "<", ">", "i", "!",  "l", "I", ";", ":", "\"", "^", "`", "'", "."};
    return map[intensity];
}

void PrintBitmap::fontSize(int x, int y) noexcept {
    CONSOLE_FONT_INFOEX cfi{};
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = x;
    cfi.dwFontSize.Y = y;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void PrintBitmap::printImage(const std::string &bitmapFileName) {
    bitmap_image image(bitmapFileName);
    system("timeout /t 1 /nobreak > nul");
    if (!image)
        return;
    unsigned int width = image.width();
    unsigned int height = image.height();

    std::string str;
    std::string pixel;
    fontSize(2, 2);
    system("mode con cols=440 lines=285");

    bool exit{false};

    double unit = (256.0 + 1) / 68.0;
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            unsigned char red, green, blue;
            image.get_pixel(x, y, red, green, blue);

            int R = (int)(red);
            int G = (int)(green);
            int B = (int)(blue);

            int grayScaleValue = (int)((B * 0.0722) + // B
                                       (G * 0.7152) + // G
                                       (R * 0.2126)); // R
            int intensity = (int)(grayScaleValue / unit);
            str = charPixel(intensity);
            pixel += str;

            printf("\033[%d;2;%d;%d;%dm%c\033[0;00m", 48, R, G, B, str[0]);

            if (kbhit())
                exit = getch() == 27;

            if (exit)
                break;
        }
        pixel += "\n";
        std::cout << std::endl;

        if (exit)
            break;
    }
    
    
    system("pause > nul");
    system("cls");
    fontSize( 8, 16 );
    system("mode con cols=140 lines=40");
}