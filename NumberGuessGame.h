#pragma once
#include "Games.h"

class NumberGuessGame :public Games
{
private:
	unsigned int AttemptsLeft;
	int TargetNumber = 0;
	int Tries;

public:
	void Instruction() override;
	void NewGame() override;
	void InputGame();
	void CheckingNumber();
	void RestartGame();
};