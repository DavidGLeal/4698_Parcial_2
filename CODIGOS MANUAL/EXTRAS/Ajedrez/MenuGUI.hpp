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

#ifndef MENU_GUI_HPP
#define MENU_GUI_HPP

#include <windows.h>
#include <string>

class MenuGUI {
    private:
        std::string title{};
        const std::string *options{nullptr};
        COORD menuPosition{4, 4};
        COORD arrowPosition{static_cast<SHORT>(this->menuPosition.X - 2), this->menuPosition.Y};
        size_t sizeOfArrayOptions{};
        size_t activeOption{1};

        /**
         * @brief print array option on console
         * 
         */
        void printOptions();

        /**
         * @brief update arrow position on console
         * 
         */
        void printArrow();

        /**
         * @brief update option selected
         * 
         */
        void setNextOption();

        /**
         * @brief update option selected
         * 
         */
        void setPreviousOption();

        /**
         * @brief Choose action to realize
         * 
         * @param keyPressed 
         * @return true if exit option is selected
         * @return false if exit option is not selected
         */
        bool switchOption(int keyPressed);

    public:
        /**
         * @brief Construct a new MenuGUI object
         * 
         */
        MenuGUI() = default;

        /**
         * @brief Construct a new MenuGUI object
         * 
         * @param title 
         * @param arrayOptions 
         * @param amountOptions 
         * @param positionXY 
         */
        MenuGUI(const std::string &title, const std::string arrayOptions[], size_t amountOptions, const COORD &positionXY);

        /**
         * @brief Set the Title Menu object
         * 
         * @param newTitleOfMenu 
         */
        void setTitleMenu(const std::string &newTitleOfMenu);

        /**
         * @brief Set the List Options object
         * 
         * @param newListOptions 
         * @param newSizeOfArrayOptions 
         */
        void setListOptions(const std::string newListOptions[], size_t newSizeOfArrayOptions);

        /**
         * @brief Set the Position Of Menu object
         * 
         * @param newPositionOfMenu 
         */
        void setPositionOfMenu(const COORD &newPositionOfMenu);
        
        /**
         * @brief print menu on console and initialize algorithm
         * 
         * @return int 
         */
        int print();
};

#endif
