//***************************************************************************
// File name:    driver.cpp
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************

#include <iostream>
#include "Memory_View_TextUI.h"

//***************************************************************************
// Method:       main
//
// Description:  play memory game between two players
//
// Parameters:   None
//
// Returned:     None
//***************************************************************************
int main ()
{
  Memory_View_TextUI cView;

  cView.UIEventLoop ();

  return EXIT_SUCCESS;
}