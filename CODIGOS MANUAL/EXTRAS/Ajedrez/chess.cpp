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
//#include "chess.h"
#include "user_interface.h"


int Chess::getPieceColor(char chPiece)
{
   if (isupper(chPiece))
   {
      return WHITE_PIECE;
   }
   else
   {
      return BLACK_PIECE;
   }
}

bool Chess::isWhitePiece(char chPiece)
{
   return getPieceColor(chPiece) == Chess::WHITE_PIECE ? true : false;
}

bool Chess::isBlackPiece(char chPiece)
{
   return getPieceColor(chPiece) == Chess::BLACK_PIECE ? true : false;
}

std::string Chess::describePiece(char chPiece)
   {
      std::string description;

      if (isWhitePiece(chPiece))
      {
         description += "White ";
      }
      else
      {
         description += "Black ";
      }

      switch (toupper(chPiece))
      {
         case 'P':
         {
            description += "peon";
         }
         break;

         case 'C':
         {
            description += "caballo";
         }
         break;

         case 'A':
         {
            description += "alfil";
         }
         break;

         case 'T':
         {
            description += "torre";
         }
         break;

         case 'D':
         {
            description += "reina";
         }
         break;

         default:
         {
            description += "Pieza desconocida";
         }
         break;
      }

      return description;
   }

 

Game::Game()
{

   m_CurrentTurn = WHITE_PLAYER;


   m_bGameFinished = false;

  
   m_undo.bCapturedLastMove         = false;
   m_undo.bCanUndo                  = false;
   m_undo.bCastlingKingSideAllowed  = false;
   m_undo.bCastlingQueenSideAllowed = false;
   m_undo.en_passant.bApplied       = false;
   m_undo.castling.bApplied         = false;

   
   memcpy(board, initial_board, sizeof(char) * 8 * 8);

 
   m_bCastlingKingSideAllowed[WHITE_PLAYER]  = true;
   m_bCastlingKingSideAllowed[BLACK_PLAYER]  = true;

   m_bCastlingQueenSideAllowed[WHITE_PLAYER] = true;
   m_bCastlingQueenSideAllowed[BLACK_PLAYER] = true;
}

Game::~Game()
{
   white_captured.clear();
   black_captured.clear();
   rounds.clear();
}

void Game::movePiece(Position present, Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion)
{

   char chPiece = getPieceAtPosition(present);


   char chCapturedPiece = getPieceAtPosition(future);


   if (0x20 != chCapturedPiece)
   {
      if (WHITE_PIECE == getPieceColor(chCapturedPiece))
      {
    
         white_captured.push_back(chCapturedPiece);
      }
      else
      {
    
         black_captured.push_back(chCapturedPiece);
      }

 
      m_undo.bCapturedLastMove = true;
      
     
      memset( &m_undo.en_passant, 0, sizeof( Chess::EnPassant ));
   }
   else if (true == S_enPassant->bApplied)
   {
      char chCapturedEP = getPieceAtPosition(S_enPassant->PawnCaptured.iRow, S_enPassant->PawnCaptured.iColumn);

      if (WHITE_PIECE == getPieceColor(chCapturedEP))
      {
       
         white_captured.push_back(chCapturedEP);
      }
      else
      {
       
         black_captured.push_back(chCapturedEP);
      }

      
      board[S_enPassant->PawnCaptured.iRow][S_enPassant->PawnCaptured.iColumn] = EMPTY_SQUARE;

    
      m_undo.bCapturedLastMove = true;
      memcpy(&m_undo.en_passant, S_enPassant, sizeof(Chess::EnPassant));
   }
   else
   {
      m_undo.bCapturedLastMove   = false;
      
    
      memset( &m_undo.en_passant, 0, sizeof( Chess::EnPassant ));
   }

   
   board[present.iRow][present.iColumn] = EMPTY_SQUARE;

   
   if ( true == S_promotion->bApplied )
   {
      board[future.iRow][future.iColumn] = S_promotion->chAfter;

  
      memcpy(&m_undo.promotion, S_promotion, sizeof(Chess::Promotion));
   }
   else
   {
      board[future.iRow][future.iColumn] = chPiece;

   
      memset( &m_undo.promotion, 0, sizeof( Chess::Promotion ));
   }  


   if ( S_castling->bApplied == true  )
   {
     
      char chPiece = getPieceAtPosition(S_castling->rook_before.iRow, S_castling->rook_before.iColumn);

    
      board[S_castling->rook_before.iRow][S_castling->rook_before.iColumn] = EMPTY_SQUARE;

   
      board[S_castling->rook_after.iRow][S_castling->rook_after.iColumn] = chPiece;

     
      memcpy(&m_undo.castling, S_castling, sizeof(Chess::Castling));

     
      m_undo.bCastlingKingSideAllowed  = m_bCastlingKingSideAllowed[getCurrentTurn()] ;
      m_undo.bCastlingQueenSideAllowed = m_bCastlingQueenSideAllowed[getCurrentTurn()];
   }
   else
   {

      memset( &m_undo.castling, 0, sizeof( Chess::Castling ));
   }

 
   if ( 'R' == toupper(chPiece) )
   {
      
      m_bCastlingKingSideAllowed[getCurrentTurn()]  = false;
      m_bCastlingQueenSideAllowed[getCurrentTurn()] = false;
   }
   else if ('T' == toupper(chPiece) )
   {
   
      if ( 0 == present.iColumn )
      {
         m_bCastlingQueenSideAllowed[getCurrentTurn()] = false;
      }

   
      else if ( 7 == present.iColumn )
      {
         m_bCastlingKingSideAllowed[getCurrentTurn()] = false;
      }
   }


   changeTurns();


   m_undo.bCanUndo = true;
}

