//***************************************************************************
// File name:    Memory_View_TextUI.h
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************
#pragma once

#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include "TextUITextWidget.h"
#include "../TextUI/TextUI.h"
#include "TextUI.h"
#include "IMemory_View.h"
#include "IMemory_Presenter.h"

class Memory_View_TextUI : public IMemory_View, public TextUI
{
public:
	Memory_View_TextUI ();	
	virtual ~Memory_View_TextUI ();


	//funcs to call to presenter
	void onSetPlayer1Name (std::string szName);
	void onSetPlayer2Name (std::string szName);
	void onFlip (std::string szXY);
	void onNextTurn (std::string);

	//funcs called by presenter
	void setPlayer1Name (std::string szName);
	void setPlayer2Name (std::string szName);
	void setPlayer1Turn ();
	void setPlayer2Turn ();
	void setPlayer1Score (int score);
	void setPlayer2Score (int score);
	void setCard (int x, int y, std::string szCard);
	void redraw ();

private:
	IMemory_Presenter *mpcPresenter = nullptr;

  TextUITextWidget *mpPlayer1Name;
  TextUITextWidget *mpPlayer2Name;
  TextUITextWidget *mpPlayer1Score;
  TextUITextWidget *mpPlayer2Score;
  static const int BOARD_SIZE = 4;
  TextUITextWidget *mapBoard[BOARD_SIZE][BOARD_SIZE];
  bool mabFixed[BOARD_SIZE][BOARD_SIZE];
};
