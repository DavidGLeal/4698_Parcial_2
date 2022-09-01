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
#ifndef MENULOGIN_HPP
#define MENULOGIN_HPP
#include <string>
class MenuGUI;
class MenuLogin {
    private:

    static std::string id;
    static std::string password;

    static MenuGUI innerMenuLogin;
    /**
     * @brief Selects the option of the menu
     * 
     * @param selectedOption 
     * @return true 
     * @return false 
     */
    static bool switchOption(int selectedOption);

    /**
     * @brief Enters and verifies the username of the user
     * 
     */
    static void enterUser();

    /**
     * @brief Enters and verifies the password of the user
     * 
     */
    static void enterPassword();
    /**
     * @brief If user is verified,main menu deploys
     * 
     */
    static void enterMainMenu();
    public:

    /**
     * @brief Launches the menu 
     * 
     */
    static void start();
};

#endif
