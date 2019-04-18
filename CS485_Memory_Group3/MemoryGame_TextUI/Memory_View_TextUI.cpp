#include "Memory_View_TextUI.h"
#include "../MemoryGame_Model/IMemory_Presenter.h"
#include "../MemoryGame_Model/IMemory_View.h"
#include "TextUITextWidget.h"
#include "Memory_Presenter.h"
#include <sstream>

Memory_View_TextUI::Memory_View_TextUI () : TextUI (std::cout, std::cin)
{
  TextUITextWidget *pcWidget;
  //setView (this);
  mpcPresenter = new Memory_Presenter (this);

  mpPlayer1Name = new TextUITextWidget ("Player1", "");
  mpPlayer2Name = new TextUITextWidget ("Player2", "");
  //mpWinnerName = new TextUITextWidget ("", "");

  addWidget (2, 3, mpPlayer1Name);
  addWidget (20, 3, mpPlayer2Name);
  //addWidget (10, 4, mpWinnerName);

  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      pcWidget = new TextUITextWidget ("", "_");
      addWidget (x + 10, y + 10, pcWidget);
      //macBoard.setWidget (x, y, pcWidget);
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

  onSetPlayer1Name ("Player 1");
  onSetPlayer2Name ("Player 2");
}

Memory_View_TextUI::~Memory_View_TextUI ()
{
}


void Memory_View_TextUI::onSetPlayer1Name(std::string name)
{
	mpcPresenter->setPlayer1Name(name);
}

void Memory_View_TextUI::onSetPlayer2Name(std::string name)
{
	mpcPresenter->setPlayer2Name(name);
}

void Memory_View_TextUI::onFlip(std::string xy)
{
	//mpcPresenter->flip(x, y);
}

void Memory_View_TextUI::onNextTurn(std::string)
{
	mpcPresenter->nextTurn();
}

void Memory_View_TextUI::setPlayer1Name(std::string name)
{
  
}

void Memory_View_TextUI::setPlayer2Name(std::string name)
{
}

void Memory_View_TextUI::setPlayer1Turn()
{
}

void Memory_View_TextUI::setPlayer2Turn()
{
}

void Memory_View_TextUI::setPlayer1Score()
{
  
}

void Memory_View_TextUI::setPlayer2Score()
{
}

void Memory_View_TextUI::setCard(int, int, std::string)
{
}

void Memory_View_TextUI::redraw()
{
}


