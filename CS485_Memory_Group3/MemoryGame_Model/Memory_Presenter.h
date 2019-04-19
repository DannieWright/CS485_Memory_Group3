//***************************************************************************
// File name:    Memory_Presenter.h
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************

#pragma once
#include <string>
#include "Model.h"
#include "IMemory_Presenter.h"
#include "IMemory_View.h"
class IMemory_View;

class Memory_Presenter : public IMemory_Presenter
{
public:
  Memory_Presenter (IMemory_View* pcView);
  ~Memory_Presenter ();
  
  virtual void setPlayer1Name (std::string szName);
  virtual void setPlayer2Name (std::string szName);
  virtual void flip (int x, int y);
  virtual void nextTurn (std::pair <int, int> &cordinate1, 
    std::pair <int, int> &cordinate2);

private:
  Model *mpcModel;
  IMemory_View *mpcView;
};