void Game::undoLastMove()
{
   string last_move = getLastMove();

 
   Chess::Position from;
   Chess::Position to;
   parseMove(last_move, &from, &to);


   char chPiece = getPieceAtPosition(to.iRow, to.iColumn);

   if ( true == m_undo.promotion.bApplied )
   {
      board[from.iRow][from.iColumn] = m_undo.promotion.chBefore;
   }
   else
   {
      board[from.iRow][from.iColumn] = chPiece;
   }


   changeTurns();

 
   if (m_undo.bCapturedLastMove)
   {

      char chCaptured;

    
      if (WHITE_PLAYER == m_CurrentTurn)
      {
         chCaptured = black_captured.back();
         black_captured.pop_back();
      }
      else
      {
         chCaptured = white_captured.back();
         white_captured.pop_back();
      }

    
      if (m_undo.en_passant.bApplied)
      {
    
         board[m_undo.en_passant.PawnCaptured.iRow][m_undo.en_passant.PawnCaptured.iColumn] = chCaptured;

        
         board[to.iRow][to.iColumn] = EMPTY_SQUARE;
      }
      else
      {
         board[to.iRow][to.iColumn] = chCaptured;
      }
   }
   else
   {
      board[to.iRow][to.iColumn] = EMPTY_SQUARE;
   }


   if ( m_undo.castling.bApplied )
   {
      char chRook = getPieceAtPosition(m_undo.castling.rook_after.iRow, m_undo.castling.rook_after.iColumn);


      board[m_undo.castling.rook_after.iRow][m_undo.castling.rook_after.iColumn] = EMPTY_SQUARE;

 
      board[m_undo.castling.rook_before.iRow][m_undo.castling.rook_before.iColumn] = chRook;

   
      m_bCastlingKingSideAllowed[getCurrentTurn()]  = m_undo.bCastlingKingSideAllowed;
      m_bCastlingQueenSideAllowed[getCurrentTurn()] = m_undo.bCastlingQueenSideAllowed;
   }


   m_undo.bCanUndo             = false;
   m_undo.bCapturedLastMove    = false;
   m_undo.en_passant.bApplied  = false;
   m_undo.castling.bApplied    = false;
   m_undo.promotion.bApplied   = false;


   m_bGameFinished = false;

 
   deleteLastMove();
}

