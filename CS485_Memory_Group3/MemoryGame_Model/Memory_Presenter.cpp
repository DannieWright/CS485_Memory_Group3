//***************************************************************************
// File name:    Memory_Presenter.cpp
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************

#include "Memory_Presenter.h"

//***************************************************************************
// Constructor:  Memory_Presenter
//
// Description:  Initialize the Memory_Presenter with a view
//
// Parameters:   pcView - the view
//
// Returned:     None
//***************************************************************************
Memory_Presenter::Memory_Presenter (IMemory_View *pcView) {
  mpcView = pcView;
  mpcModel = new Model;
}

//***************************************************************************
// Destructor:   Memory_Presenter
//
// Description:  Deletes the Memory_Presenter
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
Memory_Presenter::~Memory_Presenter () {
}

//***************************************************************************
// Function:     setPlayer1Name
//
// Description:  sets players 1 name
//
// Parameters:   szName - name of player 1
//
// Returned:     None
//***************************************************************************
void Memory_Presenter::setPlayer1Name (std::string szName) {
  mpcModel->setPlayerName (0, szName);
  mpcModel->getPlayerName (0, szName);
  mpcView->setPlayer1Name (szName);
}

//***************************************************************************
// Function:     setPlayer2Name
//
// Description:  sets players 2 name
//
// Parameters:   szName - name of player 2
//
// Returned:     None
//***************************************************************************
void Memory_Presenter::setPlayer2Name (std::string szName) {
  mpcModel->setPlayerName (1, szName);
  mpcModel->getPlayerName (1, szName);
  mpcView->setPlayer2Name (szName);
}

//***************************************************************************
// Function:     flip
//
// Description:  flips over one card that the user picks
//
// Parameters:   x - x coordinate of the card
//               y - y coordinate of the card
//
// Returned:     None
//***************************************************************************
void Memory_Presenter::flip (int x, int y) {
  if (mpcModel->flip (x, y)) {
    mpcView->setCard (x, y, mpcModel->getCard (x, y));
  }
}

//***************************************************************************
// Function:     nextTurn
//
// Description:  advances the turn to the next player and sets the players
//               score
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
void Memory_Presenter::nextTurn (std::pair <int, int> &cordinate1, 
  std::pair <int, int> &cordinate2) {
  int score;
  mpcModel->advanceTurn (cordinate1, cordinate2);
  if (mpcModel->getPlayerScore (0, score)) {
    mpcView->setPlayer1Score (score);
  }
  if (mpcModel->getPlayerScore (1, score)) {
    mpcView->setPlayer2Score (score);
  }
}

