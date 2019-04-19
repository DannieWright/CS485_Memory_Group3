//***************************************************************************
// File name:    IMemory_Presenter.h
// Author:       Group3
// Date:         4/19/19
// Class:        CS485
// Assignment:   Memory Game
// Purpose:      Practice with MVP
//***************************************************************************

#pragma once

#include <iostream>

class IMemory_Presenter
{
public:
	~IMemory_Presenter () {};

	virtual void setPlayer1Name (std::string namePlayer1) = 0;
	virtual void setPlayer2Name (std::string namePlayer2) = 0;
	virtual void flip (int x, int y) = 0;
	virtual void nextTurn (std::pair <int, int> &cordinate1,
    std::pair <int, int> &cordinate2) = 0;
};