#pragma once
#include "NewGame.h"

class Games :public NewGame
{
public:
	int GameLoop = 1;

	virtual void Instruction() = 0;
	virtual void NewGame() = 0;
	virtual void InputGame() = 0;
	virtual void ExitGame(int& GameLoop) = 0;
};