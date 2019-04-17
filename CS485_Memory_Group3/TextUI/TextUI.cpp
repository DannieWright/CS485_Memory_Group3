//***************************************************************************
// File name:  TextUI.cpp
// Author:     Chadd Williams
// Date:       3/39/2017
// Class:      CS485
// Assignment: TextUI
// Purpose:    Provide event based TextUI
//***************************************************************************
#include "TextUI.h"
#include <algorithm>

//***************************************************************************
// Constructor: TextUI
//
// Description: Set the input and output streams for the TextUI
//
// Parameters:  rcOut – the output stream
//              rcIn – the input stream
//
// Returned:    None
//***************************************************************************
TextUI::TextUI (std::ostream & rcOut, std::istream & rcIn)
  :mrcIn(rcIn), mrcOut(rcOut)
{
}

//***************************************************************************
// Destructor:  TextUI
//
// Description: Delete all the widgets added to the textUI
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TextUI::~TextUI ()
{
  for (auto &value : mWidgets)
  {
    delete value.second;
  }
  mWidgets.clear ();
}

//***************************************************************************
// Function:    addWidget
//
// Description: Add the widget at location x,y
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              pcWidget - the widget
//
// Returned:    None
//***************************************************************************
void TextUI::addWidget (int x, int y, ITextUIWidget * pcWidget)
{
  mWidgets.insert ({ std::make_pair(y, x), pcWidget });
}

//***************************************************************************
// Function:    drawScreen
//
// Description: Clear screen then draw all the widgets on the screen
//
// Parameters:  None
//
// Returned:    NOne
//***************************************************************************
void TextUI::drawScreen ()
{
  int currLine = 0;
  int currCol = 0;
  int x, y;
  ITextUIWidget *pcWidget;

  clearScreen ();
  for (auto const &value : mWidgets)
  {
    y = value.first.first;
    x = value.first.second;
    pcWidget = value.second;

    if (pcWidget->isVisible ())
    {

      while (y > currLine)
      {
        mrcOut << std::endl;
        currLine++;
        currCol = 0;
      }
      while (x > currCol)
      {
        mrcOut << " ";
        currCol++;
      }

      pcWidget->draw (mrcOut);
      currCol += pcWidget->getLength ();
    }
  }

}

//***************************************************************************
// Function:    clearScreen
//
// Description: Clear Screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TextUI::clearScreen () const
{
  system ("cls");
}

//***************************************************************************
// Function:    displayEventMenu
//
// Description: display the event menu at the bottom of the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TextUI::displayEventMenu () const
{
  std::cout << "\n\nMENU\n----\nQUIT\n";
  for (auto const &value : mEventMap)
  {
    std::cout << value.first << "\n";
  }
  std::cout << "> ";
}

//***************************************************************************
// Function:    registerEvent
//
// Description: Register an event to be displayed in the menu
//
// Parameters:  name - event menu name
//              func - function to call as result of event
//
// Returned:    None
//***************************************************************************
void TextUI::registerEvent (std::string name,
//  std::function<void (ITicTacToeView*, std::string)> func)
  std::function<void (std::string)> func)
{
  mEventMap.insert (std::make_pair (name, func));
}

//***************************************************************************
// Function:    UIEventLoop
//
// Description: Main loop.  draw screen, display menu, dispatch events
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TextUI::UIEventLoop ()
{
  const std::string QUIT = "QUIT";
  std::string command = "";
  std::string argument;

  while (QUIT != command)
  {
    drawScreen ();

    displayEventMenu ();
    std::cin >> command;
    if (QUIT != command)
    {
      std::getline (std::cin, argument);
      //argument.erase (std::remove (argument.begin (),
      //  argument.end (), ' '), argument.end ());

      //std::function<void (ITicTacToeView*, std::string)>

      auto  func = mEventMap.find(command);

      // make sure we got a valid function
      if (func != mEventMap.end()) 
      {
        //func->second (this->mpcTTTView, argument);
        func->second (argument);
      }
    }
  }
}
