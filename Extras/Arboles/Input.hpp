/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file Input.hpp
 * @author Grupo 1 y 20
 * @brief Class that simulate scanf function
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-13
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INPUT_HPP
#define INPUT_HPP

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
         * @return char* 
         */
        static char *word(short minimumCharacters, short maximumCharacters);

        /**
         * @brief Enter numericc characters. Util for numbers greather or equals than ten digits
         * 
         * @param minimumDigits (without restriction)
         * @param maximumDigits (without restriction)
         * @return char* 
         */
        static char *digits(short minimumDigits, short maximumDigits);

        /**
         * @brief Enter alphabetics characters and also space key
         * 
         * @param minimumLetters (without restriction)
         * @param maximumLetters (without restriction)
         * @return char* 
         */
        static char *alphabetic(short minimumLetters, short maximumLetters);

        /**
         * @brief Enter alphabetics and numeric characters and also space key
         * 
         * @param minimumCharacters (without restriction)
         * @param maximumCharacters (without restriction)
         * @return char* 
         */
        static char *alphanumeric(short minimumCharacters, short maximumCharacters);
};

#endif