//***************************************************************************
// File name:    Memory_Presenter.cpp
// Author:     
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


Memory_Presenter::~Memory_Presenter () {

}


void Memory_Presenter::setPlayer1Name (std::string szName) {
  mpcModel->setPlayerName (0, szName);
  mpcModel->getPlayerName (0, szName);
  mpcView->setPlayer1Name (szName);
}

void Memory_Presenter::setPlayer2Name (std::string szName) {
  mpcModel->setPlayerName (1, szName);
  mpcModel->getPlayerName (1, szName);
  mpcView->setPlayer2Name (szName);
}

void Memory_Presenter::flip (int x, int y) {
  if (mpcModel->flip (x, y)) {
    mpcView->setCard (x, y, mpcModel->getCard (x, y));
  }
}

void Memory_Presenter::nextTurn () {
  int score;
  mpcModel->advanceTurn ();
  if (mpcModel->getPlayerScore (0, score)) {
    mpcView->setPlayer1Score (score);
  }
  if (mpcModel->getPlayerScore (1, score)) {
    mpcView->setPlayer2Score (score);
  }
}

