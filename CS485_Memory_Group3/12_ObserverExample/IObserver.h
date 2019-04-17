//***************************************************************************
// File name:  IObserver.h
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************

#pragma once
#include <string>

class IObserver
{
public:

  virtual void notify (const std::string &rcData) = 0;

};