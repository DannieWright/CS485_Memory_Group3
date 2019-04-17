//***************************************************************************
// File name:  TextUITextWidget.h
// Author:     Chadd Williams
// Date:       3/39/2017
// Class:      CS485
// Assignment: TextUI
// Purpose:    Provide event based TextUI
//***************************************************************************

#pragma once

#include "ITextUIWidget.h"

class TextUITextWidget : public ITextUIWidget
{

public:

  TextUITextWidget (std::string label, std::string data);
  virtual ~TextUITextWidget () = default;

  void draw (std::ostream &rcOut) const;

  int getLength () const;

};