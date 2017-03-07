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
  board.toggleTurn();
  board.placePiece(0,1);
  ASSERT_EQ(board.getPiece(0,1), O);
  board.toggleTurn();
  board.placePiece(0,2);
  ASSERT_EQ(board.getPiece(0,2), X);
}

TEST(TicTacToeBoard, clearBoard)
{
  TicTacToeBoard board;
  for
}
