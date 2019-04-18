#pragma once
#include <string>
#include "Model.h"

class IMemory_View;

class Memory_Presenter
{
public:
	Memory_Presenter(IMemory_View* pcView, Model* pcModel);
	~Memory_Presenter();

	virtual void setPlayer1Name(std::string szName);
	virtual void setPlayer2Name(std::string szName);
	virtual void flip(int x, int y);
	virtual void nextTurn();

	/*
	+Memory_Presenter(IMemory_View*,Model*)
+~Memory_Presenter()

//funcs called by view
/+setPlayer1Name(string):void/
/+setPlayer2Name(string):void/
/+flip(int,int):void/
/+nextTurn():void/
	*/

private:
	Model *mpcModel;
	IMemory_View *mpcView;
};

