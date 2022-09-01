/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca de Veintemilla
				Kevin Vargas 
                Cristopher Iza
                Denisse Rea
					
	FECHA DE CREACION:        20-05-2022 	
	FECHA DE MODIFICACION:    24-05-2022
	Grupo #6
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
