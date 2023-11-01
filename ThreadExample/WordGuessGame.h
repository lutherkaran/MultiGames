#pragma once

#include "Games.h"

class WordGuessGame :public Games
{
private:
	std::vector<std::string> WordList = { "hi", "how", "are", "you", "doing", "today" };
	unsigned int AttemptsLeft;
	unsigned int TargetNumber = 0;
	std::string Tries;
	std::string TargetWord;

public:
	void Instruction() override;
	void NewGame() override;
	void InputGame();
	void CheckingGuess();
	std::vector<std::string> DisplayWordList();
};
