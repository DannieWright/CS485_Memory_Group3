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
  int x, y;
  std::istringstream cStringStream (xy);
  if (cStringStream >> x)
  {
    if (cStringStream >> y)
    {
      mpcPresenter->flip (x, y);
    }
  }
}

void Memory_View_TextUI::onNextTurn(std::string)
{
	mpcPresenter->nextTurn();
  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      mapBoard[i][k]->setData ("#");
    }
  }
}

void Memory_View_TextUI::setPlayer1Name(std::string name)
{
  mpPlayer1Name->setData (name);
}

void Memory_View_TextUI::setPlayer2Name(std::string name)
{
  mpPlayer2Name->setData (name);
}

void Memory_View_TextUI::setPlayer1Turn()
{

}

void Memory_View_TextUI::setPlayer2Turn()
{
}

void Memory_View_TextUI::setPlayer1Score(int score)
{
  mpPlayer1Score->setData (std::to_string (score));
}

void Memory_View_TextUI::setPlayer2Score(int score)
{
  mpPlayer2Score->setData (std::to_string (score));
}

void Memory_View_TextUI::setCard(int x, int y, std::string string)
{
  mapBoard[x][y]->setData (string);
}

void Memory_View_TextUI::redraw()
{
  drawScreen ();
}


