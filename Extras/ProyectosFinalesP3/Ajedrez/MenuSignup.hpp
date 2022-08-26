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
#ifndef MENUSIGNUP_HPP
#define MENUSIGNUP_HPP
#include <string>
class MenuGUI;
class MenuSignup {
    private:
    static std::string name;
    static std::string lastname;
    static std::string id;
    static std::string password;

    static MenuGUI innerMenuSignup;
    /**
     * @brief Selects the option of the menu
     * 
     * @param selectedOption 
     * @return true 
     * @return false 
     */
    static bool switchOption(int selectedOption);

    /**
     * @brief Registers the name of the user
     * 
     */
    static void registerName();
    
    /**
     * @brief Registers the lastname of the user
     * 
     */
    static void registerLastName();

    /**
     * @brief Registers the password of the user
     * 
     */
    static void registerPassword();

    /**
     * @brief Registers the ID of the user
     * 
     */
    static void registerID();

    /**
     * @brief Create account and save it on txt list
     * 
     */
    static void createAccount();

    public:

    /**
     * @brief Launches the menu
     * 
     */
    static void start();
};

#endif
