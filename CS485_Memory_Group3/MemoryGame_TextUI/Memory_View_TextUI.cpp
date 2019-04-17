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
	mpcPresenter;
}

void Memory_View_TextUI::onSetPlayer2Name(std::string name)
{
}


