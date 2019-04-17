#include "Memory_View_TextUI.h"
#include "../MemoryGame_Model/IMemory_Presenter.h"
#include "../MemoryGame_Model/IMemory_View.h"

Memory_View_TextUI::Memory_View_TextUI(IMemory_Presenter * pcPresenter) 
	: TextUI (std::cout, std::cin)
{
	mpcPresenter = pcPresenter;
}

Memory_View_TextUI::~Memory_View_TextUI()
{
	delete mpcPresenter;
	mpcPresenter = nullptr;
}

void Memory_View_TextUI::onSetPlayer1Name(std::string name)
{
	mpcPresenter->setPlayer1Name(name);
}

void Memory_View_TextUI::onSetPlayer2Name(std::string name)
{
	mpcPresenter->setPlayer2Name(name);
}

void Memory_View_TextUI::onFlip(int x, int y)
{
	mpcPresenter->flip(x, y);
}

void Memory_View_TextUI::onNextTurn()
{
	mpcPresenter->nextTurn();
}

void Memory_View_TextUI::setPlayer1Name(std::string name)
{

}


