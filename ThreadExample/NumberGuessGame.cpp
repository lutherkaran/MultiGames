#include <iostream>
#include "NumberGuessGame.h"

void NumberGuessGame::RestartGame()
{
	std::cout << "\n DO YOU WANT TO PLAY AGAIN? (1/0)\n\n";
	std::cin >> GameLoop;

	if (GameLoop == 1)
	{
		NewGame();
	}
	else
	{
		std::exit(0);
	}
}

void NumberGuessGame::ExitGame(int& GameLoop)
{
	std::cin >> GameLoop;
}

void NumberGuessGame::Instruction()
{
	std::cout << "\t\t\tWELCOME TO THE GUESS GAME ENTER A GUESS NUMBER BETWEEN 1 TO 10 in " << AttemptsLeft << " TRIES ONLY" << std::endl;
}

void NumberGuessGame::NewGame()
{
	system("CLS");
	AttemptsLeft = 5;
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

	} while (GameLoop != 0);
}

void NumberGuessGame::CheckingNumber()
{
	if (Tries == TargetNumber)
	{
		std::cout << "CONGRATULATIONS: YOU WON THE GAME :)" << std::endl;
		RestartGame();
	}
	else if (Tries > TargetNumber) {
		std::cout << "TOO HIGH, TRY AGAIN :(" << std::endl;
	}
	else {
		std::cout << "TOO LOW, TRY AGAIN :(" << std::endl;
	}
}
void NumberGuessGame::InputGame()
{
	std::cin >> Tries;
}