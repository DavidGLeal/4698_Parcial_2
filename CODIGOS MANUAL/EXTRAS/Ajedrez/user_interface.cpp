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
#include "user_interface.h"

// Save the next message to be displayed (regardind last command)
string next_message;

//---------------------------------------------------------------------------------------
// User interface
// All the functions regarding the user interface are in this section
// Logo, Menu, Board, messages to the user
//---------------------------------------------------------------------------------------
void createNextMessage( string msg )
{
   next_message = msg;
}

void appendToNextMessage( string msg )
{
   next_message += msg;
}
void clearScreen(void)
{
   system("cls");
}

void printLogo(void)
{
  

   cout<<"   ---------------------------------------------------------   \n";        
   cout<<"     (  _  )     _            ( )                     \n";
   cout<<"     | (_) |    (_)   __     _| | _ __    __   ____   \n";
   cout<<"     |  _  |    | | /'__`\\ /'_` |( '__) /'__`\\(_  ,)  \n";
   cout<<"     | | | |    | |(  ___/( (_| || |   (  ___/ /'/_   \n";
   cout<<"     (_) (_) _  | |`\\____)`\\__,_)(_)   `\\____)(____)  \n";
   cout<<"            ( )_| |                                    \n";
   cout<<"           `\\___/'                                    \n";
   cout<<"   ----------------------------------------------------------  \n";
}

void printMenu(void)
{
   cout << "Comandos: (N)uevo Juego \t(M)ovimiento \t(D)eshacer \t(S)alvar partida \t(L)lenar \t(Q)uitar \n";
}

void printMessage(void)
{
   cout << next_message << endl;

   next_message = "";
}

void printLine(int iLine, int iColor1, int iColor2, Game& game)
{
   
   int CELL = 6;

   
   for (int subLine = 0; subLine < CELL/2; subLine++)
   {
     
      for (int iPair = 0; iPair < 4; iPair++)
      {
        
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
          
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine, iPair*2) != 0x20 ? game.getPieceAtPosition(iLine, iPair*2) : iColor1);
            }
            else
            {
               cout << char(iColor1);
            }
         }

        
         for (int subColumn = 0; subColumn < CELL; subColumn++)
         {
           
            if ( subLine == 1 && subColumn == 3)
            {
               cout << char(game.getPieceAtPosition(iLine,iPair*2+1) != 0x20 ? game.getPieceAtPosition(iLine,iPair*2+1) : iColor2);
            }
            else
            {
               cout << char(iColor2);
            }
         }
      }

      
      if ( 1 == subLine )
      {
         cout << "   " << iLine+1;
      }

      cout << "\n";

   }
}

void printSituation(Game& game)
{
   
   if ( 0 != game.rounds.size() )
   {
      cout << "Ultimos movimientos:\n";

      int iMoves = game.rounds.size();
      int iToShow = iMoves >= 5 ? 5 : iMoves;

      string space = "";

      while( iToShow-- )
      {
         if ( iMoves < 10 )
         {
           
            space = " ";
         }

         cout << space << iMoves << " ..... " <<  game.rounds[iMoves-1].white_move.c_str() << " | " << game.rounds[iMoves - 1].black_move.c_str() << "\n";
         iMoves--;
      }

      cout << "\n";
   }

  
   if ( 0 != game.white_captured.size() || 0 != game.black_captured.size() )
   {
      cout << "---------------------------------------------\n";
      cout << "Pieza blanca capturada: ";
      for (unsigned i = 0; i < game.white_captured.size(); i++)
      {
         cout << char(game.white_captured[i]) << " ";
      }
      cout << "\n";

      cout << "Pieza negra capturada: ";
      for (unsigned i = 0; i < game.black_captured.size(); i++)
      {
         cout << char(game.black_captured[i]) << " ";
      }
      cout << "\n";

      cout << "---------------------------------------------\n";
   }

   
   cout << "Turno de : " << (game.getCurrentTurn() == Chess::WHITE_PIECE ? "Blancas (Mayusculas)" : "Negras (minusculas)") << "\n\n";

}

void printBoard(Game& game)
{
   cout << "   A     B     C     D     E     F     G     H\n\n";

   for (int iLine = 7; iLine >= 0; iLine--)
   {
      if ( iLine%2 == 0)
      {
        
         printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, game);
      }

      else
      {
        
         printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, game);
      }
   }

   cout << "\n\n   A     B     C     D     E     F     G     H\n\n";
}
