/**
 * @file Input.hpp
 * @brief Class that simulate scanf function
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

class Input {

    public:
        /**
         * @brief Enter numeric characters. Throw: DigitsOutOfBoundException
         * 
         * @param minimumDigits > 0
         * @param maximumDigits < 10
         * @return int 
         */
        static int unsignedIntegerNumber(short minimumDigits, short maximumDigits);

        /**
         * @brief Enter numeric and '.' character. Throw: DigitsOutOfBoundsException
         * 
         * @param minimumDigits > 0
         * @param maximumDigits < 15
         * @return double 
         */
        static double unsignedRealNumber(short minimumDigits, short maximumDigits);

        /**
         * @brief Enter numeric and '-' characters. Throw: DigitsOutOfBoundsException
         * 
         * @param minimumDigits > 0
         * @param maximumDigits < 10
         * @return int 
         */
        static int integerNumber(short minimumDigits, short maximumDigits);

        /**
         * @brief Enter numeric, '.' and '-' characters. Throw: DigitsOutOfBoundsException
         * 
         * @param minimumDigits > 0
         * @param maximumDigits < 15
         * @return double 
         */
        static double realNumber(short minimumDigits, short maximumDigits);

        /**
         * @brief Enter alphabetics characters
         * 
         * @param minimumCharacters (without restriction)
         * @param maximumCharacters (without restriction)
         * @return std::string 
         */
        static std::string word(short minimumCharacters, short maximumCharacters);

        /**
         * @brief Enter numericc characters. Util for numbers greather or equals than ten digits
         * 
         * @param minimumDigits (without restriction)
         * @param maximumDigits (without restriction)
         * @return std::string 
         */
        static std::string digits(short minimumDigits, short maximumDigits);

        /**
         * @brief Enter alphabetics characters and also space key
         * 
         * @param minimumLetters (without restriction)
         * @param maximumLetters (without restriction)
         * @return std::string 
         */
        static std::string alphabetic(short minimumLetters, short maximumLetters);

        /**
         * @brief Enter alphabetics and numeric characters and also space key
         * 
         * @param minimumCharacters (without restriction)
         * @param maximumCharacters (without restriction)
         * @return std::string 
         */
        static std::string alphanumeric(short minimumCharacters, short maximumCharacters);

        /**
         * @brief Enter alphanumeric characters
         * 
         * @param minimumCharacters 
         * @param maximumCharacters 
         * @return std::string 
         */
        static std::string password(short minimumCharacters, short maximumCharacters);
};

#endif