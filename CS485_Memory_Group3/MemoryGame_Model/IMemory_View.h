#pragma once
#include <string>

class IMemory_View
{
public:
	virtual ~IMemory_View() {};
	virtual void onSetPlayer1Name(std::string cPlayerName) = 0;
	virtual void onSetPlayer2Name(std::string cPlayerName) = 0;
	virtual void onFlip(int x, int y) = 0;
	virtual void onNextTurn() = 0;

	virtual void setPlayer1Name(std::string cPlayerName) = 0;
	virtual void setPlayer2Name(std::string cPlayerName) = 0;
	virtual void setPlayer1Turn() = 0;
	virtual void setPlayer2Turn() = 0;
	virtual void setPlayer1Score() = 0;
	virtual void setPlayer2Score() = 0;
	virtual void setCard(int x, int y, std::string cLabel) = 0;
	virtual void redraw() = 0;
};