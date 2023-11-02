#include "HangmanGame.h"

void HangmanGame::Instruction()
{
	std::cout << "In this hangman game, guess the letters of a fruit, Each wrong guess could kill your player." << std::endl;
}

void HangmanGame::DrawMan(std::string& message)
{
	std::cout << "LIVES: " << this->Lives;

	std::cout << "\t\t\t\t____________________" << std::endl;
	std::cout << "\t\t\t\t         |         |" << std::endl;
	std::cout << "\t\t\t\t         O         |" << std::endl;
	std::cout << "\t\t\t\t        / \\        |" << "           " << message << std::endl;
	std::cout << "\t\t\t\t         |         |" << "          /" << std::endl;
	std::cout << "\t\t\t\t        / \\        |         O" << std::endl;
	std::cout << "\t\t\t\t     =========     |         / \\" << std::endl;
	std::cout << "\t\t\t\t     |       |     |     0    |" << std::endl;
	std::cout << "\t\t\t\t     |       |     |    /    / \\" << std::endl;
	std::cout << "\t\t\t\t#############################################" << std::endl << std::endl;
}

void HangmanGame::Initializing()
{
	Lives = 3;
	DrawMan(GetMessage()[0]);
	Instruction();
	srand(time(NULL));
	int random = 0 + (std::rand() % GetTargetFruit().size());
	TargetGuess = GetTargetFruit()[random];
	HideWord(TargetGuess);
}

void HangmanGame::NewGame()
{
	Initializing();

	do
	{
		if (Lives > 0)
		{
			InputGame();
			CheckGuess();
		}

		if (Lives == 0)
		{
			system("CLS");
			DrawMan(GetMessage()[4]);
			std::cout << "CORRECT ANSWER IS: " << TargetGuess << std::endl;
			RestartGame();
		}

	} while (GetGameLoop() != 0);
	//system("CLS");
}

void HangmanGame::InputGame()
{
	std::cin >> Guess;
	toupper(Guess);
}

void HangmanGame::HideWord(std::string fruit)
{
	std::string hidden = fruit;

	for (int i = 0; i < hidden.length(); i++)
	{
		hidden[i] = 'X';
	}

	std::cout << "FRUIT TO GUESS: " << hidden << std::endl;
}

void HangmanGame::CheckGuess()
{
	for (int i = 0; i < TargetGuess.length(); i++)
	{
		if (Guess == TargetGuess[i])
		{
			srand(time(NULL));
			//int random = 1 + (std::rand() % 2);
			//system("CLS");
			DrawMan(GetMessage()[2]);
		}
		else
		{
			Lives--;
			system("CLS");
			DrawMan(GetMessage()[3]);
			break;
		}
	}
}
