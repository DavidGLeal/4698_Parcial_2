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
