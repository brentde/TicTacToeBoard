#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  gameOver = false;
  boardFilled = false;
  turn = X;
  piecesPlaced = 0;

  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    turn = O;
    return turn;
  }
  
  turn = X;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 

Piece TicTacToeBoard::placePiece(int row, int column)
{

  // Check if we've reached the end of the game
  if(gameOver || boardFilled)
    return Invalid;

  // Check if location request is out of bounds
  if((row < 0 || column < 0) || (row > BOARDSIZE || column > BOARDSIZE))
    return Invalid;

  // Check if board location is already filled
  if(board[row][column] != Blank)
    return board[row][column];

  // From this point, we know the game isn't over and the space is available

  Piece current_turn = turn;
  board[row][column] = current_turn;

  // ***********************
  // Check vertical match
  // ***********************

  int temp_col = column;
  int temp_row = row - 1;
  bool matching = true;

  // Check left 

  while(temp_row >= 0 && matching){
      Piece piece = getPiece(temp_row, temp_col);

      // This will return X, O, Invalid or Blank
      if(piece != turn){
        matching = false;
      }

      temp_row--;
  }

  temp_col = column;
  temp_row = row + 1;

  // Check right

  while(temp_row < BOARDSIZE && matching){
      Piece piece = getPiece(temp_row, temp_col);
      
      if(piece != turn){
        matching = false;
      }
      
      temp_row++;
  }

  if(matching)
    gameOver = true;


  // ***********************
  // Check horzionatal match 
  // ***********************

  if(!gameOver){
    temp_col = column - 1;
    temp_row = row;
    matching = true;

    // Check down

    while(temp_col >= 0 && matching){
        Piece piece = getPiece(temp_row, temp_col);
       
        if(piece != current_turn)
          matching = false;
        
        temp_col--;
    }

    // Check up

    temp_col = column + 1;
    temp_row = row;

    if(matching){
      while(temp_col < BOARDSIZE && matching){
          Piece piece = getPiece(temp_row, temp_col);
        
          if(piece != current_turn)
            matching = false;
        
          temp_col++;
      }
    }

    if(matching)
      gameOver = true;
  }

  // ***********************
  // Check diagonal match
  // ***********************

  if(!gameOver){
    temp_col = column - 1;
    temp_row = row - 1;
    bool not_skipped = false;
    matching = true;
    int num_matches = 1;

    while(temp_col >= 0 && temp_row >= 0 && matching){
        not_skipped = true;
        Piece piece = getPiece(temp_row, temp_col);
       
        if(piece != current_turn)
          matching = false;

        // Diagonal doesn't extend length of board
        if((temp_row == 0 && temp_col != 0) || (temp_row != 0 && temp_col == 0))
          matching = false;
    
        if(matching)
          num_matches++;

        temp_col--;
        temp_row--;
    }

    if(matching){
      temp_col = column + 1;
      temp_row = row + 1;

      while((temp_col < BOARDSIZE && temp_row < BOARDSIZE) && matching){
          not_skipped = true;
          Piece piece = getPiece(temp_row, temp_col);
        
          if(piece != current_turn)
            matching = false;

          if((temp_row == BOARDSIZE && temp_col != BOARDSIZE) || (temp_row != BOARDSIZE && temp_col == BOARDSIZE))
            matching = false;

          if(matching)
            num_matches++;
        
          temp_col++;
          temp_row++;
      }
    }

    if(matching && not_skipped && num_matches == BOARDSIZE){
      gameOver = true;
    }
  }


  // ***********************
  // Check diagonal match
  // ***********************

   if(!gameOver){
    temp_col = column + 1;
    temp_row = row - 1;
    matching = true;
    bool not_skipped = false;
    int num_matches = 1;

    while(temp_col < BOARDSIZE && temp_row >= 0 && matching){
        not_skipped = true;
        Piece piece = getPiece(temp_row, temp_col);
       
        if(piece != current_turn)
          matching = false;

        if((temp_row < 0 && temp_col < BOARDSIZE) || (temp_row >= 0 && temp_col == BOARDSIZE))
          matching = false;

        if(matching)
          num_matches++;
        
        temp_col++;
        temp_row--;
    }

    if(matching){
      temp_col = column - 1;
      temp_row = row + 1;

      while(temp_col >= 0 && temp_row < BOARDSIZE && matching){
          not_skipped = true;
          Piece piece = getPiece(temp_row, temp_col);
        
          if(piece != current_turn)
            matching = false;

          if((temp_row == BOARDSIZE && temp_col >= 0) || (temp_row < BOARDSIZE && temp_col < 0))
            matching = false;

          if(matching)
            num_matches++;

          temp_col--;
          temp_row++;
      }
    }

    if(matching && not_skipped && num_matches == BOARDSIZE){
      gameOver = true;
    }
  }


  piecesPlaced++;

  if(!gameOver){
    if(piecesPlaced == (BOARDSIZE * BOARDSIZE))
      boardFilled = !boardFilled;
  }
  
  if(!gameOver && !boardFilled)
    toggleTurn();
 
  return turn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/

Piece TicTacToeBoard::getPiece(int row, int column)
{
  if((row < 0 || column < 0) || (row > BOARDSIZE || column > BOARDSIZE))
    return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/

Piece TicTacToeBoard::getWinner()
{
  if(boardFilled)
    return Blank;
  if(!gameOver)
    return Invalid;
  return turn;
}