bool Game::undoIsPossible()
{
   return m_undo.bCanUndo;
}

bool Game::castlingAllowed(Side iSide, int iColor)
{
   if ( QUEEN_SIDE == iSide )
   {
      return m_bCastlingQueenSideAllowed[iColor];
   }
   else 
   {
      return m_bCastlingKingSideAllowed[iColor];
   }
}

char Game::getPieceAtPosition(int iRow, int iColumn)
{
   return board[iRow][iColumn];
}

char Game::getPieceAtPosition(Position pos)
{
   return board[pos.iRow][pos.iColumn];
}

char Game::getPiece_considerMove(int iRow, int iColumn, IntendedMove* intended_move)
{
   char chPiece;


   if (nullptr == intended_move)
   {
      chPiece = getPieceAtPosition(iRow, iColumn);
   }
   else
   {

      if (intended_move->from.iRow == iRow && intended_move->from.iColumn == iColumn)
      {
       
         chPiece = EMPTY_SQUARE;
      }
      else if (intended_move->to.iRow == iRow && intended_move->to.iColumn == iColumn)
      {
   
         chPiece = intended_move->chPiece;
      }
      else
      {
         chPiece = getPieceAtPosition(iRow, iColumn);
      }
   }

   return chPiece;
}

Chess::UnderAttack Game::isUnderAttack(int iRow, int iColumn, int iColor, IntendedMove* pintended_move)
{
   UnderAttack attack = { 0 };


   {
    
      for (int i = iColumn + 1; i < 8; i++)
      {
         char chPieceFound = getPiece_considerMove(iRow, i, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
        
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
    
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'T') )
         {
       
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow = iRow;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = i;
            attack.attacker[attack.iNumAttackers-1].dir = HORIZONTAL;
            break;
         }
         else
         {
         
            break;
         }
      }

   
      for (int i = iColumn - 1; i >= 0; i--)
      {
         char chPieceFound = getPiece_considerMove(iRow, i, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
      
            continue;
         }

         if  (iColor == getPieceColor(chPieceFound) )
         {
          
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'T') )
         {
      
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = iRow;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = i;
            attack.attacker[attack.iNumAttackers-1].dir = HORIZONTAL;
            break;
         }
         else
         {
          
            break;
         }
      }
   }

  
   {
      
      for (int i = iRow + 1; i < 8; i++)
      {
         char chPieceFound = getPiece_considerMove(i, iColumn, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
         
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
           
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'T')  )
         {
            
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = iColumn;
            attack.attacker[attack.iNumAttackers-1].dir = VERTICAL;
            break;
         }
         else
         {
            
            break;
         }
      }

      
      for (int i = iRow - 1; i >= 0; i--)
      {
         char chPieceFound = getPiece_considerMove(i, iColumn, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
        
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
         
            break;
         }
         else if ((toupper(chPieceFound) == 'D') ||
                  (toupper(chPieceFound) == 'T') )
         {
         
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = iColumn;
            attack.attacker[attack.iNumAttackers-1].dir = VERTICAL;
            break;
         }
         else
         {
           
            break;
         }
      }
   }

  
   {
     
      for (int i = iRow + 1, j = iColumn + 1; i < 8 && j < 8; i++, j++)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
           
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    + 1        ) &&
                   (   j   == iColumn + 1        ) &&
                   (iColor == WHITE_PIECE ) )
         {
            
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A'))
         {
           
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
           
            break;
         }
      }


      for (int i = iRow + 1, j = iColumn - 1; i < 8 && j > 0; i++, j--)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
   
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
  
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    + 1        ) &&
                   (   j   == iColumn - 1        ) &&
                   (iColor == WHITE_PIECE ) )
         {
      
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A'))
         {
           
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
           
            break;
         }
      }

  
      for (int i = iRow - 1, j = iColumn + 1; i > 0 && j < 8; i--, j++)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
     
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
        
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    - 1        ) &&
                   (   j   == iColumn + 1        ) &&
                   (iColor == BLACK_PIECE ) )
         {
            
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A') )
         {
          
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
           
            break;
         }
      }

    
      for (int i = iRow - 1, j = iColumn - 1; i > 0 && j > 0; i--, j--)
      {
         char chPieceFound = getPiece_considerMove(i, j, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
           
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
        
            break;
         }
         else if ( (toupper(chPieceFound) == 'P' ) &&
                   (   i   == iRow    - 1        ) &&
                   (   j   == iColumn - 1        ) &&
                   (iColor == BLACK_PIECE ) )
         {
         
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                     (toupper(chPieceFound) == 'A') )
         {
    
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = i;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = j;
            attack.attacker[attack.iNumAttackers-1].dir = DIAGONAL;
            break;
         }
         else
         {
         
            break;
         }
      }
   }

  
   {
   

      Position knight_moves[8] = { {  1, -2 }, {  2, -1 }, {  2, 1 }, {  1, 2 },
                                   { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };
      for (int i = 0; i < 8; i++)
      {
         int iRowToTest    = iRow    + knight_moves[i].iRow;
         int iColumnToTest = iColumn + knight_moves[i].iColumn;

         if (iRowToTest < 0 || iRowToTest > 7 || iColumnToTest < 0 || iColumnToTest > 7)
         {
       
            continue;
         }

         char chPieceFound = getPiece_considerMove(iRowToTest, iColumnToTest, pintended_move);
         if (EMPTY_SQUARE == chPieceFound)
         {
       
            continue;
         }

         if (iColor == getPieceColor(chPieceFound))
         {
         
            continue;
         }
         else if ( (toupper(chPieceFound) == 'C') )
         {
            attack.bUnderAttack = true;
            attack.iNumAttackers += 1;

            attack.attacker[attack.iNumAttackers-1].pos.iRow    = iRowToTest;
            attack.attacker[attack.iNumAttackers-1].pos.iColumn = iColumnToTest;
            break;
         }
      }
   }

   return attack;
}

