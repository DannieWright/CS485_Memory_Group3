//***************************************************************************
// File name:  Board.cpp
// Author:     Chadd Williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************
#include "Board.h"

//***************************************************************************
// Constructor: Board
//
// Description: Create a scrambled board
//
// Parameters:  seed - seed for srand()
//              bEasy - set the game to easy (half as many pairs used)
//
// Returned:    None
//***************************************************************************
Board::Board (int seed, bool bEasy)
{
  setUpBoard (seed, bEasy);
}

//***************************************************************************
// Function:    setUpBoard
//
// Description: set the board to the initial state
//
// Parameters:  seed - seed for srand()
//              bEasy - set the game to easy (half as many pairs used)
//
// Returned:    None
//***************************************************************************
void Board::setUpBoard (int seed, bool bEasy)
{
  int value;
  int newX, newY;
  Card cTempCard;

  value = 0;
  for (int x = 0; x < BOARD_SIZE / 2; ++x)
  {
    if (bEasy)
    {
      value = 0;
    }
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
      macCards[y][x] = Card (value++);
    }
  }


  value = 0;
  for (int x = BOARD_SIZE / 2; x < BOARD_SIZE; ++x)
  {
    if (bEasy)
    {
      value = 0;
    }
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
      macCards[y][x] = Card (value++);
    }
  }

  srand (seed);

  for (int y = 0; y < BOARD_SIZE; ++y)
  {
    for (int x = 0; x < BOARD_SIZE; ++x)
    {
      newX = rand () % BOARD_SIZE;
      newY = rand () % BOARD_SIZE;

      cTempCard = macCards[newY][newX];
      macCards[newY][newX] = macCards[y][x];
      macCards[y][x] = cTempCard;
      maFixed[y][x] = false;
      putFaceDown (x, y);
    }
  }
}

//***************************************************************************
// Function:    legalFlip
//
// Description: Determine if the flip is legal (not fixed, is face up)
//
// Parameters:  x - x coordinate of card
//              y - y coordinate of card
//
// Returned:    bool - true if legal, false otherwise
//***************************************************************************
bool Board::legalFlip (int x, int y) const
{
  return !maFixed[y][x] && !macCards[y][x].isFaceUp();
}

//***************************************************************************
// Function:    reset
//
// Description: Reset the board to the initial state
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Board::reset ()
{
  setUpBoard ();
}

//***************************************************************************
// Function:    flip
//
// Description: Flip the card at x,y if there is a legalFlip
//
// Parameters:  x - x coordinate of card
//              y - y coordinate of card
//
// Returned:    bool - true if legal, false otherwise
//***************************************************************************
bool Board::flip (int x, int y)
{
  bool bRetVal = false;
  if (legalFlip(x,y))
  {
    bRetVal = true;
    macCards[y][x].flip ();
//    notify (x, y);
  }
  return bRetVal;
}

//***************************************************************************
// Function:    putFaceDown
//
// Description: Unconditionally put the card at x,y face down
//
// Parameters:  x - x coordinate of card
//              y - y coordinate of card
//
// Returned:    None
//***************************************************************************
void Board::putFaceDown (int x, int y)
{
  macCards[y][x].putFaceDown();
//  notify (x, y);
}

//***************************************************************************
// Function:    match
//
// Description: Determine if the two cards (x1, y1) (x2,y2) match
//
// Parameters:  x1 - x coordinate of card 1
//              y1 - y coordinate of card 1
//              x2 - x coordinate of card 2
//              y2 - y coordinate of card 2
//
// Returned:    bool - true if they match, false otherwise
//***************************************************************************
bool Board::match (int x1, int y1, int x2, int y2)
{
  return macCards[y1][x1] == macCards[y2][x2];
}

//***************************************************************************
// Function:    replace
//
// Description: Put a USED_CARD in position x, y
//
// Parameters:  x - x coordinate of card
//              y - y coordinate of card
//
// Returned:    None
//***************************************************************************
void Board::replace (int x, int y)
{
  macCards[y][x] = Card (USED_CARD);
  flip (x, y);
  maFixed[y][x] = true;
}

//***************************************************************************
// Function:    isBoardDone
//
// Description: Determine if all the cards are flipped
//
// Parameters:  None
//
// Returned:    bool - true if full, false otherwise
//***************************************************************************
bool Board::isBoardDone () const
{
  bool bDone = true;

  for (int y = 0; bDone && y < BOARD_SIZE; ++y)
  {
    for (int x = 0; bDone &&  x < BOARD_SIZE; ++x)
    {
      if (USED_CARD != macCards[y][x].getValue ())
      {
        bDone = false;
      }
    }
  }
  return bDone;
}

//***************************************************************************
// Function:    getCard
//
// Description: get the display value of the card at (x,y)
//
// Parameters:  x - x coordinate of card
//              y - y coordinate of card
//
// Returned:    std::string - the display value of the string
//***************************************************************************
std::string Board::getCard (int x, int y) const
{
  return macCards[y][x].to_string ();
}

//***************************************************************************
// Function:    setFixed
//
// Description: Set the card at position (x,y) as fixed
//              matched as not longer flippable
//
// Parameters:  x - x coordinate of card
//              y - y coordinate of card
//
// Returned:    None
//***************************************************************************
void Board::setFixed (int x, int y)
{
  maFixed[y][x] = true;
}

