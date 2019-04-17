//***************************************************************************
// File name:  TextUITextWidget.cpp
// Author:     Chadd Williams
// Date:       3/39/2017
// Class:      CS485
// Assignment: TextUI
// Purpose:    Provide event based TextUI
//***************************************************************************
#include "TextUITextWidget.h"

//***************************************************************************
// Constructor: TextUITextWidget
//
// Description: Initialize the label and data for the widget
//
// Parameters:  label – the widget's label
//              data – the widget's data
//
// Returned:    None
//***************************************************************************
TextUITextWidget::TextUITextWidget (std::string label, std::string data)
{
	setData(data);
	setLabel(label);
}





//***************************************************************************
// Function:    draw
//
// Description: draw the widget on the screen
//
// Parameters:  rcOut - the out stream
//
// Returned:    None
//***************************************************************************
void TextUITextWidget::draw (std::ostream & rcOut) const
{
  if (getLabel().length() > 0)
  {
    rcOut << getLabel() << ": ";
  }
  rcOut << getData();
}

//***************************************************************************
// Function:    getLength
//
// Description: Get the total length of the widget (lable + " : " + data)
//
// Parameters:  None
//
// Returned:    the length
//***************************************************************************
int TextUITextWidget::getLength () const
{
  int len = 0;

  if (getLabel().length() > 0)
  {
    len += getLabel().length() + 2; 
  }
  len += getData().length();

  return len;
}

