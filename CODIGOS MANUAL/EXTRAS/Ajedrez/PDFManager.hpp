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
#ifndef PDF_MANAGER_HPP
#define PDF_MANAGER_HPP
#include <string>
#include <vector>
//#include "pdf.hpp"


class PDFManager
{
private:

public:
    /**
     * @brief generate report in PDF 
     * 
     */
    void generatePDF();

    /**
     * @brief Obtain data of game
     * 
     * @return std::vector <std::string> 
     */
    std::vector <std::string> Obtener_datos(std::string);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool verif_nombreArch(std::string);

    /**
     * @brief 
     * 
     * @return std::string 
     */
    std::string IngresarNombre();
};
#endif
