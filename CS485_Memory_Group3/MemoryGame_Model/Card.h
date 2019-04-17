//***************************************************************************
// File name:  Card.h
// Author:     Chadd Williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************

#pragma once
#include <string>

class Card
{

public:


  Card (int value = 0);

  int getValue () const;

  std::string to_string () const;

  void flip ();
  void putFaceDown ();

  bool isFaceUp () const;
  bool operator==(const Card &rcCard) const;

private:
  int mFaceValue;
  bool mbFaceUp = false;
};