/*
* @flie Input.h
* @author Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos - Estructura de Datos
* @date 19/7/2022
* @brief Archivo de cabecera para la clase Input.h
* @version 1.0
* 
*@copyright Copyright (c) 2022,Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos 
*@license MIT License
*/


#ifndef INPUT_HPP
#define INPUT_HPP

class Input {

    public:
        /** 
         * @brief method usingd Interger Numbers to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static int unsignedIntegerNumber(short minimumDigits, short maximumDigits);
        /** 
         * @brief method usingd Interger Numbers to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static double unsignedRealNumber(short minimumDigits, short maximumDigits);
        /** 
         * @brief method usingd Interger Numbers to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static int integerNumber(short minimumDigits, short maximumDigits);
        /** 
         * @brief method usingd real Numbers to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static double realNumber(short minimumDigits, short maximumDigits);
        /** 
         * @brief method *usingd String to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static char *word(short minimumCharacters, short maximumCharacters);
        /** 
         * @brief method *digits String to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static char *digits(short minimumDigits, short maximumDigits);
        /** 
         * @brief method *alphabetic String to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static char *alphabetic(short minimumLetters, short maximumLetters);
        /** 
         * @brief method *alphanumeric String to select the option
         *  
         * @param short int
         * @param short int
         * 
         * @return int
         */
        static char *alphanumeric(short minimumCharacters, short maximumCharacters);
};

#endif