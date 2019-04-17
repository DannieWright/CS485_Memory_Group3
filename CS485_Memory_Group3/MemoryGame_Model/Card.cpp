//***************************************************************************
// File name:  Card.cpp
// Author:     Chadd Williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************
#include "Card.h"

//***************************************************************************
// Constructor: Card
//
// Description: Create card based on given value
//
// Parameters:  value - the card value to use
//
// Returned:    None
//***************************************************************************
Card::Card (int value) : mFaceValue (value)
{}

//***************************************************************************
// Function:    getValue
//
// Description: Get the card's face value
//
// Parameters:  None
//
// Returned:    int - the face value
//***************************************************************************
int Card::getValue () const
{
  return mFaceValue;
}

//***************************************************************************
// Function:    to_string
//
// Description: turn the current display of the card to a string
//
// Parameters:  None
//
// Returned:    std::string - how to display the card
//***************************************************************************
std::string Card::to_string () const
{
  std::string cResult = "#";
  if (mbFaceUp)
  {
    cResult = std::to_string (mFaceValue);
  }
  return cResult;
}

//***************************************************************************
// Function:    flip
//
// Description: Flip the card
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Card::flip ()
{
  mbFaceUp = !mbFaceUp;
}

//***************************************************************************
// Function:    putFaceDown
//
// Description: Unconditionally put the card face down
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Card::putFaceDown ()
{
  mbFaceUp = false;
}

//***************************************************************************
// Function:    isFaceUp
//
// Description: Determine if the card is face up
//
// Parameters:  None
//
// Returned:    bool - true if face up, false otherwise
//***************************************************************************
bool Card::isFaceUp () const
{
  return mbFaceUp;
}

//***************************************************************************
// Function:    operator==
//
// Description: Determine if two cards match
//
// Parameters:  rcCard - card to compare against
//
// Returned:    bool - true if they are equal, false otherwise
//***************************************************************************
bool Card::operator==(const Card & rcCard) const
{
  return getValue () == rcCard.getValue ();
}
