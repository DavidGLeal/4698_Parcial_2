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
#include "play.hpp"

#include "debug.h"

bool play::isMoveValid(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion){
    
   bool bValid = false;

   char chPiece = current_game->getPieceAtPosition(present.iRow, present.iColumn);


   switch( toupper(chPiece) )
   {
      case 'P':
      {

         if ( future.iColumn == present.iColumn )
         {
         
            if ( (Chess::isWhitePiece(chPiece) && future.iRow == present.iRow + 1) ||
                 (Chess::isBlackPiece(chPiece) && future.iRow == present.iRow - 1) )
            {
               if ( EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow, future.iColumn) )
               {
                  bValid = true;
               }
            }

       
            else if ( (Chess::isWhitePiece(chPiece) && future.iRow == present.iRow + 2) ||
                      (Chess::isBlackPiece(chPiece) && future.iRow == present.iRow - 2) )
            {
             
               if ( Chess::isWhitePiece(chPiece) )
               {
                  if ( EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow-1, future.iColumn) &&
                       EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow, future.iColumn)   &&
                                1   == present.iRow )
                  {
                     bValid = true;
                  }
               }
               else 
               {
                  if ( EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow + 1, future.iColumn) &&
                       EMPTY_SQUARE == current_game->getPieceAtPosition(future.iRow, future.iColumn)     &&
                                6   == present.iRow)
                  {
                     bValid = true;
                  }
               }
            }
            else
            {
          
               return false;
            }
         }
         
         
         else if ( (Chess::isWhitePiece(chPiece) && 4 == present.iRow && 5 == future.iRow && 1 == abs(future.iColumn - present.iColumn) ) ||
                   (Chess::isBlackPiece(chPiece) && 3 == present.iRow && 2 == future.iRow && 1 == abs(future.iColumn - present.iColumn) ) )
         {
           
            string last_move = current_game->getLastMove();

            
            Chess::Position LastMoveFrom;
            Chess::Position LastMoveTo;
            current_game->parseMove(last_move, &LastMoveFrom, &LastMoveTo);

         
            char chLstMvPiece = current_game->getPieceAtPosition(LastMoveTo.iRow, LastMoveTo.iColumn);

            if (toupper(chLstMvPiece) != 'P')
            {
               return false;
            }

            
            if ( 2 == abs(LastMoveTo.iRow - LastMoveFrom.iRow) && 1 == abs(LastMoveFrom.iColumn - present.iColumn) )
            {
               cout << "Peon al paso!\n";
               bValid = true;

               S_enPassant->bApplied = true;
               S_enPassant->PawnCaptured.iRow    = LastMoveTo.iRow;
               S_enPassant->PawnCaptured.iColumn = LastMoveTo.iColumn;
            }
         }

         
         else if (1 == abs(future.iColumn - present.iColumn))
         {
            if ( (Chess::isWhitePiece(chPiece) && future.iRow == present.iRow + 1) || (Chess::isBlackPiece(chPiece) && future.iRow == present.iRow - 1))
            {
              
               if (EMPTY_SQUARE != current_game->getPieceAtPosition(future.iRow, future.iColumn))
               {
                  bValid = true;
                  cout << "El peon a tomado una pieza!\n";
               }
            }
         }
         else
         {
        
            return false;
         }

      
         if ( (Chess::isWhitePiece( chPiece ) && 7 == future.iRow) ||
              (Chess::isBlackPiece( chPiece ) && 0 == future.iRow) )
         {
            cout << "El peon a coronado!\n";
            S_promotion->bApplied = true;
         }
      }
      break;

      case 'T':
      {
         if ( (future.iRow == present.iRow) && (future.iColumn != present.iColumn) )
         {
       
            if ( current_game->isPathFree(present, future, Chess::HORIZONTAL) )
            {
               bValid = true;
            }
         }
         else if ( (future.iRow != present.iRow) && (future.iColumn == present.iColumn) )
         {
         
            if ( current_game->isPathFree(present, future, Chess::VERTICAL) )
            {
               bValid = true;
            }
         }
      }
      break;

      case 'C':
      {
         if ( (2 == abs(future.iRow - present.iRow)) && (1 == abs(future.iColumn - present.iColumn)) )
         {
            bValid = true;
         }

         else if (( 1 == abs(future.iRow - present.iRow)) && (2 == abs(future.iColumn - present.iColumn)) )
         {
            bValid = true;
         }
      }
      break;

      case 'A':
      {
      
         if ( abs(future.iRow - present.iRow) == abs(future.iColumn - present.iColumn) )
         {
          
            if ( current_game->isPathFree(present, future, Chess::DIAGONAL) )
            {
               bValid = true;
            }
         }
      }
      break;

      case 'D':
      {

         if ( (future.iRow == present.iRow) && (future.iColumn != present.iColumn) )
         {
      
            if ( current_game->isPathFree(present, future, Chess::HORIZONTAL))
            {
               bValid = true;
            }
         }

         else if ( (future.iRow != present.iRow) && (future.iColumn == present.iColumn) )
         {
   
            if ( current_game->isPathFree(present, future, Chess::VERTICAL))
            {
               bValid = true;
            }
         }

 
         else if ( abs(future.iRow - present.iRow) == abs(future.iColumn - present.iColumn) )
         {
       
            if ( current_game->isPathFree(present, future, Chess::DIAGONAL))
            {
               bValid = true;
            }
         }
      }
      break;

      case 'R':
      {
         if ( (future.iRow == present.iRow) && (1 == abs(future.iColumn - present.iColumn) ) )
         {
            bValid = true;
         }

 
         else if ( (future.iColumn == present.iColumn) && (1 == abs(future.iRow - present.iRow) ) )
         {
            bValid = true;
         }

         else if ( (1 == abs(future.iRow - present.iRow) ) && (1 == abs(future.iColumn - present.iColumn) ) )
         {
            bValid = true;
         }

         else if ( (future.iRow == present.iRow) && (2 == abs(future.iColumn - present.iColumn) ) )
         {
     

        
            if ( true == current_game->playerKingInCheck() )
            {
               return false;
            }

  
            if ( false == current_game->isPathFree( present, future, Chess::HORIZONTAL ) )
            {
               return false;
            }


            if ( future.iColumn > present.iColumn )
            {

               if ( false == current_game->castlingAllowed(Chess::Side::KING_SIDE, Chess::getPieceColor(chPiece) ) )
               {
                  createNextMessage("EL enroque no está permitido\n");
                  return false;
               }
               else
               {
     
                  Chess::UnderAttack square_skipped = current_game->isUnderAttack( present.iRow, present.iColumn + 1, current_game->getCurrentTurn() );
                  if ( false == square_skipped.bUnderAttack )
                  {
     
                     S_castling->bApplied = true;

        
                     S_castling->rook_before.iRow    = present.iRow;
                     S_castling->rook_before.iColumn = present.iColumn + 3;

            
                     S_castling->rook_after.iRow    = future.iRow;
                     S_castling->rook_after.iColumn = present.iColumn + 1; 

                     bValid = true;
                  }
               }
            }
            else 
            {
               
               if (false == current_game->castlingAllowed(Chess::Side::QUEEN_SIDE, Chess::getPieceColor(chPiece)))
               {
                  createNextMessage("El enroque no está permitido.\n");
                  return false;
               }
               else
               {
                  
                  Chess::UnderAttack square_skipped = current_game->isUnderAttack( present.iRow, present.iColumn - 1, current_game->getCurrentTurn() );
                  if ( false == square_skipped.bUnderAttack )
                  {
                     
                     S_castling->bApplied = true;

                     
                     S_castling->rook_before.iRow    = present.iRow;
                     S_castling->rook_before.iColumn = present.iColumn - 4;

                    
                     S_castling->rook_after.iRow    = future.iRow;
                     S_castling->rook_after.iColumn = present.iColumn - 1;

                     bValid = true;
                  }
               }
            }
         }
      }
      break;

      default:
      {
         cout << "!!!!No debería llegar aquí. Pieza no válida " << char(chPiece) << "\n\n\n";
      }
      break;
   }

  
   if ( false == bValid )
   {
      cout << "No es permitido mover la pieza a ese cuadro\n";
      return false;
   }



   if (current_game->isSquareOccupied(future.iRow, future.iColumn))
   {
      char chAuxPiece = current_game->getPieceAtPosition(future.iRow, future.iColumn);
      if ( Chess::getPieceColor(chPiece) == Chess::getPieceColor(chAuxPiece) )
      {
         cout << "La posicion está tomada por una pieza del mismo color\n";
         return false;
      }
   }


   if ( true == current_game->wouldKingBeInCheck(chPiece, present, future, S_enPassant) )
   {
      cout << "Movimiento pone en Jaque al rey\n";
      return false;
   }

   return bValid;
}

