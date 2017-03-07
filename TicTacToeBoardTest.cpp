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

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleTurn)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  ASSERT_EQ(board.getPiece(0,0), X);
  board.placePiece(0,1);
  ASSERT_EQ(board.getPiece(0,1), O);
  board.placePiece(0,2);
  ASSERT_EQ(board.getPiece(0,2), X);
}

TEST(TicTacToeBoard, clearBoard)
{
  TicTacToeBoard board;
  for (int i = 0; i < BOARDSIZE; i++)
  {
    for (int j = 0; j < BOARDSIZE; j++)
    {
      ASSERT_EQ(board.getPiece(i,j), Blank);
      board.placePiece(i,j);
    }
  }
  board.clearBoard();
  for (int i = 0; i < BOARDSIZE; i++)
  {
    for (int j = 0; j < BOARDSIZE; j++)
    {
      ASSERT_EQ(board.getPiece(i,j), Blank);
    }
  }
}

TEST(TicTacToeBoard, getWinner)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,0);
  board.placePiece(0,1);
  board.placePiece(1,2);
  board.placePiece(0,2);
  ASSERT_EQ(board.getWinner(), X);
  board.clearBoard();
  board.placePiece(0,2);
  board.placePiece(0,1);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(1,2);
  board.placePiece(2,1);
  ASSERT_EQ(board.getWinner(), O);
  board.clearBoard();
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(1,2);
  board.placePiece(2,2);
  ASSERT_EQ(board.getWinner(), X);
  board.clearBoard();
  board.placePiece(0,0);
  board.placePiece(0,2);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(2,2);
  board.placePiece(0,2);
  ASSERT_EQ(board.getWinner(), O);
  board.clearBoard();
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(0,0);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(0,1);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(0,2);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(1,1);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(1,0);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(1,2);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(2,2);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(2,0);
  ASSERT_EQ(board.getWinner(), Invalid);
  board.placePiece(2,1);
  ASSERT_EQ(board.getWinner(), Blank);
  board.clearBoard();
}
