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
#ifndef LOGIN_HPP
#define LOGIN_HPP

class MenuGUI;
class Login {
    private:

    static MenuGUI menuLogin;
    /**
     * @brief Selects the option of the menu
     * 
     * @param selectedOption 
     * @return true 
     * @return false 
     */
    static bool switchOption(int selectedOption);

    /**
     * @brief Gives acces to the login sub-menu
     * 
     */
    static void loginMenu();

    /**
     * @brief Gives access to the signup sub-menu
     * 
     */
    static void signUpMenu();

    public:

    /**
     * @brief Launches the menu
     * 
     */
    static void start();
};



#endif