void play::makeTheMove(Chess::Position present, Chess::Position future, Chess::EnPassant* S_enPassant, Chess::Castling* S_castling, Chess::Promotion* S_promotion){
    char chPiece = current_game->getPieceAtPosition(present.iRow, present.iColumn);


   if ( current_game->isSquareOccupied(future.iRow, future.iColumn) )
   {
      char chAuxPiece = current_game->getPieceAtPosition(future.iRow, future.iColumn);

      if ( Chess::getPieceColor(chPiece) != Chess::getPieceColor(chAuxPiece))
      {
         createNextMessage(Chess::describePiece(chAuxPiece) + " Capturado!\n");
      }
      else
      {
         cout << "Error. No deberia realizar este movimiento.\n";
         throw("Error. No deberia realizar este movimiento");
      }
   }
   else if (true == S_enPassant->bApplied)
   {
      createNextMessage("Peo capturado al paso!\n");
   }

   if ( (true == S_castling->bApplied) )
   {
      createNextMessage("Enroque realizado!\n");
   }

   current_game->movePiece(present, future, S_enPassant, S_castling, S_promotion);
}

void play::newGame(void){
    if (NULL != current_game)
   {
      delete current_game;
   }

   current_game = new Game();
}
void play::undoMove(void){
    if ( false == current_game->undoIsPossible() )
   {
      createNextMessage("No es posible deshacer el movimiento!\n");
      return;
   }

   current_game->undoLastMove();
   createNextMessage("Se deshizo el ultimo movimiento \n");
}
void play::movePiece(void){
    std::string to_record;

   // Get user input for the piece they want to move
   cout << "Elija la posicion de la pieza que desea mover. (Ejemplo: A1 o a1): ";

   std::string move_from;
   getline(cin, move_from);

   if ( move_from.length() > 2 )
   {
      createNextMessage("Solo debe ingresar dos caracteres (columna y fila)\n");
      return;
   }

   Chess::Position present;
   present.iColumn = move_from[0];
   present.iRow    = move_from[1];


   present.iColumn = toupper(present.iColumn);

   if ( present.iColumn < 'A' || present.iColumn > 'H' )
   {
      createNextMessage("Columna invalida.\n");
      return;
   }

   if ( present.iRow < '0' || present.iRow > '8' )
   {
      createNextMessage("Fila invalida.\n");
      return;
   }

   to_record += present.iColumn;
   to_record += present.iRow;
   to_record += "-";

   present.iColumn = present.iColumn - 'A';

   present.iRow  = present.iRow  - '1';

   char chPiece = current_game->getPieceAtPosition(present.iRow, present.iColumn);
   cout << "La pieza es " << char(chPiece) << "\n";

   if ( 0x20 == chPiece )
   {
      createNextMessage("Selecciono una posicion vacia.\n");
      return;
   }

   if ( Chess::WHITE_PIECE == current_game->getCurrentTurn() )
   {
      if ( false == Chess::isWhitePiece(chPiece) )
      {
         createNextMessage("Es el turno de las Blancas y eligio una pieza Negra\n");
         return;
      }
   }
   else
   {
      if ( false == Chess::isBlackPiece(chPiece) )
      {
         createNextMessage("Es el turno de las Negras y eligio una pieza Blanca\n");
         return;
      }
   }


   cout << "Mover hacia: ";
   std::string move_to;
   getline(cin, move_to);

   if ( move_to.length() > 2 )
   {
      createNextMessage("Solo debe ingresar dos caracteres (columna y fila)\n");
      return;
   }

   Chess::Position future;
   future.iColumn = move_to[0];
   future.iRow    = move_to[1];

   future.iColumn = toupper(future.iColumn);

   if ( future.iColumn < 'A' || future.iColumn > 'H' )
   {
      createNextMessage("Columna invalida.\n");
      return;
   }

   if ( future.iRow < '0' || future.iRow > '8' )
   {
      createNextMessage("Fila invalida.\n");
      return;
   }


   to_record += future.iColumn;
   to_record += future.iRow;


   future.iColumn = future.iColumn - 'A';


   future.iRow = future.iRow - '1';

   if ( future.iRow == present.iRow && future.iColumn == present.iColumn )
   {
      createNextMessage("[Invalido] Eligio la misma posicion!\n");
      return;
   }


   Chess::EnPassant  S_enPassant  = { 0 };
   Chess::Castling   S_castling   = { 0 };
   Chess::Promotion  S_promotion  = { 0 };

   if ( false == isMoveValid(present, future, &S_enPassant, &S_castling, &S_promotion) )
   {
      createNextMessage("[Invalido] La pieza no se puede mover a esa posicion!\n");
      return;
   }
   
   if ( S_promotion.bApplied == true )
   {
      cout << "Coronar a (D, T, C, A): ";
      std::string piece;
      getline(cin, piece);

      if ( piece.length() > 1 )
      {
         createNextMessage("Solo puede escoger entre (D, T, C y A)\n");
         return;
      }

      char chPromoted = toupper(piece[0]);

      if ( chPromoted != 'D' && chPromoted != 'T' && chPromoted != 'C' && chPromoted != 'A' )
      {
         createNextMessage("Caracter invalido.\n");
         return;
      }

      S_promotion.chBefore = current_game->getPieceAtPosition(present.iRow, present.iColumn);

      if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
      {
         S_promotion.chAfter = toupper(chPromoted);
      }
      else
      {
         S_promotion.chAfter = tolower(chPromoted);
      }

      to_record += '=';
      to_record += toupper(chPromoted); // always log with a capital letter
   }


   current_game->logMove( to_record );


   makeTheMove(present, future, &S_enPassant, &S_castling, &S_promotion);


   if ( true == current_game->playerKingInCheck() )
   {
      if (true == current_game->isCheckMate() )
      {
         if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
         {
            appendToNextMessage("Jaque Mate. Las piezas negras ganan!\n");
         }
         else
         {
            appendToNextMessage("Jaque Mate. Las piezas blancas ganan!\n");
         }
      }
      else
      { 

         if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
         {
            appendToNextMessage("El rey Blanco esta en jaque!\n");
         }
         else
         {
            appendToNextMessage("El rey Negro esta en jaque!\n");
         }
      }
   }

   return;
}
void play::saveGame(void){
    string file_name;
   cout << "Ingrese el nombre del archivo a guardar (sin extension): ";

   getline(cin, file_name);
   file_name += ".txt";

   std::ofstream ofs(file_name);
   if (ofs.is_open())
   {
     
      auto time_now = std::chrono::system_clock::now();
      std::time_t end_time = std::chrono::system_clock::to_time_t(time_now);
      ofs << "[Guardado a]: " << std::ctime(&end_time);

  
      for (unsigned i = 0; i < current_game->rounds.size(); i++)
      {
         ofs << current_game->rounds[i].white_move.c_str() << " | " << current_game->rounds[i].black_move.c_str() << "\n";
      }

      ofs.close();
      createNextMessage("Juego guardado como: " + file_name + "\n");
   }
   else
   {
      cout << "Guardado fallido\n";
   }

   return;
}
void play::loadGame(void){
    string file_name;
   cout << "Ingrese el nombre del archivo a cargar (sin extension):";

   getline(cin, file_name);
   file_name += ".txt";

   std::ifstream ifs(file_name);

   if (ifs)
   {
      if (NULL != current_game)
      {
         delete current_game;
      }

      current_game = new Game();


      std::string line;

      while (std::getline(ifs, line) )
      {
   
         if ( 0 == line.compare(0, 1, "["))
         {
            continue;
         }

     
         string loaded_move[2];
         

         std::size_t separator = line.find(" |");

   
         loaded_move[0] = line.substr(0, separator);


         loaded_move[1] = line.substr(line.find("|") + 2);

         for (int i = 0; i < 2 && loaded_move[i] != ""; i++)
         {
 
            Chess::Position from;
            Chess::Position to;

            char chPromoted = 0;

            current_game->parseMove(loaded_move[i], &from, &to, &chPromoted);

     
            if ( from.iColumn < 0 || from.iColumn > 7 ||
                 from.iRow    < 0 || from.iRow    > 7 ||
                 to.iColumn   < 0 || to.iColumn   > 7 ||
                 to.iRow      < 0 || to.iRow      > 7 )
            {
               createNextMessage("No se puede cargar el juego, las lineas estan erroneas!\n");

          
               current_game = new Game();
               return;
            }


            Chess::EnPassant S_enPassant = { 0 };
            Chess::Castling  S_castling  = { 0 };
            Chess::Promotion S_promotion = { 0 };

            if ( false == isMoveValid(from, to, &S_enPassant, &S_castling, &S_promotion) )
            {
               createNextMessage("No se puede cargar el juego los movimientos estan mal!\n");

               current_game = new Game();
               return;
            }

      
            if ( S_promotion.bApplied == true )
            {
               if ( chPromoted != 'D' && chPromoted != 'T' && chPromoted != 'C' && chPromoted != 'A' )
               {
                  createNextMessage("No se puede cargar el juego, existe una coronación invalida !\n");

                  current_game = new Game();
                  return;
               }

               S_promotion.chBefore = current_game->getPieceAtPosition(from.iRow, from.iColumn);

               if (Chess::WHITE_PLAYER == current_game->getCurrentTurn())
               {
                  S_promotion.chAfter = toupper(chPromoted);
               }
               else
               {
                  S_promotion.chAfter = tolower(chPromoted);
               }
            }



            current_game->logMove(loaded_move[i]);

   
            makeTheMove(from, to, &S_enPassant, &S_castling, &S_promotion);
         }
      }

      createNextMessage("Juego cargado desde " + file_name + "\n");

      return;
   }
   else
   {
      createNextMessage("Error cargando " + file_name + ". Creando nuevo juego \n");
      current_game = new Game();
      return;
   }
}
void play::start(){
    bool bRun = true;


   clearScreen();
   printLogo();

   string input = "";

   while( bRun )
   {
      printMessage();
      printMenu();

      cout << "Ingrese aqui: ";
      getline(cin, input);

      if (input.length() != 1)
      {
         cout << "Opcion invalida, ingrese un solo caracter\n\n";
         continue;
      }

      try
      {
         switch (input[0])
         {
            case 'N':
            case 'n':
            {
               newGame();
               clearScreen();
               printLogo();
               printSituation(*current_game);
               printBoard(*current_game);
            }
            break;

            case 'M':
            case 'm':
            {
               if (NULL != current_game)
               {
                  if ( current_game->isFinished() )
                  {
                     cout << "Este juego ya ha terminado!\n";
                  }
                  else
                  {
                     movePiece();
                     clearScreen();
                     printLogo();
                     printSituation( *current_game );
                     printBoard( *current_game );
                  }
               }
               else
               {
                  cout << "Ningun juego corriendo!\n";
               }
               
            }
            break;

            case 'Q':
            case 'q':
            {
               bRun = false;
            }
            break;

            case 'D':
            case 'd':
            {
               if (NULL != current_game)
               {
                  undoMove();
                  clearScreen();
                  printLogo();
                  printSituation(*current_game);
                  printBoard(*current_game);
               }
               else
               {
                  cout << "Ningun juego corriendo\n";
               }
            }
            break;

            case 'S':
            case 's':
            {
               if (NULL != current_game)
               {
                  saveGame();
                  clearScreen();
                  printLogo();
                  printSituation(*current_game);
                  printBoard(*current_game);
               }
               else
               {
                  cout << "Ningun juego corriendo\n";
               }
            }
            break;

            case 'L':
            case 'l':
            {
               loadGame();
               clearScreen();
               printLogo();
               printSituation(*current_game);
               printBoard(*current_game);
            }
            break;

            default:
            {
               cout << "La opcion no es valida\n\n";
            }
            break;

         }

      }
      catch (const char* s)
      {
         s;
      }
   }


   
}
