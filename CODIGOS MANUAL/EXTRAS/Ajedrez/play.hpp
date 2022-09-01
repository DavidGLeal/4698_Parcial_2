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
#include "includes.h"

#include <string.h> // memcpy on linux

using namespace std;

#include "user_interface.h"
//#include "chess.h"

class play{
    public:

    /**
     * @brief 
     * 
     * @param present 
     * @param future 
     * @param S_enPassant 
     * @param S_castling 
     * @param S_promotion 
     * @return true 
     * @return false 
     */
    bool isMoveValid(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion);

    /**
     * @brief 
     * 
     * @param present 
     * @param future 
     * @param S_enPassant 
     * @param S_castling 
     * @param S_promotion 
     */
    void makeTheMove(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion);

    /**
     * @brief 
     * 
     */
    void newGame(void);

    /**
     * @brief 
     * 
     */
    void undoMove(void);

    /**
     * @brief 
     * 
     */
    void movePiece(void);

    /**
     * @brief 
     * 
     */
    void saveGame(void);

    /**
     * @brief 
     * 
     */
    void loadGame(void);

    /**
     * @brief 
     * 
     */
    void start();
    private:
    Game* current_game = NULL;

};
