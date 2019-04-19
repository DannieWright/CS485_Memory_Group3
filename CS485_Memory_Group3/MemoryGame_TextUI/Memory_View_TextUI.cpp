//***************************************************************************
// File name:    Memory_View_TextUI.cpp
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************

#include "Memory_View_TextUI.h"
#include "../MemoryGame_Model/IMemory_Presenter.h"
#include "../MemoryGame_Model/IMemory_View.h"
#include "TextUITextWidget.h"
#include "Memory_Presenter.h"
#include <sstream>

//***************************************************************************
// Constructor:  Memory_View_TextUI
//
// Description:  Initialize the Memory_View_TextUI
//
// Parameters:   std::cout - ostream to the screen
//               std::cin  - istream from the screen
//
// Returned:     None
//***************************************************************************
Memory_View_TextUI::Memory_View_TextUI () : TextUI (std::cout, std::cin)
{
  TextUITextWidget *pcWidget;
  //setView (this);
  mpcPresenter = new Memory_Presenter (this);

  mpPlayer1Name = new TextUITextWidget ("Player1", "");
  mpPlayer2Name = new TextUITextWidget ("Player2", "");
  mpPlayer1Score = new TextUITextWidget ("Score", "");
  mpPlayer2Score = new TextUITextWidget ("Score", "");
  //mpWinnerName = new TextUITextWidget ("", "");

  addWidget (2, 3, mpPlayer1Name);
  addWidget (2, 4, mpPlayer1Score);

  addWidget (20, 3, mpPlayer2Name);
  addWidget (20, 4, mpPlayer2Score);
  //addWidget (10, 4, mpWinnerName);

  for (int x = 0; x < 4; x++)
  {
    pcWidget = new TextUITextWidget ("", std::to_string (x));
    addWidget (x + 10, 8, pcWidget);
    pcWidget = new TextUITextWidget ("", std::to_string (x));
    addWidget (7, x + 10, pcWidget);
    for (int y = 0; y < 4; y++)
    {
      pcWidget = new TextUITextWidget ("", "#");
      addWidget (x + 10, y + 10, pcWidget);
      mapBoard[x][y] = pcWidget;
    }
  }
  registerEvent ("FLIP", 
    std::bind (&Memory_View_TextUI::onFlip, this, std::placeholders::_1));


  registerEvent ("NEXT",
    std::bind
    (&Memory_View_TextUI::onNextTurn, this, std::placeholders::_1));


  registerEvent ("SETPLAYER1NAME",
    std::bind
    (&Memory_View_TextUI::onSetPlayer1Name, this, std::placeholders::_1));

  registerEvent ("SETPLAYER2NAME",
    std::bind
    (&Memory_View_TextUI::onSetPlayer2Name, this, std::placeholders::_1));

  onSetPlayer1Name ("Chadd");
  onSetPlayer2Name ("Computer");
}

//***************************************************************************
// Destructor:   Memory_View_TextUI     
//
// Description:  Deletes the Memory_View_TextUI
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
Memory_View_TextUI::~Memory_View_TextUI ()
{
}

//***************************************************************************
// Function:     onSetPlayer1Name
//
// Description:  sets player 1 name
//
// Parameters:   szName - name of player 1
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::onSetPlayer1Name (std::string szName)
{
	mpcPresenter->setPlayer1Name (szName);
}

//***************************************************************************
// Function:     onSetPlayer2Name
//
// Description:  sets player 2 name
//
// Parameters:   szName - name of player 2
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::onSetPlayer2Name (std::string szName)
{
	mpcPresenter->setPlayer2Name (szName);
}

//***************************************************************************
// Function:     onFlip
//
// Description:  gets the x and y coordinates when the current player wants
//               to flip a card
//
// Parameters:   szXY - string that holds the x and y coordinates
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::onFlip (std::string szXY)
{
  int x, y;
  std::istringstream cStringStream (szXY);
  if (cStringStream >> x)
  {
    if (cStringStream >> y)
    {
      mpcPresenter->flip (x, y);
    }
  }
}

//***************************************************************************
// Function:     onNextTurn
//
// Description:  sets all the cards facedown after changing turns
//
// Parameters:   string - does nothing
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::onNextTurn (std::string)
{
	mpcPresenter->nextTurn ();
  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      mapBoard[i][k]->setData ("#");
    }
  }
}

//***************************************************************************
// Function:     setPlayer1Name
//
// Description:  sets player 1 name
//
// Parameters:   szName - name of player 1
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setPlayer1Name (std::string szName)
{
  mpPlayer1Name->setData (szName);
}

//***************************************************************************
// Function:     setPlayer2Name
//
// Description:  sets player 2 name
//
// Parameters:   szName - name of player 2
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setPlayer2Name (std::string szName)
{
  mpPlayer2Name->setData (szName);
}

//***************************************************************************
// Function:     setPlayer1Turn
//
// Description:  sets the current turn to player 1
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setPlayer1Turn ()
{
}

//***************************************************************************
// Function:     setPlayer2Turn
//
// Description:  sets the current turn to player 2
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setPlayer2Turn ()
{
}

//***************************************************************************
// Function:     setPlayer1Score
//
// Description:  sets the score of player 1
//
// Parameters:   score - score of player 1
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setPlayer1Score (int score)
{
  mpPlayer1Score->setData (std::to_string (score));
}

//***************************************************************************
// Function:     setPlayer2Score
//
// Description:  sets the score of player 2
//
// Parameters:   score - score of player 2
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setPlayer2Score (int score)
{
  mpPlayer2Score->setData (std::to_string (score));
}

//***************************************************************************
// Function:     setCard
//
// Description:  sets the card 
//
// Parameters:   x        - x coordinate of the card
//               y        - y coordinate of the card
//               szString - data
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::setCard (int x, int y, std::string szString)
{
  mapBoard[x][y]->setData (szString);
}

//***************************************************************************
// Function:     redraw
//
// Description:  redraw the screen
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
void Memory_View_TextUI::redraw ()
{
  drawScreen ();
}


