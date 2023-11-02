#include <iostream>
#include "NumberGuessGame.h"


void NumberGuessGame::Instruction()
{
	std::cout << "\t\t\tWELCOME TO THE GUESS GAME ENTER A GUESS NUMBER BETWEEN 1 TO 10 in " << AttemptsLeft << " TRIES ONLY" << std::endl;
}

void NumberGuessGame::NewGame()
{
	system("CLS");
	AttemptsLeft = 5;
	srand(time(NULL));
	TargetNumber = 1 + (std::rand() % 10);
	Instruction();

	do
	{
		if (AttemptsLeft > 0)
		{
			InputGame();
			AttemptsLeft--;
			CheckingNumber();
		}

		else if (AttemptsLeft == 0)
		{
			std::cout << "SORRY: YOU'VE LOST THE GAME :(" << std::endl;
			RestartGame();
		}

	} while (GetGameLoop() != 0);
}

void NumberGuessGame::CheckingNumber()
{
	if (Tries == TargetNumber)
	{
		std::cout << "CONGRATULATIONS: YOU WON THE GAME :)" << std::endl;
		RestartGame();
	}
	else if (Tries > TargetNumber && AttemptsLeft > 0) {
		std::cout << "TOO HIGH, TRY AGAIN :(" << std::endl;
	}
	else if (Tries < TargetNumber && AttemptsLeft > 0) {
		std::cout << "TOO LOW, TRY AGAIN :(" << std::endl;
	}
}

void NumberGuessGame::InputGame()
{
	std::cin >> Tries;
}