//***************************************************************************
// File name:  Observable.cpp
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************

#include "Observable.h"

//***************************************************************************
// Function:    addObserver
//
// Description: Add an IObserver that will get a call to notify()
//
// Parameters:  pcObs - The IObserver pointer to store
//
// Returned:    None
//***************************************************************************
void Observable::addObserver (IObserver * pcObs)
{
  mcObservers.push_back (pcObs);
}

//***************************************************************************
// Function:    removeObserver
//
// Description: Remove an IObserver from observing this object
//
// Parameters:  pcObs - The IObserver pointer to remove
//
// Returned:    None
//***************************************************************************
void Observable::removeObserver (IObserver * pcObs)
{
  bool bDone = false;

  auto iter = mcObservers.begin(); 

  // erase will invalidate the iterator 
  // once erase is called any further interactions
  // with the iterator will be erroneous.
  // This is why a while loop rather than a for loop
  // is used here.
  while(!bDone && iter != mcObservers.end() )
    
  {
    if (pcObs == *iter)
    {
      mcObservers.erase (iter);
      bDone = true;
    }    
    else
    {
      iter++;
    }
  }

}

//***************************************************************************
// Function:    notifyAll
//
// Description: Invoke notify() on all existing observers with the data rcData
//
// Parameters:  rcData - the string data to send to the observers
//
// Returned:    None
//***************************************************************************
void Observable::notifyAll (const std::string &rcData)
{
  for (auto &ptr : mcObservers)
  {
    ptr->notify (rcData);
  }
}
