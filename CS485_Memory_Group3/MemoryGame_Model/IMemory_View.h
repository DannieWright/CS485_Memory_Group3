//***************************************************************************
// File name:    IMemory_View.h
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************

#pragma once
#include <string>

class IMemory_View
{
public:
	virtual ~IMemory_View () {};
	virtual void onSetPlayer1Name (std::string cPlayerName) = 0;
	virtual void onSetPlayer2Name (std::string cPlayerName) = 0;
	virtual void onFlip (std::string szXY) = 0;
	virtual void onNextTurn (std::string) = 0;

	virtual void setPlayer1Name (std::string cPlayerName) = 0;
	virtual void setPlayer2Name (std::string cPlayerName) = 0;
	virtual void setPlayer1Turn () = 0;
	virtual void setPlayer2Turn () = 0;
	virtual void setPlayer1Score (int score) = 0;
	virtual void setPlayer2Score (int score) = 0;
	virtual void setCard (int x, int y, std::string szLabel) = 0;
	virtual void redraw () = 0;
};