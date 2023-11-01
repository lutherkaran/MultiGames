#pragma once
#include <unordered_map>
#include "Games.h"

struct QuestionStruct
{
	std::string Question;
	std::list<std::string> Answers;
	unsigned long int PrizeMoney;
};

class MillionaireGame : public Games
{
private:
	std::unordered_multimap<char, QuestionStruct> QAMap;
	void Initializing();
	char Ans;

public:
	void Instruction() override;
	void NewGame() override;
	void InputGame() override;
};