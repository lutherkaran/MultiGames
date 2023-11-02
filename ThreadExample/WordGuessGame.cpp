#include <iostream>
#include "WordGuessGame.h"

void WordGuessGame::Instruction()
{
	std::cout << "\t\t\tWELCOME TO THE WORD-GUESS GAME ENTER A WORD FROM THE LIST BELOW TO GUESS IN " << AttemptsLeft << " TRIES ONLY" << std::endl;
}

std::vector<std::string> WordGuessGame::DisplayWordList()
{
	std::cout << "\t\t";
	for (auto i : WordList) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	return WordList;
}

void WordGuessGame::NewGame()
{
	system("CLS");
	AttemptsLeft = 5;

	Instruction();
	DisplayWordList();
	srand(time(NULL));
	unsigned int TargetNumber = 0 + (std::rand() % WordList.size());
	TargetWord = WordList[TargetNumber];

	do
	{
		if (AttemptsLeft > 0)
		{
			InputGame();
			AttemptsLeft--;
			CheckingGuess();
		}

		else if (AttemptsLeft == 0)
		{
			std::cout << "SORRY: YOU'VE LOST THE GAME :(" << std::endl;
			std::cout << "THE WORD WAS: " << TargetWord;
			RestartGame();
		}

	} while (GetGameLoop() != 0);
}

void WordGuessGame::CheckingGuess()
{
	if (Tries == TargetWord)
	{
		std::cout << "CONGRATULATIONS: YOU WON THE GAME :)" << std::endl;
		RestartGame();
	}
	else if (Tries != TargetWord && AttemptsLeft > 0)
	{
		std::cout << "WRONG GUESS, TRY AGAIN :(" << std::endl;
	}
}
void WordGuessGame::InputGame()
{
	std::cin >> Tries;
}