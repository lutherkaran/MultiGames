#pragma once

#include"Games.h"

class HangmanGame : public Games
{
private:
	std::vector<std::string> Fruits{ "APPLE", "BANANA", "MANGO", "CHERRY", "BERRY", "TOMATO", "GUAVA", "PEAR", "WATERMELON", "PAPAYA", "KIWI" };
	std::vector<std::string> message{ "BEST OF LUCK..!!", "BRAVO..!!", "THAT'S CORRECT..!!" ,"WRONG ANSWER..!!","TIME TO DIE BITCH ..l..", "CONGRATULATIONS, YOU WON..!!" };

	unsigned int Lives; 
	char Guess; // Input
	
	std::string GuessFruit; // To Guess
	std::string HiddenFruit;
	
	char c; // To track
	int Index;
	
	bool hidden;
	int DisplayMessageNumber;

public:

	inline std::vector<std::string> GetMessage() {
		return message;
	}
	inline std::vector<std::string> GetTargetFruit() {
		return Fruits;
	}
	// Inherited via Games
	virtual void Instruction() override;
	virtual void NewGame() override;
	virtual void InputGame() override;

	void DrawMan(std::string& message);
	void HideWord(std::string& fruit);
	void UnhideWord(char C, char Guess, int Index);
	void CheckGuess(int& DisplayMessageNumber);
	void Initializing();
};