bool Game::isReachable( int iRow, int iColumn, int iColor )
{
   bool bReachable = false;

  
   {
 
      for (int i = iColumn + 1; i < 8; i++)
      {
         char chPieceFound = getPieceAtPosition(iRow, i);
         if (EMPTY_SQUARE == chPieceFound)
         {
        
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
         
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'T') )
         {
          
            bReachable = true;
            break;
         }
         else
         {
           
            break;
         }
      }

   
      for (int i = iColumn - 1; i >= 0; i--)
      {
         char chPieceFound = getPieceAtPosition(iRow, i);
         if (EMPTY_SQUARE == chPieceFound)
         {
            
            continue;
         }

         if  (iColor == getPieceColor(chPieceFound) )
         {

            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'T') )
         {
        
            bReachable = true;
            break;
         }
         else
         {
        
            break;
         }
      }
   }


   {
  
      for (int i = iRow + 1; i < 8; i++)
      {
         char chPieceFound = getPieceAtPosition(i, iColumn);
         if (EMPTY_SQUARE == chPieceFound)
         {
       
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
        
            break;
         }
         else if ( (toupper(chPieceFound)       == 'P' )         &&
                   (getPieceColor(chPieceFound) == BLACK_PIECE ) &&
                   ( i  == iRow + 1 )                            )  
         {
     
            bReachable = true;
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'T')  )
         {
         
            bReachable = true;
            break;
         }
         else
         {
        
            break;
         }
      }

     
      for (int i = iRow - 1; i >= 0; i--)
      {
         char chPieceFound = getPieceAtPosition(i, iColumn);
         if (EMPTY_SQUARE == chPieceFound)
         {
           
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
      
            break;
         }
         else if ( (toupper(chPieceFound)       == 'P' )         &&
                   (getPieceColor(chPieceFound) == WHITE_PIECE ) &&
                   ( i  == iRow - 1 )                            )  
         {
        
            bReachable = true;
            break;
         }
         else if ((toupper(chPieceFound) == 'D') ||
                  (toupper(chPieceFound) == 'T') )
         {
          
            bReachable = true;
            break;
         }
         else
         {
   
            break;
         }
      }
   }


   {
    
      for (int i = iRow + 1, j = iColumn + 1; i < 8 && j < 8; i++, j++)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
        
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
         
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A'))
         {
            
            bReachable = true;
            break;
         }
         else
         {
        
            break;
         }
      }

      
      for (int i = iRow + 1, j = iColumn - 1; i < 8 && j > 0; i++, j--)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
          
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
            
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A'))
         {
          
            bReachable = true;
            break;
         }
         else
         {
           
            break;
         }
      }

   
      for (int i = iRow - 1, j = iColumn + 1; i > 0 && j < 8; i--, j++)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
    
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
         
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A') )
         {
          
            bReachable = true;
            break;
         }
         else
         {
           
            break;
         }
      }

   
      for (int i = iRow - 1, j = iColumn - 1; i > 0 && j > 0; i--, j--)
      {
         char chPieceFound = getPieceAtPosition(i, j);
         if (EMPTY_SQUARE == chPieceFound)
         {
           
            continue;
         }

         if ( iColor == getPieceColor(chPieceFound) )
         {
           
            break;
         }
         else if ( (toupper(chPieceFound) == 'D') ||
                   (toupper(chPieceFound) == 'A') )
         {

            bReachable = true;
            break;
         }
         else
         {

            break;
         }
      }
   }

  
   {
     

      Position knight_moves[8] = { {  1, -2 }, {  2, -1 }, {  2, 1 }, {  1, 2 },
                                   { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };
      for (int i = 0; i < 8; i++)
      {
         int iRowToTest    = iRow    + knight_moves[i].iRow;
         int iColumnToTest = iColumn + knight_moves[i].iColumn;

         if (iRowToTest < 0 || iRowToTest > 7 || iColumnToTest < 0 || iColumnToTest > 7)
         {
        
            continue;
         }

         char chPieceFound = getPieceAtPosition(iRowToTest, iColumnToTest);
         if (EMPTY_SQUARE == chPieceFound)
         {
         
            continue;
         }

         if (iColor == getPieceColor(chPieceFound))
         {
         
            continue;
         }
         else if ( (toupper(chPieceFound) == 'C') )
         {
            bReachable = true;
            break;
         }
      }
   }

   return bReachable;
}

