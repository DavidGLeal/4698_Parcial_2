/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file PrintBitMap.hpp
 * @brief Class that use bitmap library with the purpose of print image on console
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PRINT_BITMAP_HPP
#define PRINT_BITMAP_HPP

#include <string>

class PrintBitmap {
    private:
        static std::string charPixel(int intensity) noexcept;
        static void fontSize(int x, int y) noexcept;

    public:
        static void printImage(const std::string &bitmapFileName);
};

#endif