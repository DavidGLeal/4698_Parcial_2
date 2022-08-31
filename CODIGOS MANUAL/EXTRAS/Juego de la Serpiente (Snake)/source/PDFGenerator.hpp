/**
 * @file PDFGenerator.hpp
 * @brief Class that generates pdf files through an external library
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PDF_GENERATOR_HPP
#define PDF_GENERATOR_HPP

#include <string>

class PDFGenerator {
    private:

        /**
         * @brief Return a recopilation of all scores obtained of an specified user
         * 
         * @param user 
         * @return std::string 
         */
        static std::string scoreRecopilation(const std::string& user);

    public:

        /**
         * @brief Generate a PDF file with the scoreRecopilation function
         * 
         * @param user 
         */
        static void generate(const std::string& user);
};

#endif