bool Game::isSquareOccupied(int iRow, int iColumn)
{
   bool bOccupied = false;

   if ( 0x20 != getPieceAtPosition(iRow,iColumn) )
   {
      bOccupied = true;
   }

   return bOccupied;
}

bool Game::isPathFree(Position startingPos, Position finishingPos, int iDirection)
{
   bool bFree = false;

   switch(iDirection)
   {
      case Chess::HORIZONTAL:
      {

         if (startingPos.iColumn == finishingPos.iColumn)
         {
            cout << "Error. El movimiento es horizontal pero la columna es la misma\n";
         }

     
         else if (startingPos.iColumn < finishingPos.iColumn)
         {
         
            bFree = true;
            
            for (int i = startingPos.iColumn + 1; i < finishingPos.iColumn; i++)
            {
               if (isSquareOccupied(startingPos.iRow, i))
               {
                  bFree = false;
                  cout << "El camino hacia la derecha no esta libre!\n";
               }
            }
         }

         
         else 
         {
    
            bFree = true;
            
            for (int i = startingPos.iColumn - 1; i > finishingPos.iColumn; i--)
            {
               if (isSquareOccupied(startingPos.iRow, i))
               {
                  bFree = false;
                  cout << "El camino hacia la izquierda no esta libre!\n";
               }
            }
         }
      }
      break;

      case Chess::VERTICAL:
      {

         if (startingPos.iRow == finishingPos.iRow)
         {
            cout << "Error. El movimiento es vertical pero la fila es la misma\n";
           throw("Error. El movimiento es vertical pero la fila es la misma");
         }


         else if (startingPos.iRow < finishingPos.iRow)
         {
           
            bFree = true;
            
            for (int i = startingPos.iRow + 1; i < finishingPos.iRow; i++)
            {
               if ( isSquareOccupied(i, startingPos.iColumn) )
               {
                  bFree = false;
                  cout << "El camino hacia arriba no esta libre!\n";
               }
            }
         }

        
         else 
         {
            
            bFree = true;
            
            for (int i = startingPos.iRow - 1; i > finishingPos.iRow; i--)
            {
               if ( isSquareOccupied(i, startingPos.iColumn) )
               {
                  bFree = false;
                  cout << "El camino hacia abajo no esta libre!\n";
               }
            }
         }
      }
      break;

      case Chess::DIAGONAL:
      {

         if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            
            bFree = true;

            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow + i, startingPos.iColumn + i))
               {
                  bFree = false;
                  cout << "Diagonal superior derecha no esta libre!\n";
               }
            }
         }

        
         else if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
         
            bFree = true;
            
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow+i, startingPos.iColumn-i))
               {
                  bFree = false;
                  cout << "Diagonal superior izquierda no esta libre!\n";
               }
            }
         }

       
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
           
            bFree = true;
            
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow - i, startingPos.iColumn + i))
               {
                  bFree = false;
                  cout << "Diagonal inferior derecha no esta libre!\n";
               }
            }
         }


         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
      
            bFree = true;
            
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if (isSquareOccupied(startingPos.iRow - i, startingPos.iColumn - i))
               {
                  bFree = false;
                  cout << "Diagonal inferior izquierda no esta libre!\n";
               }
            }
         }

         else
         {
            throw("Error. Movimiento diagonal no permitido");
         }
      }
      break;
   }

   return bFree;
}

