#pragma once
#include "Memory_Presenter.h"



Memory_Presenter::Memory_Presenter(IMemory_View *pcView, Model *pcModel) {

	mpcView = pcView;
	mpcModel = pcModel;
}


Memory_Presenter::~Memory_Presenter() {

}


void Memory_Presenter::setPlayer1Name(std::string szName) {
	mpcModel->setPlayerName(0, szName);
	mpcModel->getPlayerName(0, szName);
	mpcView->setPlayer1Name(szName);
}

void Memory_Presenter::setPlayer2Name(std::string szName) {
	mpcModel->setPlayerName(1, szName);
	mpcModel->getPlayerName(1, szName);
	mpcView->setPlayer1Name(szName);
}

void Memory_Presenter::flip(int x, int y) {
	if (mpcModel->flip(x, y)) {
		mpcView->setCard(x, y, mpcModel->getCard(x, y));
	}
}

void Memory_Presenter::nextTurn() {
	int score;
	mpcModel->advanceTurn();
	if (mpcModel->getPlayerScore(0, score)) {
		mpcView->setPlayer1Score(score);
	}
	if (mpcModel->getPlayerScore(1, score)) {
		mpcView->setPlayer2Score(score);
	}
}

