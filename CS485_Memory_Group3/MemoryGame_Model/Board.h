//***************************************************************************
// File name:  Board.h
// Author:     Chadd Williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************

#pragma once
#include "Card.h"

class Board
{
public:
  static const int BOARD_SIZE = 4;

  Board (int seed=1, bool bEasy = false);

  bool flip (int x, int y);
  void putFaceDown (int x, int y);

  bool match (int x1, int y1, int x2, int y2);

  void replace (int x, int y);

  bool isBoardDone () const;

  std::string getCard (int x, int y) const;

  void setFixed (int x, int y);
  bool legalFlip (int x, int y) const;

  void reset ();
private:
  
  void setUpBoard (int seed=1, bool bEasy=false);


  Card macCards[BOARD_SIZE][BOARD_SIZE];
  bool maFixed[BOARD_SIZE][BOARD_SIZE]; 
  static const int USED_CARD = 9;

};