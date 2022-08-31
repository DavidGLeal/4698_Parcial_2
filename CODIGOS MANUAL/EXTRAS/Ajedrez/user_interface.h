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
#pragma once
#include "chess.h"

#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF
#define EMPTY_SQUARE 0x20

/**
 * @brief Create a Next Message object
 * 
 * @param msg 
 */
void createNextMessage( string msg );

/**
 * @brief 
 * 
 * @param msg 
 */
void appendToNextMessage( string msg );

/**
 * @brief 
 * 
 */
void clearScreen( void );

/**
 * @brief 
 * 
 */
void printLogo( void );

/**
 * @brief 
 * 
 */
void printLogo( void );

/**
 * @brief 
 * 
 */
void printMenu( void );

/**
 * @brief 
 * 
 */
void printMessage( void );

/**
 * @brief 
 * 
 * @param iLine 
 * @param iColor1 
 * @param iColor2 
 * @param game 
 */
void printLine( int iLine, int iColor1, int iColor2, Game& game );

/**
 * @brief 
 * 
 * @param game 
 */
void printSituation( Game& game );

/**
 * @brief 
 * 
 * @param game 
 */
void printBoard(Game& game);
