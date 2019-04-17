//***************************************************************************
// File name:  Player.cpp
// Author:     Chadd Williams
// Date:       5/24/2017
// Class:      CS485
// Assignment: Memory Game
// Purpose:    Practice with MVP
//***************************************************************************
#include "Player.h"

//***************************************************************************
// Constructor: Player
//
// Description: Initializes data members to default values
//
// Parameters:  cName - the player's name
//
// Returned:    None
//***************************************************************************
Player::Player (std::string cName)
{
  mScore = 0;
  setName (cName);
}

//***************************************************************************
// Function:    setName
//
// Description: set the player's name. call notify
//
// Parameters:  cName - the player's name
//
// Returned:    None
//***************************************************************************
void Player::setName (std::string cName)
{
  mcName = cName;
//  notify ();
}

//***************************************************************************
// Function:    getName
//
// Description: get the player's name
//
// Parameters:  None
//
// Returned:    std::string - the name
//***************************************************************************
std::string Player::getName () const
{
  return mcName;
}

//***************************************************************************
// Function:    getScore
//
// Description: get the player's score
//
// Parameters:  None
//
// Returned:    int - the score
//***************************************************************************
int Player::getScore () const
{
  return mScore;
}

//***************************************************************************
// Function:    incrementScore
//
// Description: Add one to the player's score, call notify
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Player::incrementScore ()
{
  mScore++;
//  notify ();
}

//***************************************************************************
// Function:    resetScore
//
// Description: Set player's score to 0, call notify
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Player::resetScore ()
{
  mScore = 0;
//  notify ();
}

