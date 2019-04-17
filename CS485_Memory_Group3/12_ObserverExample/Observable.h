//***************************************************************************
// File name:  Observable.h
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************

#pragma once
#include "IObserver.h"
#include <vector>
#include <string>

class Observable
{
public:

  Observable () = default;
  ~Observable () = default;

  virtual void addObserver (IObserver *pcObs);
  virtual void removeObserver (IObserver *pcObs);

  virtual void notifyAll (const std::string &rcData);


private:
  std::vector<IObserver *> mcObservers;
};