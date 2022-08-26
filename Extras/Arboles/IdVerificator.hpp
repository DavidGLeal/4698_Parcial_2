/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * @file IdVerificator.hpp
 * @author Grupo 1 y 20
 * @brief Class that verify the validation of identification card in Ecuador
 * Github: https://github.com/ChristopherIza/Arboles_AVL.git
 * @version 0.1
 * @date 2022-07-13
 * Date last modification: 2022-07-14
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ID_VERIFICATOR_HPP
#define ID_VERIFICATOR_HPP

#include <string>

class IdVerificator {
    public:
        /**
         * @brief Verify the validation of identification card
         * 
         * @param idCard would contain only ten digits
         * @return true 
         * @return false 
         */
        static bool isValid(const std::string &idCard);
};


#endif