/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(TicTacToeBoardTest, toggleTurn)
{
	TicTacToeBoard board;
	Piece game_piece = board.toggleTurn();
	ASSERT_EQ(game_piece, O);
}

TEST(TicTacToeBoardTest, toggleTurnTwice)
{
	TicTacToeBoard board;
	Piece game_piece = board.toggleTurn();
	game_piece = board.toggleTurn();
	ASSERT_EQ(game_piece, X);
}

//  X   O   X
//  X   O   O
//  O   X   X

TEST(TicTacToeBoardTest, fillBoardGetWinner)
{
	TicTacToeBoard board;
	board.placePiece(0,0);  // X
	board.placePiece(2,0);  // O
	board.placePiece(1,0);  // X
	board.placePiece(1,1);  // O
	board.placePiece(0,2);  // X
	board.placePiece(0,1);  // O
	board.placePiece(2,1);  // X
	board.placePiece(1,2);  // O
	board.placePiece(2,2);  // X

	ASSERT_EQ(board.getWinner(), Blank);
}

//  X   O   X
//  X   O   O
//  O   X   X

TEST(TicTacToeBoardTest, fillBoardPlacePiece)
{
	TicTacToeBoard board;
	board.placePiece(0,0);  // X
	board.placePiece(2,0);  // O
	board.placePiece(1,0);  // X
	board.placePiece(1,1);  // O
	board.placePiece(0,2);  // X
	board.placePiece(0,1);  // O
	board.placePiece(2,1);  // X
	board.placePiece(1,2);  // O
	board.placePiece(2,2);  // X

	ASSERT_EQ(board.placePiece(2,2), Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutOfBounds)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.placePiece(-1,4), Invalid);
}

TEST(TicTacToeBoardTest, getPieceOutOfBounds)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.getPiece(-1,4), Invalid);
}

TEST(TicTacToeBoardTest, getPieceExisting)
{
	TicTacToeBoard board;
	board.placePiece(0,0);

	ASSERT_EQ(board.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, getPieceBlank)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.getPiece(0,0), Blank);
}

TEST(TicTacToeBoardTest, getWinnerGameGoing)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.getWinner(), Invalid);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinHorizontalMiddle)
{
	TicTacToeBoard board;
	board.placePiece(1,1); // X places in right middle
	board.placePiece(2,2); // O places bottom right corner
	board.placePiece(1,0); // X places in left middle
	board.placePiece(2,0); // O places top right corner
	board.placePiece(1,2); // X places in left middle

	// X should be winner
	ASSERT_EQ(board.getWinner(), X);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinHorizontalTop)
{
	TicTacToeBoard board;
	board.placePiece(0,0); 
	board.placePiece(2,0); 
	board.placePiece(0,1);
	board.placePiece(2,1); 
	board.placePiece(0,2); 

	// X should be winner
	ASSERT_EQ(board.getWinner(), X);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinHorizontalBottom)
{
	TicTacToeBoard board;
	board.placePiece(2,0); 
	board.placePiece(0,1); 
	board.placePiece(2,1);
	board.placePiece(1,1); 
	board.placePiece(2,2); 

	// X should be winner
	ASSERT_EQ(board.getWinner(), X);
}

// Place Piece Toggles

TEST(TicTacToeBoardTest, placePieceToggle)
{
	TicTacToeBoard board;

	ASSERT_EQ(board.placePiece(2,2), O);
}

// TEST O WINS HORIZONTAL

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinHorizontalMiddle)
{
	TicTacToeBoard board;
	board.placePiece(2,2); // X
	board.placePiece(1,0); // O
	board.placePiece(2,0); // X
	board.placePiece(1,1); // O
	board.placePiece(0,2); // X
	board.placePiece(1,2); // O

	ASSERT_EQ(board.getWinner(), O);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinHorizontalTop)
{
	TicTacToeBoard board;
	board.placePiece(1,0); // X
	board.placePiece(0,0); // O
	board.placePiece(1,1); // X
	board.placePiece(0,1); // O
	board.placePiece(2,0); // X
	board.placePiece(0,2); // O

	ASSERT_EQ(board.getWinner(), O);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinHorizontalBottom)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // X
	board.placePiece(2,0); // O
	board.placePiece(0,1); // X
	board.placePiece(2,1); // O
	board.placePiece(1,1); // X
	board.placePiece(2,2); // O

	ASSERT_EQ(board.getWinner(), O);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinVerticallMiddle)
{
	TicTacToeBoard board;
	board.placePiece(1,1); 
	board.placePiece(2,2); 
	board.placePiece(0,1); 
	board.placePiece(2,0); 
	board.placePiece(2,1); 

	// X should be winner
	ASSERT_EQ(board.getWinner(), X);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinVerticalLeft)
{
	TicTacToeBoard board;
	board.placePiece(1,0); 
	board.placePiece(2,2); 
	board.placePiece(0,0);
	board.placePiece(2,1); 
	board.placePiece(2,0); 

	// X should be winner
	ASSERT_EQ(board.getWinner(), X);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinVerticalRight)
{
	TicTacToeBoard board;
	board.placePiece(0,2); 
	board.placePiece(0,1); 
	board.placePiece(1,2);
	board.placePiece(1,1); 
	board.placePiece(2,2); 

	// X should be winner
	ASSERT_EQ(board.getWinner(), X);
}

// TEST O WINS VERTICAL

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinVerticallMiddle)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // X
	board.placePiece(1,1); // O
	board.placePiece(0,2); // X
	board.placePiece(0,1); // O
	board.placePiece(2,0); // X
	board.placePiece(2,1); // O

	ASSERT_EQ(board.getWinner(), O);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinVerticalLeft)
{
	TicTacToeBoard board;
	board.placePiece(0,1); // X
	board.placePiece(1,0); // O
	board.placePiece(1,2); // X
	board.placePiece(0,0); // O
	board.placePiece(2,2); // X
	board.placePiece(2,0); // O

	ASSERT_EQ(board.getWinner(), O);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinVerticalRight)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // X
	board.placePiece(0,2); // O
	board.placePiece(1,0); // X
	board.placePiece(1,2); // O
	board.placePiece(2,1); // X
	board.placePiece(2,2); // O

	ASSERT_EQ(board.getWinner(), O);
}


// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinDiag_1)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // X
	board.placePiece(0,2); // O
	board.placePiece(1,1); // X
	board.placePiece(1,2); // O
	board.placePiece(2,2); // X

	ASSERT_EQ(board.getWinner(), X);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, xWinDiag_2)
{
	TicTacToeBoard board;
	board.placePiece(0,2); // X
	board.placePiece(0,0); // O
	board.placePiece(1,1); // X
	board.placePiece(2,2); // O
	board.placePiece(2,0); // X

	ASSERT_EQ(board.getWinner(), X);
}


// O    X  0,2
// 1,0  O   X
// X   2,1 2,2

TEST(TicTacToeBoardTest, oWinDiag_1)
{
	TicTacToeBoard board;
	board.placePiece(2,0); // X
	board.placePiece(0,0); // O
	board.placePiece(1,2); // X
	board.placePiece(1,1); // O
	board.placePiece(0,1); // X
	board.placePiece(2,2); // O

	ASSERT_EQ(board.getWinner(), O);
}

// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2

TEST(TicTacToeBoardTest, oWinDiag_2)
{
	TicTacToeBoard board;
	board.placePiece(0,0); // X
	board.placePiece(0,2); // O
	board.placePiece(1,2); // X
	board.placePiece(1,1); // O
	board.placePiece(1,0); // X
	board.placePiece(2,0); // O

	ASSERT_EQ(board.getWinner(), O);
}