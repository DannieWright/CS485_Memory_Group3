//***************************************************************************
// File name:  TextUI.h
// Author:     Chadd Williams
// Date:       3/39/2017
// Class:      CS485
// Assignment: TextUI
// Purpose:    Provide event based TextUI
//***************************************************************************
#pragma once

#include <string>
#include <iostream>
#include <map>
#include <functional>
#include "TextUITextWidget.h"
#include "../TextUI/TextUI.h"
#include "IMemory_View.h"

class Memory_View_TextUI : public IMemory_View, TextUI
{
public:
	Memory_View_TextUI();	
	virtual ~Memory_View_TextUI();


	//funcs to call to presenter
	void onSetPlayer1Name(std::string name);
	void onSetPlayer2Name(std::string name);
	void onFlip(std::string xy);
	void onNextTurn(std::string);

	//funcs called by presenter
	void setPlayer1Name(std::string name);
	void setPlayer2Name(std::string name);
	void setPlayer1Turn();
	void setPlayer2Turn();
	void setPlayer1Score();
	void setPlayer2Score();
	void setCard(int x, int y, std::string name);
	void redraw();

private:
	IMemory_Presenter *	mpcPresenter = nullptr;
  //TextBoardView macBoard;

  TextUITextWidget *mpPlayer1Name;
  TextUITextWidget *mpPlayer2Name;

};