bool Game::canBeBlocked(Position startingPos, Position finishingPos, int iDirection)
{
   bool bBlocked = false;
   
   Chess::UnderAttack blocker = {0};

   switch(iDirection)
   {
      case Chess::HORIZONTAL:
      {

         if (startingPos.iColumn == finishingPos.iColumn)
         {
            cout << "Error.El movimiento es horizontal pero la columna es la misma\n";
         }

       
         else if (startingPos.iColumn < finishingPos.iColumn)
         {
            for (int i = startingPos.iColumn + 1; i < finishingPos.iColumn; i++)
            {
               if ( true == isReachable( startingPos.iRow, i, getOpponentColor() ) )
               {
               
                  bBlocked = true;
               }
            }
         }

        
         else 
         {
            for (int i = startingPos.iColumn - 1; i > finishingPos.iColumn; i--)
            {
               if ( true == isReachable( startingPos.iRow, i, getOpponentColor() ) )
               {
             
                  bBlocked = true;
               }
            }
         }
      }
      break;

      case Chess::VERTICAL:
      {

         if (startingPos.iRow == finishingPos.iRow)
         {
            cout << "Error. El movimiento es vertical pero la fila es la misma\n";
           throw("Error. El movimiento es vertical pero la fila es la misma");
         }

  
         else if (startingPos.iRow < finishingPos.iRow)
         {
            for (int i = startingPos.iRow + 1; i < finishingPos.iRow; i++)
            {
               if ( true == isReachable( i, startingPos.iColumn, getOpponentColor() ) )
               {
                 
                  bBlocked = true;
               }
            }
         }

       
         else 
         {
            for (int i = startingPos.iRow - 1; i > finishingPos.iRow; i--)
            {
               if ( true == isReachable( i, startingPos.iColumn, getOpponentColor() ) )
               {
               
                  bBlocked = true;
               }
            }
         }
      }
      break;

      case Chess::DIAGONAL:
      {
       
         if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow + i, startingPos.iColumn + i, getOpponentColor() ) )
               {
              
                  bBlocked = true;
               }
            }
         }

       
         else if ( (finishingPos.iRow > startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow + i, startingPos.iColumn - i, getOpponentColor() ) )
               {
                
                  bBlocked = true;
               }
            }
         }

    
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn > startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow - i, startingPos.iColumn + i, getOpponentColor() ) )
               {
                
                  bBlocked = true;
               }
            }
         }

        
         else if ( (finishingPos.iRow < startingPos.iRow) && (finishingPos.iColumn < startingPos.iColumn) )
         {
            for (int i = 1; i < abs(finishingPos.iRow - startingPos.iRow); i++)
            {
               if ( true == isReachable( startingPos.iRow - i, startingPos.iColumn - i, getOpponentColor() ) )
               {
               
                  bBlocked = true;
               }
            }
         }

         else
         {
            cout << "Error. Movimiento diagonal no permitido\n";
            throw("Error. Movimiento diagonal no permitido");
         }
      }
      break;
   }

   return bBlocked;
}

bool Game::isCheckMate()
{
   bool bCheckmate = false;

   
   if ( false == playerKingInCheck() )
   {
      return false;
   }

  
   Chess::Position king_moves[8]  = { {  1, -1 },{  1, 0 },{  1,  1 }, { 0,  1 },
                                      { -1,  1 },{ -1, 0 },{ -1, -1 }, { 0, -1 } };

   Chess::Position king = findKing(getCurrentTurn() );

   for (int i = 0; i < 8; i++)
   {
      int iRowToTest    = king.iRow    + king_moves[i].iRow;
      int iColumnToTest = king.iColumn + king_moves[i].iColumn;

      if ( iRowToTest < 0 || iRowToTest > 7 || iColumnToTest < 0 || iColumnToTest > 7 )
      {
      
         continue;
      }

      if ( EMPTY_SQUARE != getPieceAtPosition(iRowToTest, iColumnToTest) )
      {
       
         continue;
      }

      Chess::IntendedMove intended_move;
      intended_move.chPiece      = getPieceAtPosition(king.iRow, king.iColumn);
      intended_move.from.iRow    = king.iRow;
      intended_move.from.iColumn = king.iColumn;
      intended_move.to.iRow      = iRowToTest;
      intended_move.to.iColumn   = iColumnToTest;

  
      Chess::UnderAttack king_moved = isUnderAttack( iRowToTest, iColumnToTest, getCurrentTurn(), &intended_move );

      if ( false == king_moved.bUnderAttack )
      {
       
         return false;
      }
   }

   
   Chess::UnderAttack king_attacked = isUnderAttack( king.iRow, king.iColumn, getCurrentTurn() );
   if ( 1 == king_attacked.iNumAttackers )
   {
     
      Chess::UnderAttack king_attacker = { 0 };
      king_attacker = isUnderAttack( king_attacked.attacker[0].pos.iRow, king_attacked.attacker[0].pos.iColumn, getOpponentColor() );

      if ( true == king_attacker.bUnderAttack )
      {
       
         return false;
      }
      else
      {
         
         char chAttacker = getPieceAtPosition( king_attacked.attacker[0].pos.iRow, king_attacked.attacker[0].pos.iColumn );

         switch( toupper(chAttacker) )
         {
            case 'P':
            case 'C':
            {

               bCheckmate = true;
            }
            break;

            case 'A':
            {
               if ( false == canBeBlocked(king_attacked.attacker[0].pos, king, Chess::DIAGONAL ) )
               {
                  bCheckmate = true;
               }
            }
            break;

            case 'T':
            {
               if ( false == canBeBlocked(king_attacked.attacker[0].pos, king, king_attacked.attacker[0].dir ) )
               {
                
                  bCheckmate = true;
               }
            }
            break;

            case 'D':
            {
               if ( false == canBeBlocked(king_attacked.attacker[0].pos, king, king_attacked.attacker[0].dir ) )
               {
               
                  bCheckmate = true;
               }
            }
            break;


            default:
            {
               throw("!!!!No debería llegar aquí. Parte inválida");
            }
            break;
         }
      }
   }
   else
   {
     
      bCheckmate      = true;
   }


   m_bGameFinished = bCheckmate;

   return bCheckmate;
}

bool Game::isKingInCheck(int iColor, IntendedMove* pintended_move)
{
   bool bCheck = false;

   Position king = { 0 };
   
   
   if ( nullptr != pintended_move && 'K' == toupper( pintended_move->chPiece) )
   {
      king.iRow    = pintended_move->to.iRow;
      king.iColumn = pintended_move->to.iColumn;
   }
   else
   {
      king = findKing( iColor );
   }
   
   UnderAttack king_attacked = isUnderAttack( king.iRow, king.iColumn, iColor, pintended_move );

   if ( true == king_attacked.bUnderAttack )
   {
      bCheck = true;
   }

   return bCheck;
}

bool Game::playerKingInCheck(IntendedMove* intended_move)
{
   return isKingInCheck( getCurrentTurn(), intended_move);
}

bool Game::wouldKingBeInCheck(char chPiece, Position present, Position future, EnPassant* S_enPassant)
{
   IntendedMove intended_move;

   intended_move.chPiece      = chPiece;
   intended_move.from.iRow    = present.iRow;
   intended_move.from.iColumn = present.iColumn;
   intended_move.to.iRow      = future.iRow;
   intended_move.to.iColumn   = future.iColumn;

   return playerKingInCheck(&intended_move);
}

Chess::Position Game::findKing(int iColor)
{
   char chToLook = (WHITE_PIECE == iColor) ? 'K': 'k';
   Position king = { 0 };

   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 8; j++)
      {
         if ( chToLook == getPieceAtPosition(i, j) )
         {
            king.iRow    = i;
            king.iColumn = j;
         }
      }
   }

   return king;
}

void Game::changeTurns(void)
{
   if (WHITE_PLAYER == m_CurrentTurn)
   {
      m_CurrentTurn = BLACK_PLAYER;
   }
   else
   {
      m_CurrentTurn = WHITE_PLAYER;
   }
}

bool Game::isFinished( void )
{
   return m_bGameFinished;
}

int Game::getCurrentTurn(void)
{
   return m_CurrentTurn;
}

int Game::getOpponentColor(void)
{
   int iColor;

   if (Chess::WHITE_PLAYER == getCurrentTurn())
   {
      iColor = Chess::BLACK_PLAYER;
   }
   else
   {
      iColor = Chess::WHITE_PLAYER;
   }

   return iColor;
}

void Game::parseMove(string move, Position* pFrom, Position* pTo, char* chPromoted)
{
   pFrom->iColumn = move[0];
   pFrom->iRow    = move[1];
   pTo->iColumn   = move[3];
   pTo->iRow      = move[4];

 
   pFrom->iColumn = pFrom->iColumn - 'A';
   pTo->iColumn   = pTo->iColumn   - 'A';


   pFrom->iRow  = pFrom->iRow  - '1';
   pTo->iRow    = pTo->iRow    - '1';

   if ( chPromoted != nullptr )
   {
      if ( move[5] == '=' )
      {
         *chPromoted = move[6];
      }
      else
      {
         *chPromoted = EMPTY_SQUARE;
      }
   }
}

void Game::logMove(std::string &to_record)
{

   if ( to_record.length() == 5 )
   {
      to_record += "  ";
   }

   if ( WHITE_PLAYER == getCurrentTurn() )
   {
    
      Round round;
      round.white_move = to_record;
      round.black_move = "";

      rounds.push_back(round);
   }
   else
   {
   
      Round round = rounds[rounds.size() - 1];
      round.black_move = to_record;

    
      rounds.pop_back();
      rounds.push_back(round);
   }
}

string Game::getLastMove(void)
{
   string last_move;

 
   if (BLACK_PLAYER == getCurrentTurn())
   {

      last_move = rounds[rounds.size() - 1].white_move;
   }
   else
   {

      last_move = rounds[rounds.size() - 1].black_move;
   }

   return last_move;
}

void Game::deleteLastMove( void )
{

   if (WHITE_PLAYER == getCurrentTurn())
   {
     
      rounds.pop_back();
   }
   else
   {
     
      Round round = rounds[rounds.size() - 1];
      round.black_move = "";

     
      rounds.pop_back();
      rounds.push_back(round);
   }